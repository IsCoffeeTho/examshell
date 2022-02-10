# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 03:18:55 by amenadue          #+#    #+#              #
#    Updated: 2022/02/11 00:47:24 by amenadue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = file/fl_open.c \
		libes/es_error.c \
		libes/es_shell.c \
		libes/es_util.c \
		libes/es_kerberos.c

OBJS = $(FILES:%.c=%.o)

all: fclean
	-@gcc -c $(FILES)
	-@ar -rcs ../include.a $(notdir $(OBJS))

clean:
	-@rm -rf ../include.a

fclean: clean
	-@rm -rf $(notdir $(OBJS))