#include "sorts.h"

void MainWindow::TimSort(const int TimConst){
    for(int i = 0; i < arrSize; i += TimConst){
        TimInsertionSort(i, std::min((i + TimConst - 1), (arrSize - 1)));
    }
    for(int s = TimConst; s < arrSize; s *= 2){
        for(int l = 0; l < arrSize; l += 2 * s){
            int mid = l + s - 1;
            int r = std::min(l + 2 * s - 1, arrSize - 1);
            if(mid < r){
                MergeSubArrs(l, mid, r);
            }
        }
    }

    RefreshLayout();
}

void MainWindow::TimInsertionSort(int l, int r){
    for (int i = l + 1; i <= r; i++){
        ArrLine* temp = arr[i];
        int j = i - 1;
        while (j >= l && arr[j]->getVal() > temp->getVal())
        {
            arr[j+1] = arr[j];
            Highlight(j + 1, j, !FFActivated);
            Delay(DelayTime);
            Unhighlight(j + 1, j, !FFActivated);
            j--;
        }
        arr[j+1] = temp;
        Highlight(j + 1, i, !FFActivated);
        Delay(DelayTime);
        Unhighlight(j + 1, i, !FFActivated);
    }
}
