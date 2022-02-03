#ifndef ARRLINE_H
#define ARRLINE_H

#include <QPair>
#include <QFrame>
#include <QPalette>
#include <QColor>
#include <QRandomGenerator>
#include <QWidget>

class ArrLine{
private:
    int val;
    QFrame* line = new QFrame();
public:
    ArrLine(){};
    ArrLine(int val):val(val){};
    ~ArrLine();
    void setRandVal();
    void setupLine();
    void updateLine();
    QFrame* getLine(){ return line; };
    int getVal() const { return val; };
    void paintLine(QColor color);
    bool operator< (const ArrLine& al){
        return getVal() < al.getVal();
    }
};

#endif // ARRLINE_H
