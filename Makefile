# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 16:33:26 by cpoulain          #+#    #+#              #
#    Updated: 2025/01/03 15:50:50 by cpoulain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Commands

RM				=	/usr/bin/rm -f
ECHO			=	/usr/bin/echo

# Includes

include			Files_checker.mk
include			Files_common.mk
include			Files_push_swap.mk

# Directories

SRC_DIR			:=	src
INC_DIR			:=	include
OBJ_DIR			:=	build
BIN_DIR			:=	binaries
TDPTY_DIR		:=	third_party

PUSH_SWAP		:=	push_swap
PS_SRC_DIR		:=	$(SRC_DIR)/$(PUSH_SWAP)
PS_OBJ_DIR		:=	$(OBJ_DIR)/$(PUSH_SWAP)

CHECKER			:=	checker
CK_SRC_DIR		:=	$(SRC_DIR)/$(CHECKER)
CK_OBJ_DIR		:=	$(OBJ_DIR)/$(CHECKER)

CM_SRC_DIR		:=	$(SRC_DIR)/common
CM_OBJ_DIR		:=	$(OBJ_DIR)/common

# LIBFT

LIBFT_DIR		:=	42_libft_full
LIBFT_PATH		:=	$(TDPTY_DIR)/$(LIBFT_DIR)
LIBFT_INC_H		:=	libft.h
LIBFT_TARGET	:=	libftfull.a
LIBFT_GIT		:=	https://github.com/CodeWithCharles/42_libft_full.git

# Targets

PS_TARGET		:=	$(BIN_DIR)/$(PUSH_SWAP)
CK_TARGET		:=	$(BIN_DIR)/$(CHECKER)
TDPTY_LIBFT_H	:=	$(INC_DIR)/$(LIBFT_INC_H)

# Compiler

CC				:=	cc
CFLAGS			:=	-I$(INC_DIR) -Wall -Wextra -Werror -g
LFLAGS			:=	-L$(LIBFT_PATH) -l:libftfull.a

# Objs

PS_SRCS			=	$(addprefix $(PS_SRC_DIR)/, $(addsuffix .o, $(PS_FILES)))
PS_OBJS			=	$(addprefix $(PS_OBJ_DIR)/, $(addsuffix .o, $(PS_FILES)))

CK_SRCS			=	$(addprefix $(CK_SRC_DIR)/, $(addsuffix .o, $(CK_FILES)))
CK_OBJS			=	$(addprefix $(CK_OBJ_DIR)/, $(addsuffix .o, $(CK_FILES)))

CM_SRCS			=	$(addprefix $(CM_SRC_DIR)/, $(addsuffix .o, $(CM_FILES)))
CM_OBJS			=	$(addprefix $(CM_OBJ_DIR)/, $(addsuffix .o, $(CM_FILES)))

# Terminal colors

TERM_RESET		:=	\033[0m
TERM_BLACK		:=	\033[30m
TERM_RED		:=	\033[31m
TERM_GREEN		:=	\033[32m
TERM_YELLOW		:=	\033[33m
TERM_BLUE		:=	\033[34m
TERM_MAGENTA	:=	\033[35m
TERM_CYAN		:=	\033[36m
TERM_WHITE		:=	\033[37m

TERM_UP			:=	\033[1A
TERM_CLEAR_LINE	:=	\033[2K\r

# Phony rules

all: $(PS_TARGET)

bonus: $(CK_TARGET)

clean:
	@if [ -e $(OBJ_DIR) ]; then \
		printf "$(TERM_YELLOW)Removing %d objects from \"%s\" folder...\n$(TERM_RESET)" $(words $(OBJS)) $(OBJ_DIR);\
		$(RM) -r $(OBJ_DIR);\
	fi

fclean: clean
	@if [ -e $(TARGET) ]; then \
		printf "$(TERM_YELLOW)Removing \"%s\"...\n$(TERM_RESET)" $(TARGET);\
		$(RM) $(TARGET);\
		$(RM) libft.h;\
	fi
	@if [ -e $(INC_DIR)/$(LIBFT_INC_H) ]; then \
		printf "$(TERM_YELLOW)Removing \"%s\"...\n$(TERM_RESET)" $(INC_DIR)/$(LIBFT_INC_H); \
		$(RM) $(THDPTY_LIBFT_H);\
	fi
	@if [ -e $(LIBFT_TARGET) ]; then \
		printf "$(TERM_YELLOW)Removing \"%s\"...\n$(TERM_RESET)" $(LIBFT_TARGET); \
		$(RM) $(LIBFT_TARGET);\
	fi

cleanlibs:
	@$(MAKE) clean -C $(LIBFT_PATH)

fcleanlibs:
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@$(RM) $(LIBFT_TARGET)
	@$(RM) $(THDPTY_LIBFT_H)

re: fclean all

norminette:
	@norminette $(SRC_DIR) $(INC_DIR) | grep -Ev '^Notice|OK!$$'	\
	&& $(ECHO) -e '\033[1;31mNorminette KO!'						\
	|| $(ECHO) -e '\033[1;32mNorminette OK!'

# Binary

$(PS_TARGET): $(LIBFT_TARGET) $(CM_OBJS) $(PS_OBJS)
	@mkdir -p $(@D)
	$(CC) -o $@ $(CM_OBJS) $(PS_OBJS) $(CFLAGS) $(LFLAGS)

$(CK_TARGET): $(LIBFT_TARGET) $(CM_OBJS) $(CK_OBJS)
	@mkdir -p $(@D)
	$(CC) -o $@ $(CM_OBJS) $(CK_OBJS) $(CFLAGS) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@ $(CFLAGS)

# Third party compilation

$(LIBFT_TARGET):
	@if [ ! -d "$(LIBFT_PATH)/.git" ]; then \
		printf "$(TERM_YELLOW)Cloning third party library \"%s\" in \"%s\"...\n$(TERM_RESET)" $(LIBFT_GIT) $(LIBFT_PATH);\
		git clone $(LIBFT_GIT) $(LIBFT_PATH);\
	fi
	@printf "$(TERM_MAGENTA)Making archive $(TERM_BLUE)\"%s\"$(TERM_MAGENTA)...$(TERM_RESET)" $@
	@$(MAKE) -C $(LIBFT_PATH)
	@cp $(LIBFT_PATH)/$@ ./
	@cp -u $(LIBFT_PATH)/$(LIBFT_INC_H) $(INC_DIR)/
	@printf "$(TERM_CLEAR_LINE)$(TERM_GREEN)Done copying archive $(TERM_BLUE)\"%s\"$(TERM_GREEN) !\n$(TERM_RESET)" $@

.PHONY: all bonus clean fclean re norminette cleanlibs fcleanlibs
