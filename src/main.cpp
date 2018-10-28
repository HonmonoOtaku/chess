#include <list>

#include  <iostream>
#include "piece/pos.h"
#include "piece/each_piece.h"
#include "board/board.h"
#include "move_check/piece_move_check.h"

using namespace std;

int main(void)
{	
	Board chess_board;
	list<Pos> move_list;
	cout << "(0, 1) -> (0,  2) result : "  << piece_move_check::PieceMoveCheck(Pos(0, 1), Pos(0, 2), chess_board) << endl;
	cout << "result : " << chess_board.GetPieceMoveList(Pos(0, 1) , Pos(0, 2), move_list) << endl;
	return 0;

}
