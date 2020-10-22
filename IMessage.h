#pragma once
namespace Message
{
    enum class ErrorStatus { success, fail };
    class IMessage 
    {
        public:
            ErrorStatus write()
            {
                return writeToBuffer();
            }
        protected:
            virtual Message::ErrorStatus writeToBuffer() = 0;
        
    };
}
