#include "chess_pieces.h"

Chess_Piece::Chess_Piece(const Piece_Color color, const Piece_Pos& piece_pos)
	:m_color(color), m_piece_pos(piece_pos)
{
	m_if_piece_exist = true;
}

Piece_Pos Chess_Piece::ReturnCurPos(void) const
{
	return m_piece_pos;
}

int Chess_Piece::ReturnTrackList(const Piece_Pos& destination_pos, vector<Piece_Pos>& move_track_list) const
{
	if(m_if_piece_exist == false)
		return -1;

	if(destination_pos == m_piece_pos)
		return -1;
	

	//y = ax + b
	// a counld be 0, 1 , -1
	int a = (destination_pos.x - m_piece_pos.x) / (destination_pos.y - m_piece_pos.x);
	int b = 0;
	
	move_track_list.clear();

	// exception of x = a function 
	if(a == 0 | destination_pos.x == m_piece_pos.x)
	{
		if(destination_pos.y > m_piece_pos.y)
		{
			for(int y = m_piece_pos.y; y <= destination_pos.y; y++)
				move_track_list.push_back(Piece_Pos((m_piece_pos.x), y));
		}
		else
		{
			for(int y = m_piece_pos.y; destination_pos.y <= y; y--)
				move_track_list.push_back(Piece_Pos((m_piece_pos.x), y));
		}

		return 0;
	}
	
	b = m_piece_pos.y - ( a * m_piece_pos.x);
	
	if(destination_pos.x > m_piece_pos.x)
	{
		for(int x = m_piece_pos.x; x <= destination_pos.x; x++)
			move_track_list.push_back(Piece_Pos(x, ( a * x + b)));
	}

	else
	{
		for(int x = m_piece_pos.x; destination_pos.x <= x; x++)
			move_track_list.push_back(Piece_Pos(x, ( a * x + b)));
	}
		
	return 0;
}

bool Chess_Piece::CheckPosRange(const Piece_Pos& input_pos) const
{
	if(input_pos.x < 0 | 7 < input_pos.x) 
		return false;
	 if(input_pos.y < 0 | 7 < input_pos.y)
		return false;

	 return true;
}

bool Chess_Piece::ReturnIfPieceExist(void) const
{
	return m_if_piece_exist;
}

bool Chess_Piece::ReturnIfPieceExist(void)
{
	return m_if_piece_exist;
}

King::King(const Piece_Color color, const Piece_Pos& piece_pos)
	:Chess_Piece(color, piece_pos)
{
	
}

King::King(const Piece_Color color, const Piece_Pos& piece_pos)
	:Chess_Piece(color, piece_pos)
{
	
}

int King::ReturnTrackList(const Piece_Pos& destination_pos, vector<Piece_Pos>& move_track_list) const
{
	
	const Piece_Pos cur_piece_pos = ReturnCurPos();

	if(ReturnIfPieceExist() == false)
		return -1;
	
	if(CheckPosRange(destination_pos) == false)
		return -1;

	if(abs(destination_pos.x - cur_piece_pos.x) > 1 | abs(destination_pos.y - cur_piece_pos.y) > 1)
		return -1;
	
	Chess_Piece::ReturnTrackList(destination_pos, move_track_list); 
	
	return 0;
}
















