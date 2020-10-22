#pragma once
#include <string>
namespace CommsProtocol {
	namespace EthernetConfig {
		enum class ProtocolTypes {
			TCPIP_Client,
			TCPIP_Server,
			UDP,
			MultiCast
		};

		struct SocketSettings {
			std::string IPV4_Address;
			std::string IPV6_Address;
			ProtocolTypes Type;
			uint16_t Port;
		};
	}
}
