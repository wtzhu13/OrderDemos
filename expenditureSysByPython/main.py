"""
DATE: 202006
E-MAIL: wtzhu_13@163.com

AUTHOR: Fred
VERSION:
    更多项目内容关注：https://blog.csdn.net/wtzhu_13
"""
from inputStatement import *
from summarizeInfo import *
from otherFunc import *
import os


def show_main_menu():
    """
    主菜单页面
    :return:
    """
    print("请选择功能：")
    print("1.添加费用项目")
    print("2.按月份汇总")
    print("3.查询")
    print("q.退出系统")
    choice = input("请选择功能编号：")
    os.system("clear")
    if choice == "1":
        input_info = GetInput()
        input_info.show_input_menu()
        input_info.input_account()
    elif choice == "2":
        si = SummarizeInfo()
        si.get_month()
        si.show_total_info()
        back_flag = input("输入任意键返回菜单栏...")
        os.system("clear")
    elif choice == "3":
        other = OtherFunc()
        other.query_info()
    elif choice == "q":
        exit()


if __name__ == '__main__':
    while True:
        show_main_menu()
