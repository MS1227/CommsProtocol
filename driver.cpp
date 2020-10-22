#include "TestMessage.h"
#include "TestMessageTwo.h"

void funcThatTakesAMessage( IMessage& msg);

int main()
{
    TestMessage tm;
    TestMessageTwo tm2;
    funcThatTakesAMessage(tm);
    funcThatTakesAMessage(tm2);
    return 0;
}

void funcThatTakesAMessage( IMessage& msg)
{
    msg.write();
}
