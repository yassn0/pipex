/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:36:21 by yfradj            #+#    #+#             */
/*   Updated: 2025/01/27 13:24:39 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	display_error_free(char **cmd_flags, int *fd_link)
{
	free_tab(cmd_flags);
	ft_printf("error, maybe look permission ?");
	close(fd_link[0]);
	close(fd_link[1]);
	exit(1);
}

void	process_first(char **av, char **envp, int *fd_link)
{
	int		fd_first;
	char	*path_cmd_1;
	char	**cmd_flags;
	int		answer;

	cmd_flags = ft_split(av[2], ' ');
	if (!cmd_flags)
		return ;
	fd_first = open(av[1], O_RDONLY, 0777);
	if (fd_first == -1)
		display_error_free(cmd_flags, fd_link);
	dup2(fd_link[1], 1);
	dup2(fd_first, 0);
	close(fd_link[0]);
	close(fd_first);
	path_cmd_1 = path_cmd(av[2], envp, cmd_flags);
	if (!path_cmd_1)
		close_exit(cmd_flags, fd_link);
	if (execve(path_cmd_1, cmd_flags, envp) == -1)
	{
		ft_putstr_fd("Error with the command one\n", 1);
		exit(1);
	}
	free_tab(cmd_flags);
	free(path_cmd_1);
}

void	execute_second(char **av, char **envp, int *fd_link)
{
	int		fd_second;
	char	*path_cmd_2;
	char	**cmd_flags;
	int		answer;

	cmd_flags = ft_split(av[3], ' ');
	if (!cmd_flags)
		return ;
	fd_second = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_second == -1)
		display_error_free(cmd_flags, fd_link);
	dup2(fd_link[0], 0);
	dup2(fd_second, 1);
	close(fd_link[1]);
	close(fd_second);
	path_cmd_2 = path_cmd(av[3], envp, cmd_flags);
	if (!path_cmd_2)
		close_exit(cmd_flags, fd_link);
	if (execve(path_cmd_2, cmd_flags, envp) == -1)
	{
		ft_putstr_fd("Error with the command two\n", 1);
		exit(1);
	}
	free_tab(cmd_flags);
	free(path_cmd_2);
}

void	pipex(char **av, char **envp, int fd_link[2])
{
	int	p;
	int	pid1;

	p = pipe(fd_link);
	pid1 = fork();
	if (p == -1 || pid1 == -1)
	{
		ft_putstr_fd("Error with pipe or fork\n", 1);
		exit(1);
	}
	if (pid1 == 0)
		process_first(av, envp, fd_link);
	waitpid(pid1, NULL, 0);
	execute_second(av, envp, fd_link);
	close(fd_link[0]);
	close(fd_link[1]);
}

int	main(int ac, char **av, char **envp)
{
	int	fd_link[2];

	if (ac != 5)
	{
		ft_putstr_fd("Wrong nnumber of argument\n", 1);
		exit(1);
	}
	pipex(av, envp, fd_link);
	return (0);
}
