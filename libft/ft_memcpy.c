/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:26:18 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/07/20 11:26:52 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*p1;
	char	*p2;

	i = 0;
	p1 = (char *)dest;
	p2 = (char *)src;
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (dest);
}
