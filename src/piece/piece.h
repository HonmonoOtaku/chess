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
	B,
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

namespace id
{
	char IDtoChar(const ID id);
}

typedef struct Piece_Data
{
	Pos pos;
	ID id;
	Color color;

	Piece_Data();
	Piece_Data(const Pos& init_pos, const ID init_id, const Color init_color);

}Piece_Data;

typedef struct Piece_Data_Board_Node : Piece_Data
{
	bool if_exist;

	Piece_Data_Board_Node();
	Piece_Data_Board_Node(const bool if_exist ,const Pos& init_pos, const ID init_id, const Color init_color);
		
}Piece_Data_Board_Node;

typedef struct Piece_Data_Board
{
	Piece_Data_Board_Node data_board[8][8];

	Piece_Data_Board(bool if_init);

}Piece_Data_Board;


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
