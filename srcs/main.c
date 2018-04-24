/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:18:56 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/24 21:18:57 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		print_buff(char *buffer)
{
	write(1, buffer, ft_strlen(buffer));
	write(1, "\n", 1);
}

static _Bool	check_way(t_rooms *start)
{
	int		i;

	i = 0;
	while ((start->links)[i])
		if (((start->links)[i++])->distance < INF)
			return (1);
	return (0);
}

int				main(void)
{
	char		*buffer;
	t_rooms		**rooms;
	t_rooms		*start;
	t_rooms		*end;

	buffer = 0;
	if (!(rooms = read_map(&buffer)))
	{
		free(buffer);
		ft_error();
	}
	start = get_room(rooms, 1);
	end = get_room(rooms, -1);
	prepare_rooms(rooms, end);
	search_ways(end);
	if (!check_way(start))
	{
		ft_memfree_for_all_rooms(rooms);
		free(buffer);
		ft_error();
	}
	print_buff(buffer);
	move_ants(start, end);
	ft_memfree_success(rooms, buffer);
	return (0);
}
