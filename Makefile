CC = gcc
CFLAGS =  -Werror -Wall -Wextra
NAME = BSQ
INCL = ./includes
SRCS = $(addprefix ./srcs/, first_line.c make.c free.c function.c convert.c main.c reader.c sol.c)
OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCL)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
