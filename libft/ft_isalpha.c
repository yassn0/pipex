/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:38:10 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/07 07:08:01 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1024);
	if (c >= 'A' && c <= 'Z')
		return (1024);
	return (0);
}
/*
int	main(int ac, char **av)
{
		(void)ac;
		printf("%d\n", ft_isalpha(atoi(av[1])));
		printf("%d", isalpha(atoi(av[1])));
		return (0);
}*/
