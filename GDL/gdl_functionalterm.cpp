#include "gdl_functionalterm.h"

#include <QDebug>

GDL_FunctionalTerm::GDL_FunctionalTerm(PConstant h, QVector<PTerm> b):
    head(h),
    body(b)
{
    buildName();
}

bool GDL_FunctionalTerm::isGround() const{
    for(PTerm term : body)
    {
        if(!term->isGround())
            return false;
    }
    return true;
}

void GDL_FunctionalTerm::buildName(){
    name = QString('(') + head->getName();
    for(int i=0; i<body.size(); ++i){
        name = name + " " + body[i]->toString();
    }
    name = name + ")";
}

QString GDL_FunctionalTerm::buildNameRecursively() const{
    QString answer = QString('(') + head->buildNameRecursively() ;
    for(int i=0; i<body.size(); ++i){
        answer = answer + " " + body[i]->buildNameRecursively();
    }
    answer = answer + ")";

    return answer;
}

bool GDL_FunctionalTerm::operator==(const GDL_Term & t){
    return name==t.toString();
}
