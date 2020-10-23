#include "FileConfiguration.h"
#include <sstream>
#include <algorithm>

namespace CommsProtocol {
    FileConfiguration::FileConfiguration(std::string filename, char* envp[], std::vector<std::string> validCommands) :
        m_fileName(filename)
    {
        // Store all environment variables for potential use later.
        for (int i = 0; envp[i] != NULL; ++i) {
            m_inputEnvVars.push_back(envp[i]);
        }

        m_validCommandArgs = validCommands;

        StoreEnvVarsInMap();
    }
}