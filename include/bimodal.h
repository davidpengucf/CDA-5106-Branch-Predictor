#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

class bimodal
{
public:
    int mis_pred = 0;
    int total_pred = 0;
    vector<int> tb;

    int cnt = 4;
    int cnt_max = 7;
    int pc_bit;

    bimodal();
    bimodal(int pc);
    void pred_results(int adr, int result);
    void print_results();
};