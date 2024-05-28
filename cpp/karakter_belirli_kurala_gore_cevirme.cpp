#include <iostream>

/*
* text değişkeninin içinde bulunan verinin karakterlerin sadece ingilice 
* harflerin konumu terslenmesi bu karakterler dışındakiler konumu değişmeyecek
* Örnek: "ada1sa" -> "asa1da"
*/
typedef struct
{
    int upper_start;
    int lower_start;
    int step_size;
} LimitValue_s;

LimitValue_s letters_limit = {65, 97, 25};

void getText(const char *text);
bool letterCheck(char chr);
bool invertedEquslCheck(const char* chr1, const char* chr2);
int findSize(const char *word);

const char *text = "2serk2anİı--$3";
const int size = findSize(text);

int main()
{
    int index = size;
    std::cout << text << " : " << size << " character" << std::endl;

    char reverse[size + 1];
    reverse[size] = '\0';

    for (int i = 0; i < size; i++)
    {

        if (letterCheck(text[i]))
        {
            index--;
            while(!letterCheck(text[index])){
                 index--;
            }
            reverse[index] = text[i];

        }
        else
        {
            reverse[i] = text[i];
        }
    }

    getText(reverse);
}

void getText(const char *text)
{
    std::cout << text << std::endl;
}

bool letterCheck(char letter)
{
    for (int i = 0; i <= letters_limit.step_size; i++)
    {
        char upper_char = static_cast<char>(letters_limit.upper_start + i);
        char lower_char = static_cast<char>(letters_limit.lower_start + i);
        if (letter == upper_char || letter == lower_char)
        {
            return true;
        }
    }
    return false;
}

int findSize(const char *word)
{
    int size = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        size++;
    }
    return size;
}

bool invertedEquslCheck(const char* chr1, const char* chr2)
{
    if (findSize(chr1) != findSize(chr2))
    {
        std::cout << "Sizes of Character Strings are Different" << std::endl;
        return false;
    }

    int char_size = findSize(chr1);
    for (int i = 0; i < char_size; i++)
    {
        if (chr1[i] != chr2[char_size - i - 1])
        {
            return false;
        }
    }

    return true;
}
