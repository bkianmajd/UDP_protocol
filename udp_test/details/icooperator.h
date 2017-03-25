#ifndef ICOOPERATOR_H
#define ICOOPERATOR_H

#include <sstream>

#include "bufferholder.hpp"

class ICooperator{
public:
    ICooperator(){}
    virtual ~ICooperator(){}

    virtual babak::pCommand handleDifference(const std::stringstream& newStream) const{
        qDebug()<<"handle difference called";
        return NULL;
    }

};

#endif // ICOOPERATOR_H
