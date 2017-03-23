#ifndef QUDP_HPP
#define QUDP_HPP

#include <QUdpSocket>
#include <QDebug>
#include <QByteArray>

#include "buffercommands.hpp"

class Udp_test : public QObject{
    Q_OBJECT


public:
    Udp_test(){
        clientSocket=new QUdpSocket(this);
        clientSocket->connect(clientSocket,SIGNAL(readyRead()),
                              this,SLOT(readPendingDatagrams()));
    }

    ~Udp_test(){
        clientSocket->close();
    }


void init(){
    bcast = new QHostAddress("172.168.1.177");
    clientSocket->connectToHost(*bcast,8888,QIODevice::ReadWrite);

    //clientSocket->bind(*bcast, 8888);
    QByteArray buffer;
    buffer.append(0x04);
    //buffer.append("hi");
    clientSocket->write(buffer.data(),buffer.size());
}

void exit(){
    clientSocket->close();
}


void sendData(BufferCommands input){
    if(!m_isConnected)
        qDebug()<<"Not connected! try reconnecting!\n";

    QByteArray* buffer = input.getBuffer();
    //buffer.resize(clientSocket->pendingDatagramSize());
    //buffer.append(str);

    clientSocket->write(buffer->data(),buffer->size());
}

public slots:
void readPendingDatagrams();

public:
    QUdpSocket* clientSocket;
    bool m_isConnected = false;
    QHostAddress* bcast;

    QHostAddress m_sender;
    quint16 m_senderPort;

};

#endif // QUDP_HPP
