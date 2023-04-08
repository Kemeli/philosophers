#include "philo.h"

int    handle_time(t_args *args)
{
    struct	timeval	next_time;

	gettimeofday (&next_time, NULL);
	args->count_time = (next_time.tv_sec - args->first_time.tv_sec) * 1000.0 
        + (next_time.tv_usec - args->first_time.tv_usec) / 1000.0;
	return (args->count_time);
}

void	grab_forks(t_args *args)
{
	if (args->id == args->num_philo)
	{
		pthread_mutex_lock(args->left_fork);
		pthread_mutex_lock(args->right_fork);
	}
	else
	{
		pthread_mutex_lock(args->right_fork);
		pthread_mutex_lock(args->left_fork);
	}
}

void	*routine(void *arg)
{
	t_args *args;
	args = (t_args *)arg;

	grab_forks (args);

	args->count_time = handle_time (args);
	printf ("\t%d Philosopher %d is eating\n", args->count_time, args->id);

	usleep (args->time2eat);

	pthread_mutex_unlock(args->left_fork);
	pthread_mutex_unlock(args->right_fork);

	args->count_time = handle_time(args);
    printf ("\t%d Philosopher %d is sleeping\n", args->count_time, args->id);

	usleep (args->time2sleep);

	args->count_time = handle_time(args);
	printf ("\t%d Philosopher %d is thinking\n", args->count_time, args->id);

	return (NULL);
}