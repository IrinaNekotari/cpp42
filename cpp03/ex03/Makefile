# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 14:01:23 by nmascrie          #+#    #+#              #
#    Updated: 2023/12/19 14:01:24 by nmascrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = DiamondTrap

SRC = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp
OBJ = ${SRC:.cpp=.o}

FLAGS = -Wall -Werror -Wextra -std=c++98 -Wshadow -Wno-shadow

all: $(NAME)

.cpp.o:
	c++ $(FLAGS) -c $< -o $(<:.cpp=.o)
	
$(NAME): $(OBJ)
	c++ $(OBJ) $(FLAGS) -o $(NAME)
	
clean:
	@rm  $(OBJ)

fclean: clean
	@rm $(NAME)
	
re: fclean all

.PHONY: all clean fclean re