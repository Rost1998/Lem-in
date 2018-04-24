/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:19:33 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/24 21:19:34 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		read_num_ants(char **buffer)
{
	char	*line;
	int		ants;

	line = 0;
	while (get_next_line(0, &line) && *line == '#' &&
			(ft_strcmp(line, "##start") && ft_strcmp(line, "##end")))
	{
		*buffer = ft_strjoin_modf(*buffer, line, 1, 1);
		*buffer = ft_strjoin_modf(*buffer, "\n", 1, 0);
	}
	if (!line || !(*line) || !ft_isint(line) || *line == '-')
	{
		line ? free(line) : 0;
		ft_error();
	}
	ants = ft_atoi(line);
	*buffer = ft_strjoin_modf(*buffer, line, 1, 1);
	*buffer = ft_strjoin_modf(*buffer, "\n", 1, 0);
	return (ants);
}

static _Bool	handle_line(char *line, int *se, t_rooms ***rooms, int ants)
{
	_Bool	ret;

	ret = 1;
	if (!line || !(*line))
		ret = 0;
	else if (ft_isspecdiez(line))
	{
		if (!ft_handle_diez(line, se))
			ret = 0;
	}
	else if (ft_isroom(line))
	{
		if (!(ft_addroom(rooms, line, se, ants)))
			ret = 0;
	}
	else if (ft_islink(line))
	{
		if (!(ft_addlink(*rooms, line)))
			ret = 0;
	}
	return (ret);
}

t_rooms			**read_map(char **buffer)
{
	t_rooms		**rooms;
	char		*line;
	int			ants;
	int			se;

	ants = read_num_ants(buffer);
	rooms = 0;
	se = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (!(handle_line(line, &se, &rooms, ants)))
			break ;
		*buffer = ft_strjoin_modf(*buffer, line, 1, 1);
		*buffer = ft_strjoin_modf(*buffer, "\n", 1, 0);
		line = 0;
	}
	free(line);
	if (!(ft_check_total_valid(rooms)))
		return ((t_rooms**)ft_memfree_for_all_rooms(rooms));
	return (rooms);
}
