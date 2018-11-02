#ifndef _PIECE_H_
#define _PIECE_H_

#include <list>
#include "pos.h"

#ifndef _U_
#define _U_
using namespace std;
#endif //_U_


enum class Color
{
	W,
	B
};

namespace color
{
	Color GetReverseColor(const Color color);
}

enum class ID
{
	K,
	Q,
	N,
	R,
	B,
	P
};

typedef struct Piece_Data
{
	Pos pos;
	ID id;
	Color color;
	bool if_exist;

}Piece_Data;

class Piece
{
private:
	const Color m_color;
	const ID m_id;
	Pos m_pos;

public:
	Piece(const ID id, const Color color, const Pos& pos);
	virtual ~Piece(){};

	void SetPos(const Pos& dest);

	ID GetID(void) const;
	Color GetColor(void) const;
	Pos GetPos(void) const;

	virtual int GetMoveList(const Pos& dest, list<Pos>& move_list) const = 0;
};

#endif // _PIECE_H_
