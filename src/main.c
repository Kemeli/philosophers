
#include "philo.h"

int	check_args(int argc)
{
	if (argc < 4 || argc > 5)
		return (0);
	return (1);
}

void	*convert_to_integer (char **argv, t_args **args)
{
	(*args)->num_philo = atoi(argv[0]);
	(*args)->time2die = atoi(argv[1]);
	(*args)->time2eat = (atoi(argv[2]) * 1000);
	(*args)->time2sleep = (atoi(argv[3]) * 1000);
	return NULL;
}

int	main()
{
	t_args *args;

	int argc = 4;
	char *argv[5] = {"2", "410", "200", "200", NULL};

	args = calloc (1, sizeof (t_args));
	check_args (argc);
	convert_to_integer (argv, &args);
	start_threads(args);
}
