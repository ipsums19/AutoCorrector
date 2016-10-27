#include <iostream>
#include <string>
#include <vector>
#include <map>

#define DICTIONARY_SIZE 5
#define ALPHABET std::map<char, std::pair<int,int> >
#define PAIR(a,b) std::make_pair(a,b)

ALPHABET alphabet = { {'a', PAIR(2,1)}, {'q', PAIR(0,1)}, {'w', PAIR(0,2)},
                      {'e', PAIR(0,3)}, {'r', PAIR(0,4)}, {'t', PAIR(0,5)},
                      {'y', PAIR(0,6)}, {'u', PAIR(0,7)}, {'i', PAIR(0,8)},
                      {'o', PAIR(0,9)}, {'p', PAIR(0,10)}, {'s', PAIR(2,2)},
                      {'d', PAIR(2,3)}, {'f', PAIR(2,4)}, {'g', PAIR(2,5)},
                      {'h', PAIR(2,6)}, {'j', PAIR(2,7)}, {'k', PAIR(2,8)},
                      {'l', PAIR(2,9)}, {'z', PAIR(4,1)}, {'x', PAIR(4,2)},
                      {'c', PAIR(4,3)}, {'v', PAIR(4,4)}, {'b', PAIR(4,5)},
                      {'n', PAIR(4,6)}, {'m', PAIR(4,7)}
                    };


int abs(int a, int b)
{
    return a > b? a - b : b - a;
}

int difw(std::string &w1, std::string &w2)
{
    if(w1.size() != w2.size()) return 100;

    int sum = 0;
    for(int i = 0; i < w1.size(); ++i)
    {
        sum += abs(alphabet[w1[i]].first - alphabet[w2[i]].first);
        sum += abs(alphabet[w1[i]].second - alphabet[w2[i]].second);
    }
    return sum;
}

int autocorrect(std::vector<std::string> &dic, std::string correct)
{
    int min, pos;
    pos = 0;
    min = difw(correct, dic[0]);
    for(int i = 1; i < DICTIONARY_SIZE; ++i)
    {
        int diff = difw(correct, dic[i]);
        if(diff < min)
        {
            pos = i;
            min = diff;
        }
    }
    return pos;
}

int main()
{
    std::vector<std::string> dic = {"hi", "hello", "good", "bye", "no"};
    std::string correct;
    while(std::cin >> correct)
    {
        std::cout << dic[autocorrect(dic, correct)] << std::endl;
    }
}
