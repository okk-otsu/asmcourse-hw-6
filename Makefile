CC = gcc
ASM = nasm

CFLAGS = -m32 -Iinclude
LDLIBS = -lm

BUILDDIR = build
BINDIR = $(BUILDDIR)/bin
OBJDIR = $(BUILDDIR)/obj

TARGET = $(BINDIR)/integral

TEST_ROOT = $(BINDIR)/test_root
TEST_INTEGRAL = $(BINDIR)/test_integral

CSRCS = main.c $(wildcard src/*.c)

COBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(CSRCS))

OBJS = $(COBJS) $(OBJDIR)/funcs.o

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

$(OBJDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/funcs.o: src/funcs.asm
	mkdir -p $(dir $@)
	$(ASM) -f elf32 $< -o $@

test: $(TEST_ROOT) $(TEST_INTEGRAL)
	./$(TEST_ROOT)
	./$(TEST_INTEGRAL)

$(TEST_ROOT): tests/test_root.c src/root.c
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

$(TEST_INTEGRAL): tests/test_integral.c src/integral.c
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

run: $(TARGET)
	./$(TARGET) $(ARGS)
	
clean:
	rm -rf $(BUILDDIR)

.PHONY: all run clean test 