/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:16:04 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/24 21:16:05 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static _Bool	ft_check_duplicates(t_rooms **rooms, char **info, int se)
{
	int		i;

	i = 0;
	while (rooms && rooms[i])
	{
		if (!ft_strcmp((rooms[i])->name, info[0]) ||
			(se && (rooms[i])->st_end == se) ||
				(((rooms[i])->coords)[0] == ft_atoi(info[1]) &&
					((rooms[i])->coords)[1] == ft_atoi(info[2])))
			return (1);
		++i;
	}
	return (0);
}

char			**ft_check_valid_room(t_rooms **rooms, char *line, int se)
{
	char	**divs;
	int		i;

	if (*line == '#' || *line == 'L')
		return (0);
	divs = ft_strsplit(line, ' ');
	i = 0;
	while (divs && divs[i])
		++i;
	if (i != 3 || !ft_isint(divs[1]) || !ft_isint(divs[2]))
		return ((char**)ft_memfree_for_room(divs));
	i = 0;
	while (divs[0][i])
		if (divs[0][i++] == '-')
			return (0);
	if (ft_check_duplicates(rooms, divs, se))
		return ((char**)ft_memfree_for_room(divs));
	return (divs);
}

_Bool			ft_check_valid_link(t_rooms **rooms, char *line)
{
	int		i;
	int		coincidence;
	char	**names;

	i = 0;
	coincidence = 0;
	if (!(names = ft_strsplit(line, '-')))
		return (0);
	if (!names[1] || names[2])
		return (ft_memfree_for_link(names));
	if (!ft_strcmp(names[0], names[1]))
		return (ft_memfree_for_link(names));
	while (rooms && rooms[i])
	{
		if (!ft_strcmp(names[0], (rooms[i])->name) ||
				!(ft_strcmp(names[1], (rooms[i])->name)))
			coincidence++;
		++i;
	}
	ft_memfree_for_link(names);
	if (coincidence != 2)
		return (0);
	return (1);
}

_Bool			ft_check_total_valid(t_rooms **rooms)
{
	t_rooms		*start;
	int			i;
	int			st;
	int			end;

	st = 0;
	end = 0;
	i = 0;
	start = get_room(rooms, 1);
	if (!rooms || !start || !(start->links))
		return (0);
	while (rooms && rooms[i])
	{
		if ((rooms[i])->st_end == 1)
			++st;
		if ((rooms[i])->st_end == -1)
			++end;
		++i;
	}
	if (rooms && (st != 1 || end != 1))
		return (0);
	return (1);
}
