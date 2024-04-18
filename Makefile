NAME = so_long
HEADER = so_long.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = get_next_line \
		get_next_line_utils \
		so_long_utils \
		map_checks \
		map_checks_1 \
		map_checks_2 \
		show_map \
		show_map_1 \
		moves \
		moves1 \
		so_long \

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) MLX/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/isel-azz/.brew/opt/glfw/lib/" $^ -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean norm