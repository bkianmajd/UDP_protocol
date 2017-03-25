#ifndef BUFFERCOMMANDS_HPP
#define BUFFERCOMMANDS_HPP

#include <QByteArray>

namespace babak{

class BufferHolder{
public:
    BufferHolder(){

    }

    void append(QString val){
        m_buffer.append(val);
    }

    QByteArray* getBuffer(){
        return &m_buffer;
    }

    int checkSum(){
        int sum = 0;
        for(int i = 0 ; i < m_buffer.size(); ++i){
            sum+= m_buffer[i];
        }
        return sum;
    }

private:
    bool isPassed = false;
    QByteArray m_buffer;
};

using pCommand = std::shared_ptr<BufferHolder>;

}
#endif // BUFFERCOMMANDS_HPP
