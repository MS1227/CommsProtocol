#pragma once
#include "IMessage.h"

namespace ConcreteMessage
{
    class TestMessage : public Message::IMessage
    {
       Message::ErrorStatus writeToBuffer() override; 
    };
}
