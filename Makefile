AUTEUR				= akarasso
NAME				= libft.a
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror
MAKE				= make
INC_PATH			= includes/
INC					= $(addprefix -I, $(INC_PATH))
OBJ_PATH			= objs/
SRC_PATH			= src/
BUILD_PATH			= \
	$(SRC_ARR_PATH) \
	$(SRC_CHAR_PATH) \
	$(SRC_DLST_PATH) \
	$(SRC_INTEGER_PATH) \
	$(SRC_IO_PATH) \
	$(SRC_MEM_PATH) \
	$(SRC_READ_PATH) \
	$(SRC_STR_PATH)

SRCS				= \
	$(addprefix $(SRC_ARR_PATH),$(SRC_ARR)) \
	$(addprefix $(SRC_CHAR_PATH),$(SRC_CHAR)) \
	$(addprefix $(SRC_DLST_PATH),$(SRC_DLST)) \
	$(addprefix $(SRC_INTEGER_PATH),$(SRC_INTEGER)) \
	$(addprefix $(SRC_IO_PATH),$(SRC_IO)) \
	$(addprefix $(SRC_MEM_PATH),$(SRC_MEM)) \
	$(addprefix $(SRC_READ_PATH),$(SRC_READ)) \
	$(addprefix $(SRC_STR_PATH),$(SRC_STR))

SRC_ARR_PATH = arr/
SRC_ARR = \
	ft_arr_clear.c \
	ft_arr_del_elem.c \
	ft_arr_del.c \
	ft_arr_foreach.c \
	ft_arr_join.c \
	ft_arr_new.c \
	ft_arr_pushback.c \
	ft_arr_realloc.c

SRC_CHAR_PATH = char/
SRC_CHAR = \
	ft_is_math_op.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c

SRC_DLST_PATH = dlst/
SRC_DLST = \
	ft_dlst_clear.c \
	ft_dlst_del_elem.c \
	ft_dlst_del.c \
	ft_dlst_foreach.c \
	ft_dlst_len.c \
	ft_dlst_new.c \
	ft_dlst_push.c \
	ft_dlst_pushback.c
	# ft_dlst_split.c No implemented

SRC_INTEGER_PATH = integer/
SRC_INTEGER = \
	ft_atoi.c \
	ft_itoa.c \
	ft_nbr_len.c

SRC_IO_PATH = io/
SRC_IO = \
	ft_putchar_fd.c \
	ft_putchar.c \
	ft_putendl_fd.c \
	ft_putendl.c \
	ft_putnbr_fd.c \
	ft_putnbr.c \
	ft_putstr_fd.c \
	ft_putstr.c \
	ft_tolower.c \
	ft_toupper.c

SRC_MEM_PATH = mem/
SRC_MEM = \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c

SRC_READ_PATH = read/
SRC_READ = \
	gnl.c

SRC_STR_PATH = str/
SRC_STR = \
	ft_3strjoin.c  ft_strdup.c      ft_strmapi.c  ft_str_onlychr.c \
	ft_stralpha.c  ft_strequ.c      ft_strncat.c  ft_strrchr.c \
	ft_strcat.c    ft_striter.c     ft_strnchr.c  ft_strrev.c \
	ft_strchr.c    ft_striteri.c    ft_strncmp.c  ft_strrmvchr.c \
	ft_strclr.c    ft_strjoin.c     ft_strncpy.c  ft_strsplit.c \
	ft_strcmp.c    ft_strlastchr.c  ft_strndup.c  ft_strstr.c \
	ft_strcpy.c    ft_strlcat.c     ft_strnequ.c  ft_strsub.c \
	ft_strdel.c    ft_strlen.c      ft_strnew.c   ft_strtrim.c \
	ft_strdigit.c  ft_strmap.c      ft_strnstr.c

OBJ = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

all : $(NAME) $(author)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_PATH)%.o	: $(SRC_PATH)%.c
	mkdir -p $(addprefix $(OBJ_PATH), $(BUILD_PATH))
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

author:
	echo $(author) > auteur

clean :
	rm -rf $(OBJ_PATH)

fclean : clean
	rm -f $(NAME)

re : fclean all
