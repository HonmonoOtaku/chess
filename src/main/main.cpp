#include "../error_handle/error_handle.h"
#include "../chess_board/chess_board.h"
#include "../chess_pieces/chess_pieces.h"
#include "../chess_game_process/chess_game_process.h"

#include <vector>

#include "USING_NAMESPACE_STD.h"

int main(void)
{
	Chess_Game_Process chess_game;
	
	chess_game.Move_Piece(Piece_Pos(1, 1), Piece_Pos(1, 2));

	return 0;
}

