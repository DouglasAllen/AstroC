
/* see page 82 */

double DoRhoSinPhiTwo(double doPhi, double doHeight)
   {
   double doReturnValue = (double) 0;

   double doU =  atan((((double) 1 - DO_EARTH_FLATTENING)
                       * tan(DEGREES2RADIAN(doPhi))));

   #if 0
   (void) fprintf(stdout, "\n%s line %ld doU = %8.6f", __FILE__, __LINE__,
                  RADIAN2DEGREES(doU));
   #endif

   doReturnValue = (   (  ((double) 1 - DO_EARTH_FLATTENING)
                        * sin(doU)
                       )
                    +  (  (  doHeight
                           / (double) DO_EARTH_EQUATORIAL_RADIUS
                          )
                        * sin(doU)
                       )
                    );

   return doReturnValue;
   }

