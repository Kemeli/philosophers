#include "philo.h"

long	handle_time(t_philo *philo)
{
	long count_time;
	long result;

	count_time = get_time();
	result = count_time - philo->data->start_timer;
	return (result);
}

long int	get_time(void)
{
	struct timeval	time;
	long int result;

	gettimeofday(&time, NULL);
	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);

	return (result);
}

int	ft_atoi(const char *nptr)
{
	int	number;
	int	i;
	int	signal;

	signal = 1;
	number = 0;
	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+'))
		if (nptr[i++] == '-')
			signal *= -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = (nptr[i] - '0') + (number * 10);
		i++;
	}
	return (number * signal);
}

void	ft_usleep(int sleep)
{
	long	start;
	long	current;

	start = get_time();
	current = get_time();
	sleep = sleep / 1000;
	while (current - start < sleep)
	{
		current = get_time();
		usleep(100);
	}
}

void	ft_bzero(void *s, size_t n)
{
	memset(s, 0, n);
	return ;
}

void	*ft_calloc(size_t cnt, size_t n)
{
	void	*ptr;
	int		result;

	if (cnt == 0 || n == 0)
		return (NULL);
	result = (cnt * n);
	if (result / cnt != n)
		return (NULL);
	ptr = ((void *) malloc (cnt * n));
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n * cnt);
	return (ptr);
}
