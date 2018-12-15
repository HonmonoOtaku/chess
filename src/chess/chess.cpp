#include "chess.h"

Chess::Chess()
{
	w_king_state = King_State::SAFE;
	b_king_state = King_State::SAFE;
	GameTurn = 1;

}

int Chess::MovePiece(const Pos& orig_pos, const Pos& dest_pos)
{
	//get this_turn_color 
	Color this_turn_color;
	if(GameTurn % 2 == 0)
		this_turn_color = Color::B;
	else
		this_turn_color = Color::W;

	if(board.IfExist(orig_pos) == false)
		return -1;

	//check color
	if(board.GetColor(orig_pos) != this_turn_color)
		return -2;

	//check our king state
	if(GetKingState(this_turn_color) == King_State::CHECK)
	{
		bool flage_1 = false;
		Pos king_aim_pos(0, 0);

		if( board.GetID(orig_pos) == ID::K )
			flage_1 = true;
		else if( ( piece_move_check::GetKingAimPiece(color::GetReverseColor(this_turn_color), board, nullptr, king_aim_pos) != 0 ) && ( king_aim_pos == dest_pos ) )
			flage_1 = true;

		if( flage_1 == false )
			return -3;
	}

	//move piece
	int mv_check_result = piece_move_check::PieceMoveCheck(orig_pos, dest_pos, board);
	if(mv_check_result != 0)
		return mv_check_result;

	board.MovePiece(orig_pos, dest_pos);
	
	GetReverseKingState(this_turn_color) = piece_move_check::GetKingState(color::GetReverseColor(this_turn_color), board, nullptr);

	if( GetReverseKingState(this_turn_color) == King_State::CHECKMATE )
		return 1;

	else if( GetReverseKingState(this_turn_color) == King_State::DEAD )
		return 2;

	GameTurn++;
	return 0;
}

void Chess::ReturnBoard(Piece_Data_Board& data_board) const
{
	this->board.GetBoard(data_board);	
}

void Chess::ShowKingState(void) const
{
	switch(b_king_state)
	{
		case King_State::SAFE:
			mvaddstr(2,0, "b_king_state : safe");
			break;
		case King_State::CHECK:
			mvaddstr(2,0, "b_king_state : check");
			break;
		case King_State::CHECKMATE:
			mvaddstr(2,0, "b_king_state : checkmate");
			break;
		default:
			mvaddstr(2,0, "default");
	}

	switch(w_king_state)
	{
		case King_State::SAFE:
			mvaddstr(3,0, "w_king_state : safe");
			break;
		case King_State::CHECK:
			mvaddstr(3,0, "w_king_state : check");
			break;
		case King_State::CHECKMATE:
			mvaddstr(3,0, "w_king_state : checkmate");
			break;
		default:
			mvaddstr(3,0, "default");
	}
}
