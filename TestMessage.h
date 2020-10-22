#include "IMessage.h"

class TestMessage : public IMessage
{
   void writeToBuffer() override; 
};
