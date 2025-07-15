#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int array_background[100][100] = { 0, };
    int paper_count = 0;
    int x, y, result=0;

    cin >> paper_count;

    if (paper_count < 0)
        return 0; // Error

    for (int i = 0; i < paper_count; i++)
    {
        cin >> x >> y;
        if (x > 90 || x < 0 || y > 90 || y < 0)
            return 0; //Error

        for (int X = 0; X < 10; X++)
        {
            for (int Y = 0; Y < 10; Y++)
            {
                array_background[x + X][y + Y]++;
            }
        }
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (array_background[i][j] > 0)
                result++;
        }
    }

    cout << result;
 
    return 0;
}