# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshiling <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 13:01:36 by sshiling          #+#    #+#              #
#    Updated: 2017/10/11 23:20:04 by sshiling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PUSH = push_swap

NAME_CHECK = checker

SRCS_PUSH =	push_swap.c \

SRCS_CHECK = checker.c

SRCS = general1.c \
		general2.c \
		general3.c \
		general4.c \
		general5.c \
		commands1.c \
		commands2.c \
		commands3.c \
		sort.c \
		sort_a.c \
		sort_b.c \
		boost.c \
		quicksort.c \
		sort_three1.c \
		sort_three2.c \
		errors.c \
		random_mode.c

LIBFT = libft/

OBJECTS_PUSH = $(SRCS_PUSH:.c=.o)

OBJECTS_CHECK = $(SRCS_CHECK:.c=.o)

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = gcc

%.o: %.c
	@$(CC) $(FLAGS) -c $<

all: $(NAME_PUSH) $(NAME_CHECK)

$(NAME_PUSH): $(OBJECTS_PUSH) $(OBJECTS)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME_PUSH) $(OBJECTS_PUSH) $(OBJECTS) -L $(LIBFT) -lftprintf
	@echo "All .o files successfully created."
	@echo "Push_swap successfully created."

$(NAME_CHECK): $(OBJECTS_CHECK)
	@$(CC) $(FLAGS) -o $(NAME_CHECK) $(OBJECTS_CHECK) $(OBJECTS) -L $(LIBFT) -lftprintf
	@echo "All .o files successfully created."
	@echo "Checker successfully created."

clean:
	@echo "Deleting all .o files. Please wait..."
	@rm -f $(OBJECTS_PUSH) $(OBJECTS_CHECK) $(OBJECTS)
	@make clean -C $(LIBFT)
	@echo "All .o files deleted."


fclean: clean
	@echo "Deleting all .o files, push_swap, and checker. Please wait..."
	@rm -f $(NAME_PUSH) $(NAME_CHECK) $(OBJECTS)
	@make fclean -C $(LIBFT)
	@echo "All .o files, push_swap, and checker deleted."
	

re: fclean all

.PHONY: re all clean fclean
