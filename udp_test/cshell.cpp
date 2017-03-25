#include "cshell.h"

#include <QDebug>
#include <QProcess>
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>

CShell::CShell(std::shared_ptr<
               std::unordered_map<int,QString>> menuMap) :
m_menuMap(menuMap){


}

void CShell::run(){
    while(true){
        int value;
        std::cin >> value;
        setCommand(value);
    }
}

void CShell::updateState(QString str){
    QProcess::execute("clear");

    auto printOut = [](const int first, const QString& str){
        qDebug()<< first <<": button " << str;
    };
    for(uint16_t i = 1 ; i <= m_menuMap->size(); ++i){
        QString val = m_menuMap->at(i);
        printOut(i,val);
    }

    //std::for_each(m_menuMap->begin(),m_menuMap->end(),printOut);
    qDebug()<<"current state: " << str;
}

