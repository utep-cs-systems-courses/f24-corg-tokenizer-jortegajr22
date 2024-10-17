CFLAGA=--g -03

tokenizer.o: tokenizer.h tokenizer.c uimain.c history.h 
	cc -o tokenizer.o

history.o:  history.c uimain.c tokenizer.h
	cc -o history.o

uimain.o: history.h tokenizer.h uimain.c
	cc -o uimain.o

all: starToken

starToken: history.o tokenizer.o uimain.o
	cc -o starToken 

clean:
	rm -f *.o starToken

run:starToken
	./starToken
