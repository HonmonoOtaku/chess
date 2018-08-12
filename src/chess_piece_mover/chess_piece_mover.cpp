#include "chess_piece_mover.h"


bool Chess_Piece_Mover::MoveAllow(const Chess_Piece_Identifier chess_piece, const Piece_Color piece_color, const Piece_Pos destination_pos, const Chess_Board& chess_board) const
{
	Piece_Pos piece_pos;
	vector<Piece_Pos> move_track_list;

	if(chess_board.SearchPiece(chess_piece, piece_color, piece_pos) == -1)
		return -1;
	if(chess_board.ReturnPiece(destination_pos).ReturnTrackList(destination_pos, move_track_list) == -1)
		return -1;
	


	for(int i = 0; i < move_track_list.size(); i++)
	{
		if(chess_board.IfPieceExist(move_track_list[i]) == false)
			return -1;
	}
	
	return 0;
}


