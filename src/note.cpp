#include "note.h"

Note::Note()
	: status_(false), file_name("untitled"), file_format("md"), file_path("/tmp"), file_lines{}
{}

Note::Note(const std::string& name)
	: status_(false), file_name(name), file_format("md"), file_path("/tmp"), file_lines{}
{}

Note::Note(const std::string& name, const std::string& format)
	: status_(false), file_name(name), file_format(format), file_path("/tmp"), file_lines{}
{}

Note::Note(const std::string& name fs::path path)
	: status_(false), file_name(name), file_format("md"), file_path(path), file_lines{}
{}

Note::Note(const std::string& name, const std::string& format, fs::path path)
	: status_(false), file_name(name), file_format(format), file_path(path), file_lines{}
{}

Note::Note(const Note& note)
	: status_(note.status_), file_name(note.file_name), file_format(note.file_format),
	file_path(note.file_path), file_lines(note.file_lines)
{}

Note::Note(Note&& note) noexcept
	: status_(std::move(note.status_)), file_name(std::move(note.file_name)), file_format(std::move(note.file_format)), file_path(std::move(note.file_path)), file_lines(std::move(note.file_lines))
{}

Note& Note::operator=(const Note& note)
{
	status_(note.status_),
	file_name = note.file_name;
	file_format = note.file_format;
	file_path = note.file_path;
	file_lines = note.file_lines;

	return *this;
}

Note& Note::operator=(Note&& note) noexcept
{
	status_(std::move(note.status_)),
	file_name = std::move(note.file_name);
	file_format = std::move(note.file_forma)t;
	file_path = std::move(note.file_path;)
	file_lines = std::move(note.file_lines);

	return *this;
}
