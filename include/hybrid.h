#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

class hybrid
{
    public:
        int mis_preds = 0;
        int total_preds = 0;
        int b_mis_preds = 0;
        int b_total_preds = 0;
        int g_mis_preds = 0;
        int g_total_preds = 0;
        
        vector<int> tb;
        vector<int> b_tb;
        vector<int> g_tb;
        
        int cnt = 0;
        int cnt_max = 3;
        int b_cnt = 4;
        int b_cnt_max = 7;
        int g_cnt = 4;
        int g_cnt_max = 7;

        int ch_bit;
        int b_bit;
        int g_bit;
        int bhr_bit;
        
        
        int bhr = 0;

        hybrid();
        hybrid(int ch, int g, int bhr, int b);
        void pred_results(int adr, int result);
        void print_results();
        
};