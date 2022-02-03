#include "sorts.h"

void MainWindow::BitonicSort(int begin, int cnt, int dir){
    if(cnt > 1){
        int k = cnt / 2;
        BitonicSort(begin, k, 1);
        BitonicSort(begin + k, k, 0);
        BitonicMerge(begin, cnt, dir);
    }

    if(begin == 0 && cnt == arrSize){
        RefreshLayout();
    }
}

void MainWindow::BitonicMerge(int begin, int cnt, int dir){
    if(cnt > 1){
        int k = cnt / 2;
        for(int i = begin; i < begin + k; ++i){
            BitonicSwap(i, i + k, dir);
        }
        BitonicMerge(begin, k, dir);
        BitonicMerge(begin + k, k, dir);
    }
}

void MainWindow::BitonicSwap(int i, int j, int dir){
    if(dir == (arr[i]->getVal() > arr[j]->getVal())){
        SwapInLay(i, j, !FFActivated);
        Highlight(i, j, !FFActivated);
        Delay(DelayTime);
        Unhighlight(i, j, !FFActivated);
    }
}
