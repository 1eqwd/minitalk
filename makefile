NAME = server
NAME2 = client
SRC_SERVER = server.c ft_atoi.c
SRC_CLIENT = client.c ft_atoi.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr

all: $(NAME) $(NAME2)

$(NAME2):$(SRC_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME2) $(SRC_CLIENT)

$(NAME):$(SRC_SERVER)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC_SERVER)

clean:
	$(RM) server.o client.o ft_atoi.o

fclean: clean
	$(RM) $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
# # コンパイラとフラグ
# CC = gcc
# CFLAGS = -Wall -g

# # ソースファイル
# SRC_SERVER = server.c
# SRC_CLIENT = client.c

# # 実行ファイル
# EXEC_SERVER = server
# EXEC_CLIENT = client

# # デフォルトターゲット（makeコマンドが引数なしで呼ばれた場合に実行される）
# all: $(EXEC_SERVER) $(EXEC_CLIENT)

# # serverターゲットのルール
# $(EXEC_SERVER): $(SRC_SERVER)
# 	$(CC) $(CFLAGS) -o $(EXEC_SERVER) $(SRC_SERVER)

# # clientターゲットのルール
# $(EXEC_CLIENT): $(SRC_CLIENT)
# 	$(CC) $(CFLAGS) -o $(EXEC_CLIENT) $(SRC_CLIENT)

# # cleanターゲット（コンパイル後の中間ファイルを削除）
# clean:
# 	rm -f $(EXEC_SERVER) $(EXEC_CLIENT)

# # fcleanターゲット（clean後にオブジェクトファイルも削除）
# fclean: clean
# 	rm -f $(EXEC_SERVER) $(EXEC_CLIENT)

