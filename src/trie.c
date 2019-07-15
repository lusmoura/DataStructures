#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

bool is_valid_letter(char letter) {
	return ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'));
}

int alphabetPosition(char letter) {
	return letter <= 'Z' ? letter - 'A' : letter - 'a';
}

void increase_amount(Trie* trie) {
    trie->amountOfWords++;
}

void decrease_amount(Trie* trie) {
    trie->amountOfWords--;
}

TrieNode* create_trie_node() {
	TrieNode* node = malloc(sizeof(TrieNode));
	node->endWord = false;
	
    for(int i = 0; i < alphabetSize; i++)
		node->nextLetter[i] = NULL;

	return node;
}

Trie* create_trie() {
    Trie* trie = calloc(1, sizeof(Trie));

    trie->root = create_trie_node();
    trie->amountOfWords = 0;
    trie->maxSize = 0;

    return trie;
}

void recursive_destroy(TrieNode* node) {
    for (int i = 0; i < alphabetSize; i++) {
        if (node->nextLetter[i] != NULL) 
            recursive_destroy(node->nextLetter[i]);
    }

    if (node != NULL) free(node);
}

void destroy_trie(Trie* trie) {
	if (trie == NULL) return;
    recursive_destroy(trie->root);
    free(trie);
}

bool search_word(Trie* trie, char* word) {
	int wordSize = strlen(word);
	TrieNode* curr = trie->root;

    for (int i = 0; i < wordSize; i++) {
        if (!is_valid_letter(word[i])) return false;
        
        int pos = alphabetPosition(word[i]);
        if (curr->nextLetter[pos] == NULL) return false;

         curr = curr->nextLetter[pos];
    }
	
    if (curr->endWord) return true;
	return false;
}

bool insert_word(Trie* trie, char* word) {
	if (trie == NULL) return false;
    int size = strlen(word);
    trie->maxSize = max(trie->maxSize, size);
	TrieNode* curr = trie->root;
	
	for(int i = 0; i < size; i++) {
		if (!is_valid_letter(word[i])) return false;

        int pos = alphabetPosition(word[i]);

		if(curr->nextLetter[pos] == NULL)
			curr->nextLetter[pos] =  create_trie_node();;
    
    	curr = curr->nextLetter[pos];
	}
	
    increase_amount(trie);
	curr->endWord = true;
    return true;
}

bool remove_word(Trie* trie, char* word) {
	if (trie == NULL) return false;
    int size = strlen(word);
	TrieNode* curr = trie->root;
	
	for(int i = 0; i < size; i++) {
		if (!is_valid_letter(word[i])) return false;

        int pos = alphabetPosition(word[i]);

		if(curr->nextLetter[pos] == NULL)
            return false;
    
    	curr = curr->nextLetter[pos];
	}
	
    decrease_amount(trie);
	curr->endWord = false;
    return true;
}

void print_word(char* word, int size) {
    for (int i = 0; i < size; i++)
        printf("%c", word[i]);
    printf("\n");
}

void recursive_print(TrieNode* curr, char* word, int pos) {
    if (curr == NULL) return;
    if (curr->endWord) print_word(word, pos);

    for (int i = 0; i < alphabetSize; i++) {
        if (curr->nextLetter[i] != NULL) word[pos] = 'a' + i;
        recursive_print(curr->nextLetter[i], word, pos + 1);
    }
}

void print_trie(Trie* trie) {
    if (trie == NULL) return;
    char* word = calloc(trie->maxSize, sizeof(char));
    recursive_print(trie->root, word, 0);
    free(word);
}