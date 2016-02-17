#ifndef BRANCH_H
#define BRANCH_H

#include <QObject>
#include "polygon.h"

class Branch
{
   Q_OBJECT
public:
   Branch();

private:
   QList<Polygon> model;

};

#endif // BRANCH_H
