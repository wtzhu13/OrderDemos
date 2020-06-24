#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    // 从UI界面获取用户输入的内容
    QString textStr = ui->lineEdit->text();
    // 声明两个临时变量做中间变量接受加密内容
    QString textMD5;
    QByteArray str;
    // 利用QT自带的MD5加密算法加密
    str = QCryptographicHash::hash(textStr.toLatin1(), QCryptographicHash::Md5);
    // 数据类型转换
    textMD5.append(str.toHex());
    // 终端打印结果
    qDebug() << textMD5;
    // 将结果放进UI界面显示
    ui->lineEdit_2->setText(textMD5);
}
