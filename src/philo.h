/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:50:44 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/04/19 01:50:44 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

# define FORKS " has taken a fork"
# define EAT " is \033[33meating\033[0m"
# define SLEEP " is \033[34msleeping\033[0m"
# define THINK " is \033[32mthinking\033[0m"

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
	pthread_mutex_t	*satisfied;
	pthread_mutex_t	*print;
	long int		timer;
	long int		start_timer;
	int				meals_num;
	int				dead_philo;
}	t_data;

typedef struct s_philo
{
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	int				id;
	int				meals_num;
	int				died;
	int				satisfied;
	long int		last_meal;
	t_data			*data;
}	t_philo;

int		ft_atoi(const char *nptr);
void	ft_usleep(int sleep);
void	*ft_calloc(size_t cnt, size_t n);
int		ft_isdigit(int c);

long	get_time(void);

void	start_threads(t_data *args);
void	*monitoring(void *args);

void	init_forks(t_data *args, pthread_mutex_t **forks);
void	init_data(t_data *data, t_data *args);
void	init_philo(t_data *args, t_philo *philo,
			pthread_mutex_t **forks, t_data *data);

void	*routine(void *arg);
int		check_death(t_philo *philo);
int		to_think(t_philo *philo);
int		to_sleep(t_philo *philo);
int		to_eat(t_philo *philo);

int		print_actions(t_philo *philo, char *action, int is_fork);
void	end(t_philo *philo, pthread_mutex_t *forks, pthread_t *philosopher);

#endif