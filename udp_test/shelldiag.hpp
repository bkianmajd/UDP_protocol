#ifndef SHELLDIAG_HPP
#define SHELLDIAG_HPP

#include "qudp.hpp"

class ShellDiag{
public:
    ShellDiag(){

    }

    void start(){
        pUdp = new Udp_test();
        pUdp->init();
    }

private:
    Udp_test* pUdp;
};

#endif // SHELLDIAG_HPP
