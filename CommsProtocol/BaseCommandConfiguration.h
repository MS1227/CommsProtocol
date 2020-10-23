#pragma once
#include "ICommandConfiguration.h"
#include <vector>
#include <map>

namespace CommsProtocol {
	class BaseCommandConfiguration :
		public ICommandConfiguration
	{
	protected:
		void StoreCommandArgsInMap();
		void StoreEnvVarsInMap();
		bool ValidCommand(std::string commandArg);

		//Sanitized values post processing.
		std::map<std::string, std::string> m_CommandArgs;
		std::map<std::string, std::string> m_environmentVars;

		/// <summary>
		/// Initial values as passed in.
		/// </summary>
		std::vector<std::string> m_inputCommandArgs;
		std::vector<std::string> m_inputEnvVars;

		/// <summary>
		/// Values that are valid for the command arguments.  These will be the only ones that can be saved for this 
		/// implementation.  
		/// </summary>
		std::vector<std::string> m_validCommandArgs;
	public:
		// Inherited via ICommandConfiguration
		virtual bool HasCommandArgument(std::string arg) override;
		virtual bool HasEnvironmentVariable(std::string arg) override;
		virtual std::string GetCommandArgument(std::string arg) override;
		virtual std::string GetEnvironmentVariable(std::string varName) override;
	};
}
