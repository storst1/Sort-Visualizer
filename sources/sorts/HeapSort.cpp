#include "sorts.h"

void MainWindow::HeapSort(){
    for(int i = arrSize / 2 - 1; i > -1; --i){
        Heapify(arrSize, i);
    }

    for(int i = arrSize - 1; i > -1; --i){
        SwapInLay(0, i, !FFActivated);
        Highlight(0, i, !FFActivated);
        Delay(DelayTime);
        Unhighlight(0, i, !FFActivated);
        Heapify(i, 0);
    }

    RefreshLayout();
}

void MainWindow::Heapify(int n, int i){
    int lar = i;
    int l = i * 2 + 1;
    int r = l + 1;
    if(l < n && arr[l]->getVal() > arr[lar]->getVal()){
        lar = l;
    }

    if(r < n && arr[r]->getVal() > arr[lar]->getVal()){
        lar = r;
    }

    if(lar != i){
        SwapInLay(i, lar, !FFActivated);
        Highlight(i, lar, !FFActivated);
        Delay(DelayTime);
        Unhighlight(i, lar, !FFActivated);
        Heapify(n, lar);
    }
}
