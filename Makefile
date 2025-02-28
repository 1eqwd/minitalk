NAME = server
NAME2 = client
SRCS_DIR = srcs
OBJS_DIR = obj
SRC_CLI = $(SRCS_DIR)/client.c
SRC_SER = $(SRCS_DIR)/server.c
SEC_ERR = $(SRCS_DIR)/error_handle.c
OBJ_CLI = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRC_CLI))
OBJ_SER = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRC_SER))
OBJ_ERR = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SEC_ERR))
OBJ_CLI += $(OBJ_ERR)
OBJ_SER += $(OBJ_ERR)
CC = cc
INC = -I./includes
LINK = -L./printf -lftprintf
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME) $(NAME2)

$(NAME): $(OBJ_SER)
	@make -C printf/
	$(CC) $(CFLAGS) $^ $(INC) $(LINK) -o $@

$(NAME2): $(OBJ_CLI)
	@make -C printf/
	$(CC) $(CFLAGS) $^ $(INC) $(LINK) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)
	@cd printf/ && make clean

fclean: clean
	@cd printf/ && make fclean
	$(RM) $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re