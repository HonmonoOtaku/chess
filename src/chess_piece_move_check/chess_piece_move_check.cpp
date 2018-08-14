#include "chess_piece_move_check.h"


bool Chess_Piece_Move_Check::MoveAllow(const Piece_Pos origin_pos, const Piece_Pos destination_pos, const Chess_Board& chess_board) const
{
	vector<Piece_Pos> move_track_list;

	if(chess_board.m_chess_board[origin_pos.x][origin_pos.y].m_if_piece_exist == false)
		return -1;

	const Chess_Piece * origin_piece = chess_board.m_chess_board[origin_pos.x][origin_pos.y].m_piece;

	if(origin_piece->ReturnTrackList(destination_pos, move_track_list) == -1)
		return -1;	

	for(int i = 0; i < move_track_list.size() - 1; i++) // move_track_list.size() -1 becuase of end of the list
	{													// will be killed by piece			
		if(chess_board.IfPieceExist(move_track_list[i]) == false)
			return false;
	}
	
	return true;
}


