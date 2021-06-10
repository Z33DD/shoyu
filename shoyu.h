#ifndef SHOYU_H
#define SHOYU_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class shoyu; }
QT_END_NAMESPACE

class shoyu : public QMainWindow
{
    Q_OBJECT

public:
    shoyu(QWidget *parent = nullptr);
    ~shoyu();

private slots:
    void on_iniciarButton_clicked();

private:
    Ui::shoyu *ui;
};
#endif // SHOYU_H
