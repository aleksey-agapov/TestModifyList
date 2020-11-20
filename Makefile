# ---------------------------------------------------------------
C_SRCS = test_c.c test_tz.c

OBJS = test_c.o test_tz.o

EXECUTABLE = test_list

.PHONY: all clean build build_static test all

all: build test

build_static: $(OBJS) 
    @echo 'Building target: $@'
    gcc -static -o $(EXECUTABLE) $(OBJS) 

build: $(OBJS) 
	@echo 'Building target: $@'
	gcc -o $(EXECUTABLE) $(OBJS) 

%.o: %.c
	@echo 'Building file: $<'
	gcc -c -o "$@" "$<"

clean:
	rm -rf $(OBJS) $(EXECUTABLE)

test:
	./$(EXECUTABLE)

