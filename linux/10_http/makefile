ROOT=$(shell pwd)

.PHONY:all
all:server cgi
server:server.c 
	gcc -o $@ $^ -lpthread  
cgi:
	cd $(ROOT)/www/cgi;make clean;make cd -
clean:
	rm -f server
	cd $(ROOT)/www/cgi;make clean;cd -
