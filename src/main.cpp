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

	list<Pos> piece_list;
	chess_board.GetAllPiecePos(Color::W, piece_list);
	
//	cout << "white piece list" << endl;
//	for(const auto& i : piece_list)
//		cout << "(" << i.x << "," << i.y << ")" << endl;
//
//	chess_board.GetAllPiecePos(Color::B, piece_list);
//	cout << "black piece list" << endl;
//	for(const auto& i : piece_list)
//		cout << "(" << i.x << "," << i.y << ")" << endl;

	if(piece_move_check::GetKingState(Color::W, chess_board, nullptr) == King_State::CHECK)
		cout <<"OK" << endl;
	if(piece_move_check::GetKingState(Color::W, chess_board, nullptr) == King_State::SAFE)
		cout <<"OK1" << endl;


	return 0;
}
