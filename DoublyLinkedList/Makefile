exe:main.o libdll.a
	gcc -g main.c -o exe -L. libdll.a
main.o:main.c
	gcc dll.o main.c -o main.o
libdll.a:dll.o
	ar rs libdll.a dll.o
dll.o:doubly_linked_list.c
	gcc -c doubly_linked_list.c -o dll.o
clean:
	rm dll.o
	rm main.o
