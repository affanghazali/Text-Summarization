#include<iostream>
#include "BSTree.h"

int main()
{
	BSTree tree, stop_words, sentences;
	stop_words.read_stop_words("StopWords.txt");
	//stop_words.pre_order_print();
	tree.read_from_file("Data.txt", stop_words);
	sentences.read_sentences("Data.txt", tree);

	cout << "\n\n\n\t\t\t\t\t-------------------------------- Original Document ----------------------------\n\n" << endl;

	sentences.pre_order_print();

	cout << "\n\n\n\t\t\t\t\t----------------------------------- Summary --------------------------------------\n\n" << endl;

	sentences.summary();

	return 0;
}