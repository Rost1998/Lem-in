/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:15:59 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/24 21:15:59 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_connect_rooms(t_rooms **rooms, int i1, int i2)
{
	size_t		len;

	len = ft_adrlen((void**)((rooms[i1])->links)) + 1;
	if (!((rooms[i1])->links = (t_rooms**)ft_realloc_modf((rooms[i1])->links,
				sizeof(t_rooms*) * (len + 1), sizeof(t_rooms*) * len)))
		return ;
	((rooms[i1])->links)[len - 1] = rooms[i2];
}

static _Bool	ft_check_exist_link(t_rooms **rooms, int i1, int i2)
{
	int		i;

	i = 0;
	while ((rooms[i1])->links && ((rooms[i1])->links)[i])
		if (((rooms[i1])->links)[i++] == rooms[i2])
			return (1);
	return (0);
}

_Bool			ft_addlink(t_rooms **rooms, char *line)
{
	int		i1;
	int		i2;
	char	**names;

	if (!(ft_check_valid_link(rooms, line)))
		return (0);
	if (!(names = ft_strsplit(line, '-')))
		return (0);
	i1 = 0;
	i2 = 0;
	while (ft_strcmp((rooms[i1])->name, names[0]))
		++i1;
	while (ft_strcmp((rooms[i2])->name, names[1]))
		++i2;
	ft_memfree_for_link(names);
	if (!ft_check_exist_link(rooms, i1, i2))
	{
		ft_connect_rooms(rooms, i1, i2);
		ft_connect_rooms(rooms, i2, i1);
	}
	return (1);
}

_Bool			ft_addroom(t_rooms ***rooms, char *line, int *se, int ants)
{
	size_t	len;
	char	**name;

	if (!(name = ft_check_valid_room(*rooms, line, *se)))
		return (0);
	len = ft_adrlen((void**)(*rooms)) + 1;
	if (!(*rooms = (t_rooms**)ft_realloc_modf(*rooms,
			sizeof(t_rooms*) * (len + 1), sizeof(t_rooms*) * len)))
		return (0);
	(*rooms)[len - 1] = ft_new_room(name);
	free(name[1]);
	free(name[2]);
	free(name);
	((*rooms)[len - 1])->st_end = *se;
	if (*se == 1)
		((*rooms)[len - 1])->ants = ants;
	*se = 0;
	return (1);
}
