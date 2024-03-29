# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: labintei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 14:05:41 by labintei          #+#    #+#              #
#    Updated: 2021/11/05 10:47:45 by mlaouedj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	src/main.c			\
			src/ft_utils.c			\
			src/ft_draw.c			\
			src/ft_keycode.c		\
			src/ft_frame.c			\
			src/parsing/ft_map_01.c 	\
			src/parsing/ft_map_02.c 	\
			src/parsing/ft_map_03.c		\
			src/parsing/ft_map_04.c		\
			src/parsing/ft_text_parsing.c 	\
			src/parsing/ft_map_parsing_01.c	\
			src/parsing/ft_map_parsing_02.c	\
			src/colors/ft_color_01.c	\
			src/colors/ft_color_02.c	\
			src/colors/ft_convert.c		\
			src/ray_casting/ft_ray_01.c 	\
			src/ray_casting/ft_ray_02.c     \
			src/ray_casting/ft_direction.c	\
			src/ray_casting/se/ft_se.c      \
			src/ray_casting/se/ft_se_x.c	\
			src/ray_casting/se/ft_se_y.c	\
			src/ray_casting/sw/ft_sw.c	\
			src/ray_casting/sw/ft_sw_x.c	\
			src/ray_casting/sw/ft_sw_y.c	\
			src/ray_casting/nw/ft_nw.c	\
			src/ray_casting/nw/ft_nw_x.c	\
			src/ray_casting/nw/ft_nw_y.c	\
			src/ray_casting/ne/ft_ne.c	\
			src/ray_casting//ne/ft_ne_x.c	\
			src/ray_casting//ne/ft_ne_y.c   \
			src/ray_casting/ft_texture.c	\
			src/memory/ft_memory.c		\
			src/memory/ft_error.c		\
			gnl/get_next_line.c		\
			gnl/get_next_line_utils.c	\
			
DIR_MLX		=	./mlx_linux/

OBJS		= $(SRCS:.c=.o)

CC				= gcc
CFLAGS			= -g -Wall -Wextra -Werror -I includes.
LIBS			= -L ./mlx_linux/ -lmlx -lXext -lX11 -lm
RM				= rm -f
NAME			= cub3D

all:		${NAME}
.c.o:
				${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:c=o}

$(NAME):	$(OBJS)
				make -C $(DIR_MLX)
				${CC} $(CFLAGS) -o $(NAME) $(SRCS) $(LIBS)

clean:
				make -C $(DIR_MLX) clean
				$(RM) $(OBJS)

fclean:			
				make -C $(DIR_MLX) clean
				$(RM) $(NAME)

re: clean all

.PHONY:		all clean fclean re
