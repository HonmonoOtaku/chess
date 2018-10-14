#ifndef _EACH_PIECE_H_
#define _EACH_PIECE_H_

#include <cmath>
#include <list>

#include "piece.h"
#include "pos.h"

#ifndef _U_
#define _U_
using namespace std;
#endif //_U_

enum class Slope
{
	VERTICAL,
	HORIZONTAL,
	UPRIGHT,
	DOWNRIGHT,
	ELSE
};	
	
Slope GetSlop(const Pos& orig, const Pos& dest);


class King : public Piece
{
public:
	King(const Color color, const Pos& pos);
	virtual ~King(){};
	virtual int GetMoveList(const Pos& dest, list<Pos>& move_list) const;
			
};

class Queen : public Piece
{
public:
	Queen(const Color color, const Pos& pos);
	virtual ~Queen(){};
	virtual int GetMoveList(const Pos& dest, list<Pos>& move_list) const;
			
};

class Rook : public Piece
{
public:
	Rook(const Color color, const Pos& pos);
	virtual ~Rook(){};
	virtual int GetMoveList(const Pos& dest, list<Pos>& move_list) const;
			
};

class Night : public Piece
{
public:
	Night(const Color color, const Pos& pos);
	virtual ~Night(){};
	virtual int GetMoveList(const Pos& dest, list<Pos>& move_list) const;
			
};

class Bishop : public Piece
{
public:
	Bishop(const Color color, const Pos& pos);
	virtual ~Bishop(){};
	virtual int GetMoveList(const Pos& dest, list<Pos>& move_list) const;
			
};

class Pone : public Piece
{
public:
	Pone(const Color color, const Pos& pos);
	virtual ~Pone(){};
	virtual int GetMoveList(const Pos& dest, list<Pos>& move_list) const;
			
};

#endif // _EACH_PIECE_H_
