NAME = obj_parser

SOURCES_DIR = srcs/
BUILD_DIR = build/

SOURCES = main.c errors.c init.c check_argument.c parse_element.c \
		  utils.c parse_obj_file.c print_debug.c

SOURCES := $(addprefix $(SOURCES_DIR), $(SOURCES))

OBJS = $(addprefix $(BUILD_DIR), $(notdir $(SOURCES:.c=.o)))

CC = cc

CFLAGS = -Wall -Wextra -Werror -I. -Ilibft/includes

LIBFT = libft/lib/libft.a

LIBFLAGS = -lft -Llibft/lib

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFLAGS)

$(BUILD_DIR)%.o: $(SOURCES_DIR)%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -j -C libft

all: $(NAME)

clean:
	rm -f $(OBJS)
	rmdir $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
