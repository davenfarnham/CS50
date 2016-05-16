#
# Makefile
#

all: bubble selection insertion

bubble: bubble.c
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o bubble bubble.c -lcs50 -lm

insertion: insertion.c
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o insertion insertion.c

selection: selection.c
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o selection selection.c

clean:
	rm -f *.o a.out core bubble selection insertion
