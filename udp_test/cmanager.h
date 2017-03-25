#ifndef CMANAGER_H
#define CMANAGER_H

#include <QTimer>
#include <memory>
#include <atomic>
#include <unordered_map>

#include "ifilereader.h"
#include "ifilemock.h"
#include "icooperator.h"
#include "iudpmanager.h"

enum EState{
    IDLE = 0,
    CONNECTED,
    DISCONNECTED,
    CONNECTING,
};

class CManager : public QObject{
    Q_OBJECT
public:
    CManager();
    ~CManager(){}

    void init();
    void start();
    const std::shared_ptr<std::unordered_map<int,QString>> getMap();


signals:
    void sendString(QString str);

public slots:
void updateButton(int button);
void processState();

private:
    std::shared_ptr<QTimer> m_timer;
    std::atomic<int> m_button;
    EState m_currentState = EState::IDLE;
    std::shared_ptr<std::unordered_map<int,QString>> m_menuMap;

    //interfaces
    std::shared_ptr<IUdpManager> m_udpManager;
    std::shared_ptr<IFileReader> m_reader;
    std::shared_ptr<ICooperator> m_coop;

    //methods
    void sequence();
    void handleButton();
};

#endif // CMANAGER_H
