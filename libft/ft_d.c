/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:15:22 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/26 17:02:04 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	long	n;
	long	nu;

	n = nb;
	nu = nb;
	if (nu < 0)
	{
		nu = nu * (-1);
		ft_putchar('-');
	}
	if (nu > 9)
	{
		ft_putnbr(nu / 10);
		ft_putnbr(nu % 10);
	}
	else
		ft_putchar(nu + '0');
	return (ft_len_n((int)n));
}

// int main()
// {
// 	int i = ft_putnbr(INT_MIN);
// 	printf("%d", i);
// }
