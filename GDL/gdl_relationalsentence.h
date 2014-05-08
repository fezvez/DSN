#ifndef GDL_RELATIONALSENTENCE_H
#define GDL_RELATIONALSENTENCE_H

#include "gdl_sentence.h"
#include "gdl_term.h"
#include "gdl_constant.h"

#include <QVector>

class GDL_RelationalSentence;
typedef QSharedPointer<GDL_RelationalSentence> PRelation;

class GDL_RelationalSentence : public GDL_Sentence
{
public:
    GDL_RelationalSentence(PConstant h, QVector<PTerm> b, GDL::GDL_TYPE t);

    bool isGround() const;
    QString buildNameRecursively() const;

    PConstant getRelationConstant() const;
    PConstant getHead() const;
    QVector<PTerm> getBody() const;
    GDL::GDL_TYPE getType() const;




private:
    void buildName();


protected:
    PConstant head;
    QVector<PTerm> body;
    GDL::GDL_TYPE type;
};

#endif // GDL_RELATIONALSENTENCE_H
