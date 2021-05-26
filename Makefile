# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/11 16:41:09 by asimoes           #+#    #+#              #
#    Updated: 2021/05/24 01:08:51 by asimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=\
	src/check_map.c \
	src/check_map2.c \
	src/config.c \
	src/config2.c \
	src/draw_walls_utils.c \
	src/draw_walls.c \
	src/free.c \
	src/free2.c \
	src/hooks.c \
	src/init.c \
	src/main.c \
	src/move.c \
	src/parse_c.c \
	src/parse_ea.c \
	src/parse_f.c \
	src/parse_map.c \
	src/parse_no.c \
	src/parse_r.c \
	src/parse_s.c \
	src/parse_so.c \
	src/parse_we.c \
	src/process_map.c \
	src/render.c \
	src/rotate.c \
	src/screenshot.c \
	src/sprites_utils.c \
	src/sprites.c \
	src/utils.c \
	src/utils2.c \
	src/textures.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c
DEPS=\
	inc/cub3d.h \
	get_next_line/get_next_line.h
OBJS=$(SRCS:.c=.o)
NAME=cub3D
CC=clang
CFLAGS=-O3 -Wall -Werror -Wextra -DBUFFER_SIZE=1024 -I./include -I.
CLIBS=-Llibft -lft -lm
LIBFT=libft/libft.a
UNAME=$(shell uname -s)
ifeq ($(UNAME),Linux)
	LIBMLX=minilibx-linux/libmlx.a
	LIBMLX_DIR=minilibx-linux
	CFLAGS += -DLINUX
	CLIBS += -Lminilibx-linux -lmlx -lXext -lX11
else
	LIBMLX=libmlx.dylib
	LIBMLX_DIR=minilibx-mac
	CFLAGS += -DMAC
	CLIBS += -L. -lmlx -framework OpenGL -framework AppKit
endif

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBMLX) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(CLIBS) -o $@

%.o:		%.c $(DEPS)
			$(CC) $(CFLAGS) -c $< -o $@
$(LIBFT):	
			$(MAKE) -C libft

$(LIBMLX):
			$(MAKE) -C $(LIBMLX_DIR)
ifeq ($(UNAME),Darwin)
			@mv $(LIBMLX_DIR)/$(LIBMLX) .
endif

clean:
			$(MAKE) -C libft clean
			$(MAKE) -C $(LIBMLX_DIR) clean
			rm -f $(OBJS)

fclean:		clean
			rm -f $(LIBMLX)
			rm -f $(LIBFT)
			rm -f $(NAME)

re:			fclean all