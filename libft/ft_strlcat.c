/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:59:28 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/07/20 11:18:45 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	div;

	length = 0;
	while (length < size && *dst && *(dst++))
		length++;
	div = size - length;
	if (!div)
		return (length + ft_strlen(src));
	while (*src)
	{
		if (div != 1)
		{
			*(dst++) = *src;
			div--;
		}
		src++;
		length++;
	}
	*dst = '\0';
	return (length);
}
