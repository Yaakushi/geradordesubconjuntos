CC=g++

.PHONY: all clean

all: subconjuntos prox-subconj

subconjuntos:
	$(CC) src/subconjuntos.cpp -o subconjuntos

prox-subconj:
	$(CC) src/prox-subconj.cpp -o prox-subconj

clean:
	rm subconjuntos prox-subconj
