#include "grade_calculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    grade_calculator w;
    w.show(); // ensures our window is shown when program runs

    return a.exec(); //
}
