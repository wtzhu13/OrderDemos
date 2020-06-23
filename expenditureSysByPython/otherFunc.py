"""
DATE: 202006
E-MAIL: wtzhu_13@163.com

AUTHOR: Fred
VERSION:
    更多项目内容关注：https://blog.csdn.net/wtzhu_13
"""
import os


class OtherFunc:
    def __init__(self):
        # 查询到的内容存放的列表
        self.query_list = []
        # 记录相关项目的总金额
        self.total_money = 0

    def query_info(self):
        """

        :return:
        """
        self.show_query_menu()
        choice = input("请输入选项编号：")
        if choice == "1":
            self.query_by_big_money("accountLog.txt")
        elif choice == "2":
            self.query_by_class("accountLog.txt")

    def show_query_menu(self):
        """

        :return:
        """
        print("请选择查询方式：")
        print("1.大于指定金额的费用明细")
        print("2.指定类别明细")

    def query_by_big_money(self, file_path):
        """
        query detail logs by money
        :param file_path:
        :return:
        """
        money_flag = input("请输入金额：")
        os.system("clear")
        with open(file_path, "r") as f:
            info_all = f.readlines()
            print("收⼊类：a1-⽣活费，a2-奖学金，a3-兼职")
            print("⽀出类：b1-学习⽤品，b2-通信费用，b3-饮食费用，b4-娱乐费用")
            # 遍历内容，对每一行内容进行处理
            for info in info_all:
                money = info.split(",")[2]
                if float(money) > float(money_flag):
                    print(info.strip())
                    self.query_list.append(info.strip())
        self.statistics()
        print("大于金额{0}元的总消费为{1}".format(money_flag, self.total_money))
        wait = input("请输入任意键退出...")
        os.system("clear")

    def query_by_class(self, file_path):
        """
        query detail logs by class
        :return:
        """
        print("收⼊类：a1-⽣活费，a2-奖学金，a3-兼职")
        print("⽀出类：b1-学习⽤品，b2-通信费用，b3-饮食费用，b4-娱乐费用")
        class_info = input("请输入类别：")
        with open(file_path, "r") as f:
            info_all = f.readlines()
            # 遍历内容，对每一行内容进行处理
            for info in info_all:
                if class_info == info.split(",")[0]:
                    print(info.strip())
                    self.query_list.append(info.strip())
        self.statistics()
        self.show_statistics_of_class(class_info)

    def statistics(self):
        """
        汇总金额
        :return:
        """
        for info in self.query_list:
            # 去除每条记录的费用然后累加
            money = info.split(",")[2]
            self.total_money += float(money)

    def show_statistics_of_class(self, class_flag):
        """

        :return:
        """
        if class_flag == "a1":
            print("{0}的总额为：{1}".format("生活费", self.total_money))
        elif class_flag == "a2":
            print("{0}的总额为：{1}".format("奖学金", self.total_money))
        elif class_flag == "a3":
            print("{0}的总额为：{1}".format("兼职", self.total_money))
        elif class_flag == "b1":
            print("{0}的总额为：{1}".format("学习用品", self.total_money))
        elif class_flag == "b2":
            print("{0}的总额为：{1}".format("通信费用", self.total_money))
        elif class_flag == "b3":
            print("{0}的总额为：{1}".format("饮食费用", self.total_money))
        elif class_flag == "b4":
            print("{0}的总额为：{1}".format("兼职", self.total_money))
        input("请输入任意键退出...")
        os.system("clear")


if __name__ == '__main__':
    other = OtherFunc()
    other.query_info()
