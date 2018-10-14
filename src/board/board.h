#ifndef _BOARD_H_
#define _BOARD_H_

#include "../piece/piece.h"
#include "../piece/each_piece.h"

#include <list>
#include <iostream>

#ifndef _U_
#define _U_
using namespace std;
#endif //_U_

class Board
{
private:
	Piece * board[8][8];

public:
	Board();
	~Board();

	bool IfExist(const Pos& check_pos) const;
	Color GetColor(const Pos& get_pos) const;
	ID GetID(const Pos& get_pos) const;

	int MovePiece(const Pos& orig, const Pos& dest);
	int ShowBoard(void) const;
};

#endif // _BOARD_H_
