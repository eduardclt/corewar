/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:15:29 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/06/10 11:10:52 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*pointer;

	pointer = (char *)malloc(size + 1);
	if (pointer != NULL)
	{
		ft_memset(pointer, '\0', size + 1);
		return (pointer);
	}
	return (NULL);
}
