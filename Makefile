#чтобы makefile не искал файлы с именами целей определяем их
.PHONY: all create clean
#переменная CC указывает компилятор, используемый для сборки
CC = g++
#в переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS = -c -Wall -Werror

ODIR = build 
CDIR = src

all: create board

board: $(ODIR)/main.o $(ODIR)/move.o $(ODIR)/print.o
		$(CC) -o board $(ODIR)/main.o $(ODIR)/move.o $(ODIR)/print.o

$(ODIR)/main.o: $(CDIR)/main.cpp $(CDIR)/functions.h $(CDIR)/global.h $(ODIR)/move.o $(ODIR)/print.o 
							$(CC) $(CFLAGS) -o $(ODIR)/main.o $(CDIR)/main.cpp

$(ODIR)/move.o: $(CDIR)/move.cpp $(CDIR)/print.h $(CDIR)/global.h $(ODIR)/print.o
							$(CC) $(CFLAGS) -o $(ODIR)/move.o $(CDIR)/move.cpp

$(ODIR)/print.o: $(CDIR)/print.cpp $(CDIR)/global.h
							$(CC) $(CFLAGS) -o $(ODIR)/print.o $(CDIR)/print.cpp
							
create : 
		mkdir -p $(ODIR)/
		mkdir -p bin/

clean:
						rm -f $(ODIR)/*.o
