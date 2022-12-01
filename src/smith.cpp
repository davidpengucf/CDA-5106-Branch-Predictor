#include "../include/smith.h"

smith::smith() {}

smith::smith(int bit_num)
{
    cnt = pow(2, bit_num - 1);
    cnt_max = 2 * cnt;
    cnt_max -= 1;
}

void smith::pred_results(int result)
{
    total_pred += 1;

    int predt = 0;

    if (cnt > cnt_max / 2)
        predt = 1; // taken

    else
        predt = 0; // not-taken

    if (predt != result)
        mis_pred += 1;

    if (result == 1)
    {
        if (cnt + 1 <= cnt_max)
            cnt += 1;
        else
            cnt = cnt_max;
    }
    else
    {
        if (cnt - 1 >= 0)
            cnt -= 1;
        else
            cnt = 0;
    }
}

void smith::print_results()
{
    float mis_rate;
    mis_rate = (float)mis_pred / (float)total_pred * 100;
    mis_rate = roundf(mis_rate * 100);

    cout << "OUTPUT" << endl;
    cout << "number of predictions:\t" << total_pred << endl;
    cout << "number of mispredictions:\t" << mis_pred << endl;
    cout << "misprediction rate:\t" << fixed << setprecision(2) << mis_rate / 100 << "%" << endl;
    cout << "FINAL COUNTER CONTENT:\t" << cnt << endl;
}
