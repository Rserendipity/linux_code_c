#define _CRT_SECURE_NO_WARNINGS 1
#include "Word.h"
#include "Model.h"

// �˵�
void menu()
{
    cout << "*****************************************" << endl;
    cout << "       ����1������Ӣ�ģ�ѡ����Ӧ����˼" << endl;
    cout << "       ����2���������ģ������Ӧ��Ӣ��" << endl;
    cout << "       ����3����ռ�¼" << endl;
    cout << "       ����4���˳�" << endl;
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
            SelectModel(&word);
        }
        else if (input.compare("2") == 0)
        {
            system("cls");
            InputModel(&word);
        }
        else if (input.compare("3") == 0)
        {
            ClearRecord(&word);
        }
        else if (input.compare("4") == 0)
        {
            word.Save();
            return 0;
        }
        else
        {
            cout << "ѡ���������ѡ��" << endl;
        }
        word.GetInfo();
    }
    
    SelectModel(&word);

    return 0;
}
