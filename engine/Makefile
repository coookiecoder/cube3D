units = units/units.a

NAME = engine.a

all: $(NAME)

$(units):
	make -C units

$(units)re:
	make -C units re

$(units)clean:
	make -C units clean

$(units)fclean:
	make -C units fclean

$(NAME): $(units)
	ar -rcT $(NAME) $(units)

clean: $(units)clean

fclean: $(units)fclean
	rm -rf $(NAME)

re: fclean $(units)re