#ifndef IFILEREADER_HPP
#define IFILEREADER_HPP

#include <QDebug>
#include <sstream>

class IFileReader{
public:
    IFileReader();
    virtual ~IFileReader(){}

    virtual void updateStream(){
        qDebug()<<"Update stream was called";
    }

    virtual const std::stringstream& getStream() const{
        qDebug()<<"get stream called";
        //return NULL;
    }

};

#endif // IFILEREADER_HPP
