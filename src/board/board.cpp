#include "board.h"


Board::Board()
	:w_piece_list(Color::W), b_piece_list(Color::B)
{
	for(int x = 0; x < 8; x++)
	{
		board[x][1] = new Pone(Color::W, Pos(x, 1));
		board[x][6] = new Pone(Color::B, Pos(x, 6));
	}

	board[0][0] = new Rook(Color::W, Pos(0, 0));
	board[1][0] = new Night(Color::W, Pos(1, 0));
	board[2][0] = new Bishop(Color::W, Pos(2, 0));
	board[3][0] = new Queen(Color::W, Pos(3, 0));
	board[4][0] = new King(Color::W, Pos(4, 0));
	board[5][0] = new Bishop(Color::W, Pos(5, 0));
	board[6][0] = new Night(Color::W, Pos(6, 0));
	board[7][0] = new Rook(Color::W, Pos(7, 0));

	board[0][7] = new Rook(Color::B, Pos(0, 7));
	board[1][7] = new Night(Color::B, Pos(1, 7));
	board[2][7] = new Bishop(Color::B, Pos(2, 7));
	board[3][7] = new Queen(Color::B, Pos(3, 7));
	board[4][7] = new King(Color::B, Pos(4, 7));
	board[5][7] = new Bishop(Color::B, Pos(5, 7));
	board[6][7] = new Night(Color::B, Pos(6, 7));
	board[7][7] = new Rook(Color::B, Pos(7, 7));

	for(int x = 0; x < 8; x++)
		for(int y = 2; y < 6; y++)
			board[x][y] = nullptr;

}

Board::~Board()
{
	for(int y = 0; y < 8; y++)
		for(int x = 0; x < 8; x++)
		{
			if(IfExist(Pos(x, y)) == true)
			{
				delete board[x][y];
			}
		}
}

bool Board::IfExist(const Pos& check_pos) const
{
	if(board[check_pos.x][check_pos.y] == nullptr)
		return false;
	else
		return true;
}

Color Board::GetColor(const Pos& get_pos) const
{
	return board[get_pos.x][get_pos.y]->GetColor();
}

ID Board::GetID(const Pos& get_pos) const
{
	return board[get_pos.x][get_pos.y]->GetID();
}

int Board::AddPiece(const ID add_id, const Pos& add_pos, const Color add_color)
{
	if(IfExist(add_pos) == true)
		return -1;

	switch(add_id)
	{
	case ID::K:
		board[add_pos.x][add_pos.y] = new King(add_color, add_pos);
		break;
	case ID::Q:
		board[add_pos.x][add_pos.y] = new Queen(add_color, add_pos);
		break;
	case ID::B:
		board[add_pos.x][add_pos.y] = new Bishop(add_color, add_pos);
		break;
	case ID::N:
		board[add_pos.x][add_pos.y] = new Night(add_color, add_pos);
		break;
	case ID::R:
		board[add_pos.x][add_pos.y] = new Rook(add_color, add_pos);
		break;
	case ID::P:
		board[add_pos.x][add_pos.y] = new Pone(add_color, add_pos);
		break;
	}

	GetPieceList(add_color).PushBack(*board[add_pos.x][add_pos.y]);

	return 0;

}
int Board::DeletePiece(const Pos& delete_pos)
{
	if(IfExist(delete_pos) == false)
		return -1;
		
	GetPieceList(GetColor(delete_pos)).Delete(delete_pos);
	delete board[delete_pos.x][delete_pos.y];
	board[delete_pos.x][delete_pos.y] = nullptr;

	return 0;
}

int Board::GetPieceMoveList(const Pos& orig_pos, const Pos& dest_pos, list<Pos>& move_list) const
{
	if(IfExist(orig_pos) == false)
		return -1;
	
	if(board[orig_pos.x][orig_pos.y]->GetMoveList(dest_pos, move_list) != 0)
	{
		move_list.clear();
		return -2;
	}

	return 0;
}

void Board::GetAllPiecePos(const Color color, list<Pos> &pos_list) const
{
	GetPieceList(color).GetAllPiecePos(pos_list);
}

int Board::GetKingPos(const Color color, Pos& king_pos) const
{
	for(int x = 0; x < 8; x++)
		for(int y = 0; y < 8; y++)
		{
			if(IfExist(Pos(x, y)) == true)
			{
				if(board[x][y]->GetColor() == Color::W && board[x][y]->GetID() == ID::K)
				{
					king_pos = board[x][y]->GetPos();
					return 0;
				}
			}
		}

	return -1;
}

int Board::MovePiece(const Pos& orig, const Pos& dest)
{
	if(IfExist(orig) == false)
		return -1;

	if(orig == dest)
		return -2;
		
	if(IfExist(dest) == true)
	{
		GetPieceList(GetColor(dest)).Delete(dest);
		delete board[dest.x][dest.y];
	}

	board[dest.x][dest.y] = board[orig.x][orig.y];
	board[orig.x][orig.y] = nullptr;

	Color orig_color = GetColor(dest);

	GetPieceList(orig_color).ChangePos(dest, orig);

	return 0;
}

void Board::GetBoard(Piece_Data_Board& data_board) const
{
	for(int x = 0; x < 8; x++)
		for(int y = 0; y < 8; y++)
		{
			Pos cur_pos = Pos(x, y);

			if(IfExist(cur_pos) == false)
			{
				data_board.data_board[x][y].if_exist = false;
				continue;
			}

			data_board.data_board[x][y].if_exist = true;
			data_board.data_board[x][y].id = GetID(cur_pos);
			data_board.data_board[x][y].color = GetColor(cur_pos);
			data_board.data_board[x][y].pos = cur_pos;
		}
}

int Board::ShowBoard(void) const
{
	for(int y = 7; 0 <= y; y--)
	{
		cout << y << "   ";

		for(int x = 0; x < 8; x++)
		{
			if(IfExist(Pos(x, y)) == false)
				cout << "*";
			else
			{
				switch(GetID(Pos(x, y)))				
				{
					case ID::K:
						cout << "K";
						break;
					case ID::Q:
						cout << "Q";
						break;
					case ID::R:
						cout << "R";
						break;
					case ID::N:
						cout << "N";
						break;
					case ID::B:
						cout << "B";
						break;
					case ID::P:
						cout << "P";
						break;
				}
			}
			cout << " ";
		}
		cout << endl;
	}
		
	cout << "\n" << "    0 1 2 3 4 5 6 7" << endl;

	return 0;
}

