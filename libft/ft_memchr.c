/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:40:52 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/07/20 11:22:05 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s1, int c, size_t n)
{
	char		tmp;
	char		*tmp2;

	tmp = (unsigned char)c;
	tmp2 = (char*)s1;
	while (n--)
	{
		if (*tmp2 == tmp)
			return (tmp2);
		tmp2++;
	}
	return (NULL);
}
