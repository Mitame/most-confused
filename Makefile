CC=gcc
CFLAGS=-g -Wall -Wshadow -Wextra
LDFLAGS=-g

most-confused: most-confused.c

data.tsv: most-confused stations
	./most-confused | sort -n > data.tsv
