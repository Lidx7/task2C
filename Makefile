CC = gcc
AR = ar
MAIN = main.c
NUMCLASS = NumClass.h
BASIC = basicClassification.o
LOOP = advancedClassificationLoop.o
REC = advancedClassificationRecursion.o
FLAGS= -Wall -g

all: loops recursives recursived looped mains maindloop maindrec

loops: libclassloops.a
libclassloops.a: $(LOOP) $(BASIC)
	$(AR) -rcs libclassloops.a $(LOOP) $(BASIC)

recursives: libclassrec.a
libclassrec.a: $(REC) $(BASIC)
	$(AR) -rcs libclassrec.a $(REC) $(BASIC)

recursived: libclassrec.so
libclassrec.so: $(REC) $(BASIC)
	$(CC) -shared -o libclassrec.so $(REC) $(BASIC)

looped: libclassloops.so
libclassloops.so: $(LOOP) $(BASIC)
	$(CC) -shared -o libclassloops.so $(LOOP) $(BASIC)

mains: $(MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(MAIN) libclassrec.a

maindloop: $(MAIN)
	$(CC) $(FLAGS) -o maindloop $(MAIN) ./libclassloops.so

maindrec: $(MAIN)
	$(CC) $(FLAGS) -o maindrec $(MAIN) ./libclassrec.so

main.o: $(MAIN) $(NUMCLASS)
	$(CC) $(FLAGS) -c main.c

basicClassification.o: basicClassification.c $(NUMCLASS)
	$(CC) $(FLAGS) -fPIC -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c $(NUMCLASS)
	$(CC) $(FLAGS) -fPIC -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c $(NUMCLASS)
	$(CC) $(FLAGS) -fPIC -c advancedClassificationRecursion.c


.PHONY: clean all

clean:
		rm -f *.o *.a *.so mains maindrec maindloop
