CC = gcc
CFLAGS = -Wall -Wextra

TARGET = add-nbo

all: $(TARGET)

$(TARGET): add-nbo.c
        $(CC) $(CFLAGS) -o $(TARGET) add-nbo.c

clean:
        rm -f $(TARGET)
