#ifndef EDITOR_H
#define EDITOR_H

#include <ncurses.h>
#include "note.h"

namespace fs = std::filesystem;
using Lines = std::vector<std::string>;

struct Cursor
{
	int posy;
	int posx;

	void update(int y, int x)
	{
		posy = y;
		posx = x;
	}
};

struct Textarea
{
	int height;
	int width;

	void update(int h, int w)
	{
		height = h;
		width = w;
	}
};

class Editor
{
	public:
	Editor();
	Editor(const Note& note);
	~Editor();

	bool edstatus_

	private:
	Note note_;
	Cursor cursor_;
	Textarea textarea_;
	std::string footer_;

	void edinit();
	void fresh();

	void update_footer();

	void edloop();
};

#endif // EDITOR_H
