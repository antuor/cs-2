//
// Created by nimerkuloff on 7/04/18.
//

#include "ThirdFunction.h"

/*
 * Экспериментальная трудоемкость (ТЭ) оценивается как количество сравнений элементов массива в процессе
 * сортировки и далее сравнивается с теоретическими оценками
 *  Т1 = num^2
 *  Т2 = num · log2 num.
 *  ТЭ / Т1
 *  ТЭ / Т2
 * Повторите оценки для следующих значений num: 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096.  
 */
void ExportResults() {

    string results= "results";

    ofstream resultsOutput;
    resultsOutput.open(results);


    //Файл не создан (не открыт) - возвращаемся в место вызова функции
    if (!resultsOutput.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    string  tab ="\t\t\t";
    resultsOutput<< "num" << tab<<"\t"<< "ТЭ" << tab << "Т1" << tab << "T2" << tab << "ТЭ / Т1" << tab << "ТЭ / Т2" << endl;

    for (int num = 8; num <= 4096; num = num * 2) {
        string sNum= to_string(num);
        string new_filename= "dataset_for_num_"+sNum;

        GenerateDataset(new_filename,num);
        int T_exp= SortDataset(new_filename);
        int T1 = num * num;
        double T2 = num * log2(num);
        double T3 = T_exp / T1;
        double T4 = T_exp / T2;
        resultsOutput << num << tab;
        resultsOutput << T_exp << tab;
        resultsOutput << T1 << tab;
        resultsOutput << T2 << tab;
        resultsOutput << T3 << tab;
        resultsOutput << T4 << endl;
    }
    resultsOutput.close();
}