NAME 	= libft.a
CFLAGS 	= -Wall -Wextra -Werror
CC 		= cc
LIB 	= ar -rcs
RM		= rm -fr
INC 	= libft.h
SRC 	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_strlen.c ft_memset.c ft_memcpy.c \
			ft_memmove.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_strdup.c ft_bzero.c ft_strlcpy.c \
			ft_strlcat.c ft_atoi.c ft_calloc.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ		= $(SRC:.c=.o)
COLOR_WHITE	= \e[00m
COLOR_GREEN	= \e[32m
COLOR_RED	= \e[91m

all: $(NAME)

%.o: %.c
	@echo "$(COLOR_GREEN)Compiling $(COLOR_WHITE)$(<:.c=)"
	@$(CC) $(CFLAGS) -c $< -o $@

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