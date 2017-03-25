#ifndef IUDPMANAGER_H
#define IUDPMANAGER_H

#include "bufferholder.hpp"

class IUdpManager{
public:
    IUdpManager(){}
    virtual ~IUdpManager(){}

    bool init(){
        qDebug()<<"Init was called";
        return true;
    }

    bool handleCommand(babak::pCommand command){
        qDebug()<<"A command was handled";
        return true;
    }
};

#endif // IUDPMANAGER_H
