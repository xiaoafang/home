ROOT=$(shell pwd)
INCLUDE=-I$i(ROOT)/../../lib/include    #zai zhi ding lujing zhao tou wenjian
LIB=-L$(ROOT)/../../lib/lib            #//zhao ku wen jian
LIB_NAME=-lmysqlclient                # //shangyige lujing xi ku heng duo lianjie na ge ku


.PHONY:all
all:insert select math
insert:insert.c
	gcc -o $@ $^ $(INCLUDE) $(LIB) $(LIB_NAME)
select:select.c
	gcc -o $@ $^
math:math.c
	gcc -o $@ $^
clean:
	rm -f math insert select
