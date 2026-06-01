CC = gcc
ASM = nasm

CFLAGS = -m32 -Iinclude
LDFLAGS = -no-pie -fno-pie
LDLIBS = -lm

BUILDDIR = build
BINDIR = $(BUILDDIR)/bin
OBJDIR = $(BUILDDIR)/obj

TARGET = $(BINDIR)/integral

TEST_ROOT = $(BINDIR)/test_root
TEST_INTEGRAL = $(BINDIR)/test_integral

CSRCS = \
	main.c \
	src/root.c \
	src/integral.c \
	src/options.c

COBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(CSRCS))

OBJS = $(COBJS) $(OBJDIR)/funcs.o

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(OBJDIR)/%.o: %.c %.h
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/funcs.o: funcs.asm
	mkdir -p $(dir $@)
	$(ASM) -f elf32 $< -o $@

test: $(TEST_ROOT) $(TEST_INTEGRAL)
	./$(TEST_ROOT)
	./$(TEST_INTEGRAL)

$(TEST_ROOT): tests/test_root.c src/root.c
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(TEST_INTEGRAL): tests/test_integral.c src/integral.c
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -rf $(BUILDDIR)

.PHONY: all clean test