/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:54:49 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/06/09 15:47:56 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;

	dest = (char *)malloc(ft_strlen(str) + 1);
	if (dest == NULL)
		return (NULL);
	dest = ft_strcpy(dest, str);
	return (dest);
}
