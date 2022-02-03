#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sorts.h"

#include <QMainWindow>
#include <QLine>
#include <QRandomGenerator>
#include <QFrame>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QThread>
#include <QSizePolicy>
#include <QTimer>
#include <QCoreApplication>
#include <QTime>
#include <QDesktopServices>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //Visual functions
    MainWindow(QWidget *parent = nullptr);
    void SetupVisuals();
    void ShowAdditionalInfoElem();
    void genArr();
    void printArr();
    void SwapAndHighlight(int idx1, int idx2);
    void Highlight(int idx, bool repaint);
    void Highlight(int idx1, int idx2, bool repaint);
    void Unhighlight(int idx1, int idx2, bool repaint);
    void Unhighlight(int idx, bool repaint);
    void SwapInLay(int idx1, int idx2, bool repaint);
    void ClearLay();
    void LoadLay();
    void RefreshLayout();
    void updateSliderVal();
    bool FFCheck();
    ~MainWindow();

    //Accessory functions
    void Delay(int64_t ms);
    void MergeSubArrs(const int left, const int mid, const int right);
    int QuickSortPartition(const int begin, const int end);
    void Heapify(int n, int i);
    void BitonicMerge(int begin, int cnt, int dir);
    void BitonicSwap(int i, int j, int dir);
    void TimInsertionSort(int l, int r);
    //void TimMerge(int l, int m, int r);

private slots:

    //Sort functions
    void BubbleSort();
    void MergeSort(const int start, const int end);
    void QuickSort(const int begin, const int end);
    void InsertionSort();
    void SelectionSort();
    void HeapSort();
    void ShellSort();
    void SlowSort(int i, int j);
    void BitonicSort(int begin, int cnt, int dir);
    void TimSort(const int TimConst);

    void LoadExactLayItem(QFrame* frame, int idx);

    void on_newArrButton_clicked();

    void on_BubbleSort_clicked();

    void on_MergeSort_clicked();

    void on_QuickSort_clicked();

    void on_InsertionSort_clicked();

    void on_SelectionSort_clicked();

    void on_FFButton_clicked();

    void on_HeapSort_clicked();

    void on_ShellSort_clicked();

    void on_SlowSort_clicked();

    void on_BitonicSort_clicked();

    void on_TimSort_clicked();

private:
    Ui::MainWindow *ui;
    QList<ArrLine*> arr;
    const int arrSize = 64;
    QGridLayout* Lay = nullptr;
    int DelayTime = 10;
    bool FFActivated = false;
};
#endif // MAINWINDOW_H
