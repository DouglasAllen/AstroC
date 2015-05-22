/* see page 66 */

#ifdef ASTROALGO
   #include <math.h>
   #include <stdio.h>
   #include "AstroAlgo.h"

   __declspec(dllexport) short __stdcall
#else
   short
#endif

ShDateFromYearDay(double doYD, short shYear, double *pdoM, double *pdoD)
   {
   short shReturnValue = (short) 0;
   short shIsLeap      = (short) 0;

   if (pdoM != NULL)
      {
      *pdoM = (double) -1;
      }

   if (pdoD != NULL)
      {
      *pdoD = (double) -1;
      }

   if (ShIsLeapYear(&shIsLeap, shYear,
                         (short) (shYear < 1582 ? JULIAN : GREGORIAN)) != 0)
      {
      shReturnValue = (short) 2;
      }

   else if (   (doYD < 0)
            || (doYD > (shIsLeap == 0 ? 365 : 366))
           )
      {
      shReturnValue = (short) 1;
      }

   else if (pdoM == NULL)
      {
      shReturnValue = (short) 3;
      }

   else if (pdoD == NULL)
      {
      shReturnValue = (short) 4;
      }

   else
      {
      if (doYD < 32)
         {
         *pdoM = (double) 1;
         }
      else
         {
         *pdoM = floor(  (   (  (double) 9
                              * (  (double) (shIsLeap == 1 ? 1 : 2)
                                 + doYD
                                )
                             )
                           / (double) 275
                         )
                       + (double) (0.98)
                       );

         }

      *pdoD = (   (  doYD
                   - floor( (  ((double) 275 * (*pdoM))
                             / (double) 9
                            )
                          )
                   )

                +  (  (double) (shIsLeap == 1 ? 1 : 2)
                    * floor(  (*pdoM + (double) 9)
                            / (double) 12
                           )
                   )
                + (double) 30
              );

      }

   return shReturnValue;
   }

