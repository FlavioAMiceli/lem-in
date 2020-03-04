# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/07 18:47:20 by mmarcell       #+#    #+#                 #
#    Updated: 2020/03/04 17:23:19 by mmarcell      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include srcs/mini_srcs

NAME := lem-in

OBJS := $(MINI_SOURCES:%=objs/%.o) objs/main.o

CFLAGS := -Wall -Wextra -Werror -g -fsanitize=address

LIBFT_PATH := libft
LIBFT := $(LIBFT_PATH)/libft.a

HDRS_PATH := hdrs
INCLUDES := -I $(HDRS_PATH) -I $(LIBFT_PATH)
HDRS := $(HDRS_PATH)/lem_in.h

PLUS := \033[38;5;40m+\033[0;00m
MINUS := \033[38;5;160m-\033[0;00m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
	@echo " ${PLUS} $@"

objs/%.o: srcs/%.c $(HDRS) | objs
	@$(CC) -c $(CFLAGS) -o $@ $(INCLUDES) $<
	@echo " ${PLUS} $@"

objs:
	@mkdir -p $@

$(LIBFT): FORCE
	@make -C $(LIBFT_PATH) | sed -e $$'s/^/$(LIBFT_PATH): /'

clean: lclean
	@make clean -C $(LIBFT_PATH) | sed -e $$'s/^/$(LIBFT_PATH): /'

lclean:
	@rm -rfv objs | sed -e $$'s/^/ $(MINUS) /'

fclean: clean lfclean
	@rm -fv $(LIBFT) | sed -e $$'s/^/ $(MINUS) /'

lfclean: lclean
	@rm -fv $(NAME) | sed -e $$'s/^/ $(MINUS) /'

re: fclean all

lre: lfclean all

test: $(LIBFT) $(OBJS) $(HDRS)
	@make -C tests

FORCE:

.PHONY: all clean fclean re FORCE
