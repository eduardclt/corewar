/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:21:29 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/06/10 09:40:30 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	size_t	len;

	j = 0;
	i = 0;
	len = ft_strlen(little);
	if (len == 0)
		return ((char *)big);
	while (big[i] != '\0')
	{
		while (little[j] == big[j + i])
		{
			if (j == len - 1)
				return ((char *)(big + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
