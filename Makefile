
SRCS        :=				libft/ft_atoi.c \
                          libft/ft_bzero.c \
                          libft/ft_calloc.c \
                          libft/ft_isalnum.c \
                          libft/ft_isalpha.c \
                          libft/ft_isascii.c \
                          libft/ft_isdigit.c \
                          libft/ft_isprint.c \
                          libft/ft_iswhite.c \
                          libft/ft_itoa.c \
                          libft/ft_lstadd_back.c \
                          libft/ft_lstadd_front.c \
                          libft/ft_lstclear.c \
                          libft/ft_lstdelone.c \
                          libft/ft_lstiter.c \
                          libft/ft_lstlast.c \
                          libft/ft_lstnew.c \
                          libft/ft_lstsize.c \
                          libft/ft_memchr.c \
                          libft/ft_memcmp.c \
                          libft/ft_memcpy.c \
                          libft/ft_memmove.c \
                          libft/ft_memset.c \
                          libft/ft_putchar_fd.c \
                          libft/ft_putendl_fd.c \
                          libft/ft_putnbr_fd.c \
                          libft/ft_putstr_fd.c \
                          libft/ft_split.c \
                          libft/ft_split2.c \
                          libft/ft_strchr.c \
                          libft/ft_strcmp.c \
                          libft/ft_strcpy.c \
                          libft/ft_strdup.c \
                          libft/ft_striteri.c \
                          libft/ft_strjoin.c \
                          libft/ft_strlcat.c \
                          libft/ft_strlcpy.c \
                          libft/ft_strlen.c \
                          libft/ft_strmapi.c \
                          libft/ft_strncmp.c \
                          libft/ft_strnstr.c \
                          libft/ft_strrchr.c \
                          libft/ft_substr.c \
                          libft/ft_tolower.c \
                          libft/ft_toupper.c \
                          src/errors/syntax_error.c \
                          src/exit_and_free.c \
                          src/exit_and_free2.c \
                          src/expand/expand.c \
                          src/expand/get_env.c \
                          src/expand/utils.c \
                          src/expand/utils2.c \
                          src/ft_builtins/cd_helpers.c \
                          src/ft_builtins/cd.c \
                          src/ft_builtins/export.c \
                          src/ft_builtins/export_utils.c \
                          src/ft_builtins/exportv2.c \
                          src/ft_builtins/export_helpers.c \
                          src/ft_builtins/ft_unset.c \
                          src/ft_builtins/ft_unset_helpers.c \
                          src/ft_builtins/get_envp.c \
                          src/ft_builtins/linked_list.c \
                          src/ft_builtins/ft_echo.c \
                          src/ft_builtins/ft_pwd.c \
                          src/ft_builtins/ft_env.c \
                          src/ft_builtins/ft_exit.c \
                          src/ft_malloc/ft_malloc.c \
                          src/lexer/check_Syn/check_Syntax.c \
                          src/lexer/check_Syn/check_pipe.c \
                          src/lexer/check_Syn/check_redirect.c \
                          src/lexer/lexer.c \
                          src/parser/appands/parse_append.c \
                          src/parser/args/parse_cmd_args.c \
                          src/parser/heredocs/parse_heredoc.c \
                          src/parser/infiles/parse_infiles.c \
                          src/parser/outfiles/parse_outfiles.c \
                          src/parser/parser.c \
                          src/parser/parser_utils.c \
                          src/parser/parser_ultis2.c \
                          src/parser/utils.c \
                          src/parser/utilss.c \
                          src/parser/utils_parser.c \
                          src/quote/initial_check.c \
                          src/quote/utils.c \
                          src/utils2.c \
                          src/execution/execution.c \
                          src/execution/exeuction2.c \
                          src/execution/execution3.c \
                          src/execution/exeuction4.c \
                          src/execution/execution5.c \
                          src/execution/execution6.c \
                          src/init.c \
                          src/init2.c \
                          src/Minishell.c \

NAME        := minishell
CC        := cc
FLAGS    := -Wall -Wextra -Werror -g3 -fsanitize=address#-lreadline 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

OBJS        := $(SRCS:.c=.o)

# .c.o:
# 	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -lreadline
CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS} -lreadline
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o */*/*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################


                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}
