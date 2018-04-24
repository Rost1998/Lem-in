/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:18:34 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/24 21:18:34 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rooms		*ft_new_room(char **name)
{
	t_rooms		*new;

	if (!(new = (t_rooms*)ft_memalloc(sizeof(t_rooms))))
		return (0);
	if (!(new->coords = (int*)ft_memalloc(sizeof(int) * 2)))
		return (0);
	new->name = name[0];
	(new->coords)[0] = ft_atoi(name[1]);
	(new->coords)[1] = ft_atoi(name[2]);
	new->st_end = 0;
	new->links = 0;
	new->ants = 0;
	new->marker = 0;
	return (new);
}
