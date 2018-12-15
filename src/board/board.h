#ifndef _BOARD_H_
#define _BOARD_H_

#include "../piece/piece.h"
#include "../piece/each_piece.h"
#include "piece_list.h"

#include <list>
#include <iostream>

#ifndef _U_
#define _U_
using namespace std;
#endif //_U_


class Board
{
private:
	Piece * board[8][8];
	mutable Piece_List w_piece_list;
	mutable Piece_List b_piece_list;

	inline Piece_List& GetPieceList(const Color color) const;
	inline Piece_List& GetReversePieceList(const Color color) const;

public:
	Board();
	~Board();

	inline bool IfExist(const Pos& check_pos) const;
	inline Color GetColor(const Pos& get_pos) const;
	inline ID GetID(const Pos& get_pos) const;

	int AddPiece(const ID add_id, const Pos& add_pos, const Color add_color);
	int DeletePiece(const Pos& delete_pos);


	int GetPieceMoveList(const Pos& orig_pos, const Pos& dest_pos, list<Pos>& move_list) const;

	void GetAllPiecePos(const Color color, list<Pos>& pos_list) const;

	int GetKingPos(const Color king_color, Pos& king_pos) const;

	int MovePiece(const Pos& orig, const Pos& dest);

	void GetBoard(Piece_Data_Board& data_board) const;

	int ShowBoard(void) const;
};

inline Piece_List& Board::GetPieceList(const Color color) const
{
	if(color == Color::W)
		return w_piece_list;
	else
		return b_piece_list;
}

inline Piece_List& Board::GetReversePieceList(const Color color) const
{
	if(color == Color::B)
		return w_piece_list;
	else
		return b_piece_list;
}

inline bool Board::IfExist(const Pos& check_pos) const
{
	if(board[check_pos.x][check_pos.y] == nullptr)
		return false;
	else
		return true;
}

inline Color Board::GetColor(const Pos& get_pos) const
{
	return board[get_pos.x][get_pos.y]->GetColor();
}

inline ID Board::GetID(const Pos& get_pos) const
{
	return board[get_pos.x][get_pos.y]->GetID();
}

#endif // _BOARD_H_
