#include "shoyu.h"
#include "ui_shoyu.h"

#include <sodium.h>


#include <QDir>
#include <QFileDialog>

#include "decrypt.h"
#include "encrypt.h"
#include "key.h"

shoyu::shoyu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::shoyu)
{
    ui->setupUi(this);
}

shoyu::~shoyu()
{
    sodium_init();
    delete ui;
}


void shoyu::on_iniciarButton_clicked()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("Abra o arquivo"));

    QString pass = ui->password->text();
    unsigned char *key;
    QByteArray passBytesArray = pass.toUtf8();

    key = generateKeyFromString(passBytesArray.data());

    if (ui->criptografa->isChecked()) {
        encrypt(fileName.toStdString().c_str(), fileName.toStdString().c_str(), key);
    }
    else if (ui->desincriptografa->isChecked()) {
        decrypt(fileName.toStdString().c_str(), fileName.toStdString().c_str(), key);
    }
    else {
        ui->erro->setText("Necessário escolher uma alternativa");
    }
}

