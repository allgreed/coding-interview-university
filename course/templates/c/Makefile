#config

PROJECT=$FILL THIS !!!$

CC=gcc
CFLAGS=
HEADERSUFFIX=.h
SOURCESUFFIX=.c

# main

DEPS = $(addsuffix $(HEADERSUFFIX), $(PROJECT))
FILES := $(wildcard $(addsuffix $(SOURCESUFFIX), *))

$(PROJECT): $(FILES) $(DEPS)
	$(CC) $(FILES) $(CFLAGS)
	./a.out

	@# clean a.out
	@rm a.out
