/* see page 65 */

/* DOW = 0 for Sunday, ..., 6 for Saturday */

#ifdef ASTROALGO
   #include <math.h>
   #include <stdio.h>
   #include "AstroAlgo.h"

   __declspec(dllexport) short __stdcall
#else
   short
#endif

ShDayOfWeek(short *pshDOW, double doY, double doM, double doD)
   {
   short  shReturnValue = (short)  0;

   if (pshDOW == NULL)
      {
      shReturnValue = (short) 1;
      }

   else
      {
      double doJD = (double) 0;

      *pshDOW = (short) -1;
      shReturnValue = ShJulianDay(&doJD, doY, doM, doD, (short) GREGORIAN);
      if (shReturnValue == 0)
         {
         doJD += (double) 1.5;
         *pshDOW = (short) ((unsigned long) doJD % (unsigned long) 7);
         }
      }

   return shReturnValue;
   }

