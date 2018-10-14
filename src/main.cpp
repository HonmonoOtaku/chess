#include <list>

#include  <iostream>
#include "piece/pos.h"
#include "piece/each_piece.h"
#include "board/board.h"

using namespace std;

int main(void)
{
	Board board;
	board.ShowBoard();

	while(true)
	{
		Pos orig;
		Pos dest;

		cout << "orig: ";
		cin >> orig.x >> orig.y;
		cout << "\n";
		cout << "dest: ";
		cin >> dest.x >> dest.y;
		cout << "\n";

		cout << "result :" << board.MovePiece(orig, dest) << endl;
		board.ShowBoard();
	}
}
