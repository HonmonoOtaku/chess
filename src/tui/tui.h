#ifndef _TUI_H_
#define _TUI_H_

#include "../piece/piece.h"
#include "../board/board.h"

#include <ncurses.h>

class Ncurses_Setting
{
private:
	static int class_count;


	void InitNcurses(void);
	void EndNcurses(void);
protected:
	Ncurses_Setting();
	~Ncurses_Setting();

};

class Show_Board : public Ncurses_Setting
{
private:
	Piece_Data_Board data_board;
	
private:
	Pos GetScreenPos(const Pos& pos) const;
	void RefreshBoard(void) const;

public:
	Show_Board();

	void ModifyBoard(const Piece_Data_Board& data_board);
	int MovePiece(const Pos& orig_pos, const Pos& dest_pos);
	
	void SelectPos(Pos& select_pos) const;
	void ShowBoard(void) const;
};

#endif // _TUI_H_
