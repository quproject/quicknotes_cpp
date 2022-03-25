#ifndef EDITOR_H
#define EDITOR_H

#include "note.h"
#include <ncurses.h>

namespace fs = std::filesystem;
using Lines = std::vector<std::string>;

class Editor
{
	public:
	Editor();
	Editor(const Note& note);
	~Editor() = default;

	private:
	Note note_;
};

#endif // EDITOR_H
