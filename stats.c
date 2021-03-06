#include "stats.h"
#include "stdio.h"
#include "math.h"



//This Function is used to calculate the Min, Max and Average.
struct Stats compute_statistics(const float* numberset, int setlength)
{
	float sum = 0;
	float min = 0;
	float max = 0;
	struct Stats s;
	int count = 0;

	s.max = NAN;
	s.average = NAN;
	s.min = NAN;


	if (numberset != nullptr)
	{
		min = numberset[0];
		max = numberset[0];

		while (count < setlength)
		{
			if (numberset[count] > max)
				max = numberset[count];
			if (numberset[count] < min)
				min = numberset[count];

			sum = sum + numberset[count];

			count++;
		}
		s.average = 1.0*sum / setlength;
		s.max = max;
		s.min = min;
	}

	return s;
}

//This Function is used to Check the threshold and Alert the user.
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{

	if (alerters != nullptr)
	{
		/*If the max value is greater than the Threshold value. It should call email Alert and Led Alert*/
		if (computedStats.max > maxThreshold)
		{
			alerters[0]();//Email Alert
			alerters[1]();//Led Alert
		}
	}

}
