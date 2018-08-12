#ifndef _CHESS_PIECES_H_
#define _CHESS_PIECES_H_

#include <iostream>
#include <vector>
#include <cmath> // for abs function
#include "../main/USING_NAMESPACE_STD.h"

enum class Piece_Color
{
	WHITE = 1,
	BLACK = 0,
};

enum class Chess_Piece_Identifier
{
	QUEEN,
	KING,
	ROOK,
	NIGHT,
	BISHOP,
	PONE
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
	friend bool operator==(const Piece_Pos&, const Piece_Pos&);
};

bool operator==(const Piece_Pos& x, const Piece_Pos& y); 

class Chess_Piece
{
private:
	Piece_Color m_color;
	bool m_if_piece_exist;
	Piece_Pos m_piece_pos;
	Chess_Piece_Identifier m_piece_identifier;

protected:
	Piece_Pos  ReturnCurPos(void) const;
		
public:
	Chess_Piece(const Piece_Color color, const Piece_Pos& piece_pos, const Chess_Piece_Identifier piece_name);	

	
	virtual int ReturnTrackList(const Piece_Pos& destination_pos, vector<Piece_Pos>& move_track_list) const;
	bool CheckPosRange(const Piece_Pos& input_pos) const;

	bool ReturnIfPieceExist(void) const;
	bool ReturnIfPieceExist(void);
	Chess_Piece_Identifier ReturnPieceIdentifier(void) const;
	Piece_Color ReturnPieceColor(void) const;	
};


class King : public Chess_Piece
{
public:
	King(const Piece_Color color, const Piece_Pos& piece_pos, const Chess_Piece_Identifier piece_name);
	virtual int ReturnTrackList(const Piece_Pos& destination_pos, vector<Piece_Pos>& move_track_list) const;
};


class Queen : public Chess_Piece
{
public:
	Queen(const Piece_Color color, const Piece_Pos& piece_pos, const Chess_Piece_Identifier piece_name);
	virtual int ReturnTrackList(const Piece_Pos& destination_pos, vector<Piece_Pos>& move_track_list) const;
};


class Pone : public Chess_Piece
{

public:
	Pone(const Piece_Color color, const Piece_Pos& piece_pos, const Chess_Piece_Identifier piece_name);
	virtual int ReturnTrackList(const Piece_Pos& destination_pos, vector<Piece_Pos>& move_track_list) const;
};


class Night : public Chess_Piece
{
public:
	Night(const Piece_Color color, const Piece_Pos& piece_pos, const Chess_Piece_Identifier piece_name);
	virtual int ReturnTrackList(const Piece_Pos& destination_pos, vector<Piece_Pos>& move_track_list) const;
};


class Bishop : public Chess_Piece
{
public:
	Bishop(const Piece_Color color, const Piece_Pos& piece_pos, const Chess_Piece_Identifier piece_name);
	virtual int ReturnTrackList(const Piece_Pos& destination_pos, vector<Piece_Pos>& move_track_list) const;
};


class Rook : public Chess_Piece
{
public:
	Rook(const Piece_Color color, const Piece_Pos& piece_pos, const Chess_Piece_Identifier piece_name);
	virtual int ReturnTrackList(const Piece_Pos& destination_pos, vector<Piece_Pos>& move_track_list) const;
};






















#endif //_CHESS_PIECES_H_
