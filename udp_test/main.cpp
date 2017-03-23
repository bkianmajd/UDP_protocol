#include <QCoreApplication>
#include <iostream>
#include <thread>

#include "qudp.hpp"
#include "shelldiag.hpp"

void Udp_test::readPendingDatagrams(){
    while (clientSocket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(clientSocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        clientSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

        for(int i = 0 ; i < buffer.size(); ++i){
            if(buffer[i] = 0x04){
                m_isConnected = true;
                qDebug()<<"new connection!";
            }
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    //Udp_test test;
    //test.init();

    ShellDiag shell;

    std::thread t1(&ShellDiag::start,&shell);

/*
    bool fml = true;
    while(fml){
        std::string str;
        std::getline(std::cin, str);
        QString qString(str.c_str());

        if(qString.compare("E")==0){
            test.exit();
            fml = false;
        }
    }
*/

    return a.exec();
}
