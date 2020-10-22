#include "TestMessage.h"
#include <iostream>

using namespace std;
using namespace Message;

ErrorStatus ConcreteMessage::TestMessage::writeToBuffer()
{
    cout << "Heres my message" << endl;    
    return ErrorStatus::success;
}
