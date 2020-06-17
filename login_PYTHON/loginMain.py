import login
import menuUI
import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QMessageBox
from functools import partial


def loginFunc(ui):
    # 从页面获取用户名和密码
    userNameIn = ui.lineEdit_userName.text()
    pwdIn = ui.lineEdit_pwd.text()
    # 从存贮用户名和密码的文件读取用户名和密码
    with open("userInfo.txt", "r") as f:
        infoList = f.readlines()
        for info in infoList:
            userName = info.split(",")[0]
            pwd = info.split(",")[1].strip()
            # 如果想户名和密码都相同则登录成功，否则登录失败
            if pwd == pwdIn and userNameIn == userName:
                print("登录成功！")
                return 1
        box = QMessageBox(QMessageBox.Information, '登录失败', '密码或用户名错误')
        yes = box.addButton('Ok', QMessageBox.YesRole)
        box.show()
        if box.exec() == 0:
            return 0


if __name__ == '__main__':
    app = QApplication(sys.argv)
    MainWindow = QMainWindow()
    ui = login.Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    ui.pushButton_login.clicked.connect(partial(loginFunc, ui))
    sys.exit(app.exec_())

