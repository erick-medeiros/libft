NAME 			= libft.a

INC_PATH	= ./
SRC_PATH	= src/
OBJ_PATH	= obj/
OBJ_DIRS	= obj/ obj/ft_printf/

FILES			= ft_is.c
FILES			+= ft_is2.c
FILES			+= ft_to.c
FILES			+= ft_mem.c
FILES			+= ft_strchr.c
FILES			+= ft_strcmp.c
FILES			+= ft_strdup.c
FILES			+= ft_atoi.c
FILES			+= ft_itoa.c
FILES			+= ft_split.c
FILES			+= ft_split_cmd.c
FILES			+= get_next_line.c
FILES			+= ft_free.c
FILES			+= ft_math.c

FILES			+= ft_printf/ft_printf.c
FILES			+= ft_printf/ft_placeholder.c
FILES			+= ft_printf/ft_specifiers.c
FILES			+= ft_printf/ft_subspecs.c
FILES			+= ft_printf/ft_utils.c

SRC				= $(addprefix $(SRC_PATH), $(FILES))
OBJ				= $(addprefix $(OBJ_PATH), $(FILES:.c=.o))

CFLAGS 		= -Wall -Wextra -Werror
CFLAGS		+= -g -I $(INC_PATH)
CC 				= cc
LIB 			= ar -rcs
RM				= rm -fr

C_W				= \e[00m
C_G				= \e[32m
C_R				= \e[91m

all: $(NAME)

$(OBJ_DIRS):
	@echo "$(C_G)Create dir$(C_W) $@"
	mkdir -p $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo -n "$(C_G)obj: $(C_W)"
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIRS) $(OBJ)
	@echo "$(C_G)Compiling $(C_W)$(NAME:.a=)"
	$(LIB) $(NAME) $(OBJ)
	@echo "$(C_G)Compiled $(C_W)~ $(NAME)"

clean:
	@echo "$(C_R)Removing $(C_W)all objects"
	${RM} $(OBJ)

fclean: clean
	@echo "$(C_R)Removing $(C_W)$(NAME)"
	${RM} $(NAME)

re: fclean all

norm:
	@clear
	@norminette | grep Error || true

.PHONY: all clean fclean re norm