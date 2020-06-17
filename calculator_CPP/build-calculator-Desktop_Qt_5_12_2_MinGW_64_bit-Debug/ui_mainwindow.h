/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit_ev1;
    QLineEdit *lineEdit_ev2;
    QLineEdit *lineEdit_res;
    QLabel *label;
    QLineEdit *lineEdit_op;
    QPushButton *pushButton_quit;
    QPushButton *pushButton_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(440, 182);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(440, 182));
        MainWindow->setMaximumSize(QSize(440, 182));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit_ev1 = new QLineEdit(centralwidget);
        lineEdit_ev1->setObjectName(QString::fromUtf8("lineEdit_ev1"));
        lineEdit_ev1->setGeometry(QRect(60, 60, 71, 20));
        lineEdit_ev2 = new QLineEdit(centralwidget);
        lineEdit_ev2->setObjectName(QString::fromUtf8("lineEdit_ev2"));
        lineEdit_ev2->setGeometry(QRect(222, 60, 71, 20));
        lineEdit_res = new QLineEdit(centralwidget);
        lineEdit_res->setObjectName(QString::fromUtf8("lineEdit_res"));
        lineEdit_res->setGeometry(QRect(330, 60, 41, 20));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 60, 21, 16));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"Adobe Arabic\";"));
        lineEdit_op = new QLineEdit(centralwidget);
        lineEdit_op->setObjectName(QString::fromUtf8("lineEdit_op"));
        lineEdit_op->setGeometry(QRect(160, 60, 21, 20));
        pushButton_quit = new QPushButton(centralwidget);
        pushButton_quit->setObjectName(QString::fromUtf8("pushButton_quit"));
        pushButton_quit->setGeometry(QRect(110, 110, 75, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 110, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\256\241\347\256\227\345\231\250", nullptr));
        label->setText(QApplication::translate("MainWindow", "=", nullptr));
        pushButton_quit->setText(QApplication::translate("MainWindow", "\350\256\241\347\256\227", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
