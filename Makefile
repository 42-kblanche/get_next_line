NAME = gnl.test
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
BUFF_SIZE = -D BUFFER_SIZE=100
NEUTRAL = \033[0;0m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m

SRCS = get_next_line.c\
	   gnl.c\
	   get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "${YELLOW}Building tests ${BLUE}$@\n${NEUTRAL}"

%.o: %.c
	@$(CC) $(CFLAGS) $(BUFF_SIZE) -o $@ -c $^
	@printf "Compiling ${BLUE}$^\n${NEUTRAL}"

fclean: clean
	@rm -f $(NAME)
	@printf "${RED}Deleting archives and binaries\n${NEUTRAL}"

clean:
	@rm -f $(OBJS)
	@printf "${RED}Deleting object files\n${NEUTRAL}"

.PHONY: all fclean clean re
