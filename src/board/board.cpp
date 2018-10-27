#include "board.h"


Board::Board()
	:w_piece_list(Color::W), b_piece_list(Color::B)
{
	for(int x = 0; x < 8; x++)
	{
		board[x][1] = new Pone(Color::W, Pos(x, 1));
		board[x][6] = new Pone(Color::B, Pos(x, 6));
	}

	board[0][0] = new Rook(Color::W, Pos(0, 0));
	board[1][0] = new Night(Color::W, Pos(1, 0));
	board[2][0] = new Bishop(Color::W, Pos(2, 0));
	board[3][0] = new Queen(Color::W, Pos(3, 0));
	board[4][0] = new King(Color::W, Pos(4, 0));
	board[5][0] = new Bishop(Color::W, Pos(5, 0));
	board[6][0] = new Night(Color::W, Pos(6, 0));
	board[7][0] = new Rook(Color::W, Pos(7, 0));

	board[0][7] = new Rook(Color::B, Pos(0, 7));
	board[1][7] = new Night(Color::B, Pos(1, 7));
	board[2][7] = new Bishop(Color::B, Pos(2, 7));
	board[3][7] = new Queen(Color::B, Pos(3, 7));
	board[4][7] = new King(Color::B, Pos(4, 7));
	board[5][7] = new Bishop(Color::B, Pos(5, 7));
	board[6][7] = new Night(Color::B, Pos(6, 7));
	board[7][7] = new Rook(Color::B, Pos(7, 7));

	for(int x = 0; x < 8; x++)
		for(int y = 2; y < 6; y++)
			board[x][y] = nullptr;

	cout << "hallo" << endl;
}

Board::~Board()
{
	if(board[0][5] == nullptr)
		cout << "hallo" << endl;

	for(int y = 0; y < 8; y++)
		for(int x = 0; x < 8; x++)
		{
			if(IfExist(Pos(x, y)) == true)
			{
				delete board[x][y];
			}
		}
}

bool Board::IfExist(const Pos& check_pos) const
{
	if(board[check_pos.x][check_pos.y] == nullptr)
		return false;
	else
		return true;
}

Color Board::GetColor(const Pos& get_pos) const
{
	return board[get_pos.x][get_pos.y]->GetColor();
}

ID Board::GetID(const Pos& get_pos) const
{
	return board[get_pos.x][get_pos.y]->GetID();
}


int Board::GetPieceMoveList(const Pos& orig_pos, const Pos& dest_pos, list<Pos> move_list) const
{
	if(IfExist(orig_pos) == false)
		return -1;
	
	if(board[orig_pos.x][orig_pos.y]->GetMoveList(dest_pos, move_list) != 0)
	{
		move_list.clear();
		return -2;
	}

	return 0;
}

void Board::GetAllPiecePos(const Color color, list<Pos> pos_list)
{
	GetPieceList(color).GetAllPiecePos(pos_list);
}

int Board::GetKingPos(const Color color, Pos& king_pos) const
{
	for(int x = 0; x < 8; x++)
		for(int y = 0; y < 8; y++)
		{
			if(board[x][y]->GetColor() == Color::W && board[x][y]->GetID() == ID::K)
			{
				king_pos = board[x][y]->GetPos();
				return 0;
			}
		}

	return -1;
}

int Board::MovePiece(const Pos& orig, const Pos& dest)
{
	if(IfExist(orig) == false)
		return -1;
		
	if(IfExist(dest) == true)
	{
		Color dest_color = GetColor(dest);

		GetPieceList(dest_color).Delete(dest);

		delete board[dest.x][dest.y];
	}

	board[dest.x][dest.y] = board[orig.x][orig.y];
	board[orig.x][orig.y] = nullptr;

	Color orig_color = GetColor(dest);

	GetPieceList(orig_color).ChangePos(dest, orig);

	return 0;
}


int Board::ShowBoard(void) const
{
	for(int y = 7; 0 <= y; y--)
	{
		cout << y << "   ";

		for(int x = 0; x < 8; x++)
		{
			if(IfExist(Pos(x, y)) == false)
				cout << "*";
			else
			{
				switch(GetID(Pos(x, y)))				
				{
					case ID::K:
						cout << "K";
						break;
					case ID::Q:
						cout << "Q";
						break;
					case ID::R:
						cout << "R";
						break;
					case ID::N:
						cout << "N";
						break;
					case ID::B:
						cout << "B";
						break;
					case ID::P:
						cout << "P";
						break;
				}
			}
			cout << " ";
		}
		cout << endl;
	}
		
	cout << "\n" << "    0 1 2 3 4 5 6 7" << endl;

	return 0;
}

