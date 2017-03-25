#ifndef IFILEMOCK_H
#define IFILEMOCK_H

#include <sstream>

#include <QDebug>

//mocks a file
class IFileMock{
public:
    IFileMock(){}
    virtual ~IFileMock(){}

    virtual void registerBufferCommands(){
        qDebug()<<"register buffer commands called";
    }
    virtual std::stringstream getStringStream(){
        qDebug()<<"get string stream called";
        //return NULL;
    }
};

#endif // IFILEMOCK_H
