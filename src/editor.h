#ifndef EDITOR_H
#define EDITOR_H

#include <ncurses.h>
#include <string>
#include <vector>
#include <memory>

#include "note.h"

using str = std::string;
using Content = std::vector<str>;

class Editor
{
  public:
	Editor();
	Editor(const std::string& file);
	Editor(std::shared_ptr<Note> note);
	~Editor();

  private:
	str file_;
	Content content_;
	std::shared_ptr<Note> note_;

	void edinit();
	void main_loop();
};

#endif // EDITOR_H
