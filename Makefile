SRCS	=   Mandatory/main.c Mandatory/fonction_stack.c Mandatory/ft_putstr_fd.c Mandatory/ft_strlen.c \
			Mandatory/sort_stack.c Mandatory/ft_atolong.c Mandatory/ft_split.c Mandatory/ft_memcpy.c \
			Mandatory/fonction_stack2.c Mandatory/sort_stack2.c Mandatory/sort_stack3.c Mandatory/sort_stack4.c \
			Mandatory/cheak_arg_is_valide.c


SRCS_Bonus	=	Bonus/main_bonus.c Bonus/fonction_stack_bonus.c Bonus/fonction_stack2_bonus.c Bonus/push_arg_bonus.c \
				Bonus/ft_putstr_fd.c Bonus/ft_split.c Bonus/ft_strlen.c Bonus/ft_memcpy.c Bonus/ft_atolong.c \
				Bonus/sort_management_bonus.c Bonus/ft_strncmp.c \
				Bonus/get_next_line.c Bonus/get_next_line_utils.c


OBJS_Bonus	= $(SRCS_Bonus:.c=.o)
OBJS		= $(SRCS:.c=.o)
NAME		= push_swap
NAME_BONUS	= checker
FLAGS		= -Wall -Wextra -Werror

all: ${NAME}


${NAME}: ${OBJS}
			cc ${FLAGS} ${OBJS} -o ${NAME}

Mandatory/%.o:Mandatory/%.c Mandatory/push_swap.h
		cc -c ${FLAGS} $< -o $@

Bonus/%.o:Bonus/%.c Bonus/checker_bonus.h
		cc -c ${FLAGS} $< -o $@

clean:
		rm -rf ${OBJS} ${OBJS_Bonus}
fclean:	clean
		rm -rf ${NAME} ${NAME_BONUS}
bonus:	${OBJS_Bonus}
		cc $(FLAGS) ${OBJS_Bonus} -o ${NAME_BONUS}
re : fclean all