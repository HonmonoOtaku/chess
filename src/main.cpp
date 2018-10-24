#include <list>

#include  <iostream>
#include "piece/pos.h"
#include "piece/each_piece.h"
#include "board/board.h"
#include "board/piece_data_list.h"

using namespace std;

int main(void)
{
	Piece_Data_List data_list(Color::W);
	data_list.Delete(Pos(0 ,0));
	data_list.ShowList();

	return 0;

}
