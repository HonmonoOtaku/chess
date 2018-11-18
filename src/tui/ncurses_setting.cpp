#include "tui.h"

int tui::Ncurses_Setting::class_count = 0;
const int tui::Ncurses_Setting::white_screen_color = 1;
const int tui::Ncurses_Setting::black_screen_color = 2;

tui::Ncurses_Setting::Ncurses_Setting()
{
	class_count++;

	if(class_count == 1)
		InitNcurses();
	
}

tui::Ncurses_Setting::~Ncurses_Setting()
{
	class_count--;

	if(class_count == 0)
		EndNcurses();
}

void tui::Ncurses_Setting::InitNcurses(void)
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

void tui::Ncurses_Setting::EndNcurses(void)
{
	endwin();
}
