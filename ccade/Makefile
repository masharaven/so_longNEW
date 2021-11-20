SRCS 		= 	libft.c maps.c get_next_line.c get_next_line_utils.c extra_f.c valid_map.c \
				error_write.c workwmlx/esc.c workwmlx/keyb_move.c workwmlx/put_image.c \
				pers/move_pers.c extra_f1.c main.c libft1.c
NAME		= 	so_long
INCS		=   -I
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g 
MINLBX		=  -lmlx -framework OpenGL -framework AppKit
OBJS		= $(SRCS:.c=.o)

all:			${NAME}

${NAME}:	$(OBJS) so_long.h
			${CC} ${CFLAGS} ${INCS} /usr/local/lib/ ${MINLBX} ${OBJS}  -o ${NAME}

clean:
				$(RM) $(OBJS)

fclean:			clean
				${RM} ${NAME}

re:				fclean all
.PHONY:
				all, fclean, clean, re