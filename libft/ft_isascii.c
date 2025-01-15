/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:59:28 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/07 07:08:03 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main(int ac, char **av)
{
		(void)ac;
		printf("%d\n", ft_isascii(atoi(av[1])));
		printf("%d", isascii(atoi(av[1])));
		return (0);
}*/