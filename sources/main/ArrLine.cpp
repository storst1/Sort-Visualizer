#include "ArrLine.h"

ArrLine::~ArrLine()
{
    delete line;
}

void ArrLine::setRandVal()
{
    val = QRandomGenerator::global()->bounded(30, 500);
}

void ArrLine::setupLine()
{
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    line->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    line->setFixedWidth(14);
    line->setFixedHeight(val);
    line->setMidLineWidth(14);
    paintLine(QColor(180, 14, 211));
}

void ArrLine::updateLine()
{
    line->setFixedHeight(val);
}

void ArrLine::paintLine(QColor color)
{
    QPalette p;
    p.setColor(QPalette::Mid, color);
    line->setPalette(p);
}
