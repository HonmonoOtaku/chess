#ifndef _CHESS_PIECES_H_
#define _CHESS_PIECES_H_

#include <iostream>
#include "../main/USING_NAMESPACE_STD.h"

enum Piece_Color
{
	WHITE = 1,
	BLACK = 0,
};

class Piece_Pos
{
public:
	int x;
	int y;

public:
	Piece_Pos(const unsigned int x, const unsigned int y);
	Piece_Pos();	

	Piece_Pos operator()(const int x, const int y);
};



class Chess_Piece
{
private:
	Piece_Color m_color;
	bool m_if_piece_exist;
	Piece_Pos m_piece_pos;
		
public:
	Chess_Piece(const Piece_Color m_color, const Piece_Pos& m_piece_pos);
};

#endif //_CHESS_PIECES_H_
