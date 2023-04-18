#include "philo.h"

static void	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock (philo->data->lock);
	if (philo->died == 1)
	{
		pthread_mutex_unlock (philo->data->lock);
		return ;
	}
	pthread_mutex_unlock (philo->data->lock);
	print_actions(philo, FORKS);
	print_actions(philo, FORKS);
}

void	to_eat(t_philo *philo)
{
	grab_forks (philo);
	print_actions(philo, EAT);
	pthread_mutex_lock (philo->data->monitor);
	philo->last_meal = get_time();
	pthread_mutex_unlock (philo->data->monitor);
	ft_usleep (philo->data->time2eat);

	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);

	pthread_mutex_lock (philo->data->gate);
	if (philo->meals_num)
		philo->meals_num--;
	pthread_mutex_unlock (philo->data->gate);
}

void	to_sleep(t_philo *philo)
{
	print_actions(philo, SLEEP);
	ft_usleep(philo->data->time2sleep);
}

void	to_think(t_philo *philo)
{
	print_actions(philo, THINK);
}
