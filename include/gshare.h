#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

class gshare
{
public:
    int mis_preds = 0;
    int total_preds = 0;
    vector<int> tb;

    int cnt = 4;
    int cnt_max = 7;
    int pc_bit;
    int bhr_bit;

    int bhr = 0;

    gshare();
    gshare(int pc, int bhr);
    void pred_results(int adr, int result);
    void print_results();

    int results(int adr, int result);
    void update(int result);
    void update_bhr();
};