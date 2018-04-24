/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memfree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:19:01 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/24 21:19:02 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_memfree_arrs_in_room(t_rooms *room)
{
	room->links ? free(room->links) : 0;
	free(room->name);
	free(room->coords);
}

_Bool			ft_memfree_for_all_rooms(t_rooms **rooms)
{
	int		i;

	i = 0;
	while (rooms && rooms[i])
	{
		ft_memfree_arrs_in_room(rooms[i]);
		free(rooms[i++]);
	}
	rooms ? free(rooms) : 0;
	return (0);
}

_Bool			ft_memfree_for_room(char **divs)
{
	int		i;

	i = 0;
	while (divs && divs[i])
		free(divs[i++]);
	divs ? free(divs) : 0;
	return (0);
}

_Bool			ft_memfree_for_link(char **names)
{
	int		i;

	i = 0;
	while (names && names[i])
		free(names[i++]);
	names ? free(names) : 0;
	return (0);
}

void			ft_memfree_success(t_rooms **rooms, char *buffer)
{
	ft_memfree_for_all_rooms(rooms);
	free(g_ants);
	free(buffer);
}
