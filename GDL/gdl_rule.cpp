#include "gdl_rule.h"

#include <QDebug>

GDL_Rule::GDL_Rule(PRuleHead h, QVector<PSentence> b):
    head(h),
    body(b)
{
    buildName();
    buildSkolemName();

    for(PSentence s : b){
        dependentConstants = dependentConstants.unite(s->getDependentConstants());
        dependentConstantsNegative = dependentConstantsNegative.unite(s->getDependentConstantsNegative());
    }
}

bool GDL_Rule::isGround() const{
    for(PSentence sentence : body)
    {
        if(!sentence->isGround())
            return false;
    }
    return true;
}

QString GDL_Rule::toString() const{
    if(useSkolemNames){
        return skolemName;
    }
    return name;
}

void GDL_Rule::buildName(){
    name = QString("(<= ") + head->getName();
    for(int i=0; i<body.size(); ++i){
        name = name + " " + body[i]->toString();
    }
    name = name + ")";
}

void GDL_Rule::buildSkolemName(){
    skolemName = QString("(<= ") + head->getSkolemName();
    for(int i=0; i<body.size(); ++i){
        skolemName = skolemName + " " + body[i]->toString();
    }
    skolemName = skolemName + ")";
}

QString GDL_Rule::buildNameRecursively() const{
    QString answer = QString("(<= ") + head->buildNameRecursively();
    for(int i=0; i<body.size(); ++i){
        answer = answer + " " + body[i]->buildNameRecursively();
    }
    answer = answer + ")";
    return answer;
}

PRuleHead GDL_Rule::getHead(){
    return head;
}

QVector<PSentence> GDL_Rule::getBody(){
    return body;
}

QSet<PConstant> GDL_Rule::getDependentConstants(){
    return dependentConstants;
}

QSet<PConstant> GDL_Rule::getDependentConstantsNegative(){
    return dependentConstantsNegative;
}
