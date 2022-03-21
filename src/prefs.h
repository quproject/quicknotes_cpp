#ifndef PREFS_H
#define PREFS_H

#include "futil.h"
#include <map>
#include <regex>

class Prefs
{
	public:
	Prefs() = delete;
	Prefs(const std::vector<std::string>& raw_settings);
	~Prefs() = default;

	std::map<std::string, std::string> config_;

	private:
	//std::vector<std::string>& settings_;

	void load_prefs(const std::vector<std::string>& settings);
	void parse_prefs(const std::string& line);

};

#endif // PREFS_H
