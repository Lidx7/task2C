CC = gcc
AR = ar
GRAPH = my_graph.c
MAT = my_mat.o
KNAPSACK = my_Knapsack.c
MYMAT = my_mat.h
FLAGS = -Wall -g

all: graph fulgraph my_Knapsack my_graph

graph: libgraph.a
libgraph.a: $(MAT)
	$(AR) -rcs libgraph.a $(MAT)

fulgraph: libgraph.so
libgraph.so: $(MAT)
	$(CC) -shared -o libgraph.so $(MAT)


my_Knapsack: $(KNAPSACK)
	$(CC) $(FLAGS) -o my_Knapsack $(KNAPSACK)

my_Knapsack.o: $(KNAPSACK)
	$(CC) $(FLAGS) -fPIC -c $(KNAPSACK)


my_graph: $(GRAPH) libgraph.a
	$(CC) $(FLAGS) -o my_graph $(GRAPH) libgraph.a

my_graph.o: $(GRAPH) $(MYMAT)
	$(CC) $(FLAGS) -fPIC -c $(GRAPH)


my_mat.o: $(MYMAT) my_mat.c
	$(CC) $(FLAGS) -fPIC -c my_mat.c


.PHONY: clean all

clean:
	rm -f *.o *.a *.so my_graph my_Knapsack