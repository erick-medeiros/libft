NAME		= run_test.out
CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=3 -g
RM			= rm -fr
PATH_ROOT	= ../../
INC_FLAG	= -I $(PATH_ROOT)include/ -I ./
SRC_DIR		= $(PATH_ROOT)src/
SRC			= $(SRC_DIR)get_next_line.c
OBJ			= $(SRC:.c=.o)

#TESTS

T_SRC	= utils.c main.c
T_OBJ	= $(T_SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_FLAG) -c $< -o $@

all: $(T_OBJ)
	@make -C $(PATH_ROOT)
	$(CC) $(CFLAGS) -o $(NAME) $(T_OBJ) $(PATH_ROOT)src/*.o

clean:
	@$(RM) $(OBJ) $(OBJ_B) $(T_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

m: $(T_OBJ) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(T_MAN) $(OBJ)
	make clean

.PHONY: all clean fclean re m b