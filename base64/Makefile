c:
	gcc base64.c test-base64.c -std=c99 -lm

a:
	gcc base64.c test-base64.c -std=c99 -lm -o base64.o
	ar cqs libbase64.a base64.o

so:
	gcc -fpic base64.c test-base64.c -std=c99 -lm -o base64.o
	gcc -shared -fPIC -o base64.so base64.o

clean:
	rm -rf *.out *.o *.so *.a
