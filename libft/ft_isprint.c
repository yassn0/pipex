/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:03:26 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/09 13:48:06 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c <= 31 || c >= 127)
		return (0);
	return (16384);
}
/*
int	main(int ac, char **av)
{
		(void)ac;
		printf("%d\n", ft_isprint(atoi(av[1])));
		printf("%d", isprint(atoi(av[1])));
		return (0);
}*/