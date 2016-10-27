#include <iostream>
#include <string>
#include <vector>

#define DICTIONARY_SIZE 5

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
