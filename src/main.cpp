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

	Show_Board show_board;

	for(int i = 0; i < 9; i++)
	{
		show_board.ShowBoard();
		Pos orig_pos;
		Pos dest_pos;
		show_board.SelectPos(orig_pos);
		show_board.SelectPos(dest_pos);
		show_board.MovePiece(orig_pos, dest_pos);
	}


	int temp = 0;
	cin >> temp;
	


	return 0;
}
