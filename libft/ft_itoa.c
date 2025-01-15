/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:12:17 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/08 16:55:31 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nb(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		nb *= -1;
		i++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		lenn;
	long	nb;
	char	*str;

	nb = n;
	i = 0;
	lenn = len_nb(n);
	str = malloc(sizeof(char) * (lenn + 1));
	if (!str)
		return (NULL);
	str[lenn] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
		i++;
	}
	while (lenn-- > i)
	{
		str[lenn] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
// int main()
// {
// 	printf("%s\n", ft_itoa(0));
// 	printf("%d\n", len_nb(0));
// }
