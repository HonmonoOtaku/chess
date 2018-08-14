#ifndef _CHESS_PIECE_MOVER_H_
#define _CHESS_PIECE_MOVER_H_

#include "../chess_pieces/chess_pieces.h"
#include "../chess_board/chess_board.h"
#include <vector>


class Chess_Piece_Move_Check
{
public:
	bool MoveAllow(const Piece_Pos origin_pos, const Piece_Pos destination_pos, const Chess_Board& chess_board) const;
};

#endif //_CHESS_PIECE_MOVER_H_
