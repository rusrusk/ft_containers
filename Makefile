NAME	=	ft_containers

CC		=	c++

CFLAGS	=	-Wall -Werror -Wextra --std=c++98

RM		=	rm -rf

SRCS	=	main.cpp\
			

OBJS	=	$(SRCS:cpp=o) #take the var value $(SRCS), which is a string composed of words separated by spaces, and for each word, replace suffix .c with .o

DFLAGS	=	-g -D M_DEBUG=1

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp
	@$(CC) $(CFLAGS) -c $^ -o $@

debug :
	$(CC) $(CFLAGS) $(DFLAGS) $(SRCS) -o $(NAME)

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all fclean re