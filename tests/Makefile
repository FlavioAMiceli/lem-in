# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/08 13:03:52 by mmarcell       #+#    #+#                 #
#    Updated: 2020/03/26 10:19:27 by moana         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include ../srcs/mini_srcs
include ./srcs/tests_mini_srcs

NAME := lem-in

OBJS := $(MINI_SOURCES:%=../objs/%.o)
TESTS_OBJS := $(TESTS_MINI_SOURCES:%=objs/%.o)

CFLAGS := -Wall -Wextra -Werror

LIBFT_PATH := ../libft
LIBFT := $(LIBFT_PATH)/libft.a

HDRS_PATH := ../hdrs
INCLUDES := -I $(HDRS_PATH) -I $(LIBFT_PATH)
HDRS := $(HDRS_PATH)/lem_in.h

PLUS = \033[38;5;40m+\033[0;00m
MINUS = \033[38;5;160m-\033[0;00m

all: test

test: $(OBJS) $(TESTS_OBJS)
	@$(CC) -o $@ $^ -lcriterion $(LIBFT)
	@echo -e " ${PLUS} $@"

objs/%.o: srcs/%.c $(HDRS) | objs
	@$(CC) -c $(CFLAGS) -o $@ $(INCLUDES) $<
	@echo -e " ${PLUS} $@"

objs:
	@mkdir -p $@

clean:
	@rm -fv $(TESTS_OBJS) | sed -e $$'s/^/ $(MINUS) /'

fclean: clean
	@rm -fv test | sed -e $$'s/^/ $(MINUS) /'

re: fclean all

.PHONY: all test clean fclean re
