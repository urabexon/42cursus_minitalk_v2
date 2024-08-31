# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 16:36:16 by hurabe            #+#    #+#              #
#    Updated: 2024/08/24 20:49:53 by hurabe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_NAME = client
S_NAME = server

C_SRCS = client.c
S_SRCS = server.c

cc = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I./include -I./libft -I./ft_printf
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

C_OBJS = $(C_SRCS:.c=.o)
S_OBJS = $(S_SRCS:.c=.o)

all: $(C_NAME) $(S_NAME)
$(C_NAME) $(S_NAME): %: %.o $(LIBFT) $(PRINTF)
	cc -o $@ $< $(LIBFT) $(PRINTF) $(INCLUDES)

$(C_OBJS) $(S_OBJS): %.o: %.c
	$(cc) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

bonus: all

clean:
	rm -rf $(C_OBJS) $(S_OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	rm -rf $(S_NAME) $(C_NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re bonus


