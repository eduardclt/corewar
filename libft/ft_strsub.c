/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:14:22 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/06/20 09:57:48 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	substring = (char *)ft_strnew(len);
	i = 0;
	if (substring == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		return (NULL);
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	return (substring);
}
