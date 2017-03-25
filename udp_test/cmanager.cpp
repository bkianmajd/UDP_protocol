#include "cmanager.h"
#include <QObject>

#include <sstream>
#include <QDebug>

CManager::CManager(){
    m_timer = std::make_shared<QTimer>(this);

    QObject::connect(m_timer.get(), SIGNAL(timeout()),
            this, SLOT(processState()));

    m_menuMap = std::make_shared<std::unordered_map<int,QString>>();
    m_menuMap->insert(std::pair<int,QString>(1,"Init Connection"));
    m_menuMap->insert(std::pair<int,QString>(2,"Disconnect"));

    m_timer->start(1000);
}


void CManager::handleButton(){
    switch(m_button){
    case 1:
        m_currentState = EState::CONNECTING;
        break;
    case 2:
        m_currentState = EState::DISCONNECTED;
        break;
    default:
        break;
    }
}

void CManager::processState(){
    //1. Handle Button Press
    handleButton();

    //2. Handle Sate
    switch(m_currentState){
    case IDLE:
        break;
    case CONNECTING:
        if(!m_udpManager->init())//this is blocking
            m_currentState = EState::DISCONNECTED;
        break;
    case CONNECTED:
        sequence();
        break;
    case DISCONNECTED:
        break;
    default:
        break;
    }

    //3. output
    switch(m_currentState){
    case IDLE:
        emit sendString("IDLE");
        break;
    case CONNECTING:
        emit sendString("CONNECTING");
        break;
    case CONNECTED:
        emit sendString("CONNECTED");
        break;
    case DISCONNECTED:
        emit sendString("DISCONNECTED");
        break;
    default:
        break;
    }
}

const std::shared_ptr<std::unordered_map<int,QString>> CManager::getMap(){
    return m_menuMap;
}

void CManager::sequence(){
    //1. Update reader
    m_reader->updateStream();
    //2. Cooperator get difference
    babak::pCommand command = m_coop->handleDifference(m_reader->getStream());
    //3. Send command out to upd manager
    if(!m_udpManager->handleCommand(command))//this is blocking
        m_currentState = EState::DISCONNECTED;
}

void CManager::updateButton(int button){
    m_button = button;
}

