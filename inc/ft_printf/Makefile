# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 10:59:06 by ededemog          #+#    #+#              #
#    Updated: 2024/04/08 23:24:17 by ededemog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
EXEC = prog
SRCS = ft_printf.c ft_printf_utils.c other_utils.c
BONUS	=	
MAIN	=	main.c

OBJB	=	$(BONUS:.c=.o)

OBJM	=	$(MAIN:.c=.o)

TNAME	= 	test

OBJS 	= 	$(SRCS:.c=.o)

AR		= 	ar rc

RM		= 	rm -f

.c.o:
			$(CC) $(CFLAGS) -o $(<:.c=.o) -c $<

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

test:		$(NAME) bonus
			$(CC) $(CFLAGS) -o $(TNAME) $(MAIN) -L. -lft

all:		$(NAME)

bonus:		$(OBJB)
			$(AR) $(NAME) $(OBJB)

clean:
			$(RM) $(OBJS) $(OBJM) $(OBJB)

fclean:		clean
			$(RM) $(NAME) $(TNAME)

re:			fclean all

.PHONY:		all clean fclean re test