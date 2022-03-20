#include "args.h"

Args::Args(const Svec& args)
	: status_{false}, args_(args)
{
	parse_args();
}

void Args::parse_args()
{
	char subcmd = 'u'; // undefined

	for (const auto& arg: args_)
	{
		if (arg == "-n" or arg == "--note")
		{
			subcmd = 'n'; // parsing note sub command
			continue;
		}

		if (arg == "-c" or arg == "--category")
		{
			subcmd = 'c'; // parsing category sub command
			continue;
		}

		if (arg == "-t" or arg == "--template")
		{
			subcmd = 't'; // parsing template sub command
			continue;
		}

		if (arg == "-l" or arg == "--list")
		{
			subcmd = 'l'; // parsing list sub command
			continue;
		}

		if (arg == "-s" or arg == "--search")
		{
			subcmd = 's'; // parsing search sub command
			continue;
		}
	}
}
