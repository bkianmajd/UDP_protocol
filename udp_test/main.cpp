#include <QCoreApplication>
#include <memory>
#include <unordered_map>

#include "cmanager.h"
#include "cshell.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    CManager* manager = new CManager;
    CShell* shell = new CShell(manager->getMap());


    std::unordered_map<int,std::string> menu;


    QObject::connect(shell,SIGNAL(setCommand(int)),
                     manager,SLOT(updateButton(int)));

    QObject::connect(manager,SIGNAL(sendString(QString)),
                     shell,SLOT(updateState(QString)));


    shell->start();


    return a.exec();
}
