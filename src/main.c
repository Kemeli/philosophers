
#include "philo.h"

int	check_args(int argc)
{
	if (argc < 4 || argc > 5)
		return (0);
	return (1);
}

int	convert_to_integer (char **argv, t_args **args)
{
	int temp;

	(*args)->num_philo = atoi(argv[0]);
	(*args)->time2die = atoi(argv[1]);
	(*args)->time2eat = (atoi(argv[2]) * 1000);
	(*args)->time2sleep = (atoi(argv[3]) * 1000);
	if (argv[4])
	{
		temp = atoi(argv[4]);
		if (temp > 0)
			(*args)->meals_num = temp + 1; //pra n precisar ir até zero
		else
			return (0);
	}
	else
		(*args)->meals_num = 0;
	return (1);
}

// int	main(int argc, char **argv)
int	main()
{
	t_args *args;

	int argc = 5;
	char *argv[5] = {"4", "400", "200", "200", NULL};

	args = calloc (1, sizeof (t_args));
	check_args (argc);
	if (convert_to_integer (argv, &args))
		start_threads(args);
	else
		printf ("invalid arguments\n");
	free (args);
}
