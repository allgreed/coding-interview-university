PROJECT= $ASSIGNMENT_NAME$

CC=clang
STANDARD=c11

DEVFLAGS=-g -Wall -Wextra -pedantic
OPTFLAGS= -O3 -march=native

HEADERSUFFIX=.h
SOURCESUFFIX=.c



DEPS = $(addsuffix $(HEADERSUFFIX), $(PROJECT))
FILES := $(wildcard $(addsuffix $(SOURCESUFFIX), *))

$(PROJECT): $(FILES) $(DEPS)

	$(CC) $(FILES) --std=$(STANDARD) $(DEVFLAGS) -o $(PROJECT).out

	./$(PROJECT).out

	@printf "Memleaks: "
	@valgrind --leak-check=yes --log-fd=1 ./$(PROJECT).out | sed -e '1,/LEAK SUMMARY/d' | \
	head -n 3 | awk '{$$1= ""; print "    ", substr($$0,2);}' | \
	python3 -c "import sys;lines = sys.stdin.readlines(); data = lines if lines != [] else 'None\n'; sys.stdout.write(''.join(data))"


$(PROJECT): $(FILES) $(DEPS)

	$(CC) $(FILES) --std=$(STANDARD) $(OPTFLAGS) -o $(PROJECT).out

	./$(PROJECT).out

	@printf "Memleaks: "
	@valgrind --leak-check=yes --log-fd=1 ./$(PROJECT).out | sed -e '1,/LEAK SUMMARY/d' | \
	head -n 3 | awk '{$$1= ""; print "    ", substr($$0,2);}' | \
	python3 -c "import sys;lines = sys.stdin.readlines(); data = lines if lines != [] else 'None\n'; sys.stdout.write(''.join(data))"
