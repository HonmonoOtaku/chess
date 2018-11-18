#include <list>

#include  <iostream>
#include "piece/pos.h"
#include "piece/each_piece.h"
#include "board/board.h"
#include "move_check/piece_move_check.h"
#include "tui/tui.h"

using namespace std;

int main(void)
{	
	Board chess_board;

	tui::Show_Board tui_board;

	for(int i = 0; i < 20; i++)
	{
		tui_board.ShowBoard();

		Pos orig_pos;
		Pos dest_pos;

		tui_board.SelectPos(orig_pos);
		tui_board.SelectPos(dest_pos);

		cout << "orig_pos : ( " << orig_pos.x << ", " << orig_pos.y << ")" << endl; 
		cout << "dest_pos : ( " << dest_pos.x << ", " << dest_pos.y << ")" << endl; 
	
		if(piece_move_check::PieceMoveCheck(orig_pos, dest_pos, chess_board) != 0)
		{
			std::cout << "wrong_move" << std::endl;	
			continue;
		}
		
		tui_board.MovePiece(orig_pos, dest_pos);
		chess_board.MovePiece(orig_pos, dest_pos);
		
	}

	int temp 	 = 0;
	std::cin >> temp;



	return 0;
}
