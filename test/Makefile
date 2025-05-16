NAME = objParserTest

SOURCES = test.c

OBJS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I../include -I../libft/includes

OBJPARSERLIB = ../lib/libobjParser.a

LDFLAGS = ../lib/libobjParser.a ../libft/lib/libft.a

$(NAME): $(OBJPARSERLIB) $(OBJS)
	@ echo " \033[33mCompiling ObjParser test\033[m"
	@ $(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)
	@ echo " \033[1;32m ObjParser test compiled\033[m"

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(OBJPARSERLIB):
	@ cd .. && $(MAKE) -s -j

all: $(NAME)

clean:
	@ echo " \033[33mCleaning\033[m"
	@ rm -f $(OBJS)
	@ echo " \033[32m ObjParser test object files cleaned\033[m"

fclean: clean
	@ rm -f $(NAME)
	@ echo " \033[32m ObjParser test cleaned\033[m"

re: fclean all

.PHONY: clean fclean re all
