#ifndef GDL_RULEHEAD_H
#define GDL_RULEHEAD_H

#include "gdl_relationalsentence.h"

class GDL_RuleHead;
typedef QSharedPointer<GDL_RuleHead> PRuleHead;

class GDL_RuleHead : public GDL_RelationalSentence
{
public:
    GDL_RuleHead(PConstant h, QVector<PTerm> b, GDL_TYPE t, PConstant skolemH);

    QString toString() const;
    QString getSkolemName();

private:
    void buildName();
    void buildSkolemName();

protected:
    PConstant skolemHead;
    QString skolemName;
};

#endif // GDL_RULEHEAD_H
