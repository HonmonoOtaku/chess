#ifndef _PIECE_H_
#define _PIECE_H_

#include "pos.h"

enum class Color
{
	W,
	B
};

enum class ID
{
	K,
	Q,
	N,
	R,
	B,
	P
};

class Piece
{
private:
	const Color m_color;
	const ID m_id;
	Pos m_pos;

public:
	Piece(const ID id, const Color color, const Pos& pos);

	void SetPos(const Pos& dest);

	ID getID(void) const;
	Color getColor(void) const;
	Pos getPos(void) const;


};

#endif // _PIECE_H_
