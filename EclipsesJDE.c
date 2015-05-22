
/* see page 379 */

#ifdef ASTROALGO
   #include <math.h>
   #include <stdio.h>
   #include "AstroAlgo.h"

   __declspec(dllexport) short __stdcall
#else
   short
#endif

#define D (double)

ShEclipsesJDE(double *pdoResult, double doYear, short shType)
   {
   short  shReturnValue = (short)  0;

   double doA1      = D 0;
   double doE       = D 0;
   double doF       = D 0;
   double doF1      = D 0;
   double doJDE     = D 0;
   double doJDEcorr = D 0;
   double doK       = D 0;
   double doM       = D 0;
   double doM_      = D 0;
   double doO       = D 0;
   double doP       = D 0;
   double doQ       = D 0;
   double doT0       = D 0;
   double doT1       = D 0;
   double doTemp1   = D 0;

   if (pdoResult == NULL)
      {
      shReturnValue = (short) 1;
      }
   else if ((doYear < -2000) || (doYear > 6000))
      {
      shReturnValue = (short) 2;
      }
   else if ((shType < 0) || (shType > 1))   /* 0 solar eclipse, 1 lunar eclipse */
      {
      shReturnValue = (short) 3;
      }
   else
      {
      *pdoResult = D -1;

      doK = (doYear - D 2000) * D 12.3685;
      doK = floor(doK);

      if (shType == 1)     /* lunar eclipse */
         {
         doK += D 0.5;
         }

      doT0 = doK / D 1236.85;

      doJDE =    D 2451550.09766
              + (D 29.530588861  * doK)
              + (D 0.0015437     * doT0 * doT0)
              + (D 0.000000150   * doT0 * doT0 * doT0)
              + (D 0.00000000073 * doT0 * doT0 * doT0 * doT0);

      doF  =     D 160.7108
              + (D 390.67050284  * doK)
              - (D   0.0016118   * doT0 * doT0)
              - (D   0.00000227  * doT0 * doT0 * doT0)
              + (D   0.000000011 * doT0 * doT0 * doT0 * doT0);

      doF  = REDUCE360(doF);

      doTemp1 = sin(DEGREES2RADIAN(doF));
      if (doTemp1 < 0)                               /* abs */
         {
         doTemp1 *= D -1;
         }

      if (doTemp1 > D 0.3583679495453)               /* no eclipse */
         {
         *pdoResult = D 0;
         }
      else
         {
         doT1 = (doJDE - D 2451545) / D 36525;

         doE   =    D 1
                 - (D 0.002516      * doT1)
                 - (D 0.0000074     * 1 * doT1);

         doM   =    D   2.5534
                 + (D  29.10535670  * doK)
                 - (D   0.0000014   * doT1 * doT1)
                 - (D   0.00000011  * doT1 * doT1 * doT1);

         doM_  =    D 201.5643
                 + (D 385.81693528  * doK)
                 + (D   0.0107582   * doT1 * doT1)
                 + (D   0.0000138   * doT1 * doT1 * doT1)
                 - (D   0.000000058 * doT1 * doT1 * doT1 * doT1);


         doO   =    D 124.7746
                 - (D   1.56375588  * doK)
                 + (D   0.0020672   * doT1 * doT1)
                 + (D   0.00000215  * doT1 * doT1 * doT1);

         doA1 = (D 299.77 + (D 0.107408 * doK)) - (D 0.009173 * doT1 * doT1);
         doF1 = doF - (D 0.02665 * sin(DEGREES2RADIAN(doO)));

         if (shType == 0)          /* solar eclipse */
            {
            doJDEcorr += D -0.4075       * sin(DEGREES2RADIAN(doM_));
            doJDEcorr += D  0.1721 * doE * sin(DEGREES2RADIAN(doM));
            }

         else if (shType == 1)     /* lunar eclipse */
            {
            doJDEcorr += D -0.4065       * sin(DEGREES2RADIAN(doM_));
            doJDEcorr += D  0.1727 * doE * sin(DEGREES2RADIAN(doM));
            }
         else
            {
            shReturnValue = (short) 4;
            }

         doJDEcorr += D  0.0161       * sin(DEGREES2RADIAN(D 2 * doM_));
         doJDEcorr += D -0.0097       * sin(DEGREES2RADIAN(D 2 * doF1));
         doJDEcorr += D  0.0073 * doE * sin(DEGREES2RADIAN(doM_ - doM));
         doJDEcorr += D -0.0050 * doE * sin(DEGREES2RADIAN(doM_ + doM));
         doJDEcorr += D -0.0023       * sin(DEGREES2RADIAN(doM_ - (D 2 * doF1)));
         doJDEcorr += D  0.0021 * doE * sin(DEGREES2RADIAN(D 2 * doM));
         doJDEcorr += D  0.0012       * sin(DEGREES2RADIAN(doM_ + (D 2 * doF1)));
         doJDEcorr += D  0.0006 * doE * sin(DEGREES2RADIAN((D 2 * doM_) + doM));
         doJDEcorr += D -0.0004       * sin(DEGREES2RADIAN(D 3 * doM_));
         doJDEcorr += D -0.0003 * doE * sin(DEGREES2RADIAN(doM + (D 2 * doF1)));
         doJDEcorr += D  0.0003       * sin(DEGREES2RADIAN(doA1));
         doJDEcorr += D -0.0002 * doE * sin(DEGREES2RADIAN(doM - (D 2 * doF1)));
         doJDEcorr += D -0.0002 * doE * sin(DEGREES2RADIAN((D 2 * doM_) - doM));
         doJDEcorr += D -0.0002       * sin(DEGREES2RADIAN(doO));
         }

      doP += D  0.2070 * doE * sin(DEGREES2RADIAN(doM));
      doP += D  0.0024 * doE * sin(DEGREES2RADIAN(D 2 * doM));
      doP += D -0.0392       * sin(DEGREES2RADIAN(doM_));
      doP += D  0.0116       * sin(DEGREES2RADIAN(D 2 * doM_));
      doP += D -0.0073 * doE * sin(DEGREES2RADIAN(doM_ + doM));
      doP += D  0.0067 * doE * sin(DEGREES2RADIAN(doM_ - doM));
      doP += D  0.0118       * sin(DEGREES2RADIAN(D 2 * doF1));

      *pdoResult =  doJDE + doJDEcorr;
      }

   #if 1
   doM  = REDUCE360(doM);
   doM_ = REDUCE360(doM_);
   doO  = REDUCE360(doO);
   doF1 = REDUCE360(doF1);

   (void) fprintf(stdout, "\n*pdoResult = %13.4f", *pdoResult);
   (void) fprintf(stdout, "\nA1         = %13.4f", doA1);
   (void) fprintf(stdout, "\nE          = %13.4f", doE);
   (void) fprintf(stdout, "\nF          = %13.4f", doF);
   (void) fprintf(stdout, "\nF1         = %13.4f", doF1);
   (void) fprintf(stdout, "\nJDE        = %13.4f", doJDE);
   (void) fprintf(stdout, "\nJDEcorr    = %13.4f", doJDEcorr);
   (void) fprintf(stdout, "\nk          = %13.4f", doK);
   (void) fprintf(stdout, "\nM          = %13.4f", doM);
   (void) fprintf(stdout, "\nM_         = %13.4f", doM_);
   (void) fprintf(stdout, "\nO          = %13.4f", doO);
   (void) fprintf(stdout, "\nP          = %13.4f", doP);
   (void) fprintf(stdout, "\nQ          = %13.4f", doQ);
   (void) fprintf(stdout, "\nT0         = %13.4f", doT0);
   (void) fprintf(stdout, "\nT1         = %13.4f", doT1);
   (void) fprintf(stdout, "%s", "\n");
   #endif

   return shReturnValue;
   }

#undef D

