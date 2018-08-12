#ifndef _CHESS_BOARD_H_
#define _CHESS_BOARD_H_

#include <iostream>

#include "../error_handle/error_handle.h"
#include "../chess_pieces/chess_pieces.h"

class Chess_Piece_Pointer
{	
public:
	Chess_Piece * m_piece;
	bool m_if_piece_exist;

	Chess_Piece_Pointer();
	Chess_Piece_Pointer(Chess_Piece * piece, const bool if_piece_exist);
};


class Chess_Board
{
private:	
	Chess_Piece_Pointer** m_chess_board;
		
public:
	Chess_Board();
	~Chess_Board();

	int ReturnPieceInfo(const Piece_Pos piece_pos,Chess_Piece_Identifier& chess_piece, Piece_Color& piece_color) const;
	bool IfPieceExist(const Piece_Pos piece_pos) const;
	int SearchPiece(const Chess_Piece_Identifier chess_piece, const Piece_Color piece_color, Piece_Pos& piece_pos) const;
	const Chess_Piece& ReturnPiece(const Piece_Pos piece_pos) const;
};

#endif //_CHESS_BOARD_H_
