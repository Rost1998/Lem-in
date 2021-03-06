/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 11:20:59 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/05 13:04:07 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	i;

	i = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		i = n * -1;
	}
	if (i / 10 != 0)
		ft_putnbr_fd(i / 10, fd);
	c = i % 10 + 48;
	write(fd, &c, 1);
}
