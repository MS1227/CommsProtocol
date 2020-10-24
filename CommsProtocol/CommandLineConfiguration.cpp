#include "CommandLineConfiguration.h"
#include <sstream>
#include <algorithm>
#include <vector>
#include <iostream>

namespace CommsProtocol {

    /// <summary>
    /// For now the assumption is that Command line arguments are passed as "Key" "Value"
    /// That is to say that when we find a valid switch, we check the next word if it is there, it is the value for the switch.
    /// and we store that off.
    /// </summary>
    /// <param name="argc"></param>
    /// <param name="argv"></param>
    /// <param name="envp"></param>
    /// <param name="validCommandArgs"></param>
    CommandLineConfiguration::CommandLineConfiguration(int argc, char* argv[], char* envp[], std::vector<std::string> validCommandArgs)   
    {
        //Store off all Command line arguments.
        //Skip index 0 as that is the name of the application.
        for (int ix = 1; ix < argc; ++ix) {
            m_inputCommandArgs.push_back(argv[ix]);
        }
        if (envp != nullptr) {
            // Store all environment variables for potential use later.
            for (int i = 0; envp[i] != NULL; ++i) {
                m_inputEnvVars.push_back(envp[i]);
            }
        }

        m_validCommandArgs = validCommandArgs;

        StoreCommandArgsInMap();
        StoreEnvVarsInMap();
    }
}

