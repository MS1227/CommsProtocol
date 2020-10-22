#pragma once
#include <string>
namespace CommsProtocol {
	class ICommandConfiguration
	{
	public:
		virtual bool HasCommandArgument(std::string arg) = 0;
		virtual bool HasEnvironmentVariable(std::string arg) = 0;
		virtual std::string GetCommandArgument(std::string arg) = 0;
		virtual std::string GetEnvironmentVariable(std::string varName) = 0;
	};

}