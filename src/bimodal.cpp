#include "../include/bimodal.h"

bimodal::bimodal() {}

bimodal::bimodal(int pc)
{
    pc_bit = pc;

    for (int i = 0; i < pow(2, pc_bit); i++)
        tb.push_back(cnt);
}

void bimodal::pred_results(int adr, int result)
{
    int predt;

    adr /= 4;
    total_pred += 1;

    int pc_idx;
    pc_idx = ((int)pow(2, pc_bit) - 1);
    pc_idx &= adr;

    if (tb[pc_idx] >= 4)
        predt = 1; // taken

    else
        predt = 0; // not-taken

    if (predt != result)
        mis_pred += 1;
    

    if (result == 1)
    {    
        if (tb[pc_idx] + 1 <= cnt_max)
            tb[pc_idx] += 1;
        else
            tb[pc_idx] = cnt_max;
    }

    else
    {
        if (tb[pc_idx] - 1 >= 0)
            tb[pc_idx] -= 1;
        else
            tb[pc_idx] = 0;
    }
}

void bimodal::print_results()
{
    float mis_rate;
    mis_rate = (float)mis_pred / (float)total_pred * 100;
    mis_rate = roundf(mis_rate * 100);

    cout << "OUTPUT" << endl;
    cout << "number of predictions:\t" << total_pred << endl;
    cout << "number of mispredictions:\t" << mis_pred << endl;
    cout << "misprediction rate:\t" << fixed << setprecision(2) << mis_rate / 100 << "%" << endl;
    cout << "FINAL BIMODAL CONTENTS" << endl;

    for (int i = 0; i < tb.size(); i++)
        cout << i << "\t" << tb[i] << endl;
    
}