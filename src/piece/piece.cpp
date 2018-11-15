#include "piece.h"

Piece::Piece(const ID id, const Color color, const Pos& pos)
	:m_color(color), m_id(id), m_pos(pos)
{
}

void Piece::SetPos(const Pos& dest)
{
	m_pos = dest;
}


Color color::GetReverseColor(const Color color)
{
	if(color == Color::W)
		return Color::B;
	else
		return Color::W;
}

Piece_Data::Piece_Data() {};

Piece_Data::Piece_Data(const Pos& init_pos, const ID init_id, const Color init_color)
	: pos(init_pos), id(init_id), color(init_color)
{}

Piece_Data_Board_Node::Piece_Data_Board_Node()
	:Piece_Data()
{
	if_exist = false;	
}
Piece_Data_Board_Node::Piece_Data_Board_Node(const bool if_exist ,const Pos& pos, const ID init_id, const Color init_color)
	:Piece_Data(pos, init_id, init_color)
{
	this->if_exist = if_exist;
}

char id::IDtoChar(const ID id)
{
	switch(id)
	{
	case ID::K:
		return 'K';
	case ID::Q:
		return 'Q';
	case ID::R:
		return 'R';
	case ID::B:
		return 'B';
	case ID::N:
		return 'N';
	case ID::P:
		return 'P';
	}

	return -1;
}

Piece_Data_Board::Piece_Data_Board(bool if_init)
{	
	if(if_init == true)
	{
		for(int x = 0; x < 8; x++)
		{
			data_board[x][0].if_exist = true;		
			data_board[x][1].if_exist = true;		
			data_board[x][2].if_exist = false;		
			data_board[x][3].if_exist = false;		
			data_board[x][4].if_exist = false;		
			data_board[x][5].if_exist = false;		
			data_board[x][6].if_exist = true;		
			data_board[x][7].if_exist = true;			

			data_board[x][0].color = Color::W;		
			data_board[x][1].color = Color::W;		
                    
			data_board[x][6].color = Color::B;		
			data_board[x][7].color = Color::B;		

			data_board[x][1].id = ID::P;
			data_board[x][6].id = ID::P;
		}

		data_board[0][0].id = ID::R;
		data_board[1][0].id = ID::N;
		data_board[2][0].id = ID::B;
		data_board[3][0].id = ID::Q;
		data_board[4][0].id = ID::K;
		data_board[5][0].id = ID::B;
		data_board[6][0].id = ID::N;
		data_board[7][0].id = ID::R;

		data_board[0][7].id = ID::R;
		data_board[1][7].id = ID::N;
		data_board[2][7].id = ID::B;
		data_board[3][7].id = ID::Q;
		data_board[4][7].id = ID::K;
		data_board[5][7].id = ID::B;
		data_board[6][7].id = ID::N;
		data_board[7][7].id = ID::R;
	}
}

