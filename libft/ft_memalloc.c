/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:52:26 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/06/07 14:03:37 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*pointer;

	pointer = malloc(size);
	if (pointer != NULL)
	{
		ft_memset(pointer, 0, size);
		return (pointer);
	}
	return (NULL);
}
