CFLAGS = -Wall -Werror -Wextra 
NAME   = getnextline.a
SANITIZE = -g -fsanitize=address
SRC_F  = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ_F  = $(SRC_F:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ_F)
	ar r $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

test : $(NAME) main.c *.txt *.h
	@$(CC) $(CFLAGS) main.c $(NAME) -o test && ./test

clean :
	rm -f $(OBJ_F)

fclean : clean
	rm -f $(NAME)

re : clean fclean
	make test
