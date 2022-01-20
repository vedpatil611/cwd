.PHONY: all clean install uninstall

PREFIX = /usr/local
SRC = cwd.c
OBJ = $(SRC:.c=.o)

all: cwd

.c.o:
	gcc -Wall -O2 -c $<

cwd: cwd.o
	gcc cwd.o -o cwd

clean:
	rm -f cwd $(OBJ)

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f cwd $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/cwd

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/cwd

