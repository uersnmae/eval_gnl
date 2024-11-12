/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-hki <dong-hki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:00:28 by dong-hki          #+#    #+#             */
/*   Updated: 2024/11/12 20:05:32 by dong-hki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
#include "get_next_line_bonus.h"
#else
#include "get_next_line.h"
#endif
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	#ifdef BONUS
	int	fd[3];
	int	i = 0;
	fd[0] = open("test1.txt", O_RDONLY);
	fd[1] = open("test2.txt", O_RDONLY);
	fd[2] = open("test3.txt", O_RDONLY);
	#else
	int	fd = open("test1.txt", O_RDONLY);
	#endif
	char	*str;

	#ifdef BONUS
	while (str = get_next_line(fd[i % 3]))
	{
		printf("fd index: %d\nFile read: %s\n", i % 3, str);
		free(str);
		i++;
	}
	#elif STDIN
	printf("Write your line...\n");
	while (str = get_next_line(1))
{
		printf("File read: %s\n", str);
		free(str);
	}
	#else
	while (str = get_next_line(fd))
	{
		printf("File read: %s\n", str);
		free(str);
	}
	#endif
	return (0);
}
