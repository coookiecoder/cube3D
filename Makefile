files = main

sources = $(foreach buffer, $(files), src/$(buffer).c)
objects = $(foreach buffer, $(files), obj/$(buffer).o)

CFLAGS = -Wall -Wextra -Werror -I.
CC = gcc

MLX42 = MLX42/build/libmlx42.a

NAME = cube3D

all: $(NAME)

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(objects) $(MLX42)
	$(CC) $(CFLAGS) $(objects) $(MLX42)-o $(NAME)

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
