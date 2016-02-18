#ifndef POLYGON_H
#define POLYGON_H

#include <QPoint>
#include <Qlist>
#include <math.h>

class Polygon
{
   QList<QPoint> vertices;
   QList<*QPoint> vertSequence;
   bool isClockwise;
   bool isCurve;

public:
   Polygon();
   Polygon(QList<QPoint> points, bool _isClockwise=true, bool _isCurve=false);

   void clearVerts();
   void appendVert(QPoint point);
   void setIsClockwise(bool value);
   void setIsCurve(bool value);
   void setVertices(QList<QPoint> points);
};

static double getAngle(QPoint dstP, QPoint initP=0);
static int quad(QPoint currP, QPoint initP=0, int clockwise=true);

#endif // POLYGON_H
