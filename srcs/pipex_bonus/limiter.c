/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:27:50 by yfradj            #+#    #+#             */
/*   Updated: 2025/01/22 18:01:17 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	limiter_get_line(int pid_first_child, int fd_link[2], char *limiter)
{
	char	*line;

	if (pid_first_child == 0)
	{
		close(fd_link[0]);
		line = get_next_line(0);
		while (line)
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
				&& line[ft_strlen(limiter)] == '\n')
			{
				free(line);
				exit(0);
			}
			write(fd_link[1], line, ft_strlen(line));
			if (line)
				free(line);
			line = get_next_line(0);
		}
		exit(0);
	}
}

void	limiter(char *limiter, char **av, char **envp)
{
	int	fd_link[2];
	int	pid_first_child;

	if (pipe(fd_link) == -1)
		exit(1);
	pid_first_child = fork();
	if (pid_first_child == -1)
		exit(1);
	limiter_get_line(pid_first_child, fd_link, limiter);
	close(fd_link[1]);
	dup2(fd_link[0], 0);
	wait(NULL);
}
