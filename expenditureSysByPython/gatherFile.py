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


class SummarizeInfo:
    def __init__(self):
        self.income_list = []
        self.expend_list = []
        self.alimony = 0
        self.scholarship = 0
        self.part_time_job = 0
        self.school_supplies = 0
        self.communication = 0
        self.diet = 0
        self.entertainment = 0

    def get_month(self):
        """
        get month
        :return:
        """
        self.month = input("请输⼊对收⽀类别数据进⾏汇总的⽉份(如：2020-1)：")

    def show_total_info(self):
        """
        show otal info of the month
        :return:
        """
        # 获取各个类别的总金额
        self.get_month_total_info("accountLog.txt")
        # 打印相关内容
        print("收入 生活费 " + str(self.alimony))
        print("收入 奖学金 " + str(self.scholarship))
        print("收入 兼职 " + str(self.part_time_job))
        print("支出 学习用品 " + str(self.school_supplies))
        print("支出 通信费用 " + str(self.communication))
        print("支出 饮食费用 " + str(self.diet))
        print("支出 娱乐费用 " + str(self.entertainment))
        print("{0}总收入:{1},总支出:{2}".format(self.month,
                                          self.alimony+self.scholarship+self.part_time_job,
                                          self.school_supplies+self.communication+self.diet+self.entertainment))
        detail_flag = input("是否输出该月各笔明细，（y为输出，其他为不输出）：")
        # 获取是否输出明细
        if detail_flag == "y":
            self.show_account_detail("accountLog.txt")
        else:
            return

    def get_month_total_info(self, file_path):
        """
        get info of the month
        :return:
        """
        with open(file_path, "r") as f:
            # 读取文件内容
            info_all = f.readlines()
            # 遍历内容，对每一行内容进行处理
            for info in info_all:
                # 拆分每行内容，获取各个参数
                info_list = info.split(",")
                category = info_list[0]
                date = info_list[1][0:6]
                detail_name = info_list[3].strip()[2:]
                money = info_list[2]
                # 判断类别，并将相同的金额相加
                if date == self.month and category[0] == "a":
                    if category[1] == "1":
                        self.alimony += float(money)
                    elif category[1] == "2":
                        self.scholarship += float(money)
                    elif category[1] == "3":
                        self.part_time_job += float(money)
                elif date == self.month and category[0] == "b":
                    if category[1] == "1":
                        self.school_supplies += float(money)
                    elif category[1] == "2":
                        self.communication += float(money)
                    elif category[1] == "3":
                        self.diet += float(money)
                    elif category[1] == "4":
                        self.entertainment += float(money)

    def show_account_detail(self, file_path):
        """
        show account details
        :return:
        """
        with open(file_path, "r") as f:
            # 读取文件内容
            info_all = f.readlines()
            # 遍历内容，对每一行内容进行处理
            for info in info_all:
                # 拆分每行内容，获取各个参数
                info_list = info.split(",")
                category = info_list[0]
                date = info_list[1]
                remark = info_list[3].strip()
                money = info_list[2]
                # 判断类别，并将相同的金额相加
                if date[0:6] == self.month and category[0] == "a":
                    if category[1] == "1":
                        print("生活费 收入 " + date + " " + money + " " + remark)
                    elif category[1] == "2":
                        print("奖学金 收入 " + date + " " + money + " " + remark)
                    elif category[1] == "3":
                        print("兼职 收入 " + date + " " + money + " " + remark)
                elif date[0:6] == self.month and category[0] == "b":
                    if category[1] == "1":
                        print("学习用品 支出 " + date + " " + money + " " + remark)
                    elif category[1] == "2":
                        print("通信费用 支出 " + date + " " + money + " " + remark)
                    elif category[1] == "3":
                        print("饮食费用 支出 " + date + " " + money + " " + remark)
                    elif category[1] == "4":
                        print("娱乐费用 支出 " + date + " " + money + " " + remark)


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
