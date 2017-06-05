creacion: obj/main.o obj/codificacion.o lib/libcif.so
	gcc -L./lib -I-/include obj/main.o lib/libcif.so obj/codificacion.o -lm -o bin/cifrador
obj/main.o: src/main.c
	gcc -c -fPIC -I./include src/main.c -o obj/main.o
obj/codificacion.o: src/codificacion.c
	gcc -c -fPIC -I./include src/codificacion.c -o obj/codificacion
lib/libcif.so: src/cifrado.c
	gcc -c -I./include src/cifrado.c -o temporal.o
	gcc -shared -fPIC temporal.o obj/codificacion.o -o lib/libcif.so
	rm temporal.o

