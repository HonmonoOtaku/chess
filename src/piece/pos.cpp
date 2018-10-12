#include "pos.h"

Pos::Pos(const unsigned int x, const unsigned int y)
	:x(x), y(y)
{
}

Pos::Pos()
	:x(0), y(0)
{
}

bool Pos::operator==(const Pos& rhs) const
{
	return (rhs.x == this->x && rhs.y == this->y);
}

bool Pos::operator!=(const Pos& rhs) const
{
	return !(this->operator==(rhs));
}
