/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:36:21 by yfradj            #+#    #+#             */
/*   Updated: 2025/01/15 11:11:17 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>

char	*path_cmd(char *command, char **envp)
{
	char	*var_path_tmp;
	char	*var_path;
	char	**cmd_flags;
	int		i;

	i = 0;
	cmd_flags = ft_split(command, ' ');
	if (!cmd_flags)
		return (NULL);
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	var_path_tmp = ft_strnstr(envp[i], "PATH", 4);
	if (var_path_tmp != NULL)
	{
		var_path = ft_strnstr(var_path_tmp, "=", 2);
	}
	printf("%s\n", var_path);
}

void	process_first(char **av, char **envp, int fd[2])
{
	int		fd_first;
	char	*path_cmd_1;

	fd_first = open(av[1], O_RDONLY, 0700);
	if (fd_first == -1)
		exit(1);
	dup2(fd_first, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	path_cmd_1 = path_cmd(av[2], envp);
}

void	pipex(char **av, char **envp, int fd_link[2])
{
	int	p;
	int	pid1;

	p = pipe(fd_link); // cree deux fd relie dans fd_link
	pid1 = fork();
	if (p == 1 || pid1 == 1)
		exit(1);
	while (pid1 == 0)
	{
		process_first(av, envp, fd_link);
	}
}

int	main(int ac, char **av, char **envp)
{
	int		fd_link[2];
	char	*str;

	// if (ac != 5)
	// 	exit(1);
	// pipex(av, envp, fd_link);
	str = path_cmd(av[1], envp);
	return (0);
}
