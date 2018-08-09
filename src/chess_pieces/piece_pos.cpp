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

bool operator==(const Piece_Pos& input_1, const Piece_Pos& input_2)
{
	if(input_1.x == input_2.x && input_1.y == input_2.y)
		return true;
	else
		return false;
}




