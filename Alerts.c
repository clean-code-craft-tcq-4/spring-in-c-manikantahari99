#include "stdio.h"
#include "Alerts.h"


int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void emailAlerter(void)
{
	emailAlertCallCount = 1;
}
void ledAlerter(void)
{
	ledAlertCallCount = 1;
}
