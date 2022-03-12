SERVER = server
CLIENT = client
CC = gcc
CFLAGS = -Wall -Werror -Wextra

PRINTF_DIR = ./printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SERVER_S = server.c
CLIENT_S = client.c

SERVER_O = $(patsubst %.c, %.o, $(SERVER_S))


CLIENT_O = $(patsubst %.c, %.o, $(CLIENT_S))



.PHONY : all clean fclean re

all :
	@$(MAKE) libs
	@$(MAKE) $(SERVER)
	@$(MAKE) $(CLIENT)
bonus:
	@$(MAKE) libs
	@$(MAKE) $(SERVER)
	@$(MAKE) $(CLIENT)

$(SERVER) : $(SERVER_O)
	$(CC) $(CFLAGS) $(SERVER_O) $(PRINTF) -o $(SERVER)

$(CLIENT) : $(CLIENT_O)
	$(CC) $(CFLAGS) $(CLIENT_O) $(PRINTF) -o $(CLIENT)


libs :
	@(cd $(PRINTF_DIR) && $(MAKE))

$(PRINTF) :
	@(cd $(PRINTF_DIR) && $(MAKE))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(SERVER_O) $(SERVER_D) $(CLIENT_O)
	@(cd $(PRINTF_DIR) && $(MAKE) clean)

fclean : clean
	@rm -f $(SERVER) $(CLIENT)
	@(cd $(PRINTF_DIR) && $(MAKE) fclean)

re : clean all
