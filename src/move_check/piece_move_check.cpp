#include "piece_move_check.h"

int piece_move_check::PieceMoveCheck(const Pos& orig_pos, const Pos& dest_pos, const Board& board)
{
	if(board.IfExist(orig_pos) == false)
		return -1;

	ID orig_id = board.GetID(orig_pos);
	
	if(orig_id ==ID::K)
			return KingMoveCheck(orig_pos, dest_pos, board);
	else
			return NormalMoveCheck(orig_pos, dest_pos, board);	
	
}

int piece_move_check::NormalMoveCheck(const Pos& orig_pos, const Pos& dest_pos, const Board& board)
{
	list<Pos> move_list;
	if(board.GetPieceMoveList(orig_pos, dest_pos, move_list) != 0)
		return -1;

	move_list.pop_back();
	move_list.pop_front();
	if(move_list.size() != 0)
	{
	for(list<Pos>::const_iterator iter = move_list.begin(); iter != move_list.end(); ++iter)
		{
			if(board.IfExist(*iter) == true)
				return -2;
		}
	}

	if(board.IfExist(dest_pos) == true)
		if(board.GetColor(dest_pos) == board.GetColor(orig_pos))
			return -3;

	return 0;
}

int piece_move_check::KingMoveCheck(const Pos& orig_pos, const Pos& dest_pos,const Board& board) 
{
	Color king_color = board.GetColor(orig_pos);

	list<Pos> move_list;
	if(board.GetPieceMoveList(orig_pos, dest_pos, move_list) != 0)
		return -1;

	King_State king_state;

	if(board.IfExist(dest_pos) == true)
		king_state = GetKingState(king_color, board, &dest_pos);
	else
		king_state = GetKingState(king_color, board, nullptr);
			
	if(king_state != King_State::SAFE)
		return -2;

	return 0;
}

King_State piece_move_check::GetKingState(const Color king_color, const Board& board, const Pos * ignore_pos)
{
	King_State king_state = King_State::SAFE;
	Pos king_pos(0 ,0);
	
	board.GetKingPos(king_color, king_pos);

	list<Pos> all_piece_pos;
	board.GetAllPiecePos(color::GetReverseColor(king_color), all_piece_pos);

	if(ignore_pos != nullptr)
	{
		for(list<Pos>::iterator iter = all_piece_pos.begin(); iter != all_piece_pos.end(); ++iter)
				if((*iter) == *ignore_pos)
				{
					all_piece_pos.erase(iter);
					break;
				}
	}

	if(all_piece_pos.size() == 0)
		return King_State::ERROR;

	//check if king is check
	for(const Pos& i : all_piece_pos)
	{
		list<Pos> move_list;
		if(board.GetPieceMoveList(i, king_pos, move_list) == 0)
		{
			move_list.pop_back();
			move_list.pop_front();
			
			for(const Pos& i_1 : move_list)
				if(board.IfExist(i_1) == true)
					goto FAILED;

				
			king_state = King_State::CHECK;
			break;
		}

		FAILED: ;
	}

	if(king_state == King_State::CHECK)
	{
		for(int x_1 = -1; x_1 < 2; x_1++)
			for(int y_1 = -1; y_1 < 2; y_1++)
			{
				for(const Pos& i : all_piece_pos)
				{
					list<Pos> move_list;
					if(board.GetPieceMoveList(i, Pos(king_pos.x + x_1, king_pos.y + y_1), move_list) == 0)
					{
						move_list.pop_back();
						move_list.pop_front();

						for(const Pos& i_1 : move_list)
							if(board.IfExist(i_1) == true)
								goto FAILED_1;
					}

				}

			}

		king_state = King_State::CHECKMATE;

FAILED_1:;
			
	}

	
	
	return king_state;
}

