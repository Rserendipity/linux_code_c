#define _CRT_SECURE_NO_WARNINGS 1
#include "Model.h"
// ѡ��ģʽ
void SelectModel(Word* word)
{
    string input;
    while (true)
    {
        cout << "*****************************************" << endl;
        cout << "    ѡ��ģʽ������exit�����˳���ǰģʽ" << endl;
        cout << "*****************************************" << endl;
        cout << endl;
        cout << word->GetWord() << endl;
        while (true)
        {
            cin.clear();
            cout << "������ѡ�";
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
                cout << "�������ѡ��Ŷ" << endl;
            }
        }
        word->Save();
    }
}

// ����ģʽ
void InputModel(Word* word)
{
    while (true)
    {
        cout << "*****************************************" << endl;
        cout << "    ����ģʽ������exit�����˳���ǰģʽ" << endl;
        cout << "*****************************************" << endl;
        cout << endl;
        cout << "������˼Ϊ��";
        cout << word->ch[0][word->current] << "(" <<word->current + 1<<"/4449)" << endl;
        cout << endl;

        string input;
        while (true)
        {
            cin.clear();
            cout << "������:>";
            cin >> input;
            if (input.compare(word->en[word->current]) == 0)
            {
                word->current++;
                system("cls");
                break;
            }
            else if (input.compare("next") == 0)
            {
                cout << "��������ǣ�" << word->en[word->current] << endl;
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
                cout << "������ʲ�������ƴ��Ŷ(����Ļ���������next������ǰ�ģ�ֱ����һ��)" << endl;
            }
        }
        word->Save();
    }
}

// ��ռ�¼
void ClearRecord(Word* word)
{
    word->fin.open("./data/info.txt", ios::out);
    word->current = 0;
    word->fin << word->current;
    word->fin.close();
    cout << "�����¼�ɹ�" << endl;
    system("pause");
    system("cls");
}