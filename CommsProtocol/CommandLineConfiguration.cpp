#include "CommandLineConfiguration.h"
#include <sstream>
#include <algorithm>
#include <vector>
#include <iostream>

namespace CommsProtocol {

    /// <summary>
    /// For now the assumption is that Command line arguments are passed as "Key Value"
    /// That is to say that when we find a valid switch (key), we check the next word and if it is there, we use it as the svalue for the switch.
    /// </summary>
    /// <param name="args"></param>
    /// <param name="envp"></param>
    /// <param name="validCommandArgs"></param>
    CommandLineConfiguration::CommandLineConfiguration(std::vector<std::string> args, std::vector<std::string> envp, std::vector<std::string> validCommandArgs) 
    {
        m_inputCommandArgs = args;
        m_inputEnvVars = envp;
        m_validCommandArgs = validCommandArgs;

        StoreCommandArgsInMap();
        StoreEnvVarsInMap();
    }
}

