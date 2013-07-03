OBJS	= hxOpenCV.o
CC      = gcc
CFLAGS	= -fPIC -I/usr/lib/neko/include
LDFLAGS = -shared -lneko -lcurl

all: $(OBJS)
	$(CC) $(LDFLAGS) $(CFLAGS) -o ../../ndll/Linux/hxOpenCV.ndll hxOpenCV.c

clean:
	rm -f $(OBJS)
	rm -rf ../../ndll/Linux/hxOpenCV.ndll
