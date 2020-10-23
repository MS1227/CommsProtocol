#include "BaseCommandConfiguration.h"
#include <sstream>
#include <algorithm>
#include <iostream>
namespace CommsProtocol {

	void BaseCommandConfiguration::StoreCommandArgsInMap()
	{
		std::string key;
		std::string value;
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

	void BaseCommandConfiguration::StoreEnvVarsInMap()
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

	bool BaseCommandConfiguration::ValidCommand(std::string commandArg)
	{
		return std::find(m_validCommandArgs.begin(), m_validCommandArgs.end(), commandArg) != m_validCommandArgs.end();
	}

	bool BaseCommandConfiguration::HasCommandArgument(std::string arg)
	{
		return m_CommandArgs.find(arg) != m_CommandArgs.end();
	}

	bool BaseCommandConfiguration::HasEnvironmentVariable(std::string arg)
	{
		return m_environmentVars.find(arg) != m_environmentVars.end();
	}

	std::string BaseCommandConfiguration::GetCommandArgument(std::string arg)
	{
		if (HasCommandArgument(arg)) {
			return m_CommandArgs[arg];
		}
		return "";
	}

	std::string BaseCommandConfiguration::GetEnvironmentVariable(std::string varName)
	{
		if (HasEnvironmentVariable(varName)) {
			return m_environmentVars[varName];
		}
		return "";
	}
}
