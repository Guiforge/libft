# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/05 12:29:27 by gpouyat           #+#    #+#              #
#    Updated: 2019/02/13 15:08:22 by gpouyat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# .NOTPARALLEL:

.PHONY: all clean fclean re

C_NO = \033[0m
C_G = \033[0;32m
C_Y = \033[1;33m
C_B = \033[1;34m
C_C = \033[1;36m
C_R = \033[1;31m

SRC_SUBDIR = libft_srcs/error
SRCS			+= error.c over_p_str.c over_p.c over_str.c over.c

SRC_SUBDIR += libft_srcs/list
SRCS			+= ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstfree.c ft_lstiter.c\
 							ft_lstmap.c ft_lstnew.c ft_lstpush.c ft_lstremove.c ft_lstsort.c

SRC_SUBDIR += libft_srcs/string
SRCS			+= ft_atoi_base.c ft_atoi.c ft_strcat.c ft_strchr.c ft_strcpy.c\
 							ft_striter.c ft_striteri.c ft_strlcat.c ft_strlen.c ft_strmap.c\
						   ft_strmapi.c ft_strncat.c ft_strncpy.c ft_strnstr.c ft_strrchr.c\
							  ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtolower.c \
							  ft_overwrite.c ft_tolower.c ft_toupper.c ft_strcount.c

SRC_SUBDIR += libft_srcs/string/comp
SRCS			+= ft_strcmpa.c ft_strcmp.c ft_strequ.c ft_strncmp.c ft_strnequ.c

SRC_SUBDIR += libft_srcs/string/free
SRCS			+= ft_fri.c ft_strclr.c ft_strdel.c

SRC_SUBDIR += libft_srcs/string/is
SRCS			+= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
							ft_str_isdigit.c ft_str_isprint.c ft_str_isvalue.c

SRC_SUBDIR += libft_srcs/string/put
SRCS			+= ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
 							ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
							ft_putsize_t_base_fd.c ft_putnbr_base.c

SRC_SUBDIR += libft_srcs/string/useMalloc
SRCS			+= ft_itoa_base.c ft_itoa.c ft_replace.c ft_strdup.c ft_strjoin.c\
 							ft_strnew.c ft_strtrim.c pf_itoa_base.c

SRC_SUBDIR += libft_srcs/string/wchar
SRCS			+= ft_getchar.c ft_putwchar.c ft_strwlen.c

SRC_SUBDIR += libft_srcs/tab
SRCS			+= ft_strdbldup.c ft_strdblfree.c ft_strdblnew.c ft_strdblprint.c\
 							tri.c ft_strdbllen.c

SRC_SUBDIR += libft_srcs/void
SRCS			+= ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
 							ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c

SRC_SUBDIR += libft_srcs
SRCS			+= get_next_line.c ft_next_multiple.c ft_getopt.c ft_align.c \
					ft_itochar.c close_reset.c ft_getip.c ft_exp_path.c

SRC_SUBDIR += print_srcs
SRCS			+= convers.c display_flags.c ft_cs.c ft_o.c ft_printf.c ft_x.c get.c\
							type_of_number.c color.c ft_dprintf.c print.c ft_vprintf.c

SRC_SUBDIR += secure_memory
SRCS			+= ft_secu_free.c ft_secu_malloc.c ft_strnew_secu.c ft_strdup_secu.c \
					ft_secu_malloc_debug.c

SRC_SUBDIR += btree
SRCS			+= btree_apply_infix.c btree_apply_prefix.c btree_apply_suffix.c\
 							btree_create_node.c btree_destroy.c btree_insert_data.c\
							btree_level_count.c btree_print.c btree_search_item.c\


SRC_SUBDIR += bits
SRCS			+= b_print.c b_new.c b_dump.c b_clean.c b_join.c rot.c swap.c

SRC_SUBDIR += logger
SRCS			+= log.c log_wrappers.c log_func.c


###############################################################################

#  Compiler

NAME 			= libft.a
CC				= clang
CFLAGS		= -Wall -Wextra -Werror

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	CFLAGS		+= -fPIC
endif

ifeq ($(DEV),yes)
    CFLAGS		+= -g -Wvla
endif

ifeq ($(SAN),yes)
    CFLAGS		+= -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif

#The Directories, Source, Includes, Objects and Libraries
INC			= -I includes -I includes/intern
SRCS_DIR	= sources
vpath  %c $(addprefix $(SRCS_DIR)/,$(SRC_SUBDIR))

#Objects
OBJS_DIR	= objs
 OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

BUILD_DIR	= $(OBJS_DIR) $(DEPS_DIR)

#Utils
RM					= rm -rf
MKDIR				= mkdir -p

COUNT = 0
TOTAL = 0
PERCENT = 0
$(eval TOTAL=$(shell echo $$(printf "%s" "$(SRCS)" | wc -w)))
###############################################################################


all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo
	@echo "[\033[35m---------------------------------\033[0m]"
	@echo "[\033[36m----------- Lib Done! -----------\033[0m]"
	@echo "[\033[35m---------------------------------\033[0m]"

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	$(eval PERCENT=$(shell echo $$((($(COUNT) * 100 )/$(TOTAL)))))
	@printf "$(C_B)%-8s $(C_Y) $<$(C_NO)                                           \n" "[$(PERCENT)%]"

$(BUILD_DIR):
	@$(MKDIR) $@

clean:
	@echo "\033[35m$(NAME)  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@$(RM) $(OBJS_DIR)

fclean: clean
	@echo "\033[35m$(NAME)  :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@$(RM) $(NAME)

re: fclean all
