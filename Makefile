# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 03:22:45 by amenadue          #+#    #+#              #
#    Updated: 2022/02/10 23:14:24 by amenadue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = examshell

FILES = examshell.c


all: fclean
	-@$(MAKE) all -s -C lib
	-@gcc $(addprefix src/,$(FILES)) include.a -lkrb5 -g -o examshell

clean: 
	-@$(MAKE) clean -s -C lib
	-@rm -rf examshell

fclean: clean
	-@$(MAKE) fclean -s -C lib