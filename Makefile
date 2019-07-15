all:
	gcc src/*.c -I include/ -o main -g -Wall

list:
	gcc src/list.c src/main.c -I include/ -o main -g -Wall

deque:
	gcc src/list.c src/deque.c src/main.c -I include/ -o main -g -Wall

queue:
	gcc src/list.c src/queue.c src/main.c -I include/ -o main -g -Wall

stack:
	gcc src/list.c src/stack.c src/main.c -I include/ -o main -g -Wall

pair:
	gcc src/pair.c src/main.c -I include/ -o main -g -Wall

trie:
	gcc src/trie.c src/main.c -I include/ -o main -g -Wall

bst:
	gcc src/bst.c src/main.c -I include/ -o main -g -Wall

avl:
	gcc src/avl.c src/main.c -I include/ -o main -g -Wall

run:
	./main
