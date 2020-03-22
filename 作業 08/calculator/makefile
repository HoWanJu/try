main:main.c plus.o minus.o multiply.o divide.o
	gcc main.c plus.o minus.o multiply.o divide.o -o main
%.o: %.c
	gcc -c $<
clean:
	rm *.o main
