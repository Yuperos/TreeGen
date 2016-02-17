#ifndef POLYGON_H
#define POLYGON_H

#include <QPoint>
#include <Qlist>
#include <math.h>

class Polygon
{
   QList<QPoint> vertices;
   QList<*QPoint> path;
   bool isClockwise;
   bool isCurve;

public:
   Polygon();

   static double getAngle(QPoint dstP, QPoint initP=0);
   static int quad(QPoint currP, QPoint initP=0, int clockwise=true);
};



#endif // POLYGON_H
