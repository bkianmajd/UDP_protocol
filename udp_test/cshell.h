#ifndef CSHELL_H
#define CSHELL_H

#include <QObject>
#include <QString>
#include <QThread>
#include <memory>
#include <unordered_map>

class CShell : public QThread
{
    Q_OBJECT
public:
    CShell(std::shared_ptr<std::unordered_map<int,QString>> m);


signals:
    void setCommand(int command);

public slots:
    void updateState(QString str);

private:
    std::shared_ptr<std::unordered_map<int,QString>> m_menuMap;
    void run();
};

#endif // CSHELL_H
