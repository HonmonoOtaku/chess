#ifndef _CHESS_BOARD_CPP_
#define _CHESS_BOARD_CPP_

#include "chess_board.h"

Chess_Board::Chess_Board()
{
	//vertical 
	m_chess_board = new Chess_Piece_Pointer*[8];
	//horizontal
	for(int i = 0; i < 8; i++)
		m_chess_board[i] = new Chess_Piece_Pointer[8];	
}

Chess_Board::~Chess_Board()
{
	//delete horizontal
	for(int i = 0; i < 8; i++)
		delete[] m_chess_board[i];

	delete[] m_chess_board;
}

int Chess_Board::ReturnPieceInfo(const Piece_Pos piece_pos,Chess_Piece_Identifier& chess_piece, Piece_Color& piece_color) const
{
	if(piece_pos.x < 0 | 7 < piece_pos.x)
		return -1;
	if(piece_pos.y < 0 | 7 < piece_pos.y)
		return -1;

	if(m_chess_board[piece_pos.x][piece_pos.y].m_if_piece_exist == false)
		return -1;

	chess_piece = m_chess_board[piece_pos.x][piece_pos.y].m_piece->ReturnPieceIdentifier();
	piece_color = m_chess_board[piece_pos.x][piece_pos.y].m_piece->ReturnPieceColor();
	
	return 0;
}

bool Chess_Board::IfPieceExist(const Piece_Pos piece_pos) const
{
	return m_chess_board[piece_pos.x][piece_pos.y].m_if_piece_exist;
}

int Chess_Board::SearchPiece(const Chess_Piece_Identifier chess_piece, const Piece_Color piece_color, Piece_Pos& piece_pos) const
{
	for(int x = 0; x < 8; x++)
	{
		for(int y = 0; y < 8; y++)
		{
			if(m_chess_board[x][y].m_if_piece_exist == false)
				continue;	
			
			if(m_chess_board[x][y].m_piece->ReturnPieceColor() != piece_color)
				continue;
			if(m_chess_board[x][y].m_piece->ReturnPieceIdentifier() != chess_piece)
				continue;

			piece_pos = Piece_Pos(x, y);
			return 0;//if this piece satisfied all condition
		}
	}

	return -1;
}


const Chess_Piece& Chess_Board::ReturnPiece(const Piece_Pos piece_pos) const
{
	return *(m_chess_board[piece_pos.x][piece_pos.y].m_piece);
}

ostream& operator<<(ostream& os, const Chess_Board& chess_board)
{
	Chess_Piece_Identifier piece_name = Chess_Piece_Identifier::PONE;
	os << "****chess_board*****" << endl;
	for(int y = 0; y < 8; y++)
	{
		for(int x = 0; x < 8; x++)
		{
			if(chess_board.m_chess_board[x][y].m_if_piece_exist == false)
				cout << "*";
			else
			{
				piece_name = chess_board.m_chess_board[x][y].m_piece->ReturnPieceIdentifier();
				switch(piece_name)
				{
					case Chess_Piece_Identifier::PONE:
						cout << "p";
						break;
					case Chess_Piece_Identifier::NIGHT:
						cout << "n";
						break;
					case Chess_Piece_Identifier::BISHOP:
						cout << "b";
						break;
					case Chess_Piece_Identifier::ROOK:
						cout << "r";
						break;
					case Chess_Piece_Identifier::QUEEN:
						cout << "Q";
						break;
					case Chess_Piece_Identifier::KING:
						cout << "K";
						break;
					default:
						cout << "error" << endl;
				}
			}
		}

		cout << endl;
	}
	cout << "*****chess_board*****" << endl;
	return os;
}





#endif //_CHESS_BOARD_CPP_
