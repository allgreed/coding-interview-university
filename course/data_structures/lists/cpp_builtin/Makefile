# CONFIG

PROJECT=list

CC=g++
CFLAGS=--std=c++17
HEADERSUFFIX=.hpp
SOURCESUFFIX=.cpp
IS_TEMPLATE=true

# MAIN

ifeq ($(IS_TEMPLATE), true)
        IGNORE_FILES=$(addsuffix $(SOURCESUFFIX), $(PROJECT))
else
        IGNORE_FILES=
endif

DEPS = $(addsuffix $(HEADERSUFFIX), $(PROJECT))
FILES := $(filter-out $(IGNORE_FILES), $(wildcard $(addsuffix $(SOURCESUFFIX), *)))

$(PROJECT): $(FILES) $(DEPS)
	$(CC) $(FILES) $(CFLAGS)
	./a.out

	@# clean a.out
	@rm a.out
