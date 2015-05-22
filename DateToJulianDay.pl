#~ /* see page 60 */

sub DateToJulianDay 
   {
   my %ArgumentsDefaultValues = (
                                 day   => undef,
                                 month => undef,
                                 year  => undef
                                );
   my %ArgumentsValues = (%ArgumentsDefaultValues, @_);
   my $ReturnValue     = undef;

   if (   (defined($ArgumentsValues{day})   ==      1)
       && (defined($ArgumentsValues{month}) ==      1)
       && (defined($ArgumentsValues{year})  ==      1)
       && ($ArgumentsValues{day}            >=      1) 
       && ($ArgumentsValues{day}            <=     31)
       && ($ArgumentsValues{month}          >=      1)
       && ($ArgumentsValues{month}          <=     12)
       && ($ArgumentsValues{year}           >= -99999)
       && ($ArgumentsValues{year}           <=  99999)
      )
      {
     my $D = $ArgumentsValues{day};
     my $M = $ArgumentsValues{month};
     my $Y = $ArgumentsValues{year};

     if ($M <= 2)
        {
       $Y -=  1;
       $M += 12;
       }

     my $A = int($Y / 100);
     my $B = 2 - $A + int($A / 4);
     my $JD = int(365.25 * ($Y + 4716)) + int(30.6001 * ($M + 1)) + $D + $B - 1524.5;

     $ReturnValue = $JD;
     }

   return $ReturnValue;
   }

