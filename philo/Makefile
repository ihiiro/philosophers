# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 16:34:00 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/03/21 23:32:14 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CFLAGS = -Wall -Wextra -Werror
SOURCES = main.c arg_verify.c satoi.c main_logic.c init.c routine.c clean.c time.c

all: $(NAME)

$(NAME): $(SOURCES) Makefile
	cc $(CFLAGS) $(SOURCES) -o $@

clean:
	rm $(NAME)

fclean: clean
	
re: fclean all