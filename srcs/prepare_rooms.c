/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:19:26 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/24 21:19:26 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			prepare_rooms(t_rooms **rooms, t_rooms *end)
{
	int		i;

	end ? (end->marker = 1) : 0;
	i = 0;
	while (rooms[i])
	{
		(rooms[i])->distance = (rooms[i])->st_end == -1 ? 0 : INF;
		++i;
	}
}
