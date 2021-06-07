#include "shoyu.h"
#include "ui_shoyu.h"
#include <QDir>

shoyu::shoyu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::shoyu)
{
    ui->setupUi(this);

    QDir unidades;
    foreach(QFileInfo qfi, unidades.drives()) {
        ui->unidades->addItem(qfi.absoluteFilePath());
    }
}

shoyu::~shoyu()
{
    delete ui;
}


void shoyu::on_Iniciar_clicked()
{
    QString caminho = ui->caminho->text().sliced(7);
    QString pass = ui->password->text();
    if (ui->criptografa->isChecked()) {
        bool criptografa = true;
    }
    else if (ui->desincriptografa->isChecked()) {
        bool desincriptografa = false;
    }
    else {
        ui->erro->setText("Necessário escolher uma alternativa");
    }
}


void shoyu::on_unidades_textActivated(const QString &arg1)
{
    ui->pastas->clear();
    QDir pastas(arg1);
    foreach(QFileInfo qfi, pastas.entryInfoList()) {
        if(qfi.isDir()) {
            ui->pastas->addItem("Pasta: " + qfi.absoluteFilePath());
        } else if(qfi.isFile()) {
            ui->pastas->addItem("Arquivo: " + qfi.absoluteFilePath());
        }
    }
}

void shoyu::on_pastas_doubleClicked(const QModelIndex &index)
{
    QString caminho = ui->caminho->text().sliced(7);
    ui->pastas->clear();
    QDir pastas(caminho);
    foreach(QFileInfo qfi, pastas.entryInfoList()) {
        if(qfi.isDir()) {
            ui->pastas->addItem("Pasta: " + qfi.absoluteFilePath());
        } else if(qfi.isFile()) {
            ui->pastas->addItem("Arquivo: " + qfi.absoluteFilePath());
        }
    }
}


void shoyu::on_pastas_currentTextChanged(const QString &currentText)
{
    ui->caminho->setText(currentText);
}

