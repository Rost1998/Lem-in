/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_diez.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:18:52 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/24 21:18:52 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

_Bool		ft_handle_diez(char *line, int *se)
{
	if ((!ft_strcmp(line + 1, "#start") || !ft_strcmp(line + 1, "#end"))
		&& *se != 0)
		return (0);
	else if (!ft_strcmp(line + 1, "#start"))
		*se = 1;
	else if (!ft_strcmp(line + 1, "#end"))
		*se = -1;
	return (1);
}
