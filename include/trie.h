#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>

#define DEBUG 0
#define alphabetSize 26

typedef struct trieNode {
	bool endWord;
	struct trieNode* nextLetter[alphabetSize];
} TrieNode;

typedef struct trie {
    TrieNode* root;
    int amountOfWords;
    int maxSize;
} Trie;


int min(int a, int b);
int max(int a, int b);
bool is_valid_letter(char letter);
int alphabetPosition(char letter);

Trie* create_trie();
void destroy_trie(Trie* trie);

bool insert_word(Trie* trie, char* word);
bool search_word(Trie* trie, char* word);
bool remove_word(Trie* trie, char* word);
void print_trie(Trie* trie);

#endif