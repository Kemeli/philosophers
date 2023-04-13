#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_args
{
	unsigned int time2eat;
	int	time2die;
	int	time2sleep;
	int	num_philo;
	int	meals_num;
	int	id;
	long int	first_time;
	int count_time; //long?
	pthread_mutex_t *right_fork;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *gate;
	pthread_mutex_t *lock;
	struct timeval waiting_time;
	long int timer;
	int is_dead;
	long int last_meal;
	long int start_timer;
	int key;
} t_args;

void	start_threads(t_args *args);
void	*routine(void *arg);
long int		get_time(void);


#endif