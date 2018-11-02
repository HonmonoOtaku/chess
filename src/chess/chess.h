#ifndef _CHESS_H_
#define _CHESS_H_

#include "../board/board.h"
#include "../move_check/piece_move_check.h"

class Chess
{
private:
	Board board;
	unsigned int GameTurn;
	
	mutable King_State w_king_state;
	mutable King_State b_king_state;

	inline King_State& GetKingState(const Color king_color) const;
	inline King_State& GetReverseKingState(const Color king_color) const;


public:
	Chess();	

	int MovePiece(const Pos& orig_pos, const Pos& dest_pos);
	void ReturnBoard(Piece_Data chess_board[][8]) const;
};

inline King_State& Chess::GetKingState(const Color king_color) const
{
	if(king_color == Color::W)
		return w_king_state;
	else
		return b_king_state;
}

inline King_State& Chess::GetReverseKingState(const Color king_color) const
{
	if(king_color == Color::B)
		return w_king_state;
	else
		return b_king_state;
}

#endif // _CHESS_H_
