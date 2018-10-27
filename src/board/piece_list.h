#ifndef _PIECE_DATA_LIST
#define _PIECE_DATA_LIST

#include "../piece/piece.h"
#include "../piece/each_piece.h"

#include <list>
#include <iostream>

#ifndef _U_
#define _U_
using namespace std;
#endif //_U_


class Piece_List
{
private:
	list<Piece *> piece_list;

public:
	Piece_List(const Color color);

	void PushBack(const Piece& input_piece);

	int Delete(const Pos& node_pos);

	int ChangePos(const Pos& change_pos, const Pos& pos);

	int GetPiece(const Pos& node_pos, Piece& return_piece) const;

	int GetPieceMoveList(const Pos& orig, const Pos& dest, list<Pos>& move_list) const;

	void GetAllPiecePos(list<Pos>& pos_list);

	void ShowList(void) const;

};

#endif // _PIECE_DATA_LIST


