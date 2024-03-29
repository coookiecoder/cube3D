files = main check_extension load texture floor celling map set_angle validate flood put_useful_thing_in_there purge error strlen strdup strjoin memset atoi\
		get_next_line/get_next_line get_next_line/get_next_line_utils

sources = $(foreach buffer, $(files), src/$(buffer).c)
objects = $(foreach buffer, $(files), obj/$(buffer).o)

CFLAGS = -Wall -Wextra -Werror -g3
CC = cc

MLX42 = MLX42/build/libmlx42.a

NAME = cube3D

all: $(NAME)

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(objects) $(MLX42)
	$(CC) $(CFLAGS) $(objects) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

$(MLX42):
	cd MLX42 && cmake -B build && make -C build

$(MLX42)re:
	cd MLX42 && rm -rf build && cmake -B build && make -C build

$(MLX42)clean:
	rm -rf MLX42/build

clean: $(MLX42)clean
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean $(MLX42)re all
