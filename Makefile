files = main

sources = $(foreach buffer, $(files), src/$(buffer).c)
objects = $(foreach buffer, $(files), obj/$(buffer).o)

CFLAGS = -Wall -Wextra -Werror -I.
CC = gcc

engine = engine/engine.a

MLX42 = MLX42/build/libmlx42.a

NAME = cube3D

all: $(NAME)

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

$(MLX42):
	cd MLX42 && cmake -B build && make -C build

$(MLX42)re:
	cd MLX42 && rm -rf build && cmake -B build && make -C build

$(MLX42)clean:
	rm -rf MLX42/build

$(engine):
	make -C engine

$(engine)re:
	make -C engine re

$(engine)clean:
	make -C engine clean

$(engine)fclean:
	make -C engine fclean

$(NAME): $(objects) $(MLX42) $(engine)
	$(CC) $(CFLAGS) $(objects) $(MLX42) $(engine) -o $(NAME)

clean: $(MLX42)clean $(engine)clean
	rm -rf obj

fclean: clean $(engine)fclean
	rm -rf $(NAME)

re: fclean $(MLX42)re $(engine)re all