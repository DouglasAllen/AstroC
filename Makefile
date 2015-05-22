.cc.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $<
	
all: AstronomicalAlgorithms


AstronomicalAlgorithms : AstronomicalAlgorithms.o
	cc -o AstronomicalAlgorithms AstronomicalAlgorithms.o -lm

phony :
#~ InterpolationDifferences.o : InterpolationDifferences.c
	#~ cc -c InterpolationDifferences.c
	
#~ IsLeapYear.o : IsLeapYear.c
	#~ cc -c IsLeapYear.c

#~ JulianDay.o : JulianDay.c
	#~ cc -c JulianDay.c
	
#~ DateFromJulianDay.o : DateFromJulianDay.c
	 #~ cc -c DateFromJulianDay.c
	 
#~ DayOfWeek.o : DayOfWeek.c
	 #~ cc -c DayOfWeek.c
	 
#~ DayOfYear.o : DayOfYear.c
	#~ cc -c DayOfYear.c
	
#~ DateFromYearDay.o : DateFromYearDay.c
	#~ cc -c DateFromYearDay.c
	
#~ EasterSunday.o : EasterSunday.c
	#~ cc -c EasterSunday.c
	
#~ RhoSinPhiTwo.o : RhoSinPhiTwo.c
	#~ cc -c RhoSinPhiTwo.c
	
#~ RhoCosPhiTwo.o : RhoCosPhiTwo.c
	#~ cc -c RhoCosPhiTwo.c
	
#~ MoonPhasesJDE.o : MoonPhasesJDE.c
	#~ cc -c MoonPhasesJDE.c
	
#~ SolarCoordinates.o : SolarCoordinates.c
	#~ cc -c SolarCoordinates.c
	
#~ EclipsesJDE.o : EclipsesJDE.c
	#~ cc -c EclipsesJDE.c