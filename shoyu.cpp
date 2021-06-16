#include "shoyu.h"
#include "ui_shoyu.h"

#include <QDir>
#include <QFileDialog>

#include "decrypt.h"
#include "encrypt.h"
#include "key.h"

#define EXTENSION ".crypt"

shoyu::shoyu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::shoyu)
{
    ui->setupUi(this);
}

shoyu::~shoyu()
{
    delete ui;
}


void shoyu::on_iniciarButton_clicked()
{
    QString fileName;
    QString ext = EXTENSION;
    fileName = QFileDialog::getOpenFileName(this, tr("Abra o arquivo"));

    QString pass = ui->password->text();
    unsigned char *key;
    QByteArray passBytesArray = pass.toUtf8();

    key = generateKeyFromString(passBytesArray.data());

    if (ui->criptografa->isChecked()) {
        std::string sourceFile = fileName.toStdString();
        std::string targetFile = fileName.append(ext).toStdString();

        encrypt(targetFile.c_str(), sourceFile.c_str(), key);
    }
    else if (ui->desincriptografa->isChecked()) {
        std::string sourceFile = fileName.toStdString();

        fileName.chop(ext.size());
        std::string targetFile = fileName.toStdString();

        decrypt(targetFile.c_str(), sourceFile.c_str(), key);
    }
    else {
        ui->erro->setText("Necessário escolher uma alternativa");
    }
}

