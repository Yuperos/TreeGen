#include "polygon.h"


Polygon::Polygon()
   {
   isClockwise = true;
   isCurve = false;
   }

Polygon::Polygon(QList<QPoint> points, bool _isClockwise, bool _isCurve)
   {
   setIsClockwise(_isClockwise);
   setIsCurve(_isCurve);
   setVertices(points);
   }

void Polygon::clearVerts()
   {
   vertices.clear();
   vertSequence.clear();
   }

void Polygon::appendVert(QPoint point)
   {
   vertices.append(point);
   }

void Polygon::setIsClockwise(bool value)
   {
   isClockwise = value;
   }

void Polygon::setIsCurve(bool value)
   {
   isCurve = value;
   }

void Polygon::setVertices(QList<QPoint> points)
   {
   vertices = QList(points);
   }



double getAngle(QPoint dstP, QPoint initP)
   {
   dstP-=initP;
   double a = (quad(dstP)%2==0)?dstP.y()/dstP.x() : dstP.x()/dstP.y();
   return atan(a)+ M_PI_2*quad(dstP);
   }


int quad(QPoint currP, QPoint initP, int clockwise)
   {
   currP-=initP;
   int a = (int(currP.y<0)<<1 + int(currP.x<0));
   return ((clockwise)? ~a : a) + 1 & 3;
   }
