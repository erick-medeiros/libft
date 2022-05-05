NAME 		= libft.a
CFLAGS 		= -Wall -Wextra -Werror
CC 			= cc
LIB 		= ar -rcs
RM			= rm -fr
INC 		= ./include/libft.h
INC_FLAG	= -I ./include/

SRC_DIR		= ./src/

SRC 		= $(SRC_DIR)ft_grp_is.c
SRC 		+= $(SRC_DIR)ft_toupper.c
SRC 		+= $(SRC_DIR)ft_tolower.c
SRC 		+= $(SRC_DIR)ft_strlen.c
SRC 		+= $(SRC_DIR)ft_memset.c
SRC 		+= $(SRC_DIR)ft_memcpy.c
SRC 		+= $(SRC_DIR)ft_memmove.c
SRC 		+= $(SRC_DIR)ft_strchr.c
SRC 		+= $(SRC_DIR)ft_strrchr.c
SRC 		+= $(SRC_DIR)ft_strncmp.c
SRC 		+= $(SRC_DIR)ft_memchr.c
SRC 		+= $(SRC_DIR)ft_memcmp.c
SRC 		+= $(SRC_DIR)ft_strnstr.c
SRC 		+= $(SRC_DIR)ft_strdup.c
SRC 		+= $(SRC_DIR)ft_strlcpy.c
SRC 		+= $(SRC_DIR)ft_strlcat.c
SRC 		+= $(SRC_DIR)ft_atoi.c
SRC 		+= $(SRC_DIR)ft_calloc.c
SRC 		+= $(SRC_DIR)ft_substr.c
SRC 		+= $(SRC_DIR)ft_strjoin.c
SRC 		+= $(SRC_DIR)ft_strtrim.c
SRC 		+= $(SRC_DIR)ft_split.c
SRC 		+= $(SRC_DIR)ft_itoa.c
SRC 		+= $(SRC_DIR)ft_strmapi.c
SRC 		+= $(SRC_DIR)ft_striteri.c
SRC 		+= $(SRC_DIR)ft_putchar_fd.c
SRC 		+= $(SRC_DIR)ft_putstr_fd.c
SRC 		+= $(SRC_DIR)ft_putendl_fd.c
SRC 		+= $(SRC_DIR)ft_putnbr_fd.c
SRC 		+= $(SRC_DIR)ft_lstnew.c
SRC 		+= $(SRC_DIR)ft_lstadd_front.c
SRC 		+= $(SRC_DIR)ft_lstsize.c
SRC 		+= $(SRC_DIR)ft_lstlast.c
SRC 		+= $(SRC_DIR)ft_lstadd_back.c
SRC 		+= $(SRC_DIR)ft_lstdelone.c
SRC 		+= $(SRC_DIR)ft_lstclear.c
SRC 		+= $(SRC_DIR)ft_lstiter.c
SRC 		+= $(SRC_DIR)ft_lstmap.c

OBJ			= $(SRC:.c=.o)
COLOR_WHITE	= \e[00m
COLOR_GREEN	= \e[32m
COLOR_RED	= \e[91m

all: $(NAME)

%.o: %.c
	@echo "$(COLOR_GREEN)Compiling $(COLOR_WHITE)$(<:.c=)"
	@$(CC) $(INC_FLAG) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(INC)
	@echo "$(COLOR_GREEN)Compiling $(COLOR_WHITE)$(NAME:.a=)"
	@$(LIB) $(NAME) $(INC) $(OBJ)

clean:
	@echo "$(COLOR_RED)Removing $(COLOR_WHITE)all objects"
	@${RM} $(OBJ)

fclean: clean
	@echo "$(COLOR_RED)Removing $(COLOR_WHITE)$(NAME)"
	@${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re