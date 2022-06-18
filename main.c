/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:37:01 by anruland          #+#    #+#             */
/*   Updated: 2022/06/18 10:19:09 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philotest.h"

int	main(int ac, char **av)
{
	int		*timing;
	int		*philos;
	int		*philo;
	int		death = atoi(av[2]);
	int		i;
	int		j;
	char	*line;
	char	*philo_nr;

	i = 0;
	j = 0;
	timing = (int *)calloc(sizeof(int), LINES);
	philos = (int *)calloc(sizeof(int), LINES);
	philo = (int *)calloc(sizeof(int), atoi(av[1]));
	printf("%d - %s\n", ac, av[0]);
	while (i < LINES)
	{
		line = get_next_line(STDIN_FILENO);
		if (line && strstr(line, "eating") != NULL)
		{
			timing[j] = atoi(line);
			philo_nr = strchr(line, ' ');
			// printf("nr %d\n", atoi(philo_nr));
			philos[j] = atoi(philo_nr);
			j++;
		}
		free(line);
		i++;
	}
	// i = 0;
	// while (i < atoi(av[1]))
	// {
	// 	philo[i] = 0;
	// 	i++;
	// }
	// i = 0;
	// while (i < j)
	// {
	// 	printf("death %d timing %d philo %d\n", death, timing[i], philos[i]);
	// 	i++;
	// }
	i = 0;
	while (i < j)
	{
		// printf("philo %d before %d - ", philos[i], philo[philos[i]]);
		// printf("timing %d =%d\n", timing[i], philo[philos[i]]);
		if (timing[i] - philo[philos[i]] > death)
			printf("Timing error philo %d - took %d\n", philos[i], philo[philos[i]]);
		philo[philos[i]] = timing[i];
		i++;
	}
	printf("test end\n");
	free(timing);
	free(philos);
	free(philo);
	return (0);
}
