#define _CRT_SECURE_NO_WARNINGS 1
#include "Word.h"
// �˵�
void menu()
{
    cout << "*****************************************" << endl;
    cout << "    ����1�� ����Ӣ�ģ�ѡ����Ӧ������" << endl;
    cout << "    ����2�� �������ģ�ѡ����Ӧ��Ӣ��" << endl;
    cout << "    ����3�� �������ģ������Ӧ��Ӣ��" << endl;
    cout << "    ����4�� ��ռ�¼" << endl;
    cout << "    ����5�� ��ת��¼��ָ���ĵط�" << endl;
    cout << "    ����6�� �˳�" << endl;
    cout << "*****************************************" << endl;
    cout << endl;
}

int main()
{
    Word word;
    string input;

    while (true)
    {
        menu();
        cout << "��ѡ��:>";
        cin.clear();
        cin >> input;
        if (input.compare("1") == 0)
        {
            system("cls");
            word.ChooseChinses();
        }
        else if (input.compare("2") == 0)
        {
            system("cls");
            word.ChooseEnglish();
        }
        else if (input.compare("3") == 0)
        {
            system("cls");
            word.InputEnglish();
        }
        else if (input.compare("4") == 0)
        {
            word.ClearRecord();
            system("cls");
        }
        else if (input.compare("5") == 0)
        {
            word.JumpRecord();
            system("cls");
        }
        else if (input.compare("6") == 0)
        {
            return 0;
        }
        else
        {
            cout << "ѡ���������ѡ��" << endl;
        }
    }

    return 0;
}
