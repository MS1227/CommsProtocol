#pragma once
#include "BaseCommandConfiguration.h"
#include <map>
#include <vector>
namespace CommsProtocol {
    class FileConfiguration :
        public BaseCommandConfiguration
    {
    public:
        FileConfiguration(std::string filename, std::vector<std::string> envp, std::vector<std::string> validCommands);

    private:
        std::string m_fileName;
    };
}

