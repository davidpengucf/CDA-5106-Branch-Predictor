#include"../include/hybrid.h"

hybrid::hybrid(){}

hybrid::hybrid(int ch, int g, int bhr, int b)
{
    ch_bit = ch;
    g_bit = g;
    bhr_bit = bhr;
    b_bit = b;

    for (int i = 0; i < pow(2, ch_bit); i++)
        tb.push_back(cnt);

    for (int i = 0; i < pow(2, b_bit); i++)
        b_tb.push_back(cnt);

    for (int i = 0; i < pow(2, g_bit); i++)
        g_tb.push_back(cnt);
}

void hybrid::pred_results(int adr, int result)
{
    adr /= 4;
    total_preds += 1;

    
    int g_idx;
    g_idx = (int)pow(2, g_bit) - 1;
    g_idx &= adr;
    int idx;
    idx = bhr ^ g_idx;

    int b_idx;
    b_idx = (int)pow(2, b_bit) - 1;
    b_idx &= adr;

    int ch_idx;
    ch_idx = (int)pow(2, ch_bit) - 1;
    ch_idx &= adr;

    int predt = 0;
    int b_predt = 0;
    int g_predt = 0;
    int use_g = 0;

    if (tb[ch_idx] >= 2)
        use_g = 1;
    else
        use_g = 0; // take bimodal

    if (b_tb[b_idx] >= 4)
        b_predt = 1; // bimodal pred taken

    else
        b_predt = 0; // bimodal pred not-taken

    if (g_tb[idx] >= 4)
        g_predt = 1;

    else
        g_predt = 0;

    if (use_g == 1)
    {
        if (result == 1) g_tb[idx] = min(g_tb[idx] + 1, g_cnt_max);
        else  g_tb[idx] = max(g_tb[idx] - 1, 0);
        if (g_predt != result) mis_preds += 1;
    }

    if (use_g == 0)
    {
        if (result == 1) b_tb[b_idx] = min(b_tb[b_idx] + 1, b_cnt_max);
        else  b_tb[b_idx] = max(b_tb[b_idx] - 1, 0);
        if (b_predt != result) mis_preds += 1;
    }

    bhr /= 2;
    if (result)
        bhr |= (int)pow(2, bhr_bit - 1);

    int g_true = 0;
    if (g_predt == result) g_true = 1;
    else g_mis_preds += 1;

    int b_true = 0;
    if (b_predt == result) b_true =1;
    else b_mis_preds += 1;

    if (g_true)
        if (!b_true)
            tb[ch_idx] = min(tb[ch_idx] + 1, cnt_max);
    
    if (b_true)
        if (!g_true)
            tb[ch_idx] = max(tb[ch_idx] - 1, 0);

}

void hybrid::print_results()
{
    float mis_rate;
    mis_rate = (float)mis_preds / (float)total_preds * 100;
    mis_rate = roundf(mis_rate * 100);

    cout << "OUTPUT" << endl;
    cout << "number of predictions:\t" << total_preds << endl;
    cout << "number of mispredictions:\t" << mis_preds << endl;
    cout << "misprediction rate:\t" << fixed << setprecision(2) << mis_rate / 100 << "%" << endl;
    
    cout << "FINAL CHOOSER CONTENTS" << endl;

    for (int i = 0; i < tb.size(); i++)
        cout << i << "\t" << tb[i] << endl;
    
    cout << "FINAL GSHARE CONTENTS" << endl;

    for (int i = 0; i < g_tb.size(); i++)
        cout << i << "\t" << g_tb[i] << endl;

    cout << "FINAL BIMODAL CONTENTS" << endl;

    for (int i = 0; i < b_tb.size(); i++)
        cout << i << "\t" << b_tb[i] << endl;
    
}