#include "ui.h"

Ui::Ui(/* args */)
{
}

Ui::~Ui()
{
}

/**
 * ��ʾ���˵�
*/
void Ui::showMainMenu()
{
    cout << "ϵͳ���ܣ�" << endl;
    cout << "1.�½���ϵ��" << endl;
    cout << "2.ɾ����ϵ��" << endl;
    cout << "3.�޸���Ϣ" << endl;
    cout << "4.��ѯ" << endl;
    cout << "5.���" << endl;
    cout << "6.���ֻ����Ƶ���" << endl;
    cout << "7.�ӿ����Ƶ��ֻ�" << endl;
    cout << "��ѡ������ţ�";
}

/**
 * ��ʾ����û��˵�
*/
void Ui::showAddUserMenu(int i)
{
    switch (i)
    {
    case 1:
        cout << "��ѡ��洢��ʽ��" << endl;
        cout << "1.�ֻ��洢" << endl;
        cout << "2.�ֻ����洢" << endl;
        cout << "��ѡ��洢��ʽ��ţ�";
        break;
    case 2:
        cout << "��������ϵ����Ϣ��" << endl;
        cout << "��ʽ������ ���� �绰���� QQ���м�ո���� " << endl;
        cout << "�磺Tom Beijing 13511112222 123456987" << endl;
        cout << "��������Ϣ��";
        break;
    default:
        break;
    }
}