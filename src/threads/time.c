#include "../../include/philosophers.h"

/*
** DESC: The 'get_time' function gets the actual time in miliseconds.
*/
int	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
