KERNELDIR=/usr/src/linux-2.4
INCLUDER=$(KERNELDIR)/include
CROSS_COMPILE=

AS=$(CROSS_COMPILE)as
LD=$(CROSS_COMPILE)ld
CC=$(CROSS_COMPILE)gcc
CPP=$(CC) -E
AR=$(CROSS_COMPILE)ar
NM=$(CROSS_COMPILE)nm
STRIP=$(CROSS_COMPILE)strip
OBJCOPY=$(CROSS_COMPILE)objcopy
OBJDUMP=$(CROSS_COMPILE)objdump

CFLAGS+=-I..
CFLAGS+=-Wall -O -D__KERNEL__ -DMODULE -I$(INCLUDER)
TARGET=evan.o test_demo

all:$(TARGET)
evan.o:nodevfs.c
	$(CC) -c $(CFLAGS) $^ -o $@
test_demo:test_demo.o
	$(CC) $^ -o $@

clean:
	rm -f *.o *~ core .depend test_demo
