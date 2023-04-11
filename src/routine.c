#include "philo.h"

int    handle_time(t_args *args)
{
    struct	timeval	next_time;
    long int count_time;

	gettimeofday (&next_time, NULL);
	count_time = (next_time.tv_sec - args->first_time.tv_sec) * 1000.0 
        + (next_time.tv_usec - args->first_time.tv_usec) / 1000.0;
	return (count_time);
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	grab_forks(t_args *args)
{
    int timer;

    if (args->key)
        usleep (args->time2eat);
    args->key = !args->key;
    timer = handle_time (args);
    if (timer > args->time2die)
        printf("%d philo %d DIED\n", timer, args->id);
    if (args->id != args->num_philo)
	{
		pthread_mutex_lock(args->left_fork);
        printf ("\t%d philosopher \033[31m%d\033[0m has taken a (left) fork\n",
            timer, args->id);
        pthread_mutex_lock(args->right_fork);
        printf ("\t%d philosopher \033[31m%d\033[0m has taken a (right) fork\n",
            timer, args->id);
	}
	else
	{
	    pthread_mutex_lock(args->right_fork);
        printf ("\t%d philosopher \033[31m%d\033[0m has taken a (right) fork\n",
            timer, args->id);
		pthread_mutex_lock(args->left_fork);
        printf ("\t%d philosopher \033[31m%d\033[0m has taken a (left) fork\n",
            timer, args->id);
	}
}

void    to_eat(t_args *args)
{
    pthread_mutex_lock (args->gate);
    if (args->meals_num)
        args->meals_num--;
    pthread_mutex_unlock (args->gate);

    grab_forks (args);

    args->count_time = handle_time (args);
    printf ("\t%d Philosopher \033[31m%d\033[0m is \033[33meating\033[0m\n",
        args->count_time, args->id);
    usleep (args->time2eat);

    args->last_meal = get_time();

    pthread_mutex_unlock(args->left_fork);
    pthread_mutex_unlock(args->right_fork);
}

void    to_sleep(t_args *args)
{
    args->count_time = handle_time(args);
    printf ("\t%d Philosopher \033[31m%d\033[0m is \033[34msleeping\033[0m\n",
        args->count_time, args->id);
    usleep (args->time2sleep);
}

void    to_think(t_args *args)
{
    args->count_time = handle_time(args);
    printf ("\t%d Philosopher \033[31m%d\033[0m is \033[32mthinking\033[0m\n",
        args->count_time, args->id);
}

void	*routine(void *arg)
{
	t_args *args;
	args = (t_args *)arg;

    args->last_meal = get_time();

    while (1)
    {
        to_eat (args);
        to_sleep (args);
        to_think (args);
        if (args->meals_num == 1) //checar se devem dormir e pensar após finalizar
            break ;
    }
	return (NULL);
}
