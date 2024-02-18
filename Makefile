NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror

LIBFT = Libft/libft.a

PRINTF = Ft_Printf/printf.a

SRCS =	main.c \
		basic_ft.c \
		ft_mov_push.c \
		ft_mov_rotate.c \
		ft_mov_reverse_rotate.c \
		ft_mov_swap.c \
		ft_parsing.c \
		ft_utils.c \
		ft_free.c \
		ft_algo.c \
		ft_mediane.c \
		ft_find_min_max.c \
		ft_specific_mov.c \
		ft_algo_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "it's compiled"

%.o : %.c
	@$(CC) $(FLAGS) -ILibft/libft.a -IFt_Printf/printf.a -o $@ -c $<  

$(LIBFT) :
	@make -s -C Libft

$(PRINTF) :
	@make -s -C Ft_Printf

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)
	@make -s -C ./Libft fclean
	@make -s -C ./Ft_Printf fclean
	@echo "it's clean"

re : fclean all

.PHONY : all library clean fclean re
