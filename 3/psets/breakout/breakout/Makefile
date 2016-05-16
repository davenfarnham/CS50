#
# Makefile
#
# Computer Science 50
# Problem Set 3
#

breakout: breakout.c Makefile
	clang -O0 -std=c99 -Wall -Werror -Wno-unused-variable -o breakout breakout.c -lcs -lm

breakout2: breakout2.c Makefile
	clang -O0 -std=c99 -Wall -Werror -Wno-unused-variable -o breakout2 breakout2.c -lcs -lm

clean:
	rm -f *.o core breakout
