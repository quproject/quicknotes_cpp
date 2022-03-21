#include "prefs.h"

Prefs::Prefs(const std::vector<std::string>& raw_settings)
	: config_{}
{
	load_prefs(raw_settings);
}

void Prefs::load_prefs(const std::vector<std::string>& settings)
{
	for (const auto& e: settings)
	{
		parse_prefs(e);
	}
}

void Prefs::parse_prefs(const std::string& line)
{
	const std::regex t_entry{R"(([^ ]+) ([a-zA-Z0-9]+))"};
	std::smatch m;

	if (!line.starts_with('#'))
	{
		if (std::regex_match(line, m, t_entry))
		{
			config_[std::string(m[1])] = std::string(m[2]);
			//config_.emplace(std::make_pair(std::string(m[1]), std::string(m[2])));
		}
	}
}
