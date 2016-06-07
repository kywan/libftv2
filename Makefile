EXTRA_FLAGS=
FLAGS=-Wall -Werror -Wextra -Ofast
COMPILER=gcc
GCC=$(COMPILER) $(FLAGS) -I./includes $(EXTRA_FLAGS)
RANLIB=ranlib
AR=ar
LIBSO=libftprintf.so
NAME=libftprintf.a
LIST=ft_lstnew.o \
	 ft_lstdelone.o \
	 ft_lstdel.o \
	 ft_lstadd.o \
	 ft_lstiter.o \
	 ft_lst_push_back.o \
	 ft_lstmap.o \
	 ft_lstlast.o
MEMORY=ft_memset.o \
	   ft_memcpy.o \
	   ft_memccpy.o \
	   ft_memmove.o \
	   ft_memchr.o \
	   ft_memcmp.o \
	   ft_bzero.o \
	   ft_memalloc.o \
	   ft_memdel.o
OBJ=ft_putchar.o ft_putchar_fd.o \
	ft_putstr.o ft_putstr_fd.o ft_putnstr.o \
	ft_putendl.o ft_putendl_fd.o \
	ft_swap.o \
	ft_strrev.o \
	ft_strcmp.o ft_strncmp.o \
	ft_strcat.o ft_strncat.o ft_strlcat.o \
	ft_strlen.o ft_nbrlen.o \
	ft_strchr.o ft_strrchr.o \
	ft_strstr.o ft_strnstr.o \
	ft_strsplit.o \
	ft_strcpy.o ft_strncpy.o \
	ft_strclr.o \
	ft_strmap.o ft_strmapi.o \
	ft_strequ.o ft_strnequ.o \
	ft_strsub.o ft_strsub_len.o \
	ft_strtrim.o \
	ft_strcleanc.o \
	ft_strnew.o ft_strdel.o ft_striter.o ft_striteri.o \
	ft_strjoin.o \
	ft_itoa.o ft_ftoa.o\
	ft_atoi.o \
	ft_putnbr.o ft_putnbr_fd.o \
	ft_swap_ptr.o \
	ft_strdup.o \
	ft_isalpha.o \
	ft_isdigit.o \
	ft_isalnum.o \
	ft_isascii.o \
	ft_isprint.o \
	ft_isspace.o \
	ft_tolower.o \
	ft_toupper.o
GNL=get_next_line.o
MATH=ft_pow.o
PRINTF=ft_printf.o \
	   ft_createelem.o \
	   ft_display.o \
	   ft_error.o \
	   ft_modif.o \
	   ft_width.o \
	   ft_flag.o \
	   ft_type.o \
	   ft_prec.o \
	   ft_int.o ft_uint.o \
	   ft_long.o \
	   ft_longlong.o \
	   ft_sizet.o \
	   ft_string.o
################################################################################
##                                                                            ##
##                   COMPILATION RULES : DONT TOUCH: IT'S MAGIC               ##
##                                                                            ##
################################################################################
LIB_CONTENT=$(OBJ) $(MEMORY) $(LIST) $(GNL) $(PRINTF) $(MATH)

all: $(NAME)

$(NAME): $(LIB_CONTENT)
	$(AR) rc $(NAME) $(LIB_CONTENT)
	$(RANLIB) $(NAME)

#linker for libft.so
$(LIBSO): $(LIB_CONTENT)
	$(GCC) -shared $(LIB_CONTENT) -o $(LIBSO)
so:
	make FLAGS="$(FLAGS)" $(LIBSO)

#cleaners
mrproper: fclean
	find . -name ".*.swp" -print -delete
clean:
	rm -f $(LIB_CONTENT)
fclean: clean
	rm -f $(NAME) $(LIBSO)
re: fclean all

.PHONY: all
################################################################################
##                                                                            ##
##                               IMPLICIT RULES                               ##
##                                                                            ##
################################################################################
%.o: %.c
	$(GCC) -c $<
