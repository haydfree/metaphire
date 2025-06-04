CC=						clang
LD=						clang

TARGET=					metaphire
SRCS=					main.c metaphire.c
OBJS=					${SRCS:.c=.o}

DBFLAGS=				-g3 -O0
CCFLAGS=				-std=c99 -Wextra -Werror -Wpedantic -Wall ${DBFLAGS}
LDFLAGS=				

.c.o:
	@echo ".c.o"
	${CC} ${CCFLAGS} -c $< -o $@

${TARGET}: ${OBJS}
	@echo "target: objs"
	${LD} ${LDFLAGS} $< -o $@ 

clean:
	@echo "clean"
	rm -rf ${OBJS} ${TARGET}

run:
	@echo "run"
	./${TARGET}

commit:
	echo "commit"
	git add .
	git commit -m "AUTO COMMIT: `date +'%Y-%m-%d %H:%M:%S'`"
	git push origin main

.PHONY: clean run commit
