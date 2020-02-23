NAME = libft.a

INCLUDE_DIR = ./includes
FLAGS = -Wall -Wextra -Werror
CFLAGS = -I $(INCLUDE_DIR)
DEBUG_FLAGS =

SRCS =		./chars/ft_chtostr.c\
			./chars/ft_isalnum.c\
			./chars/ft_isalpha.c\
			./chars/ft_isascii.c\
			./chars/ft_isdigit.c\
			./chars/ft_isprint.c\
			./chars/ft_putchar.c\
			./chars/ft_putchar_fd.c\
			./chars/ft_tolower.c\
			./chars/ft_toupper.c\
			./double/ft_ldtoa.c\
			./double/ft_ldtoa_utils.c\
			./ft_printf/buff_utils.c\
			./ft_printf/ft_printf.c\
			./ft_printf/function_call_manager.c\
			./ft_printf/padding_utils.c\
			./ft_printf/parse_recognitions.c\
			./ft_printf/parse_utils.c\
			./ft_printf/pf_print_utils.c\
			./ft_printf/pf_read.c\
			./ft_printf/print_cs.c\
			./ft_printf/print_di.c\
			./ft_printf/print_f.c\
			./ft_printf/print_lcls.c\
			./ft_printf/print_oux.c\
			./ft_printf/print_p.c\
			./ft_printf/utils.c\
			./ft_printf/utils2.c\
			./lst/ft_lstadd.c\
			./lst/ft_lstdel.c\
			./lst/ft_lstdelone.c\
			./lst/ft_lstiter.c\
			./lst/ft_lstmap.c\
			./lst/ft_lstnew.c\
			./math/ft_abs.c\
			./math/ft_isinf.c\
			./math/ft_isnan.c\
			./math/ft_llabs.c\
			./math/ft_pow.c\
			./mem/ft_bzero.c\
			./mem/ft_memalloc.c\
			./mem/ft_memccpy.c\
			./mem/ft_memchr.c\
			./mem/ft_memcmp.c\
			./mem/ft_memcpy.c\
			./mem/ft_memdel.c\
			./mem/ft_memmove.c\
			./mem/ft_memset.c\
			./numbers/ft_atoi.c\
			./numbers/ft_atoi_base.c\
			./numbers/ft_itoa.c\
			./numbers/ft_lllen.c\
			./numbers/ft_lltoa.c\
			./numbers/ft_putnbr.c\
			./numbers/ft_putnbr_fd.c\
			./numbers/ft_ulllen.c\
			./numbers/ft_ulltoa.c\
			./str/ft_putendl.c\
			./str/ft_putendl_fd.c\
			./str/ft_putstr.c\
			./str/ft_putstr_fd.c\
			./str/ft_strcat.c\
			./str/ft_strchr.c\
			./str/ft_strclr.c\
			./str/ft_strcmp.c\
			./str/ft_strcpy.c\
			./str/ft_strdel.c\
			./str/ft_strdup.c\
			./str/ft_strequ.c\
			./str/ft_striter.c\
			./str/ft_striteri.c\
			./str/ft_strjoin.c\
			./str/ft_strlcat.c\
			./str/ft_strlen.c\
			./str/ft_strmap.c\
			./str/ft_strmapi.c\
			./str/ft_strncat.c\
			./str/ft_strncmp.c\
			./str/ft_strncpy.c\
			./str/ft_strnequ.c\
			./str/ft_strnew.c\
			./str/ft_strnstr.c\
			./str/ft_strrchr.c\
			./str/ft_strsplit.c\
			./str/ft_strstr.c\
			./str/ft_strsub.c\
			./str/ft_strtrim.c\
			./str/ft_isnumeric.c\
			./str/ft_isnumber.c\
			./widechars/ft_putwchar.c\
			./widechars/ft_putwchar_fd.c\
			./widechars/ft_putwnchar.c\
			./widechars/ft_putwnchar_fd.c\
			./widechars/ft_putwstr.c\
			./widechars/ft_putwstr_fd.c\
			./widechars/ft_wclen.c\
			./widechars/ft_wcsncpy.c\
			./widechars/ft_wstrdup.c\
			./widechars/ft_wstrlen.c\
			./get_next_line/get_next_line.c\

OBJS = $(patsubst %.c,%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)


%.o: %.c
	gcc $(FLAGS) $(DEBUG_FLAGS) $(CFLAGS) -o $@ -c $< 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	gcc -g -o main main.c -L. -lftprintf
	echo "\n\n\n"
	./main
