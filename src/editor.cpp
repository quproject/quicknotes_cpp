#include "editor.h"

Editor::Editor():
	file_("untitled"), content_{},
	note_(std::make_shared<Note>())
{
	edinit();
}

Editor::Editor(const std::string& file):
	file_(file), content_{},
	note_(std::make_shared<Note>(fs::path(file)))
{
	edinit();
}

Editor::Editor(std::shared_ptr<Note> note):
	file_(file), content_{}, note_(note)
{
	edinit();
}

Editor::~Editor()
{
	endwin();
}

void Editor::edinit()
{
	initscr();
	//noecho();
	//cbreak();
	keypad(stdscr, true);

	main_loop();
}

void Editor::main_loop()
{
	int ch;

	do {
		ch = getch();
		switch (ch)
		{
			case KEY_DOWN:
				addstr("Key down arrow\n");
				break;
			case KEY_UP:
				addstr("Key up arrow\n");
				break;
			case KEY_LEFT:
				addstr("Key left arrow\n");
				break;
			case KEY_RIGHT:
				addstr("Key right arrow\n");
				break;
			case KEY_NPAGE:
				addstr("Key page down\n");
				break;
			case KEY_PPAGE:
				addstr("Key page up\n");
				break;
			case KEY_HOME:
				addstr("Key home\n");
				break;
			case KEY_END:
				addstr("Key to end\n");
				break;
			case KEY_BACKSPACE:
				addstr("Key backspace\n");
				break;
			case KEY_DC:
				addstr("Key delete\n");
				break;
			case KEY_F(2):
				addstr("Key F2\n");
				break;
			default:
				break;
		}
		refresh();
	} while (ch != KEY_F(1));
}
