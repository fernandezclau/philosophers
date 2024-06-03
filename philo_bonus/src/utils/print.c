#include "../../include/philosophers_bonus.h"

void    write_action(int action)
{
        if (action == EAT)
                printf(" is eating\n");
        else if (action == SLEEP)
                printf(" is sleeping\n");
        else if (action == THINK)
                printf(" is thinking\n");
        else if (action == TAKE_FORK)
                printf(" has taken a fork\n");
        else if (action == END)
        	printf("The number of meals has been reached");
	else
                printf(" died\n");
}

static void    write_timestamp(int start)
{
        int     timestamp;

        timestamp = get_time() - start;
        ft_putnbr(timestamp);
        write(1, "\t", 1);
}

/*
** DESC: The 'print_action' function logs the actio of a certain
** philosopher with timestamps.
*/
void    print_action(int action, t_philo *philo, t_options *opt)
{
        static int      is_dead = 0;

        sem_wait(opt->write);
        if (!is_dead)
        {
                write_timestamp(opt->start);
                if (action != END)
                        ft_putnbr(philo->id + 1);
                if (action >= DIE)
                        is_dead = 1;
                write_action(action);
        }
        sem_post(opt->write);
}
