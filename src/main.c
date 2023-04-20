/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:50:33 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/04/19 01:50:33 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args(int argc)
{
	if (argc < 5 || argc > 6)
		return (0);
	return (1);
}

static int	convert_to_integer(char **argv, t_data *args)
{
	int	temp;
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (argv[i][0] == '-')
			return (0);
	}
	args->num_philo = atoi(argv[1]);
	args->time2die = atoi(argv[2]);
	args->time2eat = (atoi(argv[3]));
	args->time2sleep = (atoi(argv[4]));
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

static int	validate_args(t_data *args, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i] && argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	if (!args->num_philo || !args->time2die
		|| !args->time2eat || !args->time2sleep)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*args;

	if (check_args (argc))
	{
		args = ft_calloc (1, sizeof (t_data));
		if (convert_to_integer (argv, args) && validate_args(args, argv))
		{
			start_threads(args);
			return (0);
		}
		free (args);
	}
	printf ("philosophers: error: invalid arguments\n");
	return (0);
}
