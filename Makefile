CC     = gcc
CFLAGS = -Wall -Werror -Wextra
NAME   = getnextline.a

SRC_F  = get_next_line.c get_next_line_utils.c
OBJ_F  = $(SRC_F:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ_F)
	ar r $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

test : $(NAME) main.c
	@$(CC) $(CFLAGS) main.c $(NAME) -o test && ./test

clean :
	rm -f test $(OBJ_F) $(NAME)
