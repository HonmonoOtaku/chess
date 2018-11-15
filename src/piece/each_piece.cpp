#include "each_piece.h"

Slope GetSlope(const Pos& orig, const Pos& dest)
{
	if(orig.x - dest.x == 0)
		return Slope::VERTICAL;

	double slope = (dest.y - orig.y) / (double)(dest.x - orig.x);
	
	if(slope == 1)
		return Slope::UPRIGHT;
	if(slope == -1)
		return Slope::DOWNRIGHT;
	if(slope == 0)
		return Slope::HORIZONTAL;
	else
		return Slope::ELSE; 
}

King::King(const Color color, const Pos& pos)
	:Piece(ID::K, color, pos)
{
}

Queen::Queen(const Color color, const Pos& pos)
	:Piece(ID::Q, color, pos)
{
}

Rook::Rook(const Color color, const Pos& pos)
	:Piece(ID::R, color, pos)
{
}

Night::Night(const Color color, const Pos& pos)
	:Piece(ID::N, color, pos)
{
}

Bishop::Bishop(const Color color, const Pos& pos)
	:Piece(ID::B, color, pos)
{
}

Pone::Pone(const Color color, const Pos& pos)
	:Piece(ID::P, color, pos)
{
}


int King::GetMoveList(const Pos& dest, list<Pos>& move_list) const
{
	if( !(abs(dest.x - GetPos().x) <= 1 && abs(dest.y - GetPos().y) <= 1) )
		return -1;
	
	move_list.push_back(GetPos());
	move_list.push_back(dest);	

	return 0;
}

int Queen::GetMoveList(const Pos& dest, list<Pos>& move_list) const
{
	Slope slope = GetSlope(GetPos(), dest);

	if(slope == Slope::ELSE)
		return -1;
	
	if(slope == Slope::VERTICAL)
	{	
			for(int y = GetPos().y; y != dest.y; y += (abs(dest.y - GetPos().y) / (dest.y - GetPos().y)) )
				move_list.push_back(Pos(dest.x, y));

			move_list.push_back(dest);
			return 0;
	}

	//y = ax + b
	int a = (dest.y - GetPos().y) / (dest.x - GetPos().x);
	int b = dest.y - a * dest.x;

	for(int x = GetPos().x; x != dest.x; x += (abs(dest.x - GetPos().x) / (dest.x - GetPos().x)) )
		move_list.push_back(Pos(x, a * x + b));

	move_list.push_back(dest);

	return 0;
}


int Rook::GetMoveList(const Pos& dest, list<Pos>& move_list) const
{
	Slope slope = GetSlope(GetPos(), dest);

	switch(slope)
	{
		case Slope::HORIZONTAL:
			for(int x = GetPos().x; x != dest.x; x += (abs(dest.x - GetPos().x) / (dest.x - GetPos().x)) )
				move_list.push_back(Pos(x, dest.y));

			move_list.push_back(dest);
		break;

		case Slope::VERTICAL:
			for(int y = GetPos().y; y != dest.y; y += (abs(dest.y - GetPos().y) / (dest.y - GetPos().y)) )
				move_list.push_back(Pos(dest.x, y));

			move_list.push_back(dest);
		break;

		default:
			return -1;
	}

	return 0;
}


int Bishop::GetMoveList(const Pos& dest, list<Pos>& move_list) const
{
	Slope slope = GetSlope(GetPos(), dest);

	//y = ax + b
	int a = 0, b = 0;

	switch(slope)
	{
		case Slope::UPRIGHT:
			a = 1;
			b = dest.y - dest.x;

			for(int x = GetPos().x; x != dest.x; x += (abs(dest.x - GetPos().x) / (dest.x - GetPos().x)) )
				move_list.push_back(Pos(x, a * x + b));

			move_list.push_back(dest);
		break;

		case Slope::DOWNRIGHT:
			a = -1;
			b = dest.y + dest.x;

			for(int x = GetPos().x; x != dest.x; x += (abs(dest.x - GetPos().x) / (dest.x - GetPos().x)) )
				move_list.push_back(Pos(x, a * x + b));

			move_list.push_back(dest);
		break;

		default:
			return -1;
	}

	return 0;

}

int Night::GetMoveList(const Pos& dest, list<Pos>& move_list) const
{
	//second move_list is not important so push any pos
	if(!( (abs(dest.x - GetPos().x) == 1 && abs(dest.y - GetPos().y) == 2) |
			(abs(dest.x - GetPos().x) == 2 && abs(dest.y - GetPos().y) == 1) ))
	return -1;

	move_list.push_back(GetPos());
	move_list.push_back(Pos(0, 0)); // not important
	move_list.push_back(dest);

	return 0;
}

int Pone::GetMoveList(const Pos& dest, list<Pos>& move_list) const
{
	if( (GetColor() == Color::W && dest.y == 4 && GetPos().y == 6 && (dest.x - GetPos().x == 0)) |
			(GetColor() == Color::B && dest.y == 1 && GetPos().y == 3 && (dest.x - GetPos().x == 0)) )
	{	
		move_list.push_back(GetPos());
		move_list.push_back(Pos(GetPos().x, (GetPos().y + dest.y)/2));	
		move_list.push_back(dest);
	}

	else if((GetColor() == Color::W && (dest.y - GetPos().y == 1) && dest.x == GetPos().x) |
		 (GetColor() == Color::B && (GetPos().y - dest.y == 1) && dest.x == GetPos().x) )
	{
		move_list.push_back(GetPos());
		move_list.push_back(dest);
	}
	
	else
		return -1;

	return 0;
}	

