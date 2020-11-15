run: a.out
	@./out/a.out

a.out: main.o ex1.o
	@gcc -Werror -o out/a.out out/main.o out/ex1.o

main.o: main.c ex1.h
	@gcc -Werror -c -o out/main.o main.c

ex1.o: ex1.c
	@gcc -Werror -c -o out/ex1.o ex1.c

clean:
	rm -f out/*.o
