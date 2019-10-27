SRCS		= arg_printer.c pf_putchar.c libftprintf.c pf_putchar.c pf_puthex1.c \
				pf_puthex2.c pf_puthex3.c pf_putnbr.c pf_putstr.c pf_putunsignedint.c \
				pf_atoi.c pf_putflags.c

SRCS_BONUS	=

OBJ_DIR		= objs
SRC_DIR		= srcs
INC_DIR		= .

OBJS		:= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
OBJS_BONUS	:= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS_BONUS))

NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra

$(NAME):		$(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

all:			$(NAME)

clean:
	$(RM) -r $(OBJ_DIR)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

bonus:			$(OBJS) $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS) $(OBJS_BONUS)
