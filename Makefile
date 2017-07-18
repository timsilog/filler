# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjose <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/06 15:16:08 by tjose             #+#    #+#              #
#    Updated: 2017/05/05 18:19:36 by tjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tjose.filler
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = $(addprefix $(SRCDIR), $(SRCFILES))
OBJS = $(addprefix $(OBJDIR), $(SRCFILES:.c=.o))
SRCFILES = main.c \
		   read_info.c \
		   place_piece.c \
		   let_it_go.c \
		   create_heatmap.c \
		   player_validation.c \
		   draw_chase.c \
		   print_heat.c \
		   get_next_line.c
SRCDIR = ./srcs/
OBJDIR = ./objs/
INCDIR = ./includes/
LIBFTL = -L./libft -lft

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTL) -o $(NAME)

clean:
	make -C ./libft clean
	rm -fr $(OBJDIR)

fclean:
	make -C ./libft fclean
	rm -fr $(OBJDIR)
	rm -f $(NAME)

re: fclean all

