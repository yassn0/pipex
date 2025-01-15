/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:21:48 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/26 17:02:33 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsigned_nbr(unsigned int nb)
{
	if (nb > 9)
	{
		ft_putunsigned_nbr(nb / 10);
		ft_putunsigned_nbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (ft_len_n(nb));
}
