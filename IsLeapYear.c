/* see page 62 */

#ifdef ASTROALGO
   #include <assert.h>
   #include <stdio.h>
   #include "AstroAlgo.h"
   __declspec(dllexport) short __stdcall
#else
   short
#endif

ShIsLeapYear(short *pshResult, short shYear, short shCalendar)
                  /* shCalendar JULIAN for julian, GREGORIAN for gregorian */
   {
   short shReturnValue = (short) 0;

   if (pshResult != NULL)
      {
      *pshResult = (short) -1;
      }

   if (pshResult == NULL)
      {
      shReturnValue = (short) 1;
      }

   else if (shCalendar == (short) JULIAN)
      {
      if ((shYear % (short) 4) == 0)
         {
         *pshResult = (short) 1;
         }
      else
         {
         *pshResult = (short) 0;
         }
      }

   else if (shCalendar == (short) GREGORIAN)
      {
      if (   ((shYear % (short) 4) == 0)
          && (   ((shYear % (short) 100) != 0)
              || ((shYear % (short) 400) == 0)
             )
         )
         {
         *pshResult = (short) 1;
         }
      else
         {
         *pshResult = (short) 0;
         }
      }

   else
      {
      shReturnValue = (short) 3;
      }

   return shReturnValue;
   }

