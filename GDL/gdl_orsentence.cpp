#include "gdl_orsentence.h"

GDL_OrSentence::GDL_OrSentence(QVector<PSentence> b):
    body(b)
{
    buildName();

    for(PSentence s : b){
        dependentConstants = dependentConstants.unite(s->getDependentConstants());
        dependentConstantsNegative = dependentConstantsNegative.unite(s->getDependentConstantsNegative());
    }
}


bool GDL_OrSentence::isGround() const{
    for(PSentence sentence : body){
        if(!sentence->isGround()){
            return false;
        }
    }
    return true;
}

void GDL_OrSentence::buildName(){
    name = QString("(or");
    for(int i=0; i<body.size(); ++i){
        name = name + " " + body[i]->toString();
    }
    name = name + ")";
}

 QString GDL_OrSentence::buildNameRecursively() const{
     QString nameR = QString("(or");
     for(int i=0; i<body.size(); ++i){
         nameR = nameR + " " + body[i]->buildNameRecursively();
     }
     nameR = nameR + ")";
    return nameR;
 }
