#чтобы makefile не искал файлы с именами целей определяем их
.PHONY: all create clean
#переменная CC указывает компилятор, используемый для сборки
CC = g++
#в переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS = -c -Wall -Werror

ODIR = build
CDIR = src

all: bin/board
		
bin/board: $(ODIR)/main.o $(ODIR)/move.o $(ODIR)/print.o
			$(CC) -o bin/board $(ODIR)/main.o $(ODIR)/move.o $(ODIR)/print.o

$(ODIR)/main.o: $(CDIR)/main.cpp $(CDIR)/functions.h $(CDIR)/global.h $(ODIR)/move.o $(ODIR)/print.o 
				$(CC) -o $(ODIR)/main.o $(CFLAGS) $(CDIR)/main.cpp

$(ODIR)/move.o: $(CDIR)/move.cpp $(CDIR)/print.h $(CDIR)/global.h $(ODIR)/print.o
				$(CC) -o $(ODIR)/move.o  $(CFLAGS) $(CDIR)/move.cpp

$(ODIR)/print.o: $(CDIR)/print.cpp $(CDIR)/global.h
				$(CC) -o $(ODIR)/print.o $(CFLAGS) $(CDIR)/print.cpp
		
clean:
		rm -f $(ODIR)/*.o
