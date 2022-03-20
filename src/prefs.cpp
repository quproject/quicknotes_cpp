#include "prefs.h"

Prefs::Prefs(const std::filesystem::path& conffile)
	: config_{}, conffile_(conffile)
{
	load_prefs();
}

void Prefs::load_prefs()
{
	Futil settings(conffile_);

	if (settings.status_)
	{
		settings.get_file_content();
		if (settings.status_)
		{
			for (const auto& e: settings.content_)
			{
				parse_prefs(e);
			}
		}
	}

	std::cout << settings.errormsg_ << '\n';
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
