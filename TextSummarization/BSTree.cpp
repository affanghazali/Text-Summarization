#include "BSTree.h"
#include "Exception.h"

void BSTree::insert(string word)
{
    BSTNode* temp_node = new BSTNode(word);

    if (this->root == 0)
    {
        this->root = temp_node;
        return;
    }

    BSTNode* current_node = this->root;
    BSTNode* parent_node = 0;

    while (current_node != 0) 
    {
        parent_node = current_node;

        if (word == current_node->get_word())
        {
            ++current_node->frequency;
            return;
        }
        else if (current_node->word > word)
            current_node = current_node->left_child;
        else if (current_node->word < word)
            current_node = current_node->right_child;
    }

    if (word > parent_node->word)
    {
        parent_node->right_child = temp_node;

        return;
    }
    else
    {
        parent_node->left_child = temp_node;

        return;
    }
}
void BSTree::insert(string word, BSTree stop_words)
{
    if (is_stop_word(word, stop_words))
        return;

    BSTNode* temp_node = new BSTNode(word);

    if (this->root == 0)
    {
        this->root = temp_node;
        return;
    }

    BSTNode* current_node = this->root;
    BSTNode* parent_node = 0;

    while (current_node != 0) 
    {
        parent_node = current_node;

        if (word == current_node->get_word())
        {
            ++current_node->frequency;
            return;
        }
        else if (word > current_node->word)
            current_node = current_node->right_child;
        else if (word < current_node->word)
            current_node = current_node->left_child;
    }

    if (word > parent_node->word)
    {
        parent_node->right_child = temp_node;

        return;
    }
    else
    {
        parent_node->left_child = temp_node;

        return;
    }
}
void BSTree::insert(BSTNode* node)
{
    if (this->root == 0)
    {
        this->root = node;
        return;
    }

    BSTNode* current_node = this->root;
    BSTNode* parent_node = 0;

    while (current_node != 0)
    {
        parent_node = current_node;

        if (node->get_word() == current_node->get_word())
        {
            ++current_node->frequency;
            return;
        }
        else if (current_node->word > node->get_word())
            current_node = current_node->left_child;
        else if (current_node->word < node->get_word())
            current_node = current_node->right_child;
    }

    if (node->get_word() > parent_node->word)
    {
        parent_node->right_child = node;

        return;
    }
    else
    {
        parent_node->left_child = node;

        return;
    }
}

void BSTree::pre_order_print() 
{ 
    try
    {
        if (this->root == 0)
            throw Exception("Tree is empty..\n");

        this->pre_order_print(this->root);
    }
    catch (Exception ex)
    {
        cout << ex.what() << endl;
        return;
    }
}
void BSTree::pre_order_print(BSTNode* node)
{
    if (node != 0)
    {
        cout << node->word << endl;
        this->pre_order_print(node->left_child);
        this->pre_order_print(node->right_child);
    }
}

bool is_stop_word(string word, BSTree stop_words)
{
    BSTNode* current = stop_words.get_root(); // Change the name here of ROOT according to your implemented  class
    bool visited = false;

    while (current != 0)
    {
       // cout << current->word << endl;
        visited = false;
        if (current->get_word() == word)
        {
            return true; // Returns True if the word is found to be a stopWord
        }
        else if (current->get_word() > word)
        {
            current = current->get_left_child();
            visited = true;
        }
        else if (current->get_word() < word)
        {
            current = current->get_right_child();
            visited = true;
        }
        else
        {
            current = current->get_right_child();
        } 
    }
    return false; // Retruns False if can not be found and further work can be proceeded!
}
unsigned int is_word(string word, BSTree words)
{
    BSTNode* current = words.get_root(); // Change the name here of ROOT according to your implemented  class
    bool visited = false;

    while (current != 0)
    {
        // cout << current->word << endl;
        visited = false;
        if (current->get_word() == word)
        {
            unsigned int a = current->get_frequency();
            return a; // Returns Frequency if the word is found to be a stopWord
        }
        else if (current->get_word() > word)
        {
            current = current->get_left_child();
            visited = true;
        }
        else if (current->get_word() < word)
        {
            current = current->get_right_child();
            visited = true;
        }
        else
        {
            current = current->get_right_child();
        }
    }
    return 0; // Retruns 0 if can not be found and further work can be proceeded!
}

/* bool operator > (const string& word_1, const string& word_2) 
{
    unsigned int size;
    //cout << "sd";
    if (word_1.size() <= word_2.size())
        size = word_1.size();
    else
        size = word_2.size();

    for (unsigned int i = 0; i < size; ++i)
    {
        if ((word_1[i] >= 65 && word_1[i] <= 90) && (word_2[i] >= 97 && word_2[i] <= 122))
        {
            if (word_1[i] > (word_2[i] - 32))
                return true;
            else if (word_1[i] < (word_2[i] - 32))
                return false;
        }
        else if ((word_1[i] >= 97 && word_1[i] <= 122) && (word_2[i] >= 65 && word_2[i] <= 90))
        {
            if ((word_1[i] - 32) > word_2[i])
                return true;
            else if ((word_1[i] - 32) < word_2[i])
                return false;
        }
        else
        {
            if (word_1[i] > word_2[i])
                return true;
            else if (word_1[i] < word_2[i])
                return false; 
        }
    }

    if (word_1.size() < word_2.size())
        return false;

    return false;
}
bool operator < (const string& word_1, const string& word_2) 
{
    unsigned int size;

    if (word_1.size() <= word_2.size())
        size = word_1.size();
    else
        size = word_2.size();

    for (unsigned int i = 0; i < size; ++i)
    {
        if ((word_1[i] >= 65 && word_1[i] <= 90) && (word_2[i] >= 97 && word_2[i] <= 122))
        {
            if (word_1[i] > (word_2[i] - 32))
                return false;
            else if (word_1[i] < (word_2[i] - 32))
                return true;
        }
        else if ((word_1[i] >= 97 && word_1[i] <= 122) && (word_2[i] >= 65 && word_2[i] <= 90))
        {
            if ((word_1[i] - 32) > word_2[i])
                return false;
            else if ((word_1[i] - 32) < word_2[i])
                return true;
        }
        else
        {
            if (word_1[i] > word_2[i])
                return false;
            else if (word_1[i] < word_2[i])
                return true;
        }
    }

    if (word_1.size() < word_2.size())
        return true;

    return false;
} */
bool operator == (const string& word_1, const string& word_2)
{
    if (word_1.size() != word_2.size()) 
        return false;

    for (unsigned int i = 0; i < word_1.size(); ++i)
    {
        if ((word_1[i] >= 65 && word_1[i] <= 90) && (word_2[i] >= 97 && word_2[i] <= 122))
        {
            if (word_1[i] != (word_2[i] - 32)) return false;
        }
        else if ((word_1[i] >= 97 && word_1[i] <= 122) && (word_2[i] >= 65 && word_2[i] <= 90))
        {
            if ((word_1[i] - 32) != word_2[i]) return false;
        }
        else
            if (word_1[i] != word_2[i]) return false;
    }

    return true;
} 
bool operator > (const string& word_1, const string& word_2)
{
    unsigned int i = 0, j = 0;

    while (i < word_1.size() && j < word_2.size())
    {
        if ((word_1[i] >= 65 && word_1[i] <= 90) && (word_2[j] >= 97 && word_2[j] <= 122))
        {
            if (word_1[i] > (word_2[j] - 32))
                return true;
            else if (word_1[i] < (word_2[j] - 32))
                return false;
        }
        else if ((word_1[i] >= 97 && word_1[i] <= 122) && (word_2[j] >= 65 && word_2[j] <= 90))
        {
            if ((word_1[i] - 32) > word_2[j])
                return true;
            else if ((word_1[i] - 32) < word_2[j])
                return false;
        }
        else
        {
            if (word_1[i] > word_2[j])
                return true;
            else if (word_1[i] < word_2[j])
                return false;
        }

        ++i;
        ++j;
    }

    if (i > word_1.size() - 1)
        return false;
    else if (j > word_2.size() - 1)
        return true;
}
bool operator < (const string& word_1, const string& word_2)
{
    unsigned int i = 0, j = 0;

    while (i < word_1.size() && j < word_2.size())
    {
        if ((word_1[i] >= 65 && word_1[i] <= 90) && (word_2[j] >= 97 && word_2[j] <= 122))
        {
            if (word_1[i] > (word_2[j] - 32))
                return false;
            else if (word_1[i] < (word_2[j] - 32))
                return true;
        }
        else if ((word_1[i] >= 97 && word_1[i] <= 122) && (word_2[j] >= 65 && word_2[j] <= 90))
        {
            if ((word_1[i] - 32) > word_2[j])
                return false;
            else if ((word_1[i] - 32) < word_2[j])
                return true;
        }
        else
        {
            if (word_1[i] > word_2[j])
                return false;
            else if (word_1[i] < word_2[j])
                return true;
        }

        ++i; ++j;
    }

    if (i > word_1.size() - 1)
        return true;
    else if (j > word_2.size() - 1)
        return false;
}

bool BSTree::is_greater(string word_1, string word_2)
{
    unsigned int size;

    if (word_1.size() <= word_2.size())
        size = word_1.size();
    else
        size = word_2.size();

    for (unsigned int i = 0; i < size; ++i)
    {
        if ((word_1[i] >= 65 && word_1[i] <= 90) && (word_2[i] >= 97 && word_2[i] <= 122))
        {
            if (word_1[i] > (word_2[i] - 32))
                return true;
            else if (word_1[i] < (word_2[i] - 32))
                return false;
        }
        else if ((word_1[i] >= 97 && word_1[i] <= 122) && (word_2[i] >= 65 && word_2[i] <= 90))
        {
            if ((word_1[i] - 32) > word_2[i])
                return true;
            else if ((word_1[i] - 32) < word_2[i])
                return false;
        }
        else
        {
            if (word_1[i] > word_2[i])
                return true;
            else if (word_1[i] < word_2[i])
                return false;
        }
    }

    return false;
}
bool BSTree::is_lower(string word_1, string word_2)
{
    unsigned int size;

    if (word_1.size() <= word_2.size())
        size = word_1.size();
    else
        size = word_2.size();

    for (unsigned int i = 0; i < size; ++i)
    {
        if ((word_1[i] >= 65 && word_1[i] <= 90) && (word_2[i] >= 97 && word_2[i] <= 122))
        {
            if (word_1[i] > (word_2[i] - 32))
                return false;
            else if (word_1[i] < (word_2[i] - 32))
                return true;
        }
        else if ((word_1[i] >= 97 && word_1[i] <= 122) && (word_2[i] >= 65 && word_2[i] <= 90))
        {
            if ((word_1[i] - 32) > word_2[i])
                return false;
            else if ((word_1[i] - 32) < word_2[i])
                return true;
        }
        else
        {
            if (word_1[i] > word_2[i])
                return false;
            else if (word_1[i] < word_2[i])
                return true;
        }
    }

    return false;
}
bool BSTree::is_equal(string word_1, string word_2)
{
    if (word_1.size() != word_2.size())
        return false;

    for (unsigned int i = 0; i < word_1.size(); ++i)
    {
        if ((word_1[i] >= 65 && word_1[i] <= 90) && (word_2[i] >= 97 && word_2[i] <= 122))
        {
            if (word_1[i] != (word_2[i] - 32)) return false;
        }
        else if ((word_1[i] >= 97 && word_1[i] <= 122) && (word_2[i] >= 65 && word_2[i] <= 90))
        {
            if ((word_1[i] - 32) != word_2[i]) return false;
        }
        else
            if (word_1[i] != word_2[i]) return false;
    }

    return true;
}

void BSTree::read_stop_words(string file_name)
{
    ifstream infile(file_name);
    string word;

    try
    {
        if (!infile)
            throw Exception("Input file not found..\n");

        while (infile)
        {
            if (infile.eof())
                break;
            infile >> word;
            this->insert(word);
        }

        infile.close();
    }
    catch (Exception ex)
    {
        cout << ex.what() << endl;
        return;
    }
}
void BSTree::read_from_file(string file_name, BSTree stop_words)
{
    ifstream infile(file_name);
    string word;

    try
    {
        if (!infile)
            throw Exception("Input file not found..\n");

        while (infile)
        {
            if (infile.eof())
                break;
            infile >> word;
            this->insert(word, stop_words);
        }

        infile.close();
    }
    catch (Exception ex)
    {
        cout << ex.what() << endl;
        return;
    }
}
void BSTree::read_sentences(string file_name, BSTree words_tree)
{
    char var;
    int sentence_weightage , total_words , sum_frequency;

    ifstream infile(file_name);
    ifstream infile2;
    ofstream outfile;

    string temp_sentence, sentence_node;

    while (infile)
    {
        /*if (infile.eof())
            break; */

        sentence_node = "";
        sentence_weightage = 0;
        total_words = 0;
        sum_frequency = 0;
        temp_sentence = "";
        do
        {
            infile >> var >>noskipws;
            sentence_node += var;
        } while (var != '.');
    
        outfile.open("Sentence.txt", std::ios::trunc);
        outfile << sentence_node;
        outfile.close();

        infile2.open("Sentence.txt", ios::in);

        while (infile2)
        {
            if(infile2.eof())
                break;

            infile2 >> temp_sentence;
            total_words++;
            sum_frequency += is_word(temp_sentence, words_tree);
            //cout << temp_sentence << " "  ;
        }
        
        sentence_weightage = sum_frequency / total_words;
        //cout << sentence_node << endl << sentence_weightage << " " << total_words << " "  << " " << sum_frequency<< endl ;

        BSTNode* temp_node = new BSTNode(sentence_node, sentence_weightage);
        this->insert(temp_node);

        infile2.close(); 
    }
    infile.close();
}
void BSTree::summary() {
    BSTNode* current = this->root;
    while (current->left_child != 0) {
        cout << current->get_word() << endl;
        current = current->left_child;
    }
}