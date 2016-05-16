#
# Makefile
#

all: sorts

sorts: sorts.c helpers.c helpers.h
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o sorts sorts.c helpers.c -lcs50 -lm
