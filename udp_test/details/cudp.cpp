#include "cudp.h"
#include <QMutexLocker>

CUdp::CUdp() : m_address("172.168.1.177"),
clientSocket(this),m_senderPort(8888){
    clientSocket.connect(&clientSocket,SIGNAL(readyRead()),
                         this,SLOT(readPendingDatagrams()));
}

void CUdp::init(){
    clientSocket.connectToHost(m_address,m_senderPort,QIODevice::ReadWrite);

    QByteArray buffer;
    buffer.append(0x04);
    clientSocket.write(buffer.data(),buffer.size());
}

void CUdp::exit(){
    clientSocket.close();
}

void CUdp::readPendingDatagrams(){
    QByteArray buffer;
    while (clientSocket.hasPendingDatagrams()) {
        buffer.resize(clientSocket.pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        clientSocket.readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
    }
    QMutexLocker locker(&m_mutex);
    m_recievedBuffer.append(buffer);
}

void CUdp::sendData(const QByteArray& buffer){
    clientSocket.write(buffer.data(),buffer.size());
}

void CUdp::lastBuffer(QByteArray& load){
    QMutexLocker locker(&m_mutex);
    load.append(m_recievedBuffer);

    m_recievedBuffer.clear();
    return;
}
