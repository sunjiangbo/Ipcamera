# Makefile -- Makefile for util-linux Linux utilities
# Created: Sat Dec 26 20:09:40 1992
# Revised: Fri Oct  6 21:02:21 1995 by r.faith@ieee.org
# Copyright 1992, 1993, 1994, 1995 Rickard E. Faith (faith@cs.unc.edu)
#
PREFIX  := $(shell /bin/pwd | sed -e 's/initrd.*/initrd\/stage/')
INDIR=-I/usr/local/arm/2.95.3/arm-linux/include
INDIR += -I../include
CROSS= arm-goke-linux-uclibcgnueabi-
CFLAGS=$(INDIR)
CFLAGS+= -O1
CC=$(CROSS)gcc
AR=$(CROSS)ar
STRIP=$(CROSS)strip
INSTALL=/usr/bin/install -c

all:
	$(CC)  -O3 -o watchdog watchdog.c  $(INDIR)
	$(STRIP) watchdog
	cp watchdog /nfs/yb

clean:
	rm -f watchdog