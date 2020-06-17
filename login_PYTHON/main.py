import login
import menuUI
import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QMessageBox
from functools import partial


class MyLogin(QMainWindow):
    """
    登录类
    """
    def __init__(self):
        super().__init__()
        # 创建菜单对象
        self.menu = Menu()
        # 创建登录界面UI对象
        self.logui = login.Ui_MainWindow()
        self.logui.setupUi(self)
        # 按键的信号槽连接
        self.logui.pushButton_login.clicked.connect(self.logFunc)

    def logFunc(self):
        """
        按键的参函数
        :return:
        """
        # 从页面获取用户名和密码
        userNameIn = self.logui.lineEdit_userName.text()
        pwdIn = self.logui.lineEdit_pwd.text()
        # 从存贮用户名和密码的文件读取用户名和密码
        with open("userInfo.txt", "r") as f:
            infoList = f.readlines()
            for info in infoList:
                userName = info.split(",")[0]
                pwd = info.split(",")[1].strip()
                # 如果想户名和密码都相同则登录成功，否则登录失败
                if pwd == pwdIn and userNameIn == userName:
                    print("登录成功！")
                    self.hide()
                    self.menu.show()
                    return 1
            box = QMessageBox(QMessageBox.Information, '登录失败', '密码或用户名错误')
            yes = box.addButton('Ok', QMessageBox.YesRole)
            box.show()
            if box.exec() == 0:
                return 0


class Menu(QMainWindow):
    """
    菜单类
    """
    def __init__(self):
        super().__init__()
        # UI界面对象
        self.menuUi = menuUI.Ui_Form()
        self.menuUi.setupUi(self)
        # 连接信号槽
        self.menuUi.pushButton.clicked.connect(lambda: self.printHello(1))

    def printHello(self, i):
        """
        按键的槽函数
        :param i:
        :return:
        """
        print("hello", i)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    log = MyLogin()
    log.show()
    app.exec_()

