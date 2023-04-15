#include "philo.h"

void	print_messsage (int id, int long timer, char *msg)
{
	printf ("%ld philosopher %d %s\n", timer, id, msg);

	// ft_putnbr_fd (timer, 1);
	// ft_putstr_fd (" philosopher ", 1);
	// ft_putnbr_fd ((int)id, 1);
	// ft_putstr_fd (msg, 1);
	// ft_putchar_fd ('\n', 1); //lembrar de tirar
}

void	print_actions(t_philo *philo, char *action) //colocar as actions em um enum
{
	long int timer;

	pthread_mutex_lock(philo->data->lock);
	timer = handle_time(philo);
	print_messsage (philo->id, timer, action);
	pthread_mutex_unlock(philo->data->lock);
}