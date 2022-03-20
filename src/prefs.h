#ifndef PREFS_H
#define PREFS_H

#include "futil.h"
#include <map>
#include <regex>
#include <iostream>

class Prefs
{
	public:
	Prefs() = delete;
	Prefs(const std::filesystem::path& conffile);
	~Prefs() = default;

	std::map<std::string, std::string> config_;

	private:
	fs::path conffile_;

	void load_prefs();
	void parse_prefs(const std::string& line);

};

#endif // PREFS_H
