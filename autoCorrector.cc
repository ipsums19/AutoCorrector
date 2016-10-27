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

int pwd(int i, int j)
{
    int sum = 1;
    for(int k = 0; k < j; ++k)
        sum *= i;
    return sum;
}

int getWeight(std::string s)
{
    int weight = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        weight += pwd(100,i)*(int) s[i] - 'a';
    }
    std::cout << s << " = " << weight <<std::endl;
    return weight;
}

std::vector<int> setWeight(std::string dic[])
{
    std::vector<int> weights(DICTIONARY_SIZE);
    for(int i = 0; i < DICTIONARY_SIZE; ++i)
    {
        weights[i] = getWeight(dic[i]);
    }
    return weights;
}


int difw(int w1, int w2)
{
    return w1 < w2 ?  w2 - w1 : w1 - w2;
}

int autocorrect(std::vector<int> dic, std::string correct)
{
    int min, pos;
    pos = 0;
    int weight = getWeight(correct);
    for(int i = 0; i < DICTIONARY_SIZE; ++i)
    {
        std::cout << i << " = " << dic[i] << std::endl;
    }
    min = difw(weight, dic[0]);
    for(int i = 1; i < DICTIONARY_SIZE; ++i)
    {
        int diff = difw(weight, dic[i]);
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
    std::string dic[DICTIONARY_SIZE] = {"hi", "hello", "good", "bye", "no"};
    std::vector<int> dicWeight = setWeight(dic);
    std::string correct;
    while(std::cin >> correct)
    {
        std::cout << dic[autocorrect(dicWeight, correct)] << std::endl;
    }
}
