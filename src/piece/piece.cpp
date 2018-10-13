#include "piece.h"

Piece::Piece(const ID id, const Color color, const Pos& pos)
	:m_color(color), m_id(id), m_pos(pos)
{
}

void Piece::SetPos(const Pos& dest)
{
	m_pos = dest;
}

ID Piece::GetID(void) const
{
	return m_id;
}

Color Piece::GetColor(void) const
{
	return m_color;
}

Pos Piece::GetPos(void) const
{
	return m_pos;
}
