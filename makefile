NAME = server
NAME2 = client
SER_DIR = ./srcs_ser
CLI_DIR = ./srcs_cli
SRC_SER = $(SER_DIR)/server.c $(SER_DIR)/byte.c $(SER_DIR)/support.c
OBJ_SER = $(SRC_SER:$(SER_DIR)/%.c=$(SER_DIR)/%.o)
SRC_CLI = $(CLI_DIR)/client.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
LINKS = -I./pirntf/includes -L./printf -lftprintf
RM = rm -fr

all: $(NAME) $(NAME2)

$(SER_DIR)/%.o : $(SER_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_SER)
	$(MAKE) -C printf/ 
	$(CC) $(CFLAGS) $(LINKS) -o $@  $^
	
$(NAME2): $(SRC_CLI)
	$(CC) $(CFLAGS) $(LINKS) -o $@  $^

clean:
	@cd printf/ && $(MAKE) clean
	$(RM) $(OBJ_SER) client.o

fclean: clean
	@cd printf/ && $(MAKE) fclean
	$(RM) $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re