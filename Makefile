# chwso - Raise or lower given windows. 
# See chwso.c for copyright and license details.

PREFIX?=/usr
MANPREFIX?=${PREFIX}/man
LDFLAGS?=-lX11

SRC = chwso.c
OBJ = ${SRC:.c=.o}

all: chwso

.c.o:
	@echo CC -c $<
	@${CC} -c ${CFLAGS} $<

chwso: ${OBJ}
	@echo CC -o $@
	@${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	@echo cleaning
	@rm -f chwso ${OBJ} chwso-${VERSION}.tar.gz

install: all
	@echo installing executable file to ${DESTDIR}${PREFIX}/bin
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f chwso ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/chwso
	@echo installing manual page to ${DESTDIR}${MANPREFIX}/man1/chwso.1
	@mkdir -p ${DESTDIR}${MANPREFIX}/man1
	@sed "s/VERSION/${VERSION}/g" < chwso.1 > ${DESTDIR}${MANPREFIX}/man1/chwso.1
	@chmod 644 ${DESTDIR}${MANPREFIX}/man1/chwso.1

uninstall:
	@echo removing executable file from ${DESTDIR}${PREFIX}/bin
	@rm -f ${DESTDIR}${PREFIX}/bin/chwso
	@echo removing manual page from ${DESTDIR}${MANPREFIX}/man1
	@rm -f ${DESTDIR}${MANPREFIX}/man1/chwso.1

.PHONY: all clean dist install uninstall
