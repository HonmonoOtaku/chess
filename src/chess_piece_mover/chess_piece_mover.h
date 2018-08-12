#ifndef _CHESS_PIECE_MOVER_H_
#define _CHESS_PIECE_MOVER_H_

#include "../chess_pieces/chess_pieces.h"
#include "../chess_board/chess_board.h"
#include <vector>


class Chess_Piece_Mover
{
public:
	bool MoveAllow(const Chess_Piece_Identifier chess_piece, const Piece_Color piece_color, const Piece_Pos destination_pos, const Chess_Board& chess_board) const;
};

#endif //_CHESS_PIECE_MOVER_H_
