#include "sorts.h"

void MainWindow::MergeSort(const int begin, const int end){
    if(begin >= end){
        return;
    }

    int mid = begin + (end - begin) / 2;
    MergeSort(begin, mid);
    MergeSort(mid + 1, end);
    MergeSubArrs(begin, mid, end);

    if(begin == 0 && end == arrSize - 1) {
        RefreshLayout();
    }
}

void MainWindow::MergeSubArrs(const int left, const int mid, const int right){
    QList<ArrLine*> leftArr = arr.mid(left, mid - left + 1);
    QList<ArrLine*> rightArr = arr.mid(mid + 1, right - mid);

    int i = 0, j = 0;
    int mainIdx = left;
    while(i < mid - left + 1 && j < right - mid){
        if(leftArr[i]->getVal() <= rightArr[j]->getVal()){
            arr[mainIdx] = leftArr[i];
            ++i;
        }
        else{
            arr[mainIdx] = rightArr[j];
            ++j;
        }
        if(mainIdx % 5 == 0){
            Highlight(mainIdx, !FFActivated);
            Delay(DelayTime);
            Unhighlight(mainIdx, !FFActivated);
        }
        ++mainIdx;
    }

    while(i < mid - left + 1){
        arr[mainIdx] = leftArr[i];
        ++i;
        if(mainIdx % 5 == 0){
            Highlight(mainIdx, !FFActivated);
            Delay(DelayTime);
            Unhighlight(mainIdx, !FFActivated);
        }
        ++mainIdx;
    }

    while(j < right - mid){
        arr[mainIdx] = rightArr[j];
        ++j;
        if(mainIdx % 5 == 0){
            Highlight(mainIdx, !FFActivated);
            Delay(DelayTime);
            Unhighlight(mainIdx, !FFActivated);
        }
        ++mainIdx;
    }
}
