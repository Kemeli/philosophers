#include "philo.h"

void	*routine(void *args)
{
	t_philo *philo;
	philo = (t_philo *)args;

	philo->last_meal = get_time();

	while (1)
	{
		to_eat (philo);
		to_sleep (philo);
		to_think (philo);
		if (philo->meals_num == 1) //checar se devem dormir e pensar após finalizar
			break ;
	}
	return (NULL);
}
