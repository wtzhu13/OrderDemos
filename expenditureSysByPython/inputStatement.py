"""
DATE: 202006
E-MAIL: wtzhu_13@163.com

AUTHOR: Fred
VERSION:
    更多项目内容关注：https://blog.csdn.net/wtzhu_13
"""
import os


class GetInput:

    def __init__(self):
        pass

    def show_input_menu(self):
        """
        show input menu
        :return:
        """
        print("类别编码和类别名称的对应关系如下：")
        print("收⼊类：a1-⽣活费，a2-奖学金，a3-兼职")
        print("⽀出类：b1-学习⽤品，b2-通信费用，b3-饮食费用，b4-娱乐费用")

    def input_account(self):
        """
        get account
        :return:
        """
        print("请输入明细，格式如下：")
        print("a1,2020-1-26,2000.0,1⽉⽣活费")
        while True:
            account_str = input("请输入收支明细,输入q退出：")
            if account_str == "q":
                os.system("clear")
                break
            # 检查输入的格式是否正确
            self.check_input(account_str)
            self.save_to_file("accountLog.txt", account_str)

    def save_to_file(self, file_path, account_str):
        """
        save data to txt file
        :return:
        """
        # 打开文件
        file = open(file_path, "a+")
        # 写入内容
        file.write(account_str + "\n")
        # 关闭文件
        file.flush()

    def check_input(self, input_str):
        """
        check input format
        :return:
        """
        list = input_str.split(",")
        # print(list)


if __name__ == '__main__':
    get_input = GetInput()
    get_input.show_input_menu()
    get_input.input_account()

