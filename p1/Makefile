### 
## Makefile
## INFO0030: Projet 4
## 
### 

## Variables

# Tools & flags
CC = gcc
CFLAGS = --std=c99 --pedantic -Wall -Wextra -Wmissing-prototypes -DNDEBUG 
LD = gcc
LDFLAGS =

# Files
EXEC = test

MODULES_INSERTIONSORT = InsertionSort.c main.c Array.c
OBJECTS_INSERTIONSORT = InsertionSort.o main.o Array.o

MODULES_QUICKSORT = QuickSort.c main.c Array.c
OBJECTS_QUICKSORT = QuickSort.o main.o Array.o

MODULES_HEAPSORT = HeapSort.c main.c Array.c
OBJECTS_HEAPSORT = HeapSort.o main.o Array.o

MODULES_PLACESORT = PlaceSort.c main.c Array.c
OBJECTS_PLACESORT = PlaceSort.o main.o Array.o

MODULES_RECSORT = RecSort.c main.c Array.c
OBJECTS_RECSORT = RecSort.o main.o Array.o


## Rules

#compilation

test_insertionsort: $(OBJECTS_INSERTIONSORT)
	$(LD) -o $(EXEC) $(OBJECTS_INSERTIONSORT) $(LDFLAGS) -lm

test_quicksort: $(OBJECTS_QUICKSORT)
	$(LD) -o $(EXEC) $(OBJECTS_QUICKSORT) $(LDFLAGS) -lm

test_heapsort: $(OBJECTS_HEAPSORT)
	$(LD) -o $(EXEC) $(OBJECTS_HEAPSORT) $(LDFLAGS) -lm

test_placesort: $(OBJECTS_PLACESORT)
	$(LD) -o $(EXEC) $(OBJECTS_PLACESORT) $(LDFLAGS) -lm

test_recsort: $(OBJECTS_RECSORT)
	$(LD) -o $(EXEC) $(OBJECTS_RECSORT) $(LDFLAGS) -lm


main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

Array.o: Array.c
	$(CC) -c Array.c -o Array.o $(CFLAGS)

InsertionSort.o: InsertionSort.c
	$(CC) -c InsertionSort.c -o InsertionSort.o $(CFLAGS)

QuickSort.o: QuickSort.c
	$(CC) -c QuickSort.c -o QuickSort.o $(CFLAGS)

HeapSort.o: HeapSort.c
	$(CC) -c HeapSort.c -o HeapSort.o $(CFLAGS)

PlaceSort.o: PlaceSort.c
	$(CC) -c PlaceSort.c -o PlaceSort.o $(CFLAGS)

RecSort.o: RecSort.c
	$(CC) -c RecSort.c -o RecSort.o $(CFLAGS)


#rapport
rapport:all_rapport clean_log_aux

all_rapport:
	cd ../rapport && pdflatex tad-RusseCyril.tex

clean_log_aux:
	cd ../rapport && rm -f tad-RusseCyril.aux tad-RusseCyril.log tad-RusseCyril.toc

clean_rapport: clean_log_aux
	cd ../rapport && rm -f tad-RusseCyril.pdf

#création archive
archive:
	cd .. && tar -zcvf demineur_01.tar.gz source rapport doc

#supp fichiers objets + executable
clean:
	rm -f *.o $(EXEC)