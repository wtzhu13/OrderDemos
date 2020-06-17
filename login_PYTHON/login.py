# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'login.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(448, 262)
        MainWindow.setMinimumSize(QtCore.QSize(448, 262))
        MainWindow.setMaximumSize(QtCore.QSize(448, 262))
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.pushButton_register = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_register.setGeometry(QtCore.QRect(120, 180, 75, 23))
        self.pushButton_register.setObjectName("pushButton_register")
        self.pushButton_login = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_login.setGeometry(QtCore.QRect(240, 180, 75, 23))
        self.pushButton_login.setObjectName("pushButton_login")
        self.lineEdit_userName = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_userName.setGeometry(QtCore.QRect(200, 70, 113, 20))
        self.lineEdit_userName.setObjectName("lineEdit_userName")
        self.lineEdit_pwd = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_pwd.setGeometry(QtCore.QRect(200, 120, 113, 20))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.lineEdit_pwd.sizePolicy().hasHeightForWidth())
        self.lineEdit_pwd.setSizePolicy(sizePolicy)
        self.lineEdit_pwd.setEchoMode(QtWidgets.QLineEdit.Password)
        self.lineEdit_pwd.setObjectName("lineEdit_pwd")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(140, 70, 54, 12))
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(140, 130, 54, 12))
        self.label_2.setObjectName("label_2")
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.pushButton_register.setText(_translate("MainWindow", "注册"))
        self.pushButton_login.setText(_translate("MainWindow", "登录"))
        self.label.setText(_translate("MainWindow", "用户名"))
        self.label_2.setText(_translate("MainWindow", "密  码"))

