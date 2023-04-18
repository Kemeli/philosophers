#include "philo.h"

void	print_messsage (int id, int long timer, char *msg)
{
	printf ("%ld philosopher %d %s\n", timer, id, msg);
}

void	print_actions(t_philo *philo, char *action)
{
	long int timer;

	if (philo->died == 1)
		return ;
	pthread_mutex_lock(philo->data->lock);
	timer = handle_time(philo);
	print_messsage (philo->id, timer, action);
	pthread_mutex_unlock(philo->data->lock);
}