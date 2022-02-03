#include "sorts.h"

void MainWindow::SelectionSort(){
    for(int i = 0; i < arrSize - 1; ++i){
        int min = 1e9;
        int minIdx = -1;
        for(int j = i; j < arrSize; ++j){
            if(arr[j]->getVal() < min){
                min = arr[j]->getVal();
                minIdx = j;
            }
        }
        if(i != minIdx){
            SwapInLay(i, minIdx, !FFActivated);
            Highlight(i, minIdx, !FFActivated);
            Delay(DelayTime);
            Unhighlight(i, minIdx, !FFActivated);
        }
    }

    RefreshLayout();
}
