# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 17:05:07 by sumedai           #+#    #+#              #
#    Updated: 2024/08/24 22:35:33 by sumedai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS_DIR = ./srcs
SRCS = $(SRCS_DIR)/ft_printf.c\
	   $(SRCS_DIR)/ft_printf_c.c\
	   $(SRCS_DIR)/ft_printf_s.c\
	   $(SRCS_DIR)/ft_printf_id.c\
	   $(SRCS_DIR)/ft_printf_p.c\
	   $(SRCS_DIR)/ft_printf_u.c\
	   $(SRCS_DIR)/ft_printf_larx.c\
	   $(SRCS_DIR)/ft_printf_x.c\
	   $(SRCS_DIR)/ft_numchar.c\
	   $(SRCS_DIR)/ft_numstr.c\
	   $(SRCS_DIR)/ft_putnbr_base.c\
	   $(SRCS_DIR)/ft_putunbr_base.c\
	   $(SRCS_DIR)/ft_putstr_n.c

OBJS = $(SRCS:%.c=%.o)
CC = cc
LIBFT_NAME = libft.a
LIBFT_PATH = ./srcs/libft/
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes
AR = ar rcs

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	mv $(LIBFT_PATH)/$(LIBFT_NAME) $(NAME)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all
	
.PHONY: all clean fclean re
