#pragma once
class IMessage
{
    public:
        void write()
        {
            writeToBuffer();
        }
    protected:
        virtual void writeToBuffer() = 0;
};
