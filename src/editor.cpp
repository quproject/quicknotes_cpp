#include "editor.h"

Editor::Editor()
	: edstatus_(false),
	  note_{},
	  cursor_{0, 0},
	  textarea_{0, 0},
	  footer_{}
{}

Editor::Editor(const Note& note)
	: edstatus_(false),
	  note_(note),
	  cursor_{0, 0},
	  textarea_{0, 0},
	  footer_{}
{}

~Editor()
{
	if (edstatus_)
	{
		endwin();
	}
}

void Editor::edinit()
{
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, true);

	textarea_.update(LINES - 2, COLS);

	edstatus_ = true;
	update_footer();
	edloop();
}

void fresh()
{
	refresh();
}

void Editor::update_footer()
{
    attron(A_REVERSE);
    mvprintw(LINES - 1, 0, footer_.c_str());
    clrtoeol();
    attroff(A_REVERSE);
}

void Editor::edloop()
{
	int current_char;
	bool app_exit{false};

	move(cursor_.posy, cursor_.posx);

    while(current_char = getch())
	{
		if (app_exit)
		{
			break;
		}

		switch(current_char)
		{
			case 27:           // Escape key, exit the app
				app_exit = true;
				break;
			case KEY_F(1):     // Saving the file
				break;
			case KEY_F(2):     // Showing the help
				break;
			case KEY_DOWN:
				break;
			case KEY_UP:
				break;
			case KEY_LEFT:
				break;
			case KEY_RIGHT:
				break;
			case 127:
			case KEY_BACKSPACE:
				break;
			case KEY_DC:        // Delete key
				break;
			case KEY_ENTER:
			case 10:
				break;
			case KEY_BTAB:
			case KEY_CTAB:
			case KEY_STAB:
			case KEY_CATAB:
			case 9:            // Tab key
				break;
			default:
				cursor_.posx++;
		}
	}
}
