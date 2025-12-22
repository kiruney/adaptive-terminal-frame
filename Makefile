CC = gcc
CFLAGS = -lncurses

TARGET1 = using_standart_library
TARGET2 = crossplatform_option

SOURCE1 = using_standart_library.c
SOURCE2 = crossplatform_option.c

all: $(TARGET1) $(TARGET2)

$(TARGET1): $(SOURCE1)
	$(CC) $(CFLAGS) $(SOURCE1) -o $(TARGET1)

$(TARGET2): $(SOURCE2)
	$(CC) $(CFLAGS) $(SOURCE2) -o $(TARGET2)

clean:
	rm -f $(TARGET1) $(TARGET2)

.PHONY: all clean
