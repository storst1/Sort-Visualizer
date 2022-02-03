#include "sorts.h"

void MainWindow::BubbleSort(){
    for(int i = 0; i < arrSize - 1; ++i){
        Highlight(i, !FFActivated);
        for(int j = 0; j < arrSize - i - 1; ++j){
            if(arr[j]->getVal() > arr[j + 1]->getVal()){
                SwapInLay(j + 1, j, !FFActivated);
                Highlight(j, j + 1, !FFActivated);
                Delay(DelayTime);
                Unhighlight(j, j + 1, !FFActivated);
            }
        }
        Unhighlight(i, !FFActivated);
    }

    RefreshLayout();
}
