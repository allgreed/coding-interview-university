#config

PROJECT= hash_table

CC=gcc
CFLAGS=-lm --std=c11
HEADERSUFFIX=.h
SOURCESUFFIX=.c

# main

DEPS = $(addsuffix $(HEADERSUFFIX), $(PROJECT))

FILES = $(filter-out complexity.c, $(wildcard $(addsuffix $(SOURCESUFFIX), *)))

$(PROJECT): $(FILES) $(DEPS)
	@$(CC) $(FILES) $(CFLAGS) -o $@.out
	@./$(PROJECT).out
	@printf "\nMemleaks to report:\n"
	@valgrind --log-fd=1 ./$(PROJECT).out | sed -e '1,/LEAK SUMMARY/d'

FILES_COMPLEXITY_TEST = $(filter-out unit.c, $(wildcard $(addsuffix $(SOURCESUFFIX), *)))

complexity: $(FILES_COMPLEXITY_TEST) $(DEPS)
	@$(CC) $(FILES_COMPLEXITY_TEST) $(CFLAGS) -o $@.out
	@./complexity.out | python3 cluster_reporter.py