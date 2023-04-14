#include "philo.h"

int	check_args(int argc)
{
	if (argc < 5 || argc > 6)
		return (0);
	return (1);
}

int	convert_to_integer (char **argv, t_data **args)
{
	int temp;

	(*args)->num_philo = atoi(argv[1]);
	(*args)->time2die = atoi(argv[2]);
	(*args)->time2eat = (atoi(argv[3]) * 1000);
	(*args)->time2sleep = (atoi(argv[4]) * 1000);
	if (argv[5])
	{
		temp = atoi(argv[5]);
		if (temp > 0)
			(*args)->meals_num = temp + 1; //pra n precisar ir até zero
		else
			return (0);
	}
	else
		(*args)->meals_num = 0;
	return (1);
}

// int	main()
int	main(int argc, char **argv)
{
	t_data *args;

	// int argc = 6;
	// char *argv[7] = {"0", 11", "200", "100", "200", "3", NULL};

	if (!check_args (argc))
	{
		printf("philosophers: invalid arguments\n");
		return (0);
	}
	args = calloc (1, sizeof (t_data));
	if (convert_to_integer (argv, &args))
		start_threads(args);
	else
		printf ("invalid arguments\n");
	free (args);
}
