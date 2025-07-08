#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, float> score_map = {
    {"A+", 4.5},
    {"A0", 4.0},
    {"B+", 3.5},
    {"B0", 3.0},
    {"C+", 2.5},
    {"C0", 2.0},
    {"D+", 1.5},
    {"D0", 1.0},
    {"F",  0.0}
};

int main() {
    vector<string> classname;
    int group_count = 0;
    float total_score = 0, total_grade = 0;
    bool ret = false;
   
    for (int i = 0 ; i < 20; i++)
    {
        float grade, score;
        string input_classname, input_score;
        cin >> input_classname >> grade >> input_score;
        if (find(classname.begin(), classname.end(), input_classname) != classname.end())
            return 0; //학명 중복 검사
        classname.push_back(input_classname);
        if (score_map.find(input_score) != score_map.end()) {
            score = score_map[input_score];
        }
        else if(input_score == "P")
        {
            continue; // P인경우
        }
        else
        {
            return 0;
        }
        total_grade = total_grade + grade;
        total_score = total_score + (score * grade);
    }

    cout << total_score/ total_grade;


    return 0;
}