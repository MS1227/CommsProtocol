#pragma once
#include "ICommandConfiguration.h"
#include <map>
#include <vector>
namespace CommsProtocol {
    class FileConfiguration :
        public ICommandConfiguration
    {
    public:
        FileConfiguration(std::string filename, char* envp[], std::vector<std::string> validCommands);
        // Inherited via ICommandConfiguration
        virtual bool HasCommandArgument(std::string arg) override;
        virtual bool HasEnvironmentVariable(std::string arg) override;
        virtual std::string GetCommandArgument(std::string arg) override;
        virtual std::string GetEnvironmentVariable(std::string varName) override;

    private:
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

