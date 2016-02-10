COMPILER=gcc
COMPILEROPTS=-Wall -Werror

CFILES=main.c
OFILES=main.o

.DEFAULT_GOAL=libleren.so

libleren.so: libleren.so.1
	ln -s $< $@

libleren.so.1: $(OFILES)
	$(COMPILER) -shared -o $@ $^

libleren.a: $(OFILES)
	ar rcs $@ $^

%.o: %.c
	$(COMPILER) $(COMPILEROPTS) -c -fpic -o $@ $<

.PHONY: clean all

all: libleren.so libleren.a doc

clean:
	rm *.o
	rm *.a
	rm *.so*
	rm -r doc/

doc:
	mkdir doc
	doxygen

