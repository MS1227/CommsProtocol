#include "FileConfiguration.h"

namespace CommsProtocol {
    FileConfiguration::FileConfiguration(std::string filename, char* envp[], std::vector<std::string> validCommands) :
        m_validCommandArgs(validCommands)
    {
    }

    bool FileConfiguration::HasCommandArgument(std::string arg)
    {
        return false;
    }

    bool FileConfiguration::HasEnvironmentVariable(std::string arg)
    {
        return false;
    }

    std::string FileConfiguration::GetCommandArgument(std::string arg)
    {
        return std::string();
    }

    std::string FileConfiguration::GetEnvironmentVariable(std::string varName)
    {
        return std::string();
    }
}