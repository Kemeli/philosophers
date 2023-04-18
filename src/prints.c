#include "philo.h"

void	print_messsage (int id, int long timer, char *msg)
{
	printf ("%ld philosopher %d %s\n", timer, id, msg);
}

void	print_actions(t_philo *philo, char *action)
{
	long int timer;

	if (check_death(philo))
		return ;
	pthread_mutex_lock(philo->data->print);
	timer = handle_time(philo);
	print_messsage (philo->id, timer, action);
	pthread_mutex_unlock(philo->data->print);
}
