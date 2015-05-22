
/* see page 23 */

short ShInterpolationDifferences(const double * padoTableValues,
                                 short shNumberOfTableValues,
                                 double * padoDifferences,
                                 size_t stSizeOfpadoDifferences,
                                 short shDifferenceRank)
   {
   short shReturnValue = (short) 0;
   short sh1           = (short) 0;
   short sh2           = (short) 0;

   if (padoTableValues == NULL)
      {
      shReturnValue = (short) 1;
      }

   else if (shNumberOfTableValues < 3)
      {
      shReturnValue = (short) 2;
      }

   else if (padoDifferences == NULL)
      {
      shReturnValue = (short) 3;
      }

   else if (stSizeOfpadoDifferences <
             (size_t) ((long) shNumberOfTableValues * (long) sizeof(double))
           )
      {
      shReturnValue = (short) 4;
      }

   else if ((shDifferenceRank < 1) || (shDifferenceRank > 3))
      {
      shReturnValue = (short) 5;
      }

   else
      {
      for (sh1 = (short) 0 ; sh1 < shNumberOfTableValues ; sh1++)
         {
         padoDifferences[sh1] = padoTableValues[sh1];
         }

      for (sh1 = (short) 1 ; sh1 <= shDifferenceRank ; sh1++)
         {
         for (sh2 = (short) 0 ; sh2 < shNumberOfTableValues ; sh2++)
            {
            if (sh2 >= shNumberOfTableValues - sh1)
               {
               padoDifferences[sh2] = (double) 0;
               }
            else
               {
               padoDifferences[sh2] =   padoDifferences[sh2 + 1]
                                      - padoDifferences[sh2];
               }
            }
         }
      }

   return shReturnValue;
   }

