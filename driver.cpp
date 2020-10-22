#include "TestMessage.h"

void funcThatTakesAMessage( Message::IMessage& msg);

int main()
{
    ConcreteMessage::TestMessage tm;
    funcThatTakesAMessage(tm);
    return 0;
}

void funcThatTakesAMessage( Message::IMessage& msg)
{
    msg.write();
}
