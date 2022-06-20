# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 15:13:33 by mbaazzy           #+#    #+#              #
#    Updated: 2022/06/02 15:03:37 by mbaazzy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = basic.c basic_2.c basic_3.c checking.c push_swap.c sorting.c stacks_functions.c stacks_functions_1.c stacks_functions_2.c ft_split.c ft_lstadd_back.c ft_lstnew.c sorting2.c sorting_utils_1.c sorting_utils_2.c sorting_utils_3.c sorting_utils_4.c get_next_line_utils.c  
SRC_B = check_bonus.c get_next_line.c get_next_line_utils.c basic.c basic_2.c basic_3.c checking.c sorting.c stacks_functions.c stacks_functions_1.c stacks_functions_2.c  ft_split.c ft_lstadd_back.c ft_lstnew.c sorting2.c sorting_utils_1.c sorting_utils_2.c sorting_utils_3.c sorting_utils_4.c
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
NAME = push_swap
BONUS = checker
HEADER = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror


all : $(NAME)

bonus : $(BONUS)

$(BONUS) : $(OBJ_B)
	$(CC) $(FLAGS) $(OBJ_B) -o $(BONUS)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_B)

fclean: clean
	rm -rf $(NAME) $(BONUS) 

re: fclean all