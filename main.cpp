#include <iostream>
#include <string>
#include <vector>

void parse_words(std::string &phrase, std::vector<std::string> &words);
void translate(std::vector<std::string> &words);
void print_result(std::vector<std::string> &words);

int main(int argc, char **argv)
{
    std::cout << "Enter some text:  ";
    std::string raw_input;
    std::getline(std::cin, raw_input);

    std::vector<std::string> words;
    parse_words(raw_input, words);
    translate(words);

    print_result(words);

    return EXIT_SUCCESS;
}

// Split the string into a vector of words
void parse_words(std::string &phrase, std::vector<std::string> &words)
{
    int i = 0;
    std::string word;
    for (auto& ch : phrase)
    {
        if (ch != ' ')
        {
            word += ch;
            continue;
        }

        words.push_back(word);
        word = "";
        i++;
    }

    words.push_back(word);
}

// Translate the English text into Pig Latin
void translate(std::vector<std::string>& words)
{
    int len = words.size();
    for (int i = 0; i < len; i++)
    {
        char first = words[i][0];
        int len_i = words[i].length();

        for (int j = 1; j < len_i; j++)
        {
            words[i][j - 1] = words[i][j];
        }

        words[i].pop_back();
        words[i] += first;
        words[i] += "ay";
    }
}

// Print the Pig Latin text to stdout
void print_result(std::vector<std::string> &words)
{
    int len = words.size();
    for (int i = 0; i < len; i++)
    {
        std::cout << words[i];
        if (i < len - 1)
            std::cout << ' ';
    }
}