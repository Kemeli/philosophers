#include "philo.h"

// int	check_death(t_philo *philo)
// {
// 	int		smone_died = 0;

// 	pthread_mutex_lock(philo->data->gate);
// 	smone_died = philo->data->smone_died;
// 	pthread_mutex_unlock(philo->data->gate);
// 	printf ("%d\n", smone_died);
// 	if (smone_died)
// 		return (0);
// 	return (1);
// }

void	*routine(void *args)
{
	t_philo *philo;
	philo = (t_philo *)args;

	while (1)
	{
		to_eat (philo);
		to_sleep (philo);
		to_think (philo);
		if (philo->meals_num == 1)
			break ;
	}
	return (NULL);
}
