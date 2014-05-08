#include "gdl_rulehead.h"

GDL_RuleHead::GDL_RuleHead(PConstant h, QVector<PTerm> b, GDL_TYPE t, PConstant skolemH):GDL_RelationalSentence(h,b,t),
    skolemHead(skolemH)
{
    buildSkolemName();
}

QString GDL_RuleHead::toString() const{
    if(useSkolemNames){
        return skolemName;
    }
    return name;
}

QString GDL_RuleHead::getSkolemName(){
    return skolemName;
}

void GDL_RuleHead::buildSkolemName(){
    if(skolemHead.isNull()){
        skolemName = head->toString();
    }
    else{
        skolemName = skolemHead->toString();
    }

    skolemName = QString('(') + skolemName;
    for(int i=0; i<body.size(); ++i){
        skolemName = skolemName + " " + body[i]->toString();
    }
    skolemName = skolemName + ")";
}


void GDL_RuleHead::buildName(){

    name = QString('(') + getHead()->toString();
    for(int i=0; i<body.size(); ++i){
        name = name + " " + body[i]->toString();
    }
    name = name + ")";

    if(type==GDL::NEXT){
        name = QString("next ") + name;
    }
    if(type==GDL::BASE){
        name = QString("base ") + name;
    }
}

