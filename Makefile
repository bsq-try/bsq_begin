CC = gcc
CFLAGS =  -Werror -Wall -Wextra
NAME = BSQ
INCL = ./includes
SRCS = $(addprefix ./srcs/, j_first_line.c jc_make.c j_free.c s_function.c y_convert.c j_main.c s_reader.c y_sol.c)
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
