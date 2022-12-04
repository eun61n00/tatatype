NAME = tatatype
PLAYER = player

CC = gcc
CFLAG = -g -lcurses

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

SRCS = $(SRCS_DIR)/main.c $(SRCS_DIR)/make_game_board.c $(SRCS_DIR)/word_node_list.c
OBJS = $(OBJS_DIR)/main.o $(OBJS_DIR)/make_game_board.o $(OBJS_DIR)/word_node_list.o

PlAYER_SRCS = $(SRCS_DIR)/player.c
PlAYER_OBJS = $(OBJS_DIR)/player.o

all : $(NAME) $(PLAYER)

$(NAME) : $(OBJS)
	@printf "$(LF)$(LIGHT_GREEN)Successfully Created $(GREEN)$(NAME)'s Object files!"
	@printf "$(CRLF)$(LIGHT_GREEN)Archiving! $(GREEN)$@${CRLF}"
	$(CC) $(CFLAG) $(OBJS) -I $(INCLUDES_DIR) -o $(NAME)
	@printf "$(LF)$(LIGHT_GREEN)Successfully Archived $(GREEN)$@$(LIGHT_GREEN)!${CRLF}"

$(PLAYER) :
	$(CC) $(PlAYER_SRCS) -o $(PLAYER)
	@printf "$(LF)$(LIGHT_GREEN)Successfully Archived $(GREEN)$@$(LIGHT_GREEN)!${CRLF}"

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAG) -c $^ -o $@ -I $(INCLUDES_DIR)
	@printf "$(LF)$(LIGHT_GREEN)Create $(GREEN)$@ $(LIGHT_GREEN)from $(GREEN)$<${CRLF}"

clean :
	@${RM} $(RMFLAG) $(OBJS) $(OBJS_DIR)
	@printf "$(LF)$(LIGHT_GREEN)Cleaning $(GREEN)$(NAME)'s Object files...${CRLF}"

fclean : clean
	@${RM} $(RMFLAG) $(NAME) $(PLAYER)
	@printf "$(LF)$(LIGHT_GREEN)Cleaning $(GREEN)$(NAME)${CRLF}"

re : fclean all

.PHONY : all clean fclean re