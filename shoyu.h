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
    void on_Iniciar_clicked();

    void on_unidades_textActivated(const QString &arg1);

    void on_pastas_doubleClicked(const QModelIndex &index);

    void on_pastas_currentTextChanged(const QString &currentText);

private:
    Ui::shoyu *ui;
};
#endif // SHOYU_H
