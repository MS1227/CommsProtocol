#include "CommandLineConfiguration.h"
#include <sstream>
#include <algorithm>
#include <vector>
#include <iostream>

namespace CommsProtocol {

    CommandLineConfiguration::CommandLineConfiguration(int argc, char* argv[], char* envp[], std::vector<std::string> validCommandArgs) : 
        m_validCommandArgs(validCommandArgs)
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

        StoreCommandArgsInMap();
        StoreEnvVarsInMap();
    }

    bool CommandLineConfiguration::HasCommandArgument(std::string arg)
    {
        return m_CommandArgs.find(arg) != m_CommandArgs.end();
    }

    bool CommandLineConfiguration::HasEnvironmentVariable(std::string arg)
    {
        return m_environmentVars.find(arg) != m_environmentVars.end();
    }

    std::string CommandLineConfiguration::GetCommandArgument(std::string arg)
    {
        if (HasCommandArgument(arg)) {
            return m_CommandArgs[arg];
        }
        return "";
    }

    std::string CommandLineConfiguration::GetEnvironmentVariable(std::string varName)
    {
        if (HasEnvironmentVariable(varName)) {
            return m_environmentVars[varName];
        }
        return "";
    }

    /// <summary>
    /// We assume that we have switches (/p statements) to identify the options 
    /// </summary>
    void CommandLineConfiguration::StoreCommandArgsInMap()
    {
        std::string key;
        std::string value;
        ;
        for (auto it = m_inputCommandArgs.cbegin(); it != m_inputCommandArgs.cend(); ++it) {

            if (ValidCommand(*it)) {
                key = *it;
                ++it;
                value = *it;
                std::cout << key << " = " << value << std::endl;

                m_CommandArgs[key] = value;
            }
            else {
                std::cout << *it << " was an invalid Command line option." << std::endl;
            }
        }
    }

    /// <summary>
    /// Command line options are stored as "Key=Value"
    /// </summary>
    void CommandLineConfiguration::StoreEnvVarsInMap()
    {
        std::string key;
        std::string value;
        for (auto line : m_inputEnvVars) {
            std::replace(line.begin(), line.end(), '=', ' ');
            std::stringstream ss(line);

            ss >> key >> value;

            m_environmentVars[key] = value;
        }
    }
    bool CommandLineConfiguration::ValidCommand(std::string commandArg)
    {
        return std::find(m_validCommandArgs.begin(), m_validCommandArgs.end(), commandArg) != m_validCommandArgs.end();
    }
}

