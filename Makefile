NAME = fillit

SRC = main.c                    \
      valid.c                   \
      map.c                     \
      decision.c                \
      read.c                     

OBJ = $(SRS:.c=.o)

INC = fillit.h

LIBFT = libft/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ): %.o: %.c
	gcc -c $(FLAGS) -I $(INC) -o $@ -c $<

$(NAME): 
	make -C $(LIBFT)	
	gcc $(FLAGS) -o $(NAME) $(SRC) -I $(INC) -L. $(LIBFT)libft.a

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

