/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:55:47 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/07 17:35:25 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (c >= 'a' && c <= 'z')
		return (8);
	if (c >= 'A' && c <= 'Z')
		return (8);
	if (c >= '0' && c <= '9')
		return (8);
	return (0);
}
/*
int	main(int ac, char **av)
{
		(void)ac;
		printf("%d\n", ft_isalnum(atoi(av[1])));
		printf("%d", isalnum(atoi(av[1])));
		return (0);
}*/