#include "chess_board.h"

Chess_Piece_Pointer::Chess_Piece_Pointer()
{
	m_piece = NULL;
	m_if_piece_exist = false;
}

Chess_Piece_Pointer::Chess_Piece_Pointer(Chess_Piece * piece, const bool if_piece_exist)
	:m_piece(piece), m_if_piece_exist(if_piece_exist)
{

}


