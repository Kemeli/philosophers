#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#define FORKS " has taken a fork"
#define EAT " is \033[33meating\033[0m"
#define SLEEP " is \033[34msleeping\033[0m"
#define THINK " is \033[32mthinking\033[0m"

typedef struct s_data
{
	unsigned int	time2eat;
	int				time2die;
	int				time2sleep;
	int				num_philo;
	int				smone_died;
	long int		first_time;
	pthread_mutex_t	*gate;
	pthread_mutex_t	*lock;
	pthread_mutex_t	*monitor;
	long int		timer;
	long int		start_timer;
	int				meals_num;
	// int				who_died;
	// struct timeval waiting_time;
} t_data;

typedef struct s_philo
{
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	// int				key;
	int				id;
	int				meals_num;
	int				died;
	long int		last_meal;
	t_data			*data;
}	t_philo;


void	start_threads(t_data *args);
void	monitoring (t_philo *philo);

// void    init_mutex(t_data *args, pthread_mutex_t **gate, pthread_mutex_t **lock);
void	init_forks(t_data *args, pthread_mutex_t **forks);

void	init_data(t_data *data, t_data *args);

void	init_philo(t_data *args, t_philo *philo,
		pthread_mutex_t **forks, t_data *data);
// size_t	ft_strlen(const char *s);
// void	ft_putchar_fd(char c, int fd);
// void	ft_putnbr_fd(long int num, int fd);
// void	ft_putstr_fd(char *s, int fd);

int		handle_time(t_philo *philo);
long int	get_time(void);

void	*routine(void *arg);
void	to_think(t_philo *philo);
void	to_sleep(t_philo *philo);
void	to_eat(t_philo *philo);

void	print_actions(t_philo *philo, char *action);
void	print_actions(t_philo *philo, char  *action);

void	end(t_philo *philo, pthread_mutex_t *forks, pthread_t *philosopher);

#endif