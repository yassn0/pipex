/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:42:11 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/09 16:54:00 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char const *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	int		len;
	char	*tab;

	if (!s1)
		return (ft_strdup(""));
	len = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_sep(s1[start], set))
		start++;
	while (is_sep(s1[end], set) && end >= start)
		end--;
	len = end - start + 1;
	tab = malloc(sizeof(char) * (len + 1));
	if (tab == NULL)
		return (NULL);
	ft_memcpy(tab, &s1[start], len);
	tab[len] = '\0';
	return (tab);
}
