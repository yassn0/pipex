/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:15:34 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/09 16:15:47 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static unsigned int	ft_strnlen(char *str, unsigned int n )
{
	unsigned int	i;

	i = 0;
	while (str[i] && i < n)
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	lendest;
	unsigned int	lensrc;

	i = 0;
	lendest = ft_strnlen(dest, size);
	lensrc = ft_strlen((char *)src);
	if (lendest >= size)
		return (lendest + lensrc);
	while (src[i] != '\0' && ((i + lendest) < (size - 1)))
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = '\0';
	return (lendest + lensrc);
}
