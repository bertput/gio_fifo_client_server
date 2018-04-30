#
# Makefile for SQRL
#

CC = gcc

GTK_CFLAGS = `pkg-config gtk+-2.0 --cflags`
GTK_LIBS   = `pkg-config gtk+-2.0 --libs`


# DEBUG     = -ggdb
CFLAGS    = -c $(GTK_CFLAGS) -pthread -Wall $(DEBUG)
LINKLIBS  = $(GTK_LIBS) -pthread  -lssl -lcrypto -luriparser


HFILES   = \
	log.h \
	fifo.h \
	version.h
CPPFILES = \
	log.c \
	fifo.c \
	server.c \
	client.c
CLIENT_OBJFILES = \
	log.o \
	fifo.o \
	client.o
SERVER_OBJFILES = \
	log.o \
	fifo.o \
	server.o

TARGETS  = client server

# Search for include files in each directory,
#  in addition to the "usual" places.
#
INCLUDES  =


# This must be the first target, so you can specify additional targets
# in the include files which follow.
#
all : $(TARGETS)


# Individual targets
client : $(CLIENT_OBJFILES)
	$(CC) -o client $(CLIENT_OBJFILES) $(LINKLIBS)

server : $(SERVER_OBJFILES)
	$(CC) -o server $(SERVER_OBJFILES) $(LINKLIBS)

.cpp.o :
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $<

tags : $(HFILES) $(CPPFILES)
	ctags $(HFILES) $(CPPFILES)

clean:
	rm -f $(TARGETS) $(CLIENT_OBJFILES) $(SERVER_OBJFILES)

