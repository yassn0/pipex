/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:37 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/26 17:02:21 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned long n, const char *base)
{
	int				len;
	unsigned long	base_len;

	len = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n >= base_len)
		len += ft_putnbr_base(n / base_len, base);
	len += write(1, &base[n % base_len], 1);
	return (len);
}
