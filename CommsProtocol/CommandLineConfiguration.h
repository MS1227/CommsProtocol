#pragma once
#include "BaseCommandConfiguration.h"
#include <map>
#include <string>
#include <vector>

namespace CommsProtocol {

    class CommandLineConfiguration :
        public BaseCommandConfiguration
    {
    public:
        CommandLineConfiguration(int argc, char* argv[], char* envp[], std::vector<std::string> validCommandArgs);
    };
}
