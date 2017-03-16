# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/05 12:29:27 by gpouyat           #+#    #+#              #
#    Updated: 2017/03/11 15:08:23 by gpouyat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme main

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

C_NO = \033[0m
C_G = \033[0;32m
C_Y = \033[1;33m
C_B = \033[1;34m
C_C = \033[1;36m
C_R = \033[1;31m

SRC_PATH = ./print_srcs
LIB_PATH = ./libft_srcs
INC_PATH = ./includes
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

SRC_NAME =	convers.c ft_printf.c get.c display_flags.c ft_cs.c ft_o.c\
				type_of_number.c ft_x.c

LIB_NAME = 	ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_strlen.c ft_putstr_fd.c\
ft_putnbr.c ft_putnbr_fd.c ft_putendl.c ft_putendl_fd.c ft_itoa.c ft_strdup.c\
ft_strcmp.c ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
ft_isprint.c ft_toupper.c ft_tolower.c ft_strcpy.c ft_strncpy.c ft_memset.c\
ft_memmove.c ft_bzero.c ft_atoi.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
ft_strcat.c ft_strncat.c ft_memcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
ft_strstr.c ft_strnstr.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c\
ft_striter.c ft_strclr.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strmapi.c\
ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c\
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
get_next_line.c over.c ft_strdblnew.c ft_strtolower.c error.c ft_replace.c\
ft_itoa_base.c ft_atoi_base.c pf_itoa_base.c ft_putwchar.c ft_strwlen.c\
ft_getchar.c ft_strdbldup.c ft_isprintable.c ft_is_number.c ft_strdblfree.c\
ft_fri.c

INC_NAME = libft.h

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)


SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB)
	@ar rc $(NAME) $(OBJ) $(OBJLIB)
	@ranlib $(NAME)
	@printf "\n$(C_B)%-20s\t$(C_R)Compilation\t$(C_G)[ OK ✔ ]$(C_NO)\n" $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -o $@ $(FLAGS) -c $< -I includes
	@printf "$(C_B)█$(C_NO)"

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir -p $(OBJLIB_PATH)
	@$(CC) -o $@ $(FLAGS) -c $< -I includes
	@printf "$(C_Y)█$(C_NO)"

clean:
	@rm -rf $(OBJ) $(OBJLIB)
	@rm -rf includes/libft.h.gch
	@rm -rf includes/get_next_line.h.gch
	@printf "$(C_B)%-20s\t$(C_Y)Cleaning obj\t$(C_G)[ OK ✔ ]$(C_NO)\n" $(NAME)

fclean: clean
	@rm -rf ./obj $(NAME)
	@rm -rf maintest
	@printf "$(C_B)%-20s\t$(C_Y)Cleaning lib\t$(C_G)[ OK ✔ ]$(C_NO)\n" $(NAME)

re: fclean all

norme:
		@norminette $(SRC) $(LIB) $(INC)
		@printf "$(C_B)%-20s\t$(C_Y)Norminette\t$(C_G)[ OK ✔ ]$(C_NO)\n" $(NAME)

main: $(NAME)
	@$(CC) $(FLAGS) -o maintest main.c $(NAME) -I libft -I includes
	@printf "$(C_B)%-20s\t$(C_Y)compilation\t$(C_G)[ OK ✔ ]$(C_NO)\n" "maintest"
