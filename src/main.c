#include "philo.h"

int	check_args(int argc)
{
	if (argc < 5 || argc > 6)
		return (0);
	return (1);
}

int	convert_to_integer (char **argv, t_data *args)
{
	int temp;
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (argv[i][0] == '-')
			return (0);
	}
	args->num_philo = atoi(argv[1]);
	args->time2die = atoi(argv[2]);
	args->time2eat = (atoi(argv[3]) * 1000);
	args->time2sleep = (atoi(argv[4]) * 1000);
	if (argv[5])
	{
		temp = atoi(argv[5]);
		if (temp > 0)
			args->meals_num = temp + 1;
		else
			return (0);
	}
	else
		args->meals_num = 0;
	return (1);
}

int	validate_args(t_data *args)
{
	if (!args->num_philo || !args->time2die
		|| !args->time2eat || !args->time2sleep)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data *args;

	if (check_args (argc))
	{
		args = ft_calloc (1, sizeof (t_data));
		if (convert_to_integer (argv, args) && validate_args(args))
		{
			start_threads(args);
			return (0);
		}
		free (args);
	}
	printf ("philosophers: error: invalid arguments\n");
	return (0);
}
