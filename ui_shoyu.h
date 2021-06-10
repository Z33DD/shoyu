/********************************************************************************
** Form generated from reading UI file 'shoyu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOYU_H
#define UI_SHOYU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shoyu
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *password;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *criptografa;
    QRadioButton *desincriptografa;
    QPushButton *iniciarButton;
    QLabel *erro;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *shoyu)
    {
        if (shoyu->objectName().isEmpty())
            shoyu->setObjectName(QString::fromUtf8("shoyu"));
        shoyu->resize(296, 197);
        centralwidget = new QWidget(shoyu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 271, 68));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        password = new QLineEdit(layoutWidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(password);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        criptografa = new QRadioButton(layoutWidget);
        criptografa->setObjectName(QString::fromUtf8("criptografa"));

        horizontalLayout_2->addWidget(criptografa);

        desincriptografa = new QRadioButton(layoutWidget);
        desincriptografa->setObjectName(QString::fromUtf8("desincriptografa"));

        horizontalLayout_2->addWidget(desincriptografa);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        iniciarButton = new QPushButton(centralwidget);
        iniciarButton->setObjectName(QString::fromUtf8("iniciarButton"));
        iniciarButton->setGeometry(QRect(100, 110, 80, 30));
        erro = new QLabel(centralwidget);
        erro->setObjectName(QString::fromUtf8("erro"));
        erro->setGeometry(QRect(110, 90, 56, 17));
        shoyu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(shoyu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 296, 27));
        shoyu->setMenuBar(menubar);
        statusbar = new QStatusBar(shoyu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        shoyu->setStatusBar(statusbar);

        retranslateUi(shoyu);

        QMetaObject::connectSlotsByName(shoyu);
    } // setupUi

    void retranslateUi(QMainWindow *shoyu)
    {
        shoyu->setWindowTitle(QCoreApplication::translate("shoyu", "shoyu", nullptr));
        password->setText(QString());
        password->setPlaceholderText(QCoreApplication::translate("shoyu", "password", nullptr));
        criptografa->setText(QCoreApplication::translate("shoyu", "Criptografar", nullptr));
        desincriptografa->setText(QCoreApplication::translate("shoyu", "Desincriptografar", nullptr));
        iniciarButton->setText(QCoreApplication::translate("shoyu", "Shoyu!", nullptr));
        erro->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class shoyu: public Ui_shoyu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOYU_H
