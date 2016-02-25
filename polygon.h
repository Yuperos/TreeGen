#ifndef POLYGON_H
#define POLYGON_H

#include <QPoint>
#include <Qlist>
#include <math.h>

class Polygon
{
   QList<QPoint*> vertices;
   QList<QPoint*> vertSequence;
   bool isClockwise;
   bool isCurve;

public:
   Polygon();
   Polygon(QList<QPoint> points, bool _isClockwise=true, bool _isCurve=false);

   void clearVerts();
   void appendVert(QPoint point);
   void setIsClockwise(bool value);
   void setIsCurve(bool value);
   void setVertices(QList<QPoint *> points);
   void linkPath();
};


static double getAngle(QPoint dstP, QPoint initP=QPoint());
static int quad(QPoint currP, QPoint initP=QPoint(), bool clockwise=true);

#endif // POLYGON_H
