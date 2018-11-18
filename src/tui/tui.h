#ifndef _TUI_H_
#define _TUI_H_

#include "../piece/piece.h"
#include "../board/board.h"

#include <ncurses.h>

namespace tui
{

class Ncurses_Setting
{
private:
	static int class_count;


	void InitNcurses(void);
	void EndNcurses(void);


protected:

	static const int white_screen_color;
	static const int black_screen_color;

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

	int PrintPiece(const int x, const int y, const ID piece_id, const Color piece_color) const;
	

public:
	Show_Board();

	void ModifyBoard(const Piece_Data_Board& data_board);
	int MovePiece(const Pos& orig_pos, const Pos& dest_pos);
	
	void SelectPos(Pos& select_pos) const;
	void ShowBoard(void) const;
};

}
#endif // _TUI_H_
