CLIENT_NAME = Client
SERV_NAME = Server
CC = cc
CFLAGS = -Wall -Wextra -Werror
C_files =  client.c
S_files =  server.c
OBJS = $(C_files:.c=.o)
SERVOBJS = $(S_files:.c=.o)
LIBFT = ../libft/libft.a
FT_PRINTF = ../ft_printf/libftprintf.a
HEADER = Mini_talk.h

# prerequisite
all: $(CLIENT_NAME) $(SERV_NAME)

$(CLIENT_NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(CLIENT_NAME)
	
.c.o: $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

server: $(SERV_NAME)

$(SERV_NAME): $(SERVOBJS)
	$(CC) $(SERVOBJS) $(LIBFT) $(FT_PRINTF) -o $(SERV_NAME)
	
clean:
	rm -f $(OBJS) $(SERVOBJS)
	
fclean: clean
	rm -f $(CLIENT_NAME) $(SERV_NAME)

re: fclean all Bonus

.PHONY: clean
