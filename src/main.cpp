#include <list>

#include  <iostream>
#include "./piece/pos.h"
#include "./piece/each_piece.h"

using namespace std;

int main(void)
{
	Piece * piece_p = new Queen(Color::W, Pos(3, 3));

	for(int x = 0; x < 8; x++)
		for(int y = 0; y < 8; y++)
		{
			list<Pos> move_list;
			move_list.clear();
			if(piece_p->GetMoveList(Pos(x, y), move_list) == 0)
			{
				list<Pos>::const_iterator end_pos = --(move_list.end());
				cout << "AllowPos : " << "(" << end_pos->x << "," << end_pos->y << ")" << endl;
				for(const auto i : move_list)
					cout << "####(" << i.x << "," << i.y << ")" << endl;
				cout << endl;
			}
		}
}
