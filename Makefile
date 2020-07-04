# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/07 18:47:20 by mmarcell      #+#    #+#                  #
#    Updated: 2020/07/04 12:01:43 by mmarcell      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include srcs/mini_srcs

NAME := lem-in

OBJS := $(MINI_SOURCES:%=objs/%.o) objs/main.o

CFLAGS := -Wall -Wextra -Werror -g

LIBFT_PATH := libft
LIBFT := $(LIBFT_PATH)/libft.a

HDRS_PATH := hdrs
INCLUDES := -I $(HDRS_PATH) -I $(LIBFT_PATH)
HDRS := $(HDRS_PATH)/lem_in.h

PLUS = $$(tput setaf 2)+$$(tput sgr0)
MINUS = $$(tput setaf 1)-$$(tput sgr0)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
	@echo " $(PLUS) $@"

objs/%.o: srcs/%.c $(HDRS) | objs
	@$(CC) -c $(CFLAGS) -o $@ $(INCLUDES) $<
	@echo " $(PLUS) $@"

objs:
	@mkdir -p $@

$(LIBFT): FORCE
	@make -C $(LIBFT_PATH) | sed "s/^/$(LIBFT_PATH): /"

clean: lclean
	@make clean -C $(LIBFT_PATH) | sed "s/^/$(LIBFT_PATH): /"

lclean:
	@rm -rfv objs | sed "s/^/ $(MINUS) /"

fclean: clean lfclean
	@rm -fv $(LIBFT) | sed "s/^/ $(MINUS) /"

lfclean: lclean
	@rm -fv $(NAME) | sed "s/^/ $(MINUS) /"

re: fclean all

lre: lfclean all

test: $(LIBFT) $(OBJS) $(HDRS)
	@make -C tests

FORCE:

.PHONY: all clean fclean re FORCE
