#pragma once
#include "IMessage.h"

class TestMessageTwo : public IMessage
{
   void writeToBuffer() override; 
};
