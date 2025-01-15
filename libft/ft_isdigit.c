/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:01:20 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/07 07:08:04 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}
/*
int	main(int ac, char **av)
{
		(void)ac;
		printf("%d\n", ft_isdigit(atoi(av[1])));
		printf("%d", isdigit(atoi(av[1])));
		return (0);
}*/