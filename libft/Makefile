# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 13:08:39 by hurabe            #+#    #+#              #
#    Updated: 2024/08/25 17:25:13 by hurabe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoi.c ft_isdigit.c ft_strlen.c \
		  ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c
		
OBJS	= $(SRCS:.c=.o)

# INCS	= -I includes
NAME	= libft.a
CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

ifeq ($(BONUS_FLAG),yes)
	SOURCES = $(BASIC_SRCS) $(BONUS_SRCS)
else
	SOURCES = $(BASIC_SRCS)
endif

# %.o:%.c
# 	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean	all

.PHONY:	all clean fclean re