#include "tui.h"

Show_Board::Show_Board()
	:data_board(true)
{
	
}

Pos Show_Board::GetScreenPos(const Pos& pos) const
{	
	const unsigned int begin_x = 140;
	const unsigned int begin_y = 20;

	return Pos(3 * ( pos.x + 1 )  - 1 + begin_x , 2 * ( (7 - pos.y) + 1)  - 1 + begin_y );
}

void Show_Board::ModifyBoard(const Piece_Data_Board& data_board)
{
	this->data_board = data_board;
}

int Show_Board::MovePiece(const Pos& orig_pos, const Pos& dest_pos)
{
	if(data_board.data_board[orig_pos.x][orig_pos.y].if_exist == false)
		return -1;

		
	data_board.data_board[dest_pos.x][dest_pos.y] = data_board.data_board[orig_pos.x][orig_pos.y];	
	data_board.data_board[orig_pos.x][orig_pos.y].if_exist = false;

	Pos screen_pos = GetScreenPos(dest_pos);
	PrintPiece(screen_pos.x, screen_pos.y, data_board.data_board[dest_pos.x][dest_pos.y].id, data_board.data_board[dest_pos.x][dest_pos.y].color);

	return 0;
}

void Show_Board::SelectPos(Pos& select_pos) const
{		
	static Pos point_pos = Pos(0, 0);
	//cout << "before_point_pos : [" << before_point_pos.x << ", " << before_point_pos.y << "]" << endl;

	Pos init_screen_curser_pos = GetScreenPos(point_pos);	
	move(init_screen_curser_pos.y, init_screen_curser_pos.x);


	while(true)
	{
		int get_arrow = getch();

		switch(get_arrow)
		{
			case KEY_UP:
				if( 7 < (point_pos.y + 1) )
					continue;

				point_pos.y += 1;
			break;

			case KEY_DOWN:
				if( (point_pos.y - 1) < 0 )
					continue;

				point_pos.y -= 1;
			break;

			case KEY_LEFT:
				if( (point_pos.x - 1) < 0 )
					continue;

				point_pos.x -= 1;
			break;

			case KEY_RIGHT:
				if( 7 < (point_pos.x + 1) )
					continue;

				point_pos.x += 1;
			break;

			case ' ': // ' ' means spacebar input
				move(0, 0);
				select_pos = point_pos;
				RefreshBoard();


				return;
		}

		
		Pos screen_point_pos = GetScreenPos(point_pos);
		move(screen_point_pos.y, screen_point_pos.x);
		RefreshBoard();
		
	}
}

void Show_Board::RefreshBoard(void) const
{
	refresh();
}

int Show_Board::PrintPiece(const int x, const int y, const ID piece_id, const Color piece_color) const
{
	if(piece_color == Color::W)			
		return mvaddch(y, x, id::IDtoChar(piece_id) | COLOR_PAIR(white_screen_color));
	else
		return mvaddch(y, x, id::IDtoChar(piece_id) | COLOR_PAIR(black_screen_color));
}

void Show_Board::ShowBoard() const
{
	for(int y = 0; y < 8; y++)
	{
		for(int x = 0; x < 8; x++)
		{
			Pos screen_pos = GetScreenPos(Pos(x, y));

			if(data_board.data_board[x][y].if_exist == true)
					PrintPiece(screen_pos.x , screen_pos.y, data_board.data_board[x][y].id, data_board.data_board[x][y].color);
			else
				mvaddch(screen_pos.y, screen_pos.x, '*');
		}
	}	

		RefreshBoard();
}
