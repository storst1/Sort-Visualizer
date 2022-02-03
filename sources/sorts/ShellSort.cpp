#include "sorts.h"

void MainWindow::ShellSort(){

    QList<int> gapArr = {1750, 701, 301, 132, 57, 23, 10, 4, 1};
    //int BestGapForHundred = 57;
    int idx = 4;
    bool sorted = false;
    while(true){
        sorted = true;
        int st = 0;
        for(int x = gapArr[idx]; x < arrSize; x += gapArr[idx]){
            if(arr[st]->getVal() > arr[x]->getVal()){
                sorted = false;
                SwapInLay(st, x, !FFActivated);
                Highlight(st, x, FFActivated);
                Delay(DelayTime);
                Unhighlight(st, x, FFActivated);
            }
            st = x;
        }
        if(++idx >= 8){
            idx = 8;
        }
        if(sorted && idx == 8){
            break;
        }
    }

    RefreshLayout();

}

//O(n^2) implementation
/*
 * for(int gap = arrSize / 2; gap > 0; gap /= 2){
        for(int i = gap; i < arrSize; ++i){
            ArrLine* tmp = arr[i];
            int j;

            for(j = i; j >= gap && arr[j - gap]->getVal() > tmp->getVal(); j -= gap){
                arr[j] = arr[j - gap];
                Highlight(j, FFActivated);
                Delay(DelayTime);
                Unhighlight(j, FFActivated);
            }

            arr[j] = tmp;
            Highlight(j, FFActivated);
            Delay(DelayTime);
            Unhighlight(j, FFActivated);
        }
    }
 */
