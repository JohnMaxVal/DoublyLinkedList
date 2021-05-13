exe:main.o libdll.a
	gcc -g main.c -o exe -L. libdll.a
libdll.a:dll.o
	ar rs libdll.a dll.o
dll.o:doubly_linked_list.c
	gcc -c doubly_linked_list.c -o dll.o
main.o:main.c
	gcc -c main.c -o main.o
clean:
	rm dll.o
	rm main.o
