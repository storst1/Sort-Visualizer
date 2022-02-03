#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SetupVisuals();
}

void MainWindow::SetupVisuals()
{
    ui->ComplexityLabel->hide();
    ui->ComplexityValue->hide();
    ui->MemoryComplexityLabel->hide();
    ui->MemoryComplexityValue->hide();
    ui->WorstComplexityLabel->hide();
    ui->WorstComplexityValue->hide();
    ui->SpeedSlider->setMinimum(1);
    ui->SpeedSlider->setMaximum(100);
    ui->SpeedSlider->setSliderPosition(100 - DelayTime);
    ui->SpeedSlider->hide();
    ui->Slow->hide();
    ui->Fast->hide();
    ui->Sort->hide();
    ui->SortName->hide();
    ui->WikipediaButton->hide();
    genArr();
    printArr();
}

void MainWindow::ShowAdditionalInfoElem()
{
    ui->ComplexityLabel->show();
    ui->ComplexityValue->show();
    ui->MemoryComplexityLabel->show();
    ui->MemoryComplexityValue->show();
    ui->WorstComplexityLabel->show();
    ui->WorstComplexityValue->show();
    ui->Slow->show();
    ui->Fast->show();
    ui->Sort->show();
    ui->SortName->show();
    ui->SpeedSlider->show();
    ui->WikipediaButton->show();
}

void MainWindow::genArr()
{
    qDeleteAll(arr);
    arr.clear();
    for(int i = 0; i < arrSize; ++i){
        arr.push_back(new ArrLine());
        arr[i]->setRandVal();
        arr[i]->setupLine();
    }
}

void MainWindow::printArr()
{
    delete Lay;
    Lay = new QGridLayout;
    LoadLay();

    ui->wLay->setLayout(Lay);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newArrButton_clicked()
{
    genArr();
    printArr();
}

void MainWindow::SwapAndHighlight(int idx1, int idx2)
{
    Highlight(idx1, idx2);
    SwapInLay(idx1, idx2, true);
}

void MainWindow::Highlight(int idx, bool repaint)
{
    QColor color(255, 0, 0);
    arr[idx]->paintLine(color);
    if(repaint){
        RefreshLayout();
    }
}

void MainWindow::Highlight(int idx1, int idx2, bool repaint)
{
    QColor color(255, 0, 0);
    arr[idx1]->paintLine(color);
    arr[idx2]->paintLine(color);
    if(repaint){
        RefreshLayout();
    }
}

void MainWindow::Unhighlight(int idx1, int idx2, bool repaint)
{
    QColor color (180, 14, 211);
    arr[idx1]->paintLine(color);
    arr[idx2]->paintLine(color);
    if(repaint){
        RefreshLayout();
    }
}

void MainWindow::Unhighlight(int idx, bool repaint)
{
    QColor color (180, 14, 211);
    arr[idx]->paintLine(color);
    if(repaint){
        RefreshLayout();
    }
}

void MainWindow::SwapInLay(int idx1, int idx2, bool repaint)
{
    if(idx1 == idx2){
        return;
    }
    std::swap(arr[idx1], arr[idx2]);
    if(repaint){
        RefreshLayout();
    }
}

void MainWindow::ClearLay()
{
    while(QLayoutItem* item = Lay->takeAt(0)){
        Lay->removeItem(item);
        delete item;
    }
}

void MainWindow::LoadLay()
{
    for(int i = 0; i < arrSize; ++i){
        LoadExactLayItem(arr[i]->getLine(), i);
    }
    QWidget::repaint();
}

void MainWindow::RefreshLayout()
{
    ClearLay();
    LoadLay();
}

void MainWindow::LoadExactLayItem(QFrame *frame, int idx)
{
    Lay->addWidget(frame, 0, idx, Qt::AlignTop);
    //QWidget::repaint();
}

void MainWindow::Delay(int64_t ms)
{
    if(!ms){
        return;
    }
    QTime dieTime= QTime::currentTime().addMSecs(ms);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::updateSliderVal()
{
    FFActivated = false;
    DelayTime = 101 - ui->SpeedSlider->value();
}

bool MainWindow::FFCheck()
{
    if(FFActivated){
        std::sort(arr.begin(), arr.end());
        return true;
    }
    return false;
}

void MainWindow::on_FFButton_clicked()
{
    DelayTime = 0;
    FFActivated = false;
}

void MainWindow::on_BubbleSort_clicked()
{
    ui->SortName->setText("Bubble Sort");
    disconnect(ui->WikipediaButton, &QPushButton::clicked, this, 0);
    connect(ui->WikipediaButton, &QPushButton::clicked, this, []
    {
        QDesktopServices::openUrl(QUrl("https://en.wikipedia.org/wiki/Bubble_sort"));
    });
    ui->ComplexityValue->setText("O(n^2)");
    ui->WorstComplexityValue->setText("O(n^2)");
    ui->MemoryComplexityValue->setText("O(1)");
    ShowAdditionalInfoElem();
    disconnect(ui->Sort, &QPushButton::clicked, this, 0);
    connect(ui->Sort, &QPushButton::clicked, this, [this]
    {
        updateSliderVal();
        BubbleSort();
    });
}

void MainWindow::on_MergeSort_clicked()
{
    ui->SortName->setText("Merge Sort");
    disconnect(ui->WikipediaButton, &QPushButton::clicked, this, 0);
    connect(ui->WikipediaButton, &QPushButton::clicked, this, []
    {
        QDesktopServices::openUrl(QUrl("https://en.wikipedia.org/wiki/Merge_sort"));
    });
    ui->ComplexityValue->setText("O(n*log(n))");
    ui->WorstComplexityValue->setText("O(n*log(n))");
    ui->MemoryComplexityValue->setText("O(n)");
    ShowAdditionalInfoElem();
    disconnect(ui->Sort, &QPushButton::clicked, this, 0);
    connect(ui->Sort, &QPushButton::clicked, this, [this]
    {
        updateSliderVal();
        MergeSort(0, arrSize - 1);
    });
}

void MainWindow::on_QuickSort_clicked()
{
    ui->SortName->setText("Quick Sort");
    disconnect(ui->WikipediaButton, &QPushButton::clicked, this, 0);
    connect(ui->WikipediaButton, &QPushButton::clicked, this, []
    {
        QDesktopServices::openUrl(QUrl("https://en.wikipedia.org/wiki/Quicksort"));
    });
    ui->ComplexityValue->setText("O(n*log(n))");
    ui->WorstComplexityValue->setText("O(n^2)");
    ui->MemoryComplexityValue->setText("O(log(n))");
    ShowAdditionalInfoElem();
    disconnect(ui->Sort, &QPushButton::clicked, this, 0);
    connect(ui->Sort, &QPushButton::clicked, this, [this]
    {
        updateSliderVal();
        QuickSort(0, arrSize - 1);
    });
}

void MainWindow::on_InsertionSort_clicked()
{
    ui->SortName->setText("Insertion Sort");
    disconnect(ui->WikipediaButton, &QPushButton::clicked, this, 0);
    connect(ui->WikipediaButton, &QPushButton::clicked, this, []
    {
        QDesktopServices::openUrl(QUrl("https://en.wikipedia.org/wiki/Insertion_sort"));
    });
    ui->ComplexityValue->setText("O(n^2)");
    ui->WorstComplexityValue->setText("O(n^2)");
    ui->MemoryComplexityValue->setText("O(1)");
    ShowAdditionalInfoElem();
    disconnect(ui->Sort, &QPushButton::clicked, this, 0);
    connect(ui->Sort, &QPushButton::clicked, this, [this]
    {
        updateSliderVal();
        InsertionSort();
    });
}


void MainWindow::on_SelectionSort_clicked()
{
    ui->SortName->setText("Selection Sort");
    disconnect(ui->WikipediaButton, &QPushButton::clicked, this, 0);
    connect(ui->WikipediaButton, &QPushButton::clicked, this, []
    {
        QDesktopServices::openUrl(QUrl("https://en.wikipedia.org/wiki/Selection_sort"));
    });
    ui->ComplexityValue->setText("O(n^2)");
    ui->WorstComplexityValue->setText("O(n^2)");
    ui->MemoryComplexityValue->setText("O(1)");
    ShowAdditionalInfoElem();
    disconnect(ui->Sort, &QPushButton::clicked, this, 0);
    connect(ui->Sort, &QPushButton::clicked, this, [this]
    {
        updateSliderVal();
        SelectionSort();
    });
}

void MainWindow::on_HeapSort_clicked()
{
    ui->SortName->setText("Heap Sort");
    disconnect(ui->WikipediaButton, &QPushButton::clicked, this, 0);
    connect(ui->WikipediaButton, &QPushButton::clicked, this, []
    {
        QDesktopServices::openUrl(QUrl("https://en.wikipedia.org/wiki/Heapsort"));
    });
    ui->ComplexityValue->setText("O(n*log(n))");
    ui->WorstComplexityValue->setText("O(n*log(n))");
    ui->MemoryComplexityValue->setText("O(1)");
    ShowAdditionalInfoElem();
    disconnect(ui->Sort, &QPushButton::clicked, this, 0);
    connect(ui->Sort, &QPushButton::clicked, this, [this]
    {
        updateSliderVal();
        HeapSort();
    });
}


void MainWindow::on_ShellSort_clicked()
{
    ui->SortName->setText("Shell Sort");
    disconnect(ui->WikipediaButton, &QPushButton::clicked, this, 0);
    connect(ui->WikipediaButton, &QPushButton::clicked, this, []
    {
        QDesktopServices::openUrl(QUrl("https://en.wikipedia.org/wiki/Shellsort"));
    });
    ui->ComplexityValue->setText("O(n^(4/3))");
    ui->WorstComplexityValue->setText("O(n^(3/2))");
    ui->MemoryComplexityValue->setText("O(1)");
    ShowAdditionalInfoElem();
    disconnect(ui->Sort, &QPushButton::clicked, this, 0);
    connect(ui->Sort, &QPushButton::clicked, this, [this]
    {
        updateSliderVal();
        ShellSort();
    });
}
void MainWindow::on_SlowSort_clicked()
{
    ui->SortName->setText("Slow Sort");
    disconnect(ui->WikipediaButton, &QPushButton::clicked, this, 0);
    connect(ui->WikipediaButton, &QPushButton::clicked, this, []
    {
        QDesktopServices::openUrl(QUrl("https://en.wikipedia.org/wiki/Slowsort"));
    });
    ui->ComplexityValue->setText("O(n^(log(n))");
    ui->WorstComplexityValue->setText("O(n^(log(n))");
    ui->MemoryComplexityValue->setText("O(n)");
    ShowAdditionalInfoElem();
    disconnect(ui->Sort, &QPushButton::clicked, this, 0);
    connect(ui->Sort, &QPushButton::clicked, this, [this]
    {
        updateSliderVal();
        SlowSort(0, arrSize - 1);
    });
}


void MainWindow::on_BitonicSort_clicked()
{
    ui->SortName->setText("Bitonic Sort");
    disconnect(ui->WikipediaButton, &QPushButton::clicked, this, 0);
    connect(ui->WikipediaButton, &QPushButton::clicked, this, []
    {
        QDesktopServices::openUrl(QUrl("https://en.wikipedia.org/wiki/Bitonic_sorter"));
    });
    ui->ComplexityValue->setText("O(log^2(n))");
    ui->WorstComplexityValue->setText("O(n*log^2(n))");
    ui->MemoryComplexityValue->setText("O(1)");
    ShowAdditionalInfoElem();
    disconnect(ui->Sort, &QPushButton::clicked, this, 0);
    connect(ui->Sort, &QPushButton::clicked, this, [this]
    {
        updateSliderVal();
        BitonicSort(0, arrSize, 1);
    });
}


void MainWindow::on_TimSort_clicked()
{
    ui->SortName->setText("Timsort");
    disconnect(ui->WikipediaButton, &QPushButton::clicked, this, 0);
    connect(ui->WikipediaButton, &QPushButton::clicked, this, []
    {
        QDesktopServices::openUrl(QUrl("https://en.wikipedia.org/wiki/Timsort"));
    });
    ui->ComplexityValue->setText("O(n*log(n))");
    ui->WorstComplexityValue->setText("O(n*log(n))");
    ui->MemoryComplexityValue->setText("O(n)");
    ShowAdditionalInfoElem();
    disconnect(ui->Sort, &QPushButton::clicked, this, 0);
    connect(ui->Sort, &QPushButton::clicked, this, [this]
    {
        updateSliderVal();
        TimSort(16);
    });
}

