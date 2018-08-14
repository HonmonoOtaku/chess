#ifndef _CHESS_GAME_PROCESS_H_
#define _CHESS_GAME_PROCESS_H_

#include "../chess_board/chess_board.h"
#include "../chess_pieces/chess_pieces.h"
#include "../chess_piece_move_check/chess_piece_move_check.h"
#include <vector>
#include <functional>

#include "../main/USING_NAMESPACE_STD.h"


class Chess_Game_Process : public Chess_Piece_Move_Check 
{
private:
	Chess_Board m_chess_board;
	vector<Chess_Piece*> m_white_pieces_list;
	vector<Chess_Piece*> m_black_pieces_list;
public:
	Chess_Game_Process();	
	~Chess_Game_Process();	

	int Move_Piece(const Piece_Pos cur_pos, const Piece_Pos destination_pos);	
	int SkipTrue(void);
};

#endif //_CHESS_GAME_PROCESS_H_
