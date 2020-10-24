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
        CommandLineConfiguration(std::vector<std::string> args, std::vector<std::string> envp, std::vector<std::string> validCommandArgs);
        CommandLineConfiguration() = delete;
    };
}
