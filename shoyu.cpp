#include "shoyu.h"
#include "ui_shoyu.h"

#include <QDir>
#include <QFileDialog>
#include <sodium.h>
#include <stdio.h>

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

    unsigned char key[crypto_secretstream_xchacha20poly1305_KEYBYTES];

    FILE *keyfile;

    if (ui->criptografa->isChecked()) {
        crypto_secretstream_xchacha20poly1305_keygen(key);

        std::string sourceFile = fileName.toStdString();
        std::string targetFile = fileName.append(ext).toStdString();

        keyfile = fopen("key", "wb");
        fwrite(key, sizeof(unsigned char), crypto_secretstream_xchacha20poly1305_KEYBYTES, keyfile);
        fclose(keyfile);

        encrypt(targetFile.c_str(), sourceFile.c_str(), key);
    }
    else if (ui->desincriptografa->isChecked()) {
        keyfile = fopen("key", "r");

        fread(key, crypto_secretstream_xchacha20poly1305_KEYBYTES +1, 1, keyfile);
        fclose(keyfile);
        printf("key: %s\n", key);

        std::string sourceFile = fileName.toStdString();

        fileName.chop(ext.size());
        std::string targetFile = fileName.toStdString();

        decrypt(targetFile.c_str(), sourceFile.c_str(), key);
    }
    else {
        ui->erro->setText("Necessário escolher uma alternativa");
    }
}

