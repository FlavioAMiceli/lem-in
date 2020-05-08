# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/08 13:03:52 by mmarcell      #+#    #+#                  #
#    Updated: 2020/05/07 13:21:23 by mmarcell      ########   odam.nl          #
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

PLUS = $$(tput setaf 2)+$$(tput sgr0)
MINUS = $$(tput setaf 1)-$$(tput sgr0)

all: test

test: $(OBJS) $(TESTS_OBJS)
	@$(CC) -o $@ $^ -lcriterion $(LIBFT)
	@echo " ${PLUS} $@"

objs/%.o: srcs/%.c $(HDRS) | objs
	@$(CC) -c $(CFLAGS) -o $@ $(INCLUDES) $<
	@echo " ${PLUS} $@"

objs:
	@mkdir -p $@

clean:
	@rm -fv $(TESTS_OBJS) | sed 's/^/ $(MINUS) /'

fclean: clean
	@rm -fv test | sed 's/^/ $(MINUS) /'

re: fclean all

.PHONY: all test clean fclean re
