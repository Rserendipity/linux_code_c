#define _CRT_SECURE_NO_WARNINGS 1
#include "Model.h"
// 选择模式
void SelectModel(Word* word)
{
    string input;
    while (true)
    {
        cout << "*****************************************" << endl;
        cout << "    选择模式，输入exit可以退出当前模式" << endl;
        cout << "*****************************************" << endl;
        cout << endl;
        cout << word->GetWord() << endl;
        while (true)
        {
            cin.clear();
            cout << "请输入选项：";
            cin >> input;
            
            if (toupper(input[0]) == (word->Options[word->GetCorrectOption()]))
            {
                system("cls");
                break;
            }
            else if (input.compare("exit") == 0)
            {
                system("cls");
                return;
            }
            else
            {
                cout << "不是这个选项哦" << endl;
            }
        }
        word->Save();
    }
}

// 输入模式
void InputModel(Word* word)
{
    while (true)
    {
        cout << "*****************************************" << endl;
        cout << "    输入模式，输入exit可以退出当前模式" << endl;
        cout << "*****************************************" << endl;
        cout << endl;
        cout << "中文意思为：";
        cout << word->ch[0][word->current] << "(" <<word->current + 1<<"/4449)" << endl;
        cout << endl;

        string input;
        while (true)
        {
            cin.clear();
            cout << "请输入:>";
            cin >> input;
            if (input.compare(word->en[word->current]) == 0)
            {
                word->current++;
                system("cls");
                break;
            }
            else if (input.compare("next") == 0)
            {
                cout << "这个单词是：" << word->en[word->current] << endl;
                word->current++;
                system("pause");
                system("cls");
                break;
            }
            else if (input.compare("exit") == 0)
            {
                system("cls");
                return;
            }
            else
            {
                cout << "这个单词不是这样拼的哦(不会的话可以输入next跳过当前的，直接下一个)" << endl;
            }
        }
        word->Save();
    }
}

// 清空记录
void ClearRecord(Word* word)
{
    word->fin.open("./data/info.txt", ios::out);
    word->current = 0;
    word->fin << word->current;
    word->fin.close();
    cout << "清除记录成功" << endl;
    system("pause");
    system("cls");
}