/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvon-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 08:23:41 by wvon-gra          #+#    #+#             */
/*   Updated: 2017/07/20 10:21:48 by wvon-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
	return (NULL);
}
