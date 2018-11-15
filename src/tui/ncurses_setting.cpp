#include "tui.h"

int Ncurses_Setting::class_count = 0;
const int Ncurses_Setting::white_screen_color = 1;
const int Ncurses_Setting::black_screen_color = 2;

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
	start_color();
	use_default_colors();

	init_pair(white_screen_color, 193, 0); 
	init_pair(black_screen_color, 128, 0); 
}

void Ncurses_Setting::EndNcurses(void)
{
	endwin();
}
