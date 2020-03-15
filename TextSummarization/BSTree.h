#ifndef AVL_H
#define AVL_H

#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class BSTNode
{
private:
	string word;
	unsigned int frequency;
	BSTNode* left_child, * right_child;
	friend class BSTree;

public:
	BSTNode(string word) : word(word), frequency(1), left_child(0), right_child(0) {	}
	BSTNode(string sentence, unsigned int frequency) : word(sentence), frequency(frequency) { }
	string get_word() { return this->word; }
	BSTNode* get_left_child() { return this->left_child; }
	BSTNode* get_right_child() { return this->right_child; }
	unsigned int get_frequency() { return this->frequency; }
};

class BSTree
{
private:
	BSTNode* root;

public:
	BSTree() : root(0) {	}
	void insert(string word);
	void insert(string word, BSTree stop_words);
	void insert(BSTNode* node);

    void pre_order_print();
    void pre_order_print(BSTNode* node);

	bool is_greater(string word_1, string word_2);
	bool is_lower(string word_1, string word_2);
	bool is_equal(string word_1, string word_2);

	void read_stop_words(string file_name);
	void read_from_file(string file_name, BSTree stop_words);
	void read_sentences(string file_name, BSTree words_tree);
	void summary();
	BSTNode* get_root() { return this->root; }
};

bool operator > (const string& word_1, const string& word_2);
bool operator < (const string& word_1, const string& word_2);
bool operator == (const string& word_1, const string& word_2);
bool is_stop_word(string word, BSTree stop_words);
unsigned int is_word(string word, BSTree words);

#endif
