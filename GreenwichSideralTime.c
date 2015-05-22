/* see page 87 */

#ifdef ASTROALGO
   #include <math.h>
   #include <stdio.h>
   #include "AstroAlgo.h"

   __declspec(dllexport) short __stdcall
#else
   short
#endif

ShGreenwichMeanSideralTime(double *pdoGreenwichSideralTime, short shY,
                           short shM, short shD, short shH, short shm,
                           short shS, short shCalendar, short shMode)
            /* shCalendar JULIAN for julian, GREGORIAN for gregorian */
            /* shMode 1 gives the result in seconds */
            /* shMode 2 gives the result in degrees */
   {
   short  shReturnValue      = (short) 0;
   short  shIsLeap           = (short) 0;
   double ashDaysInMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   double doInputJulianDate  = (double) 0;

   if (pdoGreenwichSideralTime != NULL)
      {
      *pdoGreenwichSideralTime = (double) 0;
      }

   if (pdoGreenwichSideralTime == NULL)
      {
      shReturnValue = (short) 1;
      }

   else if ((shM < 1) || (shM > 12))
      {
      shReturnValue = (short) 3;
      }

   else if ((shD < 1) || (shD > ashDaysInMonth[(int) shM - 1]))
      {
      shReturnValue = (short) 4;
      }

   else if (   (shH < 0)
            || (shH > 23)
          )
      {
      shReturnValue = (short) 5;
      }

   else if (   (shm < 0)
            || (shm > 59)
          )
      {
      shReturnValue = (short) 6;
      }

   else if (   (shS < 0)
            || (shS > 59)
          )
      {
      shReturnValue = (short) 7;
      }

   else if (   (shCalendar != (short) JULIAN)
            && (shCalendar != (short) GREGORIAN)
          )
      {
      shReturnValue = (short) 8;
      }

   else if (   (shMode != (short) 1)
            && (shMode != (short) 2)
          )
      {
      shReturnValue = (short) 9;
      }

   /* leap year validation */
   else if (ShIsLeapYear(&shIsLeap, (short) shY, shCalendar) != 0)
      {
      shReturnValue = (short) 901;
      }

   else if ((shM == 2) && (shD == 29) && (shIsLeap != 1))
      {
      shReturnValue = (short) 101;
      }

   else if (ShJulianDay(&doInputJulianDate, shY, shM, shD, shCalendar) != 0)
      {
      shReturnValue = (short) 102;
      }

   else if (doInputJulianDate - floor(doInputJulianDate) != (double) 0.5)
      {
      shReturnValue = (short) 103;
      }

   else
      {
      double doT = (double) ((doInputJulianDate - (double) 2451545) /
                              (double) 36525);

      if (shMode == 1)
         {
         *pdoGreenwichSideralTime =
              (   (  ((double)  6 * (double) 3600)
                   + ((double) 41 * (double)   60)
                   + (double) 50.54841
                  )
               +  ((double) 8640184.812866  * doT)
               +  ((double)       0.093104  * doT * doT)
               -  ((double)       0.0000062 * doT * doT * doT)
              );

         *pdoGreenwichSideralTime +=
               (double) 1.00273790935 *
                  (
                     ((double) shH * (double) 3600)
                   + ((double) shm * (double) 60)
                   + ((double) shS)
                  );
         }
      else if (shMode == 2)
         {
         *pdoGreenwichSideralTime =
              (   (double)   100.46061837
               + ((double) 36000.770053608 * doT)
               + ((double)     0.000387933 * doT * doT)
               - ((doT * doT * doT) / (double) 38710000)
              );

          /* add H m S to InputJulianDate, see page 88 */
         }
      }

   return shReturnValue;
   }

