#ifndef _PIECE_DATA_LIST
#define _PIECE_DATA_LIST

#include "../piece/piece.h"

#include <list>
#include <iostream>

#ifndef _U_
#define _U_
using namespace std;
#endif //_U_

typedef struct Piece_Data
{
	Pos pos;
	ID id;
	
	Piece_Data(const Pos& pos, const ID id);
}Piece_Data;

class Piece_Data_List
{
private:
	list<Piece_Data> piece_data_list;

public:
	Piece_Data_List(const Color color);
	void PushBack(const Piece_Data& node);
	int Delete(const Pos& node_pos);
	int ChangePos(const Pos& change_pos, const Pos& pos);
	int ChangeId(const Pos& change_pos, const ID id);
	int GetNode(const Pos& node_pos, Piece_Data& return_node) const;
	void ShowList(void) const;

	void GetList(list<Piece_Data>& piece_data_list) const;
};

#endif // _PIECE_DATA_LIST


