#ifndef GDL_RULE_H
#define GDL_RULE_H

#include "gdl.h"
#include "gdl_relationalsentence.h"
#include "gdl_rulehead.h"
#include "gdl_sentence.h"
#include "gdl_constant.h"
#include "gdl_variable.h"

#include <QVector>
#include <QSharedPointer>

class GDL_Rule;
typedef QSharedPointer<GDL_Rule> PRule;

class GDL_Rule : public GDL
{
public:
    GDL_Rule(PRuleHead h, QVector<PSentence> b);

    bool isGround() const;
    QString toString() const;
    QString buildNameRecursively() const;

    PRuleHead getHead();
    QVector<PSentence> getBody();

    QSet<PConstant> getDependentConstants();
    QSet<PConstant> getDependentConstantsNegative();



private:

    void buildName();
    void buildSkolemName();
    void buildVariables();

private:
    PRuleHead head;
    QVector<PSentence> body;
    QSet<PConstant> dependentConstants;
    QSet<PConstant> dependentConstantsNegative;

    QMap<QString, PVariable> variables;

    QString skolemName;
};

#endif // GDL_RULE_H
