
tokenizer.o: tokenizer.h tokenizer.c uimain.c history.h 
	cc -c tokenizer.c -o tokenizer.o

history.o:  history.c uimain.c tokenizer.h
	cc -c history.c -o history.o

uimain.o: history.h tokenizer.h uimain.c
	cc -c uimain.c -o uimain.o

all: starToken

starToken: history.o tokenizer.o uimain.o
	cc history.o tokenizer.o uimain.o -o starToken 

clean:
	rm -f *.o starToken

run:starToken
	./starToken
