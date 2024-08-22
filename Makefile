# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 18:20:34 by yuuko             #+#    #+#              #
#    Updated: 2024/09/13 22:01:39 by yuuko            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= cub3D

# **************************************************************************** #
#    Dependencies                                                              #
# **************************************************************************** #

LIBS		:= \
	lib/libft/libft.a \
	lib/MLX42/build/libmlx42.a \

INCS		:= \
	lib/libft/include \
	lib/MLX42/include \
	src \

# **************************************************************************** #
#    Sources                                                                   #
# **************************************************************************** #

SRC_DIR		:= src

SRCS		:= \
	main.c \
	common/error.c \
	common/file.c \
	core/math/ivector2.c \
	core/math/ivector2_operation.c \
	core/math/vector2.c \
	core/math/vector2_operation.c \
	core/math/angle.c \
	core/math/matrix.c \
	core/color/color.c \
	core/color/parse.c \
	core/types/orientation.c \
	core/types/direction.c \
	core/ctx/ctx.c \
	core/ctx/event.c \
	core/ctx/image.c \
	core/draw/draw.c \
	app/map/map.c \
	app/map/data.c \
	app/map/transform.c \
	app/map/component.c \
	app/map/validate.c \
	app/scene/scene.c \
	app/scene/element.c \
	app/scene/parse.c \
	app/scene/build.c \
	app/scene/error.c \
	app/ray/ray.c \
	app/render/wall.c \
	app/render/floor.c \
	app/render/sky.c \
	app/render/minimap.c \
	app/render/view.c \
	app/player/player.c \
	app/player/move.c \
	app/game/game.c \
	app/game/key.c \
	app/game/loop.c \

SRCS		:= $(addprefix $(SRC_DIR)/, $(SRCS))

# **************************************************************************** #
#    Build                                                                     #
# **************************************************************************** #

BUILD_DIR	:= build

OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L,$(dir $(LIBS)))
LDLIBS		:= -lft -lmlx42 -ldl -lglfw -pthread -lm

# **************************************************************************** #
#    Misc                                                                      #
# **************************************************************************** #

RM			:= rm -f
MAKEFLAGS	+= --no-print-directory

RED			:= $(shell tput setaf 1)
GREEN		:= $(shell tput setaf 2)
YELLOW		:= $(shell tput setaf 3)
BLUE		:= $(shell tput setaf 4)
MAGENTA		:= $(shell tput setaf 5)
CYAN		:= $(shell tput setaf 6)
WHITE		:= $(shell tput setaf 7)
ERROR		:= $(shell tput setab 1)$(WHITE)
SUCCESS		:= $(shell tput setab 2)$(WHITE)
WARNING		:= $(shell tput setab 3)$(WHITE)
INFO		:= $(shell tput setab 4)$(WHITE)
BOLD		:= $(shell tput bold)
RESET		:= $(shell tput sgr0)
CLEAR		:= $(shell tput cuu1; tput el)
TITLE		:= $(YELLOW)$(basename $(NAME))$(RESET)

# 1: action, 2: target, 3: color
define message
	$(info [$(TITLE)] $(3)$(1)$(RESET) $(2))
endef

ifdef WITH_DEBUG
	TITLE	+= $(MAGENTA)debug$(RESET)
	CFLAGS	+= -g3
else
	CFLAGS	+= -O3
endif

ifdef WITH_SANITIZER
	TITLE	+= $(MAGENTA)sanitizer$(RESET)
	CFLAGS	+= -fsanitize=address,undefined
endif

ifdef WITH_BONUS
	TITLE	+= $(MAGENTA)bonus$(RESET)
endif

# **************************************************************************** #
#    Targets                                                                   #
# **************************************************************************** #

all: $(NAME) ## Build the program

bonus: ## Build the bonus program
	$(MAKE) WITH_BONUS=1 all

debug: ## Build the program with debug symbols
	$(MAKE) WITH_DEBUG=1 all

sanitizer: ## Build the program with debug symbols and sanitizer
	$(MAKE) WITH_DEBUG=1 WITH_SANITIZER=1 all

loose: ## Build the program ignoring warnings
	$(MAKE) CFLAGS="$(filter-out -Werror,$(CFLAGS))" all

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	$(call message,CREATED,$(NAME),$(BLUE))

$(LIBS): lib/MLX42/build
	$(MAKE) -C $(@D) -j4

lib/MLX42/build:
	cmake -S $(@D) -B $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	$(call message,CREATED,$(basename $(notdir $@)),$(GREEN))

clean: ## Remove all generated object files
	for lib in $(dir $(LIBS)); do $(MAKE) -C $$lib clean; done
	$(RM) -r $(BUILD_DIR)
	$(call message,DELETED,$(BUILD_DIR),$(RED))

fclean: clean ## Remove all generated files
	for lib in $(dir $(LIBS)); do $(MAKE) -C $$lib fclean; done
	$(RM) $(NAME)
	$(call message,DELETED,$(NAME),$(RED))

re: ## Rebuild the program
	$(MAKE) fclean
	$(MAKE) all

re.%: ## Force execution of a target recipe (usage: make re.<target>)
	$(MAKE) --always-make $*

run: $(NAME) ## Run the program
	$(call message,RUNNING,./$(NAME),$(CYAN))
	./$(NAME)

run.%: $(NAME) ## Run the program with arguments (usage: make run.<args>)
	$(call message,RUNNING,./$(NAME) $*,$(CYAN))
	./$(NAME) maps/$*

valgrind: $(NAME) ## Run valgrind on the program
	$(call message,RUNNING,valgrind ./$(NAME),$(CYAN))
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME)

valgrind.%: $(NAME) ## Run valgrind on the program passing arguments (usage: make run.valgrind.<args>)
	$(call message,RUNNING,valgrind ./$(NAME) $*,$(CYAN))
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME) maps/$*

update: ## Update the repository and its submodules
	git stash
	git pull
	git submodule update --init
	git stash pop

info.%: ## Print the target recipe (usage: make info.<target>)
	$(MAKE) --dry-run --always-make $* | grep -v "info"

print.%: ## Print the value of a variable (usage: make print.<variable>)
	$(info '$*'='$($*)')

help: ## Show this message
	echo "$(BOLD)Usage: make [<name>=<value>...]$(RESET) $(BOLD)$(CYAN)[target...]$(RESET)"
	echo
	echo "$(BOLD)Targets:$(RESET)"
	grep -E '^[a-zA-Z_.%-]+:.*?## .*$$' Makefile \
	| awk 'BEGIN {FS = ":.*?## "}; {printf "%2s$(CYAN)%-20s$(RESET) %s\n", "", $$1, $$2}'

.PHONY: all bonus debug sanitizer loose clean fclean re run valgrind update help
.SILENT:
.IGNORE: clean fclean run update help
.DELETE_ON_ERROR:

-include $(DEPS)
