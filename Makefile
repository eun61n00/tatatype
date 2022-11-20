NAME = tatatype

CC = gcc
CFLAG = -Wall -Wextra -Werror

AR = ar
ARFLAG = -crs

RM = rm
RMFLAG = -rf

INCLUDES_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

# color
NO_COLOR = \e[0m
LIGHT_GREEN = \e[1;32;189;147;249m
GREEN = \e[0;32;189;147;249m
LIGHT_GRAY = \e[1;32;255;121;198
LF = \e[1K\r$(NO_COLOR)
CRLF = \n$(LF)

SRCS  = $(wildcard $(SRCS_DIR)/*.c)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	# $(MAKE) -C ./lib/ft_printf all
	@printf "$(LF)$(LIGHT_GREEN)Successfully Created $(GREEN)$(NAME)'s Object files!"
	@printf "$(CRLF)$(LIGHT_GREEN)Archiving! $(GREEN)$@${CRLF}"
	$(CC) $(CFLAG) $(OBJS) -I $(INCLUDES_DIR) -o $(NAME)
	@printf "$(LF)$(LIGHT_GREEN)Successfully Archived $(GREEN)$@$(LIGHT_GREEN)!${CRLF}"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAG) -c $^ -o $@ -I $(INCLUDES_DIR)
	@printf "$(LF)$(LIGHT_GREEN)Create $(GREEN)$@ $(LIGHT_GREEN)from $(GREEN)$<${CRLF}"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean :
	# @$(MAKE) -C ./lib/ft_printf clean
	@${RM} $(RMFLAG) $(OBJS) $(OBJS_DIR)
	@printf "$(LF)$(LIGHT_GREEN)Cleaning $(GREEN)$(NAME)'s Object files...${CRLF}"

fclean : clean
	@${RM} $(RMFLAG) $(NAME)
	@printf "$(LF)$(LIGHT_GREEN)Cleaning $(GREEN)$(NAME)${CRLF}"

re : fclean all

.PHONY : all clean fclean re