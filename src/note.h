#ifndef NOTE_H
#define NOTE_H

#include <utility>
#include <string>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;
using Lines = std::vector<std::string>;

class Note
{
	public:
	Note();

	Note(const std::string& name);
	Note(const std::string& name, const std::string& format);
	Note(const std::string& name, fs::path path);
	Note(const std::string& name, const std::string& format, fs::path path);

	Note(const Note& note);
	Note(Note&& note) noexcept;

	Note& operator=(const Note& note);
	Note& operator=(Note&& note) noexcept;

	~Note() = default;

	bool status_;

	private:
	std::string file_name;
	std::string file_format;
	fs::path file_path;
	Lines file_lines;
};

#endif // EDITOR_H
