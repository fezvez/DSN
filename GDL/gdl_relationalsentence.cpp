#include "gdl_relationalsentence.h"

#include <QDebug>

GDL_RelationalSentence::GDL_RelationalSentence(PConstant h, QVector<PTerm> b, GDL_TYPE t):
    head(h),
    body(b),
    type(t)
{
    buildName();
    dependentConstants.insert(h);
}


bool GDL_RelationalSentence::isGround() const{
    for(PTerm term : body)
    {
        if(!term->isGround()){
            return false;
        }
    }
    return true;
}


void GDL_RelationalSentence::buildName(){

    name = QString('(') + getHead()->toString();
    for(int i=0; i<body.size(); ++i){
        name = name + " " + body[i]->toString();
    }
    name = name + ")";

    if(type==GDL::TRUE){
        name = QString("true ") + name;
    }
    if(type==GDL::INIT){
        name = QString("init ") + name;
    }
}



QString GDL_RelationalSentence::buildNameRecursively() const{
    QString answer = getHead()->buildNameRecursively();
    switch(body.size()){
    case 0:
        break;
    case 1:
        answer = QString('(') + answer + ' ' + body[0]->buildNameRecursively() + ')';
        break;
    default:
        answer = QString('(') + answer + " (" + body[0]->buildNameRecursively();
        for(int i=1; i<body.size(); ++i){
            answer = answer + " " + body[i]->buildNameRecursively();
        }
        answer = answer + "))";
        break;
    }

    return answer;
}

PConstant GDL_RelationalSentence::getRelationConstant() const{
    return head;
}

PConstant GDL_RelationalSentence::getHead() const{
    return getRelationConstant();
}
QVector<PTerm> GDL_RelationalSentence::getBody() const{
    return body;
}


GDL::GDL_TYPE GDL_RelationalSentence::getType() const{
    return type;
}


