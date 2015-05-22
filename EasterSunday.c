/* see page 66 */

#ifdef ASTROALGO
   #include <math.h>
   #include <stdio.h>
   #include "AstroAlgo.h"

   __declspec(dllexport) short __stdcall
#else
   short
#endif

ShEasterSunday(short shYear, short *pshM, short *pshD,
                     short shCalendar, short shReligion)
                  /* shCalendar JULIAN for julian, GREGORIAN for gregorian */
   {
   short shReturnValue = (short) 0;

   if (pshM != NULL)
      {
      *pshM = (short) -1;
      }

   if (pshD != NULL)
      {
      *pshD = (short) -1;
      }

   if (shYear < 0)
      {
      shReturnValue = (short) 1;
      }

   else if (pshM == NULL)
      {
      shReturnValue = (short) 2;
      }

   else if (pshD == NULL)
      {
      shReturnValue = (short) 3;
      }

   else if (   (shCalendar != (short) JULIAN)
            && (shCalendar != (short) GREGORIAN)
          )
      {
      shReturnValue = (short) 4;
      }

   else if (shReligion != (short) CHRISTIAN)
      {
      shReturnValue = (short) 5;
      }

   else if (shCalendar == (short) JULIAN)
      {
      ;
      }

   else if (shCalendar == (short) GREGORIAN)
      {
      short shA = (short) 0;
      short shB = (short) 0;
      short shC = (short) 0;
      short shD = (short) 0;
      short shE = (short) 0;
      short shF = (short) 0;
      short shG = (short) 0;
      short shH = (short) 0;
      short shI = (short) 0;
      short shK = (short) 0;
      short shL = (short) 0;
      short shM = (short) 0;
      short shN = (short) 0;
      short shP = (short) 0;

      shA = (short) (shYear % (short)  19);
      shB = (short) (shYear / (short) 100);
      shC = (short) (shYear % (short) 100);
      shD = (short) (shB    / (short)   4);
      shE = (short) (shB    % (short)   4);
      shF = (short) ((shB + (short) 8) / (short) 25);
      shG = (short) (((shB - shF) + (short) 1) / (short) 3);
      shH = (short) (((short)  (((  (  ((short) 19 * shA)
                                    + shB
                                    )
                                  - shD
                                 )
                                - shG
                               )
                              )
                              + (short) 15
                             )
                       % (short) 30
                     );
      shI = (short) shC / (short) 4;
      shK = (short) ((short) shC % (short) 4);
      shL = (short)((short)   (  (short) 32
                                +  shE
                                +  shE
                                +  shI
                                +  shI
                                -  shH
                                -  shK
                               )
                       % (short) 7
                     );
      shM = (short) (  (  shA
                         + ((short) 11 * shH)
                         + ((short) 22 * shL)
                        )
                      / (short) 451
                     );
      shN = (short) (  (  shH
                         + shL
                         - ((short) 7 * shM)
                         + (short) 114
                        )
                      / (short) 31
                     );
       shP = (short) ((short)(  (  shH
                                  + shL
                                  - ((short) 7 * shM)
                                  + (short) 114
                                 )
                              )
                        % (short) 31
                       );

      *pshM = shN;
      *pshD = shP + (short) 1;

      #if 0
      (void) fprintf(stdout,
                     "Year %02hd : %hd/%02hd (a=%02hd, b=%hd, c=%02hd,"
                     " d=%hd, e=%hd, f=%hd, g=%hd, h=%02hd, "
                     "i=%02hd, k=%hd, l=%hd, m=%hd, n=%hd, "
                     "p=%02hd)\n"
                     ,
                     shYear, *pshM, *pshD, shA, shB, shC, shD, shE, shF, shG,
                     shH, shI, shK, shL, shM, shN, shP);

      #endif
      }
   return shReturnValue;
   }

