files = dir pos vector int float

sources = $(foreach buffer, $(files), src/$(buffer).c)
objects = $(foreach buffer, $(files), obj/$(buffer).o)

CFLAGS = -Wall -Wextra -Werror -I.
CC = gcc

NAME = units.a

all: $(NAME)

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(objects)
	$(AR) -rcs $(NAME) $(objects)

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all