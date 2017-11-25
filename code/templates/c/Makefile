#config

PROJECT= $ASSIGNMENT_NAME$

CC=gcc
CFLAGS=
HEADERSUFFIX=.h
SOURCESUFFIX=.c

# main

DEPS = $(addsuffix $(HEADERSUFFIX), $(PROJECT))
FILES := $(wildcard $(addsuffix $(SOURCESUFFIX), *))

$(PROJECT): $(FILES) $(DEPS)
	$(CC) $(FILES) $(CFLAGS) -o $@.out
	@./$@.out
	@printf "\nMemleaks:\n"
	@valgrind --leak-check=yes --log-fd=1 ./$@.out | sed -e '1,/LEAK SUMMARY/d' |\
	 head -n 3 | awk '{$$1= ""; print "    ", substr($$0,2);}'
