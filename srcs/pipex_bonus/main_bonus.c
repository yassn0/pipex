/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:02:39 by yfradj            #+#    #+#             */
/*   Updated: 2025/01/27 11:34:40 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc_case(int ac, char **av, char **envp)
{
	int	fd_out;

	if (ac != 6)
	{
		ft_putstr_fd("Invalid number of arguments for here_doc\n", 1);
		exit(1);
	}
	fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_out == -1)
	{
		perror("Error opening file");
		exit(1);
	}
	limiter(av[2], av, envp);
	execute_fisrt_command_in_stdout(av, envp);
	dup2(fd_out, 1);
	execute_with_stdin(av, envp, fd_out);
	close(fd_out);
}

void	pipex_bonus(int ac, char **av, char **envp)
{
	if (ft_strcmp("here_doc", av[1]) == 0)
		here_doc_case(ac, av, envp);
	else
		main_case(ac, av, envp);
}

int	main(int ac, char **av, char **envp)
{
	if (!envp)
	{
		ft_putstr_fd("envp is NULL\n", 1);
		exit(1);
	}
	if (ac < 5)
	{
		ft_putstr_fd("Wrong number of argument\n", 1);
		exit(1);
	}
	pipex_bonus(ac, av, envp);
	return (0);
}
