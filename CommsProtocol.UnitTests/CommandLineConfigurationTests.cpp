#include "pch.h"
#include "CommandLineConfiguration.h"
#include <string>
#include <vector>

using namespace CommsProtocol;

namespace {

	TEST(CommandLineConfiguration, CallCtorWithNoArgs_HowToTest) {

		std::vector<std::string> args;
		std::vector<std::string> envp;
		std::vector<std::string> validCommands;
		CommandLineConfiguration config(args, envp, validCommands);

		ASSERT_TRUE(config.GetCommandArgument("") == "");
		ASSERT_FALSE(config.HasCommandArgument(""));
	}

	TEST(CommandLineConfiguration, CommandValidWithKey_SavesKey) {

		std::vector<std::string> args{ "/Mike", "/bob", "InvalidFormatted", "/f" };
		std::vector<std::string> envp;
		std::vector<std::string> validCommands{ "/f","/Mike"};

		CommandLineConfiguration config(args, envp, validCommands);

		ASSERT_TRUE(config.HasCommandArgument(args[0]));
		ASSERT_EQ(config.GetCommandArgument(args[0]), args[1]);
	}

	TEST(CommandLineConfiguration, ValidCommandButIsLastArg_DoesntSaveSwitch) {

		std::vector<std::string> args{ "/Mike" };
		std::vector<std::string> envp;
		std::vector<std::string> validCommands{ "/f","/Mike" };

		CommandLineConfiguration config(args, envp, validCommands);

		ASSERT_FALSE(config.HasCommandArgument(args[0]));
		ASSERT_EQ(config.GetCommandArgument(args[0]), std::string(""));
	}

}  // namespace
