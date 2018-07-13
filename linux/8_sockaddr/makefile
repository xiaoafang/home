.PHONY:all
all:server client
server:server.c
	gcc -g -o $@ $^
client:client.c
	gcc -g -o $@ $^
.PHONY:clean
clean:
	rm -f client server
