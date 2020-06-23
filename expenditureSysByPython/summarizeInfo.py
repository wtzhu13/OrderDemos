"""
DATE: 202006
E-MAIL: wtzhu_13@163.com

AUTHOR: Fred
VERSION:
    更多项目内容关注：https://blog.csdn.net/wtzhu_13
"""

"""
print("收⼊类：a1-⽣活费，a2-奖学金，a3-兼职")
print("⽀出类：b1-学习⽤品，b2-通信费用，b3-饮食费用，b4-娱乐费用")
"""


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


if __name__ == '__main__':
    si = SummarizeInfo()
    si.get_month()
    si.show_account_detail("accountLog.txt")
