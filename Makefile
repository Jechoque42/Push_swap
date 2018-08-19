# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/20 14:46:44 by jechoque          #+#    #+#              #
#    Updated: 2018/08/19 18:07:11 by jean-bapt        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= 	gcc

RM	= 	rm -f

CFLAGS	= 	-Wall -Wextra -Werror

LIB1	=	./libft/libft.a

LIB2	=	./minilibx_macos/libmlx.a

NAME1	= 	checker

HDR1	= 	./include/checker.h

SRC1	= 	./src/Checker/main.c			\
		./src/Checker/ft_ch_apply.c		\
		./src/Checker/ft_ch_error.c		\
		./src/Checker/ft_ch_gen_a.c		\
		./src/Checker/ft_ch_lstc.c		\
		./src/Checker/ft_ch_operand.c		\
		./src/Checker/ft_ch_visual.c

NAME2	=	push_swap

HDR2	=	./include/push_swap.h

SRC2	=	./src/push_swap/main.c			\
		./src/push_swap/ft_ps_del.c		\
		./src/push_swap/ft_ps_error.c		\
		./src/push_swap/ft_ps_operand.c		\
		./src/push_swap/ft_ps_gen_a.c		\
		./src/push_swap/ft_ps_algo.c		\
		./src/push_swap/ft_ps_addcmd.c		\
		./src/push_swap/ft_ps_check.c		\
		./src/push_swap/ft_ps_put.c		\
		./src/push_swap/ft_ps_sort.c

OBJS1	= $(SRC1:.c=.o)

OBJS2	= $(SRC2:.c=.o)

all:	$(NAME1) $(NAME2)

$(NAME1): $(OBJS1) $(HDR1)
	@make -C ./libft
	@$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1) $(LIB1) $(LIB2) -framework OpenGL -framework Appkit
	@echo "####################################"
	@echo "##  ___ _  _ ___ ___ _ _ ___ __   ##"
	@echo "##  |   |__| |_  |   |/  |_  |_)  ##"
	@echo "##  |__ |  | |__ |__ |\_ |__ | \  ##"
	@echo "##                                ##"
	@echo "####################################"
	@echo "\033[1;34mchecker\t\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(NAME2): $(OBJS2) $(HDR2)
	@$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2) $(LIB1)
	@echo "#######################################################"
	@echo "##  ___  _  _  ___ _  _     ___ _       _  _   ___   ##"
	@echo "##  |__) |  | (__  |__| __ (__   \  X  /  /_\  |__)  ##"
	@echo "##  |    |__| ___) |  |    ___)   \/ \/  /   \ |     ##"
	@echo "##                                                   ##"
	@echo "#######################################################"
	@echo "\033[1;34mpush_swap\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

clean :
	@make -C ./libft clean
	@$(RM) $(OBJS1) $(OBJS2)

fclean : clean
	@make -C ./libft fclean
	@$(RM) $(NAME1) $(NAME2)

re : fclean all

.PHONY : all clean fclean re
