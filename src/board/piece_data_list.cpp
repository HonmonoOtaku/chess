#include "piece_data_list.h"

Piece_Data::Piece_Data(const Pos& pos, const ID id)
	:pos(pos), id(id)
{
}

Piece_Data_List::Piece_Data_List(const Color color)
{
	if(color == Color::W)
	{
		piece_data_list.push_back(Piece_Data(Pos(0, 0),ID::R));
		piece_data_list.push_back(Piece_Data(Pos(0, 1),ID::N));
		piece_data_list.push_back(Piece_Data(Pos(0, 2),ID::B));
		piece_data_list.push_back(Piece_Data(Pos(0, 3),ID::Q));
		piece_data_list.push_back(Piece_Data(Pos(0, 4),ID::K));
		piece_data_list.push_back(Piece_Data(Pos(0, 5),ID::B));
		piece_data_list.push_back(Piece_Data(Pos(0, 6),ID::N));
		piece_data_list.push_back(Piece_Data(Pos(0, 7),ID::R));
		piece_data_list.push_back(Piece_Data(Pos(1, 0),ID::P));
		piece_data_list.push_back(Piece_Data(Pos(1, 1),ID::P));
		piece_data_list.push_back(Piece_Data(Pos(1, 2),ID::P));
		piece_data_list.push_back(Piece_Data(Pos(1, 3),ID::P));
		piece_data_list.push_back(Piece_Data(Pos(1, 4),ID::P));
		piece_data_list.push_back(Piece_Data(Pos(1, 5),ID::P));
		piece_data_list.push_back(Piece_Data(Pos(1, 6),ID::P));
		piece_data_list.push_back(Piece_Data(Pos(1, 7),ID::P));
	}
	else
	{
		piece_data_list.push_back(Piece_Data(Pos(7, 0),ID::R));
		piece_data_list.push_back(Piece_Data(Pos(7, 1),ID::N));
		piece_data_list.push_back(Piece_Data(Pos(7, 2),ID::B));
		piece_data_list.push_back(Piece_Data(Pos(7, 3),ID::Q));
		piece_data_list.push_back(Piece_Data(Pos(7, 4),ID::K));
		piece_data_list.push_back(Piece_Data(Pos(7, 5),ID::B));
		piece_data_list.push_back(Piece_Data(Pos(7, 6),ID::N));
		piece_data_list.push_back(Piece_Data(Pos(7, 7),ID::R));
		piece_data_list.push_back(Piece_Data(Pos(6, 0),ID::P));
		piece_data_list.push_back(Piece_Data(Pos(6, 1),ID::P));
		piece_data_list.push_back(Piece_Data(Pos(6, 2),ID::P));
		piece_data_list.push_back(Piece_Data(Pos(6, 3),ID::P));
		piece_data_list.push_back(Piece_Data(Pos(6, 4),ID::P));
		piece_data_list.push_back(Piece_Data(Pos(6, 5),ID::P));
		piece_data_list.push_back(Piece_Data(Pos(6, 6),ID::P));
		piece_data_list.push_back(Piece_Data(Pos(6, 7),ID::P));
	}
}

void Piece_Data_List::PushBack(const Piece_Data& node)
{
	piece_data_list.push_back(node);
}

int Piece_Data_List::Delete(const Pos& node_pos)
{
	for(list<Piece_Data>::iterator iter = piece_data_list.begin(); iter != piece_data_list.end(); ++iter)
	{
		if(iter->pos == node_pos)
		{
			piece_data_list.erase(iter);
			return 0;
		}
	}

	return -1;
}

int Piece_Data_List::ChangePos(const Pos& change_pos, const Pos& pos)
{
	for(list<Piece_Data>::iterator iter = piece_data_list.begin(); iter != piece_data_list.end(); ++iter)
	{
		if(iter->pos == change_pos)
		{
			iter->pos = change_pos;
			return 0;
		}
	}

	return -1;
}

int Piece_Data_List::ChangeId(const Pos& change_pos, const ID id)
{
	for(list<Piece_Data>::iterator iter = piece_data_list.begin(); iter != piece_data_list.end(); ++iter)
	{
		if(iter->pos == change_pos)
		{
			iter->id = id;
			return 0;
		}
	}

	return -1;
}

int Piece_Data_List::GetNode(const Pos& node_pos, Piece_Data& return_node) const
{
	for(list<Piece_Data>::const_iterator iter = piece_data_list.begin(); iter != piece_data_list.end(); ++iter)
	{
		if(iter->pos == node_pos)
		{
			return_node = *iter;
			return 0;
		}
	}

	return -1;
}

void Piece_Data_List::ShowList(void) const
{
	cout << "******list_data*****" << endl;
	cout << "lenght : " << piece_data_list.size() << endl;
	cout << "contents : ";
	for(auto& i : piece_data_list)
	{
		switch(i.id)
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

void Piece_Data_List::GetList(list<Piece_Data>& piece_data_list) const
{
	piece_data_list = this->piece_data_list;
}

