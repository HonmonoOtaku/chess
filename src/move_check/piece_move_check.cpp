#include "piece_move_check.h"

int piece_move_check::PieceMoveCheck(const Pos& orig_pos, const Pos& dest_pos, const Board& board)
{
	if(board.IfExist(orig_pos) == false)
		return -1;

	if( board.IfExist(dest_pos) == true )
		if( board.GetColor(dest_pos) == board.GetColor(orig_pos) )
			return -2;

	ID orig_id = board.GetID(orig_pos);
	
	switch(orig_id)
	{
	case ID::K:
			return KingMoveCheck(orig_pos, dest_pos, board);
	case ID::P:
			return PoneMoveCheck(orig_pos, dest_pos, board);
	case ID::N:
			return NightMoveCheck(orig_pos, dest_pos, board);
	default:
			return NormalMoveCheck(orig_pos, dest_pos, board);	
	}
	
	return 0;
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

	return 0;
}

int piece_move_check::PoneMoveCheck(const Pos& orig_pos, const Pos& dest_pos, const Board& board)
{
	Color orig_color = board.GetColor(orig_pos);
	
	//exception for Pone	
	
	if(orig_color == Color::W)
	{

	Pos up_right(orig_pos.x + 1, orig_pos.y + 1);
	Pos up_left(orig_pos.x - 1, orig_pos.y + 1);

	if(board.IfExist(up_right) == true && up_right== dest_pos && board.GetColor(up_right) != board.GetColor(orig_pos))
		return 0;

	if(board.IfExist(up_left) == true && up_left == dest_pos && board.GetColor(up_left) != board.GetColor(orig_pos))
		return 0;
	}

	else
	{

	Pos down_right(orig_pos.x + 1, orig_pos.y - 1);
	Pos down_left(orig_pos.x - 1, orig_pos.y - 1);

	if( board.IfExist(down_right) == true && down_right == dest_pos && board.GetColor(down_right) != board.GetColor(orig_pos) )
		return 0;

	if( board.IfExist(down_left) == true && down_left == dest_pos && board.GetColor(down_left) != board.GetColor(orig_pos) )
		return 0;
	}

		
	list<Pos> move_list;
	if(board.GetPieceMoveList(orig_pos, dest_pos, move_list) == 0)
		return 0;

	return -1;
}

int piece_move_check::NightMoveCheck(const Pos& orig_pos, const Pos& dest_pos, const Board& board)
{
	list<Pos> move_list;

	if(board.GetPieceMoveList(orig_pos, dest_pos, move_list) != 0)
		return -1;
	else 
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
	Pos king_pos;
	
	if(board.GetKingPos(king_color, king_pos) != 0)
		return King_State::DEAD;

	list<Pos> all_piece_pos;
	board.GetAllPiecePos(color::GetReverseColor(king_color), all_piece_pos);

	//erase ignore_pos piece
	if(ignore_pos != nullptr)
	{
		for(list<Pos>::iterator iter = all_piece_pos.begin(); iter != all_piece_pos.end(); ++iter)
				if((*iter) == *ignore_pos)
				{
					all_piece_pos.erase(iter);
					break;
				}
	}

	//check if king is check
	for(const Pos& i_pos : all_piece_pos)
	{
		list<Pos> move_list;
		if(board.GetPieceMoveList(i_pos, king_pos, move_list) == 0)
		{
			move_list.pop_back();
			move_list.pop_front();
			
			for(const Pos& j_pos : move_list)
				if(board.IfExist(j_pos) == true)
					goto FAILED;

				
			king_state = King_State::CHECK;
			break;
		}

		FAILED:;
	}

	if(king_state == King_State::CHECK)
	{
		int check_count = 0;
		int king_kill_event = 0;
		for(int x_1 = -1; x_1 < 2; x_1++)
			for(int y_1 = -1; y_1 < 2; y_1++)
			{
				if( !( 0 <= king_pos.x + x_1 && king_pos.x + x_1 <= 7  &&  0 <= king_pos.y + y_1 && king_pos.y + y_1 <= 7 ) )
					continue;
				
				if( board.IfExist(Pos(king_pos.x + x_1, king_pos.y + y_1)) == true)
					if(board.GetColor(Pos(king_pos.x + x_1, king_pos.y + y_1)) == king_color )
						continue;

				check_count++;
				for(const Pos& i_pos : all_piece_pos)
				{
					list<Pos> move_list;
					if(board.GetPieceMoveList(i_pos, Pos(king_pos.x + x_1, king_pos.y + y_1), move_list) == 0)
					{
						move_list.pop_back();
						move_list.pop_front();

						for(const Pos& j_pos : move_list)
							if(board.IfExist(j_pos) == true)
								goto FAILED_1;
						king_kill_event++;
					}
					FAILED_1:;
				}
			}

		if( check_count == king_kill_event)
			king_state = King_State::CHECKMATE;
	}

	return king_state;
}

int piece_move_check::GetKingAimPiece(const Color king_color, const Board& board, const Pos * ignore_pos, Pos& aim_pos)
{
	if(GetKingState(king_color, board, ignore_pos) != King_State::CHECK)
		return -1;


	Pos king_pos;
	board.GetKingPos(king_color, king_pos);

	list<Pos> all_piece_pos;
	board.GetAllPiecePos(color::GetReverseColor(king_color), all_piece_pos);

	for(const Pos& i_pos : all_piece_pos)
	{
		list<Pos> move_list;
		if(board.GetPieceMoveList(i_pos, king_pos, move_list) == 0)
		{
			move_list.pop_back();
			move_list.pop_front();
			
			for(const Pos& j_pos : move_list)
				if(board.IfExist(j_pos) == true)
					goto FAILED;

				
			aim_pos = i_pos;
			break;
		}

		FAILED:;
	}

	return 0;
}
