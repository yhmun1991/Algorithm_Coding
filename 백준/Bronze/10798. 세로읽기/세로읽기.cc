#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    string arraystring[5];
    int maxium_value = -1, input_data = 0, index = 0;

    for (int i = 0; i < 5; i++){
        cin >> arraystring[i];
        for (char c : arraystring[i]) {
            if (!isalnum(c))
                return 0;
        }
    }
    
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (i < arraystring[j].length()) {
                if (arraystring[j][i] != NULL)
                    cout << arraystring[j][i];
            }
        }
    }
 
    return 0;
}