/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 11:27:16 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/07/20 11:27:22 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t l)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	while (i < l)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			return ((unsigned char *)dest + i + 1);
		i++;
	}
	return (NULL);
}
