#include "polygon.h"

Polygon::Polygon()
   {
   isClockwise = true;
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
