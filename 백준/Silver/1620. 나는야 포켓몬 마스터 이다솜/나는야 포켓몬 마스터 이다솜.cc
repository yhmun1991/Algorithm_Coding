#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <string>
#include <cctype>
#include <unordered_map>

#define CHAR_OFFSET 48
using namespace std;
struct linkedlist
{
    int* pre;
    int value;
    int* tail;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, string> pokemon, pokemon2;
    vector<string> output_data;
    int input_data_A, input_data_B;

    cin >> input_data_A >> input_data_B;

    if (input_data_A < 1 || input_data_A > 100'000 || input_data_B < 1 || input_data_B > 100'000)
        return 0;

    for (int i = 1; i < input_data_A+1; i++) {
        string name;
        cin >> name;
        pokemon.insert({name,to_string(i) });
        pokemon2.insert({ to_string(i),name });
    }

    for (int i = 0; i < input_data_B; i++) {
        string input_data;
        cin >> input_data;
        
        if (pokemon.find(input_data) != pokemon.end()) {
            output_data.push_back(pokemon[input_data]);
        }
        else
        {
            if(pokemon2.find(input_data) != pokemon2.end())
               output_data.push_back(pokemon2[input_data]);
            
        }
    }
    

    for (auto b : output_data) {
        cout << b << "\n";
    }
    
    return 0;
}