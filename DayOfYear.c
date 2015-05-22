
/* see page 65 */

#ifdef ASTROALGO
   #include <math.h>
   #include <stdio.h>
   #include "AstroAlgo.h"

   __declspec(dllexport) short __stdcall
#else
   short
#endif

ShDayOfYear(short *pshDOY, double doY, double doM, double doD)
   {
   short  shReturnValue = (short)  0;

   if (pshDOY == NULL)
      {
      shReturnValue = (short) 1;
      }

   else
      {
      short shIsLeap = (short) 0;

      *pshDOY = (short) -1;
      shReturnValue = ShIsLeapYear(&shIsLeap, (short) doY,
                                  (short) (doY < 1582 ? JULIAN : GREGORIAN));

      if (shReturnValue == 0)
         {
         *pshDOY = (short) (((  floor((((double) 275) * doM) / (double)  9)
                              - (  (double) (shIsLeap == 1 ? 1 : 2)
                                 *  floor((((double)   9) + doM) / (double) 12)
                                )
                              )
                              + doD
                             )
                            - (double) 30
                           );
         }
      }

   return shReturnValue;
   }

