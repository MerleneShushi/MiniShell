# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 12:27:15 by dcarrilh          #+#    #+#              #
#    Updated: 2023/07/24 12:27:25 by dcarrilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c builtins.c builts2.c env.c
	
CC = cc -g
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

OBJ = $(SRC:%.c=%.o)
BONUS = $(BNS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./libft
		@$(CC) $(CFLAGS) $(OBJ) ./libft/libft.a -lreadline -o $(NAME)
		
clean:
		$(MAKE) clean -C ./libft
		@$(RM) $(OBJ)
		
fclean: clean
		$(MAKE) fclean -C ./libft
		@$(RM) $(NAME) 
		
re: fclean all
		$(MAKE) re -C ./libft

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	cc -nostartfiles -shared -o libft.so $(OBJ)
