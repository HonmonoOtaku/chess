#ifndef _PIECE_MOVE_CHECK_LIST_H_
#define _PIECE_MOVE_CHECK_LIST_H_

#include "../board/board.h"
#include "../board/piece_list.h"
#include <list>


#ifndef _U_
#define _U_
using namespace std;
#endif //_U_

enum class King_State
{
	SAFE,
	CHECK,
	CHECKMATE
};

namespace piece_move_check
{
	King_State GetKingState(const Color king_color, const Board& board);;
	int KingMoveCheck(const Pos& orig_pos, const Pos& dest_pos, const Board& board); 
	King_State GetKingState(const Color king_color, const Board& board, const Pos * ignore_pos); 
	int NormalMoveCheck(const Pos& orig_pos, const Pos& dest_pos, const Board& board); 
	int PieceMoveCheck(const Pos& orig_pos, const Pos& dest_pos, const Board& board); 

}

#endif // _PIECE_MOVE_CHECK_LIST_H_
