#include "sorts.h"

void MainWindow::SlowSort(int i, int j){
    if(i >= j){
        return;
    }

    int m = std::floor((i + j) / 2);
    SlowSort(i, m);
    SlowSort(m + 1, j);

    if(arr[m]->getVal() > arr[j]->getVal()){
        SwapInLay(j, m, !FFActivated);
        Highlight(j, m, FFActivated);
        Delay(DelayTime);
        Unhighlight(j, m, FFActivated);
    }
    SlowSort(i, j - 1);

    if(i == 0 && j == arrSize - 1){
        RefreshLayout();
    }
}
