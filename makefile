CC=gcc
AR=ar
FLAGS= -Wall -g

all: loops recursives recursived loopd mains maindloop maindrec

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c 

basicClassification.o: basicClassification.c 
	$(CC) $(FLAGS) -c basicClassification.c 
	
advancedClassificationLoop.o: advancedClassificationLoop.c 
	$(CC) $(FLAGS) -c advancedClassificationLoop.c 

advancedClassificationRecursion.o: advancedClassificationRecursion.c 
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c 

loops: libclassloops.a 

recursives: libclassrec.a 

recursived: libclassrec.so

loopd: libclassloops.so

libclassloops.a: basicClassification.o advancedClassificationLoop.o
	$(AR) -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

libclassloops.so: basicClassification.o advancedClassificationLoop.o
	$(CC) -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o

libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	$(AR) -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o

libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	$(CC) -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o

mains: main.o libclassrec.a 
	$(CC) $(FLAGS) -o mains main.o libclassrec.a -lm

maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so -lm

maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so -lm

.PHONY: clean all loopd loops recursived recursives

clean:
	rm -f *.o *.a *.so mains maindrec maindloop