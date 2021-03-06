/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:58:40 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/07 21:10:02 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	*ft_realloc_modf(void *ptr, size_t newsize, size_t oldsize)
{
	void	*new;

	new = ft_memalloc(newsize);
	if (ptr)
	{
		ft_memcpy(new, ptr, oldsize);
		free(ptr);
	}
	return (new);
}
