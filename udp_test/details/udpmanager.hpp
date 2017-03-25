#ifndef UDPMANAGER_HPP
#define UDPMANAGER_HPP

#include "cudp.h"
#include "bufferholder.hpp"

#include <memory>
#include <QString>

//handles bufferCommands
namespace babak{


class UdpManager{
public:
    UdpManager(){

    }

    bool init(){

    }

    bool handleCommand(pCommand command){

    }


private:
    CUdp m_udp;
};
}

#endif // UDPMANAGER_HPP
