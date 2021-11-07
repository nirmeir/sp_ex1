CC = gcc
AR=ar
CFLAGS = -Wall
LOOPOBJ = BasicClassification.o advancedClassificationLoop.o
RECUSIVEOBJ = BasicClassification.o advancedClassificationRecursion.o

all: loops recursives recursived loopd mains maindloop maindrec 

main.o: main.c NumClass.h
	$(CC) $(CFLAGS) -c main.c
BasicClassification.o: BasicClassification.c NumClass.h
	$(CC) $(CFLAGS) -c BasicClassification.c 
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationLoop.c 
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationRecursion.c 

loops: libclassloops.a

recursives: libclassrec.a

loopd: libclassloops.so

recursived: libclassrec.so

libclassloops.a: $(LOOPOBJ)
	$(AR) -rcs libclassloops.a $(LOOPOBJ)

libclassrec.a: $(RECUSIVEOBJ)
	$(AR) -rcs libclassrec.a $(RECUSIVEOBJ)	

libclassloops.so: $(LOOPOBJ)
	$(CC) -shared -fPIC -o libclassloops.so $(LOOPOBJ)

libclassrec.so: $(RECUSIVEOBJ)
	$(CC) -shared -fPIC -o libclassrec.so $(RECUSIVEOBJ)

mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a -lm

maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so -lm

maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so -lm

.PHONY: clean all loops loopd recursives recursived
clean:
	rm -f *.o *.a *.so mains maindloop maindrec