# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 14:21:07 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/03/24 21:44:25 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CFLAGS = -Wall -Wextra -Werror
SOURCES = main_bonus.c arg_verify_bonus.c satoi_bonus.c main_logic_bonus.c init_bonus.c time_bonus.c

all: bonus

bonus: $(NAME)

$(NAME): $(SOURCES) Makefile #NOTE: ADD CFLAGS!!
	cc $(CFLAGS) $(SOURCES) -o $@

clean:
	rm $(NAME)

fclean: clean
	
re: fclean all