#include "FileConfiguration.h"
#include <sstream>
#include <algorithm>

namespace CommsProtocol {
    FileConfiguration::FileConfiguration(std::string filename, std::vector<std::string> envp, std::vector<std::string> validCommands) :
        m_fileName(filename)
    {
        m_inputEnvVars = envp;

        m_validCommandArgs = validCommands;

        StoreEnvVarsInMap();
    }
}