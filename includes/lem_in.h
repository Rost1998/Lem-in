/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 14:40:20 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/25 14:40:21 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"

# define INF 2147483647

/*
** -1 : end;
** 0 : -;
** 1 : start;
*/

typedef struct		s_rooms
{
	char			*name;
	int				*coords;
	struct s_rooms	**links;
	int				distance;
	_Bool			marker;
	int				st_end;
	int				ants;
}					t_rooms;

int					g_steps;
char				*g_iteration;
t_rooms				**g_ants;

t_rooms				**read_map(char **buffer);
t_rooms				*ft_new_room(char **name);
_Bool				ft_isroom(char *line);
_Bool				ft_islink(char *line);
_Bool				ft_isspecdiez(char *line);
_Bool				ft_isnumber(char *num);
_Bool				ft_isint(char *num);
_Bool				ft_handle_diez(char *line, int *se);
_Bool				ft_addroom(t_rooms ***rooms, char *name, int *se, int ants);
_Bool				ft_addlink(t_rooms **rooms, char *line);
size_t				ft_adrlen(void **ptr);
t_rooms				*get_room(t_rooms **rooms, int code);
void				prepare_rooms(t_rooms **rooms, t_rooms *end);
void				*ft_realloc_modf(void *ptr, size_t newsize, size_t oldsize);
_Bool				ft_check_total_valid(t_rooms **rooms);
_Bool				ft_check_valid_link(t_rooms **rooms, char *line);
char				**ft_check_valid_room(t_rooms **rooms, char *line, int se);
void				search_ways(t_rooms *end);
void				move_ants(t_rooms *start, t_rooms *end);
void				push_ant(t_rooms *from, t_rooms *to, int i);
void				ft_error();
_Bool				ft_memfree_for_all_rooms(t_rooms **rooms);
_Bool				ft_memfree_for_room(char **divs);
_Bool				ft_memfree_for_link(char **names);
void				ft_memfree_success(t_rooms **rooms, char *buffer);

#endif
