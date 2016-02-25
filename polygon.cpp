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
   if (!vertices.empty())
      foreach (QPoint* a, vertices) {
         delete a;
         }
   if (!vertSequence.empty())
      foreach (QPoint* a, vertSequence) {
         delete a;
         }
   }

void Polygon::appendVert(QPoint point)
   {
   vertices.append(new QPoint(point));
   }

void Polygon::setIsClockwise(bool value)
   {
   isClockwise = value;
   }

void Polygon::setIsCurve(bool value)
   {
   isCurve = value;
   }

void Polygon::setVertices(QList<QPoint*> points)
   {
   vertices = QList<QPoint*>(points);
   points.clear();
   linkPath();
   }

void Polygon::linkPath()
   {
   int max=0;, nAngle;
   double minAngle;
   QList<QPoint*> tempVert = vertices;
   while(tempVert.length() > 0)
      {
      for (int i; i<tempVert.length(); i++){
         if (vertSequence.empty()) {
            if (tempVert.at(max)->y() <= tempVert.at(i)->y() &&
                tempVert.at(max)->x() <  tempVert.at(i)->x())
               max = i;
            }
         else
            {
            double tempAngle = getAngle(tempVert.at(i),vertSequence.last());
            if (tempAngle<minAngle){
               minAngle = tempAngle;
               nAngle = i;
               }
            }
         }
      vertSequence.append(tempVert.takeAt(i));
      }

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
   int a = int(currP.y()<0)<<1 + int(currP.x()<0);
   return ((clockwise)? ~a : a) + 1 & 3;
   }
