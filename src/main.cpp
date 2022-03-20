#include "args.h"
//#include "futil.h"
#include <iostream>
#include <vector>
#include <string>
#include <string_view>

using std::cout;

const std::string app_name{"qn"};
const std::string app_version{"0.2.0"};
const std::string help_msg{R"(Usage: qn [OPTION]... [NAME]... [TERMS]... [FORMAT]

Options:
  -n, --new [NAME]...                Create a new note named \033[4mNAME\033[0m
  -r, --read [NAME]...               Read the note named \033[4mNAME\033[0m (if found)
  -c, --category [NAME]              Specify the note's category \033[4mNAME\033[0m to associate with a new note or create a new category if used alone
  -t, --template [NAME]              Specify a template \033[4mNAME\033[0m to use (default: memo.md)
  -l, --list [a|n|c|t [0-9]*]        List notes and categories ([a]ll, [n]otes, [c]ategories, [t]ags, [0-9] number of items to show)
  -s, --search [TERMS]...            Search \033[4mTERMS\033[0m in notes
  -e, --export [FORMAT] [NAME]...    Export the note \033[4mNAME\033[0m to the format \033[4mFORMAT\033[0m
  -m, --manage [n|c] [NAME]...       Edit [n]ote, [c]ategory \033[4mNAME\033[0m
  -p, --prefs                        Display current settings of preferences
  -h, --help                         Display this help message and exit
  -v, --version                      Display the current app version)"};

void print_help()
{
	cout << help_msg << '\n';
}

void print_version()
{
	cout << app_name << ' ' << app_version << '\n';
}

void print_prefs()
{
	cout << "Not yet implemented!\n";
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		interactive_mode();
	}
	else if (argc == 2)
	{
		if (std::string_view(argv[1]) == "-h" or std::string_view(argv[1]) == "--help")
		{
			print_help();
		}
		else if (std::string_view(argv[1]) == "-v" or std::string_view(argv[1]) == "--version")
		{
			print_version();
		}
		else if (std::string_view(argv[1]) == "-p" or std::string_view(argv[1]) == "--prefs")
		{
			print_prefs();
		}
		else
		{
			std::cerr << "\033[31mError:\033[0m unknown argument... " << argv[1] << ". Do:  " << app_name << " --help to see how to form the query.\n";
			return 1;
		}
	}
	else
	{
		const std::vector<std::string_view> arguments(argv + 1, argv + argc);
		Args args(arguments);

		if (!args.status_)
		{
			std::cerr << "\033[31mError:\033[0m Could not parse arguments... Do:  " << app_name << " --help to see how to form the query.\n";

			return 1;
		}
	}

	return 0;
}
