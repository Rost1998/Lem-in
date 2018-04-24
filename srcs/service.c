/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:19:44 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/24 21:19:45 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rooms		*get_room(t_rooms **rooms, int code)
{
	int		i;

	i = 0;
	while (rooms && rooms[i])
	{
		if ((rooms[i])->st_end == code)
			return (rooms[i]);
		++i;
	}
	return (0);
}

void		push_ant(t_rooms *from, t_rooms *to, int i)
{
	char	*step;
	char	*num_ant;

	(from->ants)--;
	(to->ants)++;
	g_ants[i] = to;
	num_ant = ft_itoa(i + 1);
	step = ft_strdup("L");
	step = ft_strjoin_modf(step, num_ant, 1, 1);
	step = ft_strjoin_modf(step, "-", 1, 0);
	step = ft_strjoin_modf(step, to->name, 1, 0);
	step = ft_strjoin_modf(step, " ", 1, 0);
	g_iteration = ft_strjoin_modf(g_iteration, step, 1, 1);
}
