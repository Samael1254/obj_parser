NAME = obj_parser

SOURCES_DIR = srcs/
BUILD_DIR = build/

SOURCES = main.c errors.c init.c check_argument.c parse_element.c \
		  utils.c parse_obj_file.c print_debug.c

SOURCES := $(addprefix $(SOURCES_DIR), $(SOURCES))

OBJS = $(addprefix $(BUILD_DIR), $(notdir $(SOURCES:.c=.o)))

CC = cc

CFLAGS = -Wall -Wextra -Werror -I. -Ilibft/includes

LIBFLAGS = -lft -Llibft/lib

$(NAME): $(OBJS)
	@ echo " \033[33mCompiling obj parser\033[m"
	@ $(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFLAGS)
	@ echo " \033[1;32m Obj parser binary compiled\033[m"

$(BUILD_DIR)%.o: $(SOURCES_DIR)%.c
	@ mkdir -p $(BUILD_DIR)
	@ $(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@ echo " \033[33mCleaning\033[m"
	@ rm -f $(OBJS)
	@ rm -df $(BUILD_DIR)
	@ echo " \033[32m Obj parser build files cleaned\033[m"

fclean: clean
	@ rm -f $(NAME)
	@ echo " \033[32m Obj parser binary cleaned\033[m"

re: fclean all

.PHONY: clean fclean re all
