CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c 
OBJ = $(SRC:.c=.o)
BONUSOBJ = ft_lstadd_back.o \
ft_lstadd_front.o \
ft_lstclear.o \
ft_lstdelone.o \
ft_lstiter.o \
ft_lstlast.o \
ft_lstmap.o \
ft_lstnew.o \
ft_lstsize.o
HEADER = libft.h
RM = rm -f
AR = ar
all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) cr $@ $^

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

bonus : $(BONUSOBJ) 
	$(AR) cr $(NAME) $(BONUSOBJ)

clean :
	$(RM) $(OBJ) $(BONUSOBJ)

fclean : clean
	$(RM) libft.a

re : fclean all

.PHONY : clean fclean bonus re all 

