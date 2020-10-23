#include "pch.h"
#include "CommandLineConfiguration.h"
#include <string>
#include <vector>

using namespace CommsProtocol;

namespace {

	TEST(CommandLineConfiguration, CallCtorWithNoArgs) {

		std::vector<std::string> validCommands;
		CommandLineConfiguration config(0, nullptr, nullptr, validCommands);

		ASSERT_TRUE(config.GetCommandArgument("") == "");
		ASSERT_FALSE(config.HasCommandArgument(""));
	}

}  // namespace
