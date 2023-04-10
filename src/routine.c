#include "philo.h"

int    handle_time(t_args *args)
{
    struct	timeval	next_time;

	gettimeofday (&next_time, NULL);
	args->count_time = (next_time.tv_sec - args->first_time.tv_sec) * 1000.0 
        + (next_time.tv_usec - args->first_time.tv_usec) / 1000.0;
	return (args->count_time);
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
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

void    to_eat(t_args *args)
{
        pthread_mutex_lock (args->meals_gate);
        args->meals_num--;
        pthread_mutex_unlock (args->meals_gate);
        grab_forks (args);

        args->count_time = handle_time (args);
        printf ("\t%d Philosopher %d is eating\n", args->count_time, args->id);

        usleep (args->time2eat);

        pthread_mutex_unlock(args->left_fork);
        pthread_mutex_unlock(args->right_fork);
}

void    to_sleep(t_args *args)
{
        args->count_time = handle_time(args);
        printf ("\t%d Philosopher %d is sleeping\n", args->count_time, args->id);
        usleep (args->time2sleep);
}

void    to_think(t_args *args)
{
    args->count_time = handle_time(args);
    printf ("\t%d Philosopher %d is thinking\n", args->count_time, args->id);
}

void	*routine(void *arg)
{
	t_args *args;
	args = (t_args *)arg;
    long int waiting;
    long int last_meal;

    while (args->meals_num > 0)
    {
        to_eat (args);
        last_meal = get_time();
        to_sleep (args);
        to_think (args);
        waiting = get_time();
        // printf ("\twaiting: %ld\n", waiting);
        // printf ("\tlast_meal: %ld\n", last_meal);

        if (waiting >= last_meal + args->time2die)
        {
            printf("\tphilosopher %d died\n\n", args->id);
            return (NULL);
        }
    }
	return (NULL);
}
