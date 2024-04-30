#include <stdio.h>
#include <math.h>





int
main( void )
{
	double x;
	for ( x = -1; x < 2; x += 0.5 )
	{
		printf("%f  %f   %f   %f\n", x, fabs(x), ceil(x), floor(x));
		printf("%f  %f\n", pow(x,2), pow(x,.5));
	}

}



