#include "chess_pieces.h"

Piece_Pos::Piece_Pos(const unsigned int x, const unsigned int y)
	:x(x), y(y)
{
}

Piece_Pos::Piece_Pos()
{
	x = 0;
	y = 0;
}

Piece_Pos Piece_Pos::operator()(const int x, const int y)
{
	this->x = x;
	this->y = y;

	return *this;
}

Chess_Piece::Chess_Piece(const Piece_Color color, const Piece_Pos& piece_pos)
	:m_color(color), m_piece_pos(piece_pos)
{
	m_if_piece_exist = true;
}
