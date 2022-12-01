#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class smith
{
public:
    int mis_pred = 0;
    int total_pred = 0;
    int cnt;
    int cnt_max;

    smith();
    smith(int bit_num);
    void pred_results(int result);
    void print_results();
};
