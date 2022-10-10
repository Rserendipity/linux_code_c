#define _CRT_SECURE_NO_WARNINGS 1
#include "Word.h"
// 菜单
void menu()
{
    cout << "*****************************************" << endl;
    cout << "    输入1： 给出英文，选择相应的中文" << endl;
    cout << "    输入2： 给出中文，选择相应的英文" << endl;
    cout << "    输入3： 给出中文，输入对应的英文" << endl;
    cout << "    输入4： 清空记录" << endl;
    cout << "    输入5： 跳转记录至指定的地方" << endl;
    cout << "    输入6： 退出" << endl;
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
        cout << "请选择:>";
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
            cout << "选择错误，重新选择" << endl;
        }
    }

    return 0;
}
