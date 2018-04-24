/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkisit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:16:10 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/24 21:16:11 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

_Bool		ft_isspecdiez(char *line)
{
	if (*line == '#')
		return (1);
	return (0);
}

_Bool		ft_islink(char *line)
{
	if (!ft_memchr(line, ' ', ft_strlen(line)) &&
			ft_memchr(line, '-', ft_strlen(line)))
		return (1);
	return (0);
}

_Bool		ft_isroom(char *line)
{
	if (ft_memchr(line, ' ', ft_strlen(line)))
		return (1);
	return (0);
}

_Bool		ft_isnumber(char *num)
{
	int		i;

	if (*num == '-' || *num == '+')
		++num;
	i = 0;
	while (num[i] && ft_isdigit(num[i]))
		++i;
	return (num[i] ? 0 : 1);
}

_Bool		ft_isint(char *num)
{
	_Bool	neg;
	int		len;

	if (!ft_isnumber(num))
		return (0);
	neg = *num == '-' ? 1 : 0;
	num += *num == '-' || *num == '+' ? 1 : 0;
	len = ft_strlen(num);
	if (len > 10)
		return (0);
	else if (len == 10 && ((!neg && ft_strcmp(num, "2147483647") > 0) ||
							(neg && ft_strcmp(num, "2147483648") > 0)))
		return (0);
	return (1);
}
