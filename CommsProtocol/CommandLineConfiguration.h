#pragma once
#include "ICommandConfiguration.h"
#include <map>
#include <string>
#include <vector>

namespace CommsProtocol {

    class CommandLineConfiguration :
        public ICommandConfiguration
    {
    public:
        CommandLineConfiguration(int argc, char* argv[], char* envp[], std::vector<std::string> validCommandArgs);
        // Inherited via ICommandConfiguration
        virtual bool HasCommandArgument(std::string arg) override;
        virtual bool HasEnvironmentVariable(std::string arg) override;
        virtual std::string GetCommandArgument(std::string arg) override;
        virtual std::string GetEnvironmentVariable(std::string varName) override;

    private:
        void StoreCommandArgsInMap();
        void StoreEnvVarsInMap();
        bool ValidCommand(std::string commandArg);

        //Sanitized values post processing.  These will be used to answer the questions above.
        std::map<std::string, std::string> m_CommandArgs;
        std::map<std::string, std::string> m_environmentVars;

        /// <summary>
        /// Initial values as passed in.
        /// </summary>
        std::vector<std::string> m_inputCommandArgs;
        std::vector<std::string> m_inputEnvVars;

        std::vector<std::string> m_validCommandArgs;
    };
}
