#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 22:37:03 by ciglesia          #+#    #+#              #
#    Updated: 2021/06/15 16:10:30 by ciglesia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libelf.a

INCLUDE		=	./include/

#***************** DIR ********************#

DIRSRC		=	./src/

#***************** SRC ********************#

SRC			=	elf_ident.c

#***************** DEPS *******************#

DIROBJ		=	./depo/

OAUX		=	$(SRC:%=$(DIROBJ)%)
DEPS		=	$(OAUX:.c=.d)
OBJS		=	$(OAUX:.c=.o)

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -ansi -pedantic -g
	endif
else
CFLAGS		=	-Wall -Wextra -Werror -fPIC
endif

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/bin/echo -e
BOLD		=	"\e[1m"
BLINK		=	 "\e[5m"
RED			=	 "\e[38;2;255;0;0m"
GREEN		=	 "\e[92m"
BLUE		=	 "\e[34m"
YELLOW		=	 "\e[33m"
E0M			=	 "\e[0m"

#************************ DEPS COMPILATION *************************

%.o		:		../$(DIRSRC)/%.c
				@printf $(GREEN)"Generating libelf objects... %-33.33s\r" $@
				@$(CC) $(CFLAGS) -I $(INCLUDE) -MMD -o $@ -c $<

#************************ MAIN COMPILATION *************************

$(NAME)	:		$(OBJS)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)
				@$(ECHO) $(BOLD) $(GREEN) '> Compiled' $(E0M)

clean	:
				@($(RM) $(OBJS))
				@($(RM) $(DEPS))
				@$(ECHO) '> Directory cleaned'

all		:		$(NAME)

fclean	:		clean
				@$(RM) $(NAME)
				@$(ECHO) '> Remove executable'

re		:		fclean all

.PHONY	:		all clean re

-include $(DEPS)
