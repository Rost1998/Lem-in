# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 18:49:17 by rtulchiy          #+#    #+#              #
#    Updated: 2018/02/25 13:15:22 by rtulchiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

OBJSRC = main.c ft_realloc_modf.c add.c check_valid.c checkisit.c ft_adrlen.c\
		 ft_errors.c ft_new_room.c get_next_line.c handle_diez.c memfree.c\
		 move_ants.c prepare_rooms.c read_map.c search_ways.c service.c

OBJC = $(OBJSRC:%.c=srcs/%.c)
OBJO = $(OBJSRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
LIBDIR = libft

%.o: srcs/%.c
	gcc $(CFLAGS) -c $< -I includes

all: $(NAME)

$(NAME): $(OBJO)
	make -C $(LIBDIR)
	gcc $(CFLAGS) -o $(NAME) $(OBJO) -L./$(LIBDIR) -lft -I includes

clean:
	make clean -C $(LIBDIR)
	rm -f $(OBJO)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -f $(NAME)

re: fclean all
