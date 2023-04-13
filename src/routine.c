#include "philo.h"


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(long int num, int fd)
{
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}


int    handle_time(t_args *args)
{
    long int count_time;
    long int result;

	count_time = get_time ();
    result = count_time - args->first_time;
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

void    print_messsage (int id, int long timer, char *msg)
{
    printf ("%ld philosopher %d is %s\n", timer, id, msg);

    // ft_putnbr_fd (timer, 1);
    // ft_putstr_fd (" philosopher ", 1);
    // ft_putnbr_fd ((int)id, 1);
    // ft_putstr_fd (msg, 1);
    // ft_putchar_fd ('\n', 1);
}

void    print_actions(t_args *args, int action) //colocar as actions em um enum
{
    long int timer;
    // static pthread_mutex_t *loco; //inicializa com nullo

    // if (!loco)
    // {
    //     loco = calloc (1, sizeof (pthread_mutex_t));
        // pthread_mutex_init(&args->gate, NULL);
    // }

    pthread_mutex_lock(args->gate);
    timer = handle_time(args);
    if (action == 1)
        print_messsage (args->id, timer, " has taken a fork");       
    else if (action == 2)
        print_messsage (args->id, timer, " is \033[33meating\033[0m");      
    else if (action == 3)
        print_messsage (args->id, timer, " is \033[34msleeping\033[0m");      
    else if (action == 4)
        print_messsage (args->id, timer, " is \033[32mthinking\033[0m");
    pthread_mutex_unlock(args->gate);
}

void	grab_forks(t_args *args)
{
    // int timer;

    if (args->key)
        usleep (100);
    args->key = !args->key;
    // timer = handle_time (args);
    // printf("\t\t%d\n", timer);
    if (args->id != args->num_philo)
	{
		pthread_mutex_lock(args->left_fork);
        print_actions(args, 1);
        pthread_mutex_lock(args->right_fork);
        print_actions(args, 1);
	}
	else
	{
	    pthread_mutex_lock(args->right_fork);
        print_actions(args, 1);
		pthread_mutex_lock(args->left_fork);
        print_actions(args, 1);
    }
}

void    to_eat(t_args *args)
{
    pthread_mutex_lock (args->gate);
    if (args->meals_num)
        args->meals_num--;
    pthread_mutex_unlock (args->gate);

    grab_forks (args);

    print_actions(args, 2);
    pthread_mutex_lock (args->gate);
    args->last_meal = get_time();
    pthread_mutex_unlock (args->gate);
    usleep (args->time2eat);


    pthread_mutex_unlock(args->left_fork);
    pthread_mutex_unlock(args->right_fork);
}

void    to_sleep(t_args *args)
{
    print_actions(args, 3);
    usleep (args->time2sleep);
}

void    to_think(t_args *args)
{
    args->count_time = handle_time(args);
    print_actions(args, 4);
}

void	*routine(void *arg)
{
	t_args *args;
	args = (t_args *)arg;

    args->last_meal = get_time();

    while (1)
    {
        to_eat (args);
        to_sleep (args);
        to_think (args);
        if (args->meals_num == 1) //checar se devem dormir e pensar após finalizar
            break ;
    }
	return (NULL);
}
