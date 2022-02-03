#include "sorts.h"

void MainWindow::InsertionSort()
{
    for(int i = 1; i < arrSize; ++i){
        ArrLine* key = arr[i];
        int j = i - 1;
        while(j > -1 && arr[j]->getVal() > key->getVal()){
            arr[j + 1] = arr[j];
            Highlight(j + 1, j, !FFActivated);
            Delay(15);
            Unhighlight(j + 1, j, !FFActivated);
            --j;
        }
        arr[j + 1] = key;
        Highlight(j + 1, i, !FFActivated);
        Delay(DelayTime);
        Unhighlight(j + 1, i, !FFActivated);
    }

    RefreshLayout();
}
