#ifndef CUDP_H
#define CUDP_H

#include <QDebug>
#include <QUdpSocket>
#include <QByteArray>
#include <QMutex>

class CUdp : public QObject{
    Q_OBJECT
public:
    CUdp();

    ~CUdp(){
        clientSocket.close();
    }

    void init();
    void sendData(const QByteArray& input);
    void lastBuffer(QByteArray& load);
    void exit();


public slots:
    void readPendingDatagrams();

private:
    QUdpSocket clientSocket;
    const QHostAddress m_address;
    const quint16 m_senderPort;

    QByteArray m_recievedBuffer;
    QMutex m_mutex;
};

#endif // CUDP_H
