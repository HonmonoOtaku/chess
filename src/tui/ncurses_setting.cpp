#include "tui.h"

int Ncurses_Setting::class_count = 0;

Ncurses_Setting::Ncurses_Setting()
{
	class_count++;

	if(class_count == 1)
		InitNcurses();
	
}

Ncurses_Setting::~Ncurses_Setting()
{
	class_count--;

	if(class_count == 0)
		EndNcurses();
}

void Ncurses_Setting::InitNcurses(void)
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
}

void Ncurses_Setting::EndNcurses(void)
{
	endwin();
}
