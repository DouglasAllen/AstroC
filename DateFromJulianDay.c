/* see page 63 */

#ifdef ASTROALGO
   #include <math.h>
   #include <stdio.h>
   #include "AstroAlgo.h"

   __declspec(dllexport) short __stdcall
#else
   short
#endif

ShDateFromJulianDay(double doJD, double *pdoY, double *pdoMonth, double *pdoD,
                                 double *pdoH, double *pdoMin,   double *pdoS)
   {
   short shReturnValue = (short) 0;

   if (pdoY != NULL)
      {
      *pdoY = (double) -1;
      }

   if (pdoMonth != NULL)
      {
      *pdoMonth = (double) -1;
      }

   if (pdoD != NULL)
      {
      *pdoD = (double) -1;
      }

   if (doJD < 0)
      {
      shReturnValue = (short) 1;
      }

   else if (pdoY == NULL)
      {
      shReturnValue = (short) 2;
      }

   else if (pdoMonth == NULL)
      {
      shReturnValue = (short) 3;
      }

   else if (pdoD == NULL)
      {
      shReturnValue = (short) 4;
      }

   else if (pdoH == NULL)
      {
      shReturnValue = (short) 5;
      }

   else if (pdoMin == NULL)
      {
      shReturnValue = (short) 6;
      }

   else if (pdoS == NULL)
      {
      shReturnValue = (short) 7;
      }
   else
      {
      double do1     = (double) 0;
      double do2     = (double) 0;
      double doZ     = floor(doJD + (double) 0.5);
      double doF     = doJD + (double) 0.5 - doZ;
      double doA     = (double) 0;
      double doAlpha = (double) 0;
      double doB     = (double) 0;
      double doC     = (double) 0;
      double doD     = (double) 0;
      double doE     = (double) 0;

      if (doZ < (double) 2299161)
         {
         doA = doZ;
         }
      else
         {
         doAlpha = floor((doZ - (double) 1867216.25) / (double) 36524.25);
         doA = doZ + (double) 1 + doAlpha - floor(doAlpha / (double) 4);
         }

      doB = doA + (double) 1524;
      doC = floor((doB - (double) 122.1) / (double) 365.25);
      doD = floor(doC * (double) 365.25);
      doE = floor((doB - doD) / (double) 30.6001);

      *pdoD = ((doB - doD) - floor(doE * (double) 30.6001)) + doF;
      *pdoMonth = (double) (doE < (double) 14 ? doE - (double)  1
                                              : doE - (double) 13);

      *pdoY = (double) (*pdoMonth > (double) 2 ? doC - (double) 4716
                                               : doC - (double) 4715);


      /* drop fractional parts */
      *pdoY      = floor(*pdoY);
      *pdoMonth  = floor(*pdoMonth);
      *pdoD      = floor(*pdoD);

      /* time */
      do1      = modf(doJD - (double) 0.5, &do2) * (double) 86400;
      *pdoH    = floor(do1 / (double) 3600);
      do1     -= (*pdoH * (double) 3600);
      *pdoMin  = floor(do1 / (double) 60);
      *pdoS    = do1 - (*pdoMin * (double) 60);
      }

   return shReturnValue;
   }



