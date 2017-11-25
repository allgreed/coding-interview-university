#config

PROJECT=queue

CC=gcc
CFLAGS=
HEADERSUFFIX=.h
SOURCESUFFIX=.c

# main

DEPS = $(addsuffix $(HEADERSUFFIX), $(PROJECT))
FILES := $(wildcard $(addsuffix $(SOURCESUFFIX), *))

$(PROJECT): $(FILES) $(DEPS)
	$(CC) $(FILES) $(CFLAGS) -o $@.out
	@./$(PROJECT).out
	@printf "\nMemleaks to report:\n"
	@valgrind --log-fd=1 ./queue.out | sed -e '1,/LEAK SUMMARY/d'
