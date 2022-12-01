#include <fstream>
#include <string>
#include "include/smith.h"
#include "include/bimodal.h"
#include "include/gshare.h"
#include "include/hybrid.h"

int main(int argc, char *argv[])
{
    string type = argv[1];
    string path;

    smith smith_predictor;
    if (type == "smith")
    {
        int cnt_bit = stoi(argv[2]);
        path = argv[3];
        smith_predictor = smith(cnt_bit);
    }

    bimodal bimodal_predictor;
    if (type == "bimodal")
    {
        int pc_bit = stoi(argv[2]);
        path = argv[3];
        bimodal_predictor = bimodal(pc_bit);
    }

    gshare gshare_predictor;
    if (type == "gshare")
    {
        int pc_bit = stoi(argv[2]);
        int bhr_bit = stoi(argv[3]);
        path = argv[4];
        gshare_predictor = gshare(pc_bit, bhr_bit);
    }

    hybrid hybrid_predictor;
    if (type == "hybrid")
    {
        int ch_bit = stoi(argv[2]);
        int g_bit = stoi(argv[3]);
        int bhr_bit = stoi(argv[4]);
        int b_bit = stoi(argv[5]);
        path = argv[6];

        hybrid_predictor = hybrid(ch_bit, g_bit, bhr_bit, b_bit);
    }

    cout << "COMMAND" << endl;

    for (int i = 0; i < argc - 1; i++)
    {
        cout << argv[i] << " ";
    }

    cout << argv[argc - 1] << endl;

    fstream file;

    file.open(path, std::ios::in);

    if (file.is_open())
    {
        int sign;
        string file_line;
        string adr;
        string result;

        while (file >> adr >> result)
        {
            if (result == "t")
                sign = 1;
            else
                sign = 0;

            if (type == "smith")
                smith_predictor.pred_results(sign);

            if (type == "bimodal")
                bimodal_predictor.pred_results(stoi(adr, nullptr, 16), sign);

            if (type == "gshare")
                gshare_predictor.pred_results(stoi(adr, nullptr, 16), sign);

            if (type == "hybrid")
                hybrid_predictor.pred_results(stoi(adr, nullptr, 16), sign);
        }

        if (type == "smith")
            smith_predictor.print_results();

        if (type == "bimodal")
            bimodal_predictor.print_results();

        if (type == "gshare")
            gshare_predictor.print_results();

        if (type == "hybrid")
            hybrid_predictor.print_results();
    }

    return 0;
}