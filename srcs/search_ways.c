/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:19:39 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/24 21:19:40 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		otkat(t_rooms *tmpry)
{
	tmpry->marker = 0;
	--g_steps;
}

void			search_ways(t_rooms *tmpry)
{
	int		i_links;

	if (tmpry->st_end != -1)
	{
		++g_steps;
		tmpry->marker = 1;
		tmpry->distance = g_steps;
	}
	if (tmpry->st_end == 1)
	{
		otkat(tmpry);
		return ;
	}
	i_links = 0;
	while (tmpry->links && (tmpry->links)[i_links])
	{
		while ((tmpry->links)[i_links] && (((tmpry->links)[i_links])->marker ||
				((tmpry->links)[i_links])->distance <= g_steps + 1))
			++i_links;
		if (!((tmpry->links)[i_links]))
			break ;
		search_ways((tmpry->links)[i_links]);
		++i_links;
	}
	otkat(tmpry);
}
