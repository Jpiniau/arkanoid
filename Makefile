NAME = test

FLAGS = -Wall -Werror -Wextra

GFLW = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo -framework Carbon

SRC =	main.c\
		init.c\
		draw.c\
		content.c\
		key_hook.c\
		ship.c

OBJ = $(SRC:.c=.o)

all: lib $(NAME)

lib:
	@make -C libft/
	@make -C glfw/

$(NAME) : $(OBJ)
	gcc $(FLAGS) -o $(NAME) $^ $(GFLW) -L glfw/src -L libft/ -lft

%.o : %.c
	gcc $(FLAGS) -o $@ -c $< -I glfw/include -I libft/includes -I arkanoid.h

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all
