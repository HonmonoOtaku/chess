#include <list>

#include  <iostream>
#include "piece/pos.h"
#include "piece/each_piece.h"
#include "board/board.h"
#include "move_check/piece_move_check.h"

using namespace std;

int main(void)
{	
	Board chess_board;

	for(int x = 0; x < 8; x++)
		for(int y = 0; y < 2; y++)
			chess_board.DeletePiece(Pos(x, y));

	for(int x = 0; x < 8; x++)
		for(int y = 6; y < 8; y++)
			chess_board.DeletePiece(Pos(x, y));

	chess_board.AddPiece(ID::K, Pos(3, 0), Color::W);
	chess_board.AddPiece(ID::R, Pos(3, 7), Color::B);

	chess_board.ShowBoard();

	Piece_Data_Board data_board(false);
	chess_board.GetBoard(data_board);
	


	return 0;
}
