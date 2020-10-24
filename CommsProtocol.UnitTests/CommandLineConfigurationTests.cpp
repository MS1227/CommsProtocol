#include "pch.h"
#include "CommandLineConfiguration.h"
#include <string>
#include <vector>
#include <array>

using namespace CommsProtocol;

namespace {

	TEST(CommandLineConfiguration, CallCtorWithNoArgs) {

		std::vector<std::string> validCommands;
		CommandLineConfiguration config(0, nullptr, nullptr, validCommands);

		ASSERT_TRUE(config.GetCommandArgument("") == "");
		ASSERT_FALSE(config.HasCommandArgument(""));
	}

	TEST(CommandLineConfiguration, OneCommandValid) {

		std::vector<std::string> validCommands{ "/f","/Mike"};

		//Here use a fixed size.
		//First element is always the executable, will always skip.
		std::array<std::string, 5> CommandArgs{ "Test.exe", "/Mike", "/bob", "InvalidFormatted", "/f" };

		char** input = new char* [CommandArgs.size()];
		size_t arrSize = 0;
		for (auto c : CommandArgs) {
		
			input[arrSize] = new char[c.size() + 1];
			strcpy_s(input[arrSize++], c.size() + 1, c.c_str());
		}

		CommandLineConfiguration config(CommandArgs.size(), input, nullptr, validCommands);

		ASSERT_TRUE(config.HasCommandArgument(CommandArgs[1]));
		ASSERT_EQ(config.GetCommandArgument(CommandArgs[1]), CommandArgs[2]);


		for (int ix = CommandArgs.size() - 1; ix >= 0; --ix) {
			delete input[ix];
		}
		delete[] input;
	}

	TEST(CommandLineConfiguration, CommandSwitchButNoValue_DoesntSaveSwitch) {

		std::vector<std::string> validCommands{ "/f","/Mike" };

		//Here use a fixed size.
		//First element is always the executable, will always skip.
		std::array<std::string, 2> CommandArgs{ "Test.exe", "/Mike"};

		char** input = new char* [CommandArgs.size()];
		size_t arrSize = 0;
		for (auto c : CommandArgs) {

			input[arrSize] = new char[c.size() + 1];
			strcpy_s(input[arrSize++], c.size() + 1, c.c_str());
		}

		CommandLineConfiguration config(CommandArgs.size(), input, nullptr, validCommands);

		ASSERT_FALSE(config.HasCommandArgument(CommandArgs[1]));
		ASSERT_EQ(config.GetCommandArgument(CommandArgs[1]), std::string(""));


		for (int ix = CommandArgs.size() - 1; ix >= 0; --ix) {
			delete input[ix];
		}
		delete[] input;
	}

}  // namespace
