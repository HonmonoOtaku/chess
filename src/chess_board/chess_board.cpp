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



#endif //_CHESS_BOARD_CPP_
