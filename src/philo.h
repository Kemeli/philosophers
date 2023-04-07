

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_args
{
	unsigned int	time2eat;
	int	time2die;
	int	time2sleep;
	int	num_philo;
	int	id;
	// pthread_mutex_t forks;
	struct	timeval	first_time;
	int count_time; //long?
} t_args;

void	start_threads(t_args *args);


#endif