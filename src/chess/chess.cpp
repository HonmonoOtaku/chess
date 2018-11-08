#include "chess.h"

Chess::Chess()
{
	w_king_state = King_State::SAFE;
	b_king_state = King_State::SAFE;
	GameTurn = 0;

}

int Chess::MovePiece(const Pos& orig_pos, const Pos& dest_pos)
{
	Color this_turn_color;
	if(GameTurn % 2 == 0)
		this_turn_color = Color::B;
	else
		this_turn_color = Color::W;

	if(board.GetColor(orig_pos) != this_turn_color)
		return -1;

	if(GetKingState(this_turn_color) != King_State::SAFE && board.GetID(orig_pos) != ID::K)
		return -2;

	int piece_move_check_result;
	piece_move_check_result = piece_move_check::PieceMoveCheck(orig_pos, dest_pos, board);
	if(piece_move_check_result != 0)
		return piece_move_check_result;

	board.MovePiece(orig_pos, dest_pos);
	
	GetReverseKingState(this_turn_color) = piece_move_check::GetKingState(this_turn_color, board, nullptr);

	if(GetReverseKingState(this_turn_color) == King_State::CHECKMATE)
		return 1;

	GameTurn++;
	return 0;
}

void Chess::ReturnBoard(Piece_Data_Board& data_board) const
{
	this->board.GetBoard(data_board);	
}
