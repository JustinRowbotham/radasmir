# 1. Variables
CC = avr-gcc
CFLAGS = -mmcu=atmega2560 -DF_CPU=16000000UL -Os -Iinclude
TARGET = exes/fun.elf

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

# 2. Default Target
all: $(TARGET)

# 3. Rule to Link the Executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 4. Pattern Rule to Compile C Files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 5. Phony Targets
.PHONY: all clean

clean:
	rm -rf $(OBJS) $(TARGET)
