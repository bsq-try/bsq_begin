CC = gcc
CFLAGS =  -Werror -Wall -Wextra
NAME = bsq
SRCS = $(addprefix ./srcs/ ,)
OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
