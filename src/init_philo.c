#include "philo.h"

void	init_args(t_args *args, t_args **phil_args, pthread_mutex_t **forks, pthread_mutex_t **meals)
{
	int i;
	i = 0;
	while (i < args->num_philo)
	{
		(*phil_args)[i].id = i + 1;
		(*phil_args)[i].num_philo = args->num_philo;
		(*phil_args)[i].time2die = args->time2die;
		(*phil_args)[i].time2eat = args->time2eat;
		(*phil_args)[i].time2sleep = args->time2sleep;
		(*phil_args)[i].meals_num = args->meals_num;
		(*phil_args)[i].right_fork = &(*forks)[i];
		(*phil_args)[i].left_fork = &(*forks)[(i + 1) % args->num_philo];
		(*phil_args)[i].meals_gate = &(*meals)[i];

		gettimeofday(&(*phil_args)[i].first_time, NULL);
		i++;
	}
}

void	init_forks(t_args *args, pthread_mutex_t **forks)
{
	int	i;

	*forks = calloc (args->num_philo, sizeof (pthread_mutex_t));
	i = -1;
	while (++i < args->num_philo)
		pthread_mutex_init(&(*forks)[i], NULL);
}

void	init_mutex(t_args *args, pthread_mutex_t **meals, pthread_mutex_t **time)
{
	int	i;

	*time = calloc (args->num_philo, sizeof (pthread_mutex_t));
	*meals = calloc (args->num_philo, sizeof (pthread_mutex_t));
	i = -1;
	while (++i < args->num_philo)
	{
		pthread_mutex_init (&(*meals)[i], NULL);
		pthread_mutex_init (&(*time)[i], NULL);
	}
}

void	start_threads(t_args *args)
{
	pthread_t Philosopher[args->num_philo];
	pthread_mutex_t *forks;
	pthread_mutex_t *meals; 
	pthread_mutex_t *time; 
	t_args *phil_args;
	int	i;

	phil_args = calloc (args->num_philo, sizeof (t_args));

	init_forks(args, &forks);
	init_mutex(args, &meals, &time);
	init_args(args, &phil_args, &forks, &meals);

    i = -1;
	while (++i < args->num_philo)
		pthread_create (&Philosopher[i], NULL, routine, &phil_args[i]);

	i = -1;
	while (++i < args->num_philo)
		pthread_join (Philosopher[i], NULL);
	i = -1;
	while (++i < args->num_philo)
		pthread_mutex_destroy(&forks[i]);
	i = 0;
	while (++i < args->num_philo)
		free (phil_args);
}
