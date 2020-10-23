#include "CommandLineConfiguration.h"
#include <sstream>
#include <algorithm>
#include <vector>
#include <iostream>

namespace CommsProtocol {

    CommandLineConfiguration::CommandLineConfiguration(int argc, char* argv[], char* envp[], std::vector<std::string> validCommandArgs)   
    {
        //Store off all Command line arguments.
        //Skip index 0 as that is the name of the application.
        for (int ix = 1; ix < argc; ++ix) {
            m_inputCommandArgs.push_back(argv[ix]);
        }

        // Store all environment variables for potential use later.
        for (int i = 0; envp[i] != NULL; ++i) {
            m_inputEnvVars.push_back(envp[i]);
        }

        m_validCommandArgs = validCommandArgs;

        StoreCommandArgsInMap();
        StoreEnvVarsInMap();
    }
}

