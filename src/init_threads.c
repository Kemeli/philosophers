
#include "philo.h"

int    handle_time(struct	timeval	first_time, int sleeping)
{
    int count_time = 0;
    struct	timeval	next_time;

	usleep (sleeping);
	gettimeofday (&next_time, NULL);
	count_time = (next_time.tv_sec - first_time.tv_sec) * 1000.0 
        + (next_time.tv_usec - first_time.tv_usec) / 1000.0;
	return (count_time);
}

void	*routine(void *arg)
{
	t_args *args;
	pthread_mutex_t gate;
	int	count_time = 0;
    struct timeval first_time;

	args = (t_args *)arg;
	args->id +=1;
	pthread_mutex_init(&gate, NULL);
	pthread_mutex_lock(&gate);

	printf ("\t%d Philosopher %d is eating\n", count_time, args->id);
    gettimeofday (&first_time, NULL);
    count_time = handle_time(first_time, args->time2eat);
    printf ("\t%d Philosopher %d is sleeping\n", count_time, args->id);

    count_time = handle_time(first_time, args->time2sleep);
	printf ("\t%d Philosopher %d is thinking\n", count_time, args->id);

	pthread_mutex_unlock(&gate);
	return (NULL);
}

void	start_threads(t_args *args)
{
	pthread_t Philosopher[args->num_philo];
	t_args *phil_args = calloc (args->num_philo, sizeof (t_args));
	int	i;

	i = 0;
	while (i < args->num_philo)
	{
		phil_args[i].id = i;
		phil_args[i].num_philo = args->num_philo;
		phil_args[i].time2die = args->time2die;
		phil_args[i].time2eat = args->time2eat;
		phil_args[i].time2sleep = args->time2sleep;
		i++;
	}
    i = 0;
	while (i < args->num_philo)
	{
		pthread_create (&Philosopher[i], NULL, routine, &phil_args[i]);
		i++;
	}

	i = 0;
	while (i < args->num_philo)
	{
		pthread_join (Philosopher[i], NULL);
		i++;
	}
}
