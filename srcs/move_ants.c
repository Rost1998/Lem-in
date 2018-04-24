/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:19:07 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/24 21:19:08 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

typedef unsigned long long t_ull;

static int		get_profitable_way(t_rooms *room)
{
	int			i;
	int			ret;
	int			min;
	t_ull		index;

	ret = -1;
	min = INF;
	i = 0;
	while ((room->links)[i])
	{
		index = (t_ull)room->distance;
		if (room->st_end == 1)
			index += room->ants;
		if (((room->links)[i])->st_end == -1)
			return (i);
		if (((room->links)[i])->distance < min && !(((room->links)[i])->ants) &&
				(t_ull)(((room->links)[i])->distance) < index)
		{
			ret = i;
			min = ((room->links)[i])->distance;
		}
		++i;
	}
	return (ret);
}

static _Bool	ft_add_ant(t_rooms *start, size_t i)
{
	size_t		len;

	if (!g_ants)
	{
		if (!(g_ants = (t_rooms**)ft_memalloc(sizeof(t_rooms*) * 2)))
			return (0);
		g_ants[i] = start;
	}
	else if (!(g_ants[i]))
	{
		len = ft_adrlen((void**)g_ants);
		if (!(g_ants = (t_rooms**)ft_realloc_modf(g_ants,
				sizeof(t_rooms*) * (len + 2), sizeof(t_rooms*) * (len + 1))))
			return (0);
		g_ants[i] = start;
	}
	return (1);
}

static void		free_ant(t_rooms *start)
{
	int		to;
	size_t	i;

	while (start->ants && (to = get_profitable_way(start)) >= 0)
	{
		i = ft_adrlen((void**)g_ants);
		ft_add_ant(start, i);
		push_ant(g_ants[i], ((g_ants[i])->links)[to], i);
	}
}

static void		get_iteration(t_rooms *start, t_rooms *end)
{
	int		i;
	int		to;

	i = 0;
	while (g_ants && g_ants[i])
	{
		if (g_ants[i] == end)
		{
			++i;
			continue ;
		}
		to = get_profitable_way(g_ants[i]);
		to >= 0 ? push_ant(g_ants[i], ((g_ants[i])->links)[to], i) : 0;
		++i;
	}
	free_ant(start);
}

void			move_ants(t_rooms *start, t_rooms *end)
{
	int		ants;

	ants = start->ants;
	while (end->ants < ants)
	{
		get_iteration(start, end);
		write(1, g_iteration, ft_strlen(g_iteration) - 1);
		write(1, "\n", 1);
		free(g_iteration);
		g_iteration = 0;
	}
}
