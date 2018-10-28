#include "piece_list.h"


Piece_List::Piece_List(const Color color)
{
	if(color == Color::W)
	{
		piece_list.push_back(new Rook(Color::W, Pos(0, 0)));
		piece_list.push_back(new Night(Color::W, Pos(1, 0)));
		piece_list.push_back(new Bishop(Color::W, Pos(2,0 )));
		piece_list.push_back(new Queen(Color::W, Pos(3, 0)));
		piece_list.push_back(new King(Color::W, Pos(4, 0)));
		piece_list.push_back(new Bishop(Color::W, Pos(5,0)));
		piece_list.push_back(new Night(Color::W, Pos(6,0)));
		piece_list.push_back(new Rook(Color::W, Pos(7, 0)));
		piece_list.push_back(new Pone(Color::W, Pos(0, 1)));
		piece_list.push_back(new Pone(Color::W, Pos(1, 1)));
		piece_list.push_back(new Pone(Color::W, Pos(2, 1)));
		piece_list.push_back(new Pone(Color::W, Pos(3, 1)));
		piece_list.push_back(new Pone(Color::W, Pos(4, 1)));
		piece_list.push_back(new Pone(Color::W, Pos(5, 1)));
		piece_list.push_back(new Pone(Color::W, Pos(6, 1)));
		piece_list.push_back(new Pone(Color::W, Pos(7, 1)));
	}
	else
	{
		piece_list.push_back(new Rook(Color::B, Pos(0, 7)));
		piece_list.push_back(new Night(Color::B, Pos(1, 7)));
		piece_list.push_back(new Bishop(Color::B, Pos(2, 7)));
		piece_list.push_back(new Queen(Color::B, Pos(3, 7)));
		piece_list.push_back(new King(Color::B, Pos(4, 7)));
		piece_list.push_back(new Bishop(Color::B, Pos(5, 7)));
		piece_list.push_back(new Night(Color::B, Pos(6, 7)));
		piece_list.push_back(new Rook(Color::B, Pos(7, 7)));
		piece_list.push_back(new Pone(Color::B, Pos(0, 6)));
		piece_list.push_back(new Pone(Color::B, Pos(1, 6)));
		piece_list.push_back(new Pone(Color::B, Pos(2, 6)));
		piece_list.push_back(new Pone(Color::B, Pos(3, 6)));
		piece_list.push_back(new Pone(Color::B, Pos(4, 6)));
		piece_list.push_back(new Pone(Color::B, Pos(5, 6)));
		piece_list.push_back(new Pone(Color::B, Pos(6, 6)));
		piece_list.push_back(new Pone(Color::B, Pos(7, 6)));
	}
}

void Piece_List::PushBack(const Piece& input_piece)
{
	ID input_piece_id = input_piece.GetID();
	switch(input_piece_id)
	{
	case ID::K:
		piece_list.push_back(new King(input_piece.GetColor(), input_piece.GetPos()));
		break;
	case ID::Q:
		piece_list.push_back(new Queen(input_piece.GetColor(), input_piece.GetPos()));
		break;
	case ID::B:
		piece_list.push_back(new Bishop(input_piece.GetColor(), input_piece.GetPos()));
		break;
	case ID::N:
		piece_list.push_back(new Night(input_piece.GetColor(), input_piece.GetPos()));
		break;
	case ID::R:
		piece_list.push_back(new Rook(input_piece.GetColor(), input_piece.GetPos()));
		break;
	case ID::P:
		piece_list.push_back(new Pone(input_piece.GetColor(), input_piece.GetPos()));
		break;
	}
}

int Piece_List::Delete(const Pos& node_pos)
{
	for(list<Piece *>::iterator iter = piece_list.begin(); iter != piece_list.end(); ++iter)
	{
		if((*iter)->GetPos() == node_pos)
		{
			delete *iter;
			piece_list.erase(iter);
			return 0;
		}
	}

	return -1;
}

int Piece_List::ChangePos(const Pos& change_pos, const Pos& pos)
{
	for(list<Piece *>::iterator iter = piece_list.begin(); iter != piece_list.end(); ++iter)
	{
		if((*iter)->GetPos() == change_pos)
		{
			(*iter)->SetPos(change_pos);
			return 0;
		}
	}

	return -1;
}

int Piece_List::GetPieceMoveList(const Pos& orig, const Pos& dest, list<Pos>& move_list) const
{
	for(list<Piece *>::const_iterator iter = piece_list.begin(); iter != piece_list.end(); ++iter)
	{
		if((*iter)->GetPos() == orig)
		{
			(*iter)->GetMoveList(dest, move_list);
			return 0;
		}
	}

	return -1;
}

void Piece_List::GetAllPiecePos(list<Pos>& pos_list) const
{
	pos_list.clear();

	for(list<Piece *>::const_iterator iter = piece_list.begin(); iter != piece_list.end(); ++iter)
		pos_list.push_back((*iter)->GetPos());
		
}

void Piece_List::ShowList(void) const
{
	cout << "******list_data*****" << endl;
	cout << "lenght : " << piece_list.size() << endl;
	cout << "contents : ";
	for(auto& i : piece_list)
	{		
		ID piece_id = i->GetID();
		switch(piece_id)
		{
			case ID::K:
				cout << "K ";
				break;
			case ID::Q:
				cout << "Q ";
				break;
			case ID::N:
				cout << "N ";
				break;
			case ID::B:
				cout << "B ";
				break;
			case ID::P:
				cout << "P ";
				break;
			case ID::R:
				cout << "R ";
				break;
		}
	}

	cout << endl;
	
}



