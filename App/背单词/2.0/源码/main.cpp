#define _CRT_SECURE_NO_WARNINGS 1
#include "Word.h"
#include "Model.h"

// 菜单
void menu()
{
    cout << "*****************************************" << endl;
    cout << "       输入1：给出英文，选择相应的意思" << endl;
    cout << "       输入2：给出中文，输入对应的英文" << endl;
    cout << "       输入3：清空记录" << endl;
    cout << "       输入4：退出" << endl;
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
            cout << "选择错误，重新选择" << endl;
        }
        word.GetInfo();
    }
    
    SelectModel(&word);

    return 0;
}
