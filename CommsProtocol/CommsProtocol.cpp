#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <vector>

#include "EthernetConfig.h"
#include "CommandLineConfiguration.h"
#include "FileConfiguration.h"

std::map<std::string, std::string> CommandLineConfigMap{
    {"/f", "Configuration File Name.  This will be used over command line switches if both are provided!" },
    {"/p", "Port Number" },
    {"/i", "IP Address"},
    {"/proto", "Protocol: 0 (TCP Client), 1 (TCP Server), 2 (UDP), 3 (Multicast)"} };
std::map<std::string, std::string> FileConfigMap{
    {"Port", "Port Number"},
    {"Address", "IP Address"},
    {"Protocol", "Protocol: 0 (TCP Client), 1 (TCP Server), 2 (UDP), 3 (Multicast)" } };

std::string applicationName;

std::vector<std::string> parametersArgs;
std::vector<std::string> parameterEnvironmentVars;

/// <summary>
/// Prints the usage for how to configure the 
/// </summary>
void Usage() {
    std::cout << std::endl << std::endl;

    std::cout << "Usage: " << std::endl;
    std::cout << applicationName << " can be used with command line switches or you can provide a file that we can parse for the configuration settings." << std::endl;
    std::cout << "Command line switches and descriptions are as follows:" << std::endl;
    for (auto opt : CommandLineConfigMap) {
        std::cout << " " << opt.first << " : " << opt.second << std::endl;
    }
    std::cout << std::endl;

    std::cout << "File settings and descriptions are specified as key=value and are as follows:" << std::endl;
    for (auto opt : FileConfigMap) {
        std::cout << " " << opt.first << " : " << opt.second << std::endl;
    }
    std::cout << std::endl;
}

void StoreParameters(int argc, char* argv[], char* envp[]) {

    applicationName = argv[0];

    //Store off all Command line arguments.
    //Skip index 0 as that is the name of the application.        
    for (int ix = 1; ix < argc; ++ix) {
        parametersArgs.push_back(argv[ix]);
    }
    if (envp != nullptr) {
        // Store all environment variables for potential use later.
        for (int i = 0; envp[i] != NULL; ++i) {
            parameterEnvironmentVars.push_back(envp[i]);
        }
    }
}

std::vector<std::unique_ptr<CommsProtocol::ICommandConfiguration>> ProcessConfigurations() {

    std::vector< std::unique_ptr<CommsProtocol::ICommandConfiguration>> configs;

    std::vector<std::string> commandLineSwitches;
    for (const auto& opt : CommandLineConfigMap) {
        commandLineSwitches.push_back(opt.first);
    }

    //First lets get the command line data.
    std::unique_ptr<CommsProtocol::CommandLineConfiguration> config = 
        std::make_unique<CommsProtocol::CommandLineConfiguration>(parametersArgs, parameterEnvironmentVars, commandLineSwitches);

    //Now lets see if we have a file that we can read based on the /f flag from the command line.
    if (config->HasCommandArgument("/f")) {
        std::vector<std::string> fileSwitches;

        for (const auto& opt : FileConfigMap) {
            fileSwitches.push_back(opt.first);
        }

        std::string filename(config->GetCommandArgument("/f"));
        std::unique_ptr < CommsProtocol::FileConfiguration> fileConfig = 
            std::make_unique<CommsProtocol::FileConfiguration>(filename, parameterEnvironmentVars, fileSwitches);

        configs.push_back(std::move(fileConfig));
    }

    configs.push_back(std::move(config));

    return configs;    
}

bool ValidConfig(const std::vector<std::unique_ptr<CommsProtocol::ICommandConfiguration>> &configs) {
    return false;
}

/// <summary>
/// Entrypoint to program.
/// </summary>
/// <param name="argc">Count of arguments</param>
/// <param name="argv">Arguments passed in as an array</param>
/// <param name="envp">Environment variables that were set when console app was started.</param>
/// <returns></returns>
int main(int argc, char* argv[], char* envp[])
{
    //Normalize our input data to a C++ container.
    StoreParameters(argc, argv, envp);
    //Store off our configurations.  
    std::vector<std::unique_ptr<CommsProtocol::ICommandConfiguration>> configs = ProcessConfigurations();

    //Check to see if we have a valid configuration, or enough information to start up an interface.
    if (!ValidConfig(configs)) {
        Usage();
    }

    //Now that we know we have a valid config, let try to create an ethernet Object from it.

    return 0;
}
