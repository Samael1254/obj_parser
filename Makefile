NAME = lib/libobjParser.a

SOURCES_DIR = srcs/
BUILD_DIR = build/

SOURCES = errors.c init.c check_filename.c parse_element.c \
		  utils.c parse_obj_file.c print_mesh.c

SOURCES := $(addprefix $(SOURCES_DIR), $(SOURCES))

OBJS = $(addprefix $(BUILD_DIR), $(notdir $(SOURCES:.c=.o)))

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./srcs -I./include -I./libft/includes

LIBFT = libft/lib/libft.a

LIBFLAGS = -lft -Llibft/lib

$(NAME): $(OBJS) $(LIBFT)
	@ echo " \033[33mCompiling ObjParser library\033[m"
	@ mkdir -p lib
	@ ar crs $@ $(OBJS)
	@ echo " \033[1;34m ObjParser library compiled\033[m"

$(BUILD_DIR)%.o: $(SOURCES_DIR)%.c
	@ mkdir -p $(BUILD_DIR)
	@ $(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@ cd libft && make -s -j

all: $(NAME)

clean:
	@ echo " \033[33mCleaning\033[m"
	@ rm -f $(OBJS)
	@ rm -df $(BUILD_DIR)
	@ echo " \033[34m ObjParser build files cleaned\033[m"

fclean: clean
	@ rm -f $(NAME)
	@ rm -df lib
	@ echo " \033[34m ObjParser library cleaned\033[m"

re: fclean all

.PHONY: clean fclean re all
