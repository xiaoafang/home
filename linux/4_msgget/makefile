.PHONY:all
all:server client
server:server.c comm.c
	gcc -g -o $@ $^
client:client.c comm.c
	gcc -g -o $@ $^

.PHONY:clean
clean:
	rm -f client server
