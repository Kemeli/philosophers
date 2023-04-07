


#include "philo.h"

int    handle_time(t_args *args)
{
    int count_time = 0;
    struct	timeval	first_time;
    struct	timeval	sec_time;

    gettimeofday (&first_time, NULL);
	usleep (args->time2eat);
	gettimeofday (&sec_time, NULL);
	count_time = (sec_time.tv_sec - first_time.tv_sec) * 1000.0 + (sec_time.tv_usec - first_time.tv_usec) / 1000.0;
	return (count_time);
}

void	*routine(void *arg)
{
	t_args *args;
	struct	timeval	third_time;
	pthread_mutex_t gate;
	int	count_time = 0;

	args = (t_args *)arg;
	args->id +=1;
	pthread_mutex_init(&gate, NULL);
	pthread_mutex_lock(&gate);

	printf ("\t%d Philosopher %d is eating\n", count_time, args->id);
    count_time = handle_time(args);
    printf ("\t%d Philosopher %d is sleeping\n", count_time, args->id);

	usleep (args->time2sleep);
	gettimeofday (&third_time, NULL);
	count_time = (third_time.tv_sec - first_time.tv_sec) * 1000.0 + (third_time.tv_usec - first_time.tv_usec) / 1000.0;
	printf ("\t%d Philosopher %d is thinking\n", count_time, args->id);

	pthread_mutex_unlock(&gate);
	return (NULL);
}