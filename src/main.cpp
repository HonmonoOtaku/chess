#include <list>

#include  <iostream>
#include "piece/pos.h"
#include "piece/each_piece.h"
#include "board/board.h"
#include "move_check/piece_move_check.h"
#include "tui/tui.h"
#include "chess/chess.h"

using namespace std;

int main(void)
{	
	Chess chess_board;

	tui::Show_Board tui_board;

	for(int i = 0; i < 30; i++)
	{
		tui_board.ShowBoard();

		Pos orig_pos;
		Pos dest_pos;

		tui_board.SelectPos(orig_pos);
		tui_board.SelectPos(dest_pos);

		int mv_result = chess_board.MovePiece(orig_pos, dest_pos);
		chess_board.ShowKingState();	
		if( mv_result == 0 )
		{
			tui_board.MovePiece(orig_pos, dest_pos);
			mvaddstr(0, 0, "correct_move\n");
		}
		else if(mv_result == 1)
		{
			addstr("game_finish\n");
			refresh();
			break;
		}
		else
			std::cout << "error_val : " << mv_result << std::endl;

		
	}
	
	
	int temp 	 = 0;
	std::cin >> temp;



	return 0;
}
