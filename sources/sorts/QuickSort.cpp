#include "sorts.h"

void MainWindow::QuickSort(const int begin, const int end)
{
    if(begin < end){
        int partIdx = QuickSortPartition(begin, end);

        QuickSort(begin, partIdx - 1);
        QuickSort(partIdx + 1, end);
    }

    if(begin == 0 && end == arrSize - 1) {
        RefreshLayout();
    }
}

int MainWindow::QuickSortPartition(const int begin, const int end){
    int pivot = arr[end]->getVal();
    int i = begin - 1;

    for(int j = begin; j < end; ++j){
        if(arr[j]->getVal() <= pivot){
            ++i;
            SwapInLay(i, j, !FFActivated);
            Highlight(i, j, !FFActivated);
            Delay(DelayTime);
            Unhighlight(i, j, !FFActivated);
        }
    }
    SwapInLay(i + 1, end, !FFActivated);
    Highlight(i + 1, end, !FFActivated);
    Delay(DelayTime);
    Unhighlight(i + 1, end, !FFActivated);
    return i + 1;
}
