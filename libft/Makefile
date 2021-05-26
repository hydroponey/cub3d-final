# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/07 20:29:22 by asimoes           #+#    #+#              #
#    Updated: 2021/05/24 01:08:55 by asimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_atoi.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c\
				ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c\
				ft_split.c\
				ft_strchr.c\
				ft_strdup.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strmapi.c\
				ft_strncmp.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strtrim.c\
				ft_substr.c\
				ft_tolower.c\
				ft_toupper.c

SRCS_BONUS	=	ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlast.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_lstsize.c

OBJ=$(SRCS:.c=.o)
OBJ_BONUS=$(SRCS_BONUS:.c=.o)

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

all:		$(NAME)

bonus:		$(OBJ) $(OBJ_BONUS)
			ar rc $(NAME) $(OBJ) $(OBJ_BONUS)
			ranlib $(NAME)

%.o:		%.c
			$(CC) -I. -o $@ -c $? $(CFLAGS)
clean:
			rm -f $(OBJ) $(OBJ_BONUS)

fclean:		clean
			rm -f $(NAME)
			rm -f libft.so

re:			fclean all

so:			$(OBJ) $(OBJ_BONUS)
			$(CC) -shared $(CFLAGS) -o libft.so $^