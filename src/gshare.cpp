#include "../include/gshare.h"

gshare::gshare() {}

gshare::gshare(int pc, int bhr)
{
    pc_bit = pc;
    bhr_bit = bhr;

    for (int i = 0; i < pow(2, pc_bit); i++)
        tb.push_back(cnt);
}

void gshare::pred_results(int adr, int result)
{
    adr /= 4;
    total_preds += 1;

    int pc_idx;
    pc_idx = (int)pow(2, pc_bit) - 1;
    pc_idx &= adr;

    int idx;
    idx = bhr ^ pc_idx;

    int predt;

    if (tb[idx] >= 4)
        predt = 1;

    else
        predt = 0;

    if (predt != result)
        mis_preds += 1;

    if (result == 1)
        tb[idx] = min(tb[idx] + 1, cnt_max);

    else
        tb[idx] = max(tb[idx] - 1, 0);

    bhr /= 2;

    if (result)
        bhr |= (int)pow(2, bhr_bit - 1);
}

void gshare::print_results()
{
    float mis_rate;
    mis_rate = (float)mis_preds / (float)total_preds * 100;
    mis_rate = roundf(mis_rate * 100);

    cout << "OUTPUT" << endl;
    cout << "number of predictions:\t" << total_preds << endl;
    cout << "number of mispredictions:\t" << mis_preds << endl;
    cout << "misprediction rate:\t" << fixed << setprecision(2) << mis_rate / 100 << "%" << endl;
    cout << "FINAL GSHARE CONTENTS" << endl;

    for (int i = 0; i < tb.size(); i++)
        cout << i << "\t" << tb[i] << endl;
    
}

int gshare::results(int adr, int result)
{
    adr /= 4;
    total_preds += 1;

    int pc_idx;
    pc_idx = (int)pow(2, pc_bit) - 1;
    pc_idx &= adr;

    int idx;
    idx = bhr ^ pc_idx;

    int predt;

    if (tb[idx] >= 4)
        predt = 1;

    else
        predt = 0;

    return predt;
}