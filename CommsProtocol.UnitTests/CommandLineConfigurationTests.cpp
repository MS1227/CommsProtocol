#include "pch.h"
#include "CommandLineConfiguration.h"
#include <string>
#include <vector>
#include <array>

using namespace CommsProtocol;

namespace {

	TEST(CommandLineConfiguration, CallCtorWithNoArgs) {

		std::vector<std::string> args;
		std::vector<std::string> envp;
		std::vector<std::string> validCommands;
		CommandLineConfiguration config(args, envp, validCommands);

		ASSERT_TRUE(config.GetCommandArgument("") == "");
		ASSERT_FALSE(config.HasCommandArgument(""));
	}

	TEST(CommandLineConfiguration, OneCommandValid) {

		std::vector<std::string> args{ "Test.exe", "/Mike", "/bob", "InvalidFormatted", "/f" };
		std::vector<std::string> envp;
		std::vector<std::string> validCommands{ "/f","/Mike"};

		CommandLineConfiguration config(args, envp, validCommands);

		ASSERT_TRUE(config.HasCommandArgument(args[1]));
		ASSERT_EQ(config.GetCommandArgument(args[1]), args[2]);
	}

	TEST(CommandLineConfiguration, CommandSwitchButNoValue_DoesntSaveSwitch) {

		std::vector<std::string> args{ "Test.exe", "/Mike" };
		std::vector<std::string> envp;
		std::vector<std::string> validCommands{ "/f","/Mike" };

		CommandLineConfiguration config(args, envp, validCommands);

		ASSERT_FALSE(config.HasCommandArgument(args[1]));
		ASSERT_EQ(config.GetCommandArgument(args[1]), std::string(""));
	}

}  // namespace
