#include "Word.h"

Word::Word()
{
	// ת������
	char* temp = new char[MAX_WORD_SIZE];

	// ÿ��temp����ĵ�ַ�϶���һ����ֱ����temp�ĵ�ַ��Ϊ�������
	srand((unsigned int)temp);

	// ��ȡ���е����ĺ���
	for (int i = 0; i < 4; i++)
	{
		string s;
		s += "./data/ch";
		s += to_string(i);
		s += ".txt";

		fin.open(s, ios::in);
		ch[i] = new string[MAX_WORD_SIZE];
		for (int j = 0; j < MAX_WORD_SIZE; j++)
		{
			fin.getline(temp, MAX_WORD_SIZE);
			ch[i][j] += temp;
		}
		fin.close();
	}

	// ��ȡ���е�Ӣ�ﵥ��
	for (int i = 0; i < 4; i++)
	{
		string s;
		s += "./data/en";
		s += to_string(i);
		s += ".txt";

		fin.open(s, ios::in);
		en[i] = new string[MAX_WORD_SIZE];
		for (int j = 0; j < MAX_WORD_SIZE; j++)
		{
			fin.getline(temp, MAX_WORD_SIZE);
			en[i][j] += temp;
		}
		fin.close();
	}

	// ��ȡ��ǰ�ļ�¼
	fin.open("./data/info.txt", ios::in);
	fin >> this->current;
	fin.close();

	// ��ȡ�����ѡ��
	GetRandOptions();

	// ������ʱ���ٵĿռ�
	delete[] temp;
}

Word::~Word()
{
	// ���ٱ������ĵ�string
	for (int i = 0; i < 4; i++)
	{
		delete[] ch[i];
	}
	// ���ٱ���Ӣ�ĵ�string
	for (int i = 0; i < 4; i++)
	{
		delete[] en[i];
	}
}

void Word::GetRandOptions()
{
	// ��ȡ0~3�Ĳ��ظ������������Ϊѡ��
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		randArray[i] = -1; // �ȸ���-1�������ظ�
	}
	i = 0;
	while (i < 4)
	{
		int temp = rand() % 4;
		if (randArray[0] != temp && randArray[1] != temp && randArray[2] != temp && randArray[3] != temp)
		{
			// ��ȡ�������ֵ�����������ֵ����ͬ��ʱ������鸳ֵ��Ȼ�� i++
			randArray[i] = temp;
			i++;
		}
	}
}

void Word::ChooseChinses()
{
	while (true)
	{
		CheckOver();
		cout << "******************************************" << endl;
		cout << "  ����ѡ��ģʽ������exit�����˳���ǰģʽ" << endl;
		cout << "******************************************" << endl;
		cout << endl;
		cout << "Ӣ��Ϊ��"<< this->GetLineEnglish() << " (" << this->current + 1 << "/4449)\n" << endl;
		cout << this->GetFourChinese() << endl;
		this->current++;
		
		while (true)
		{
			string input;
			cin.clear();
			cout << "������ѡ�";
			cin >> input;
			Sleep(15); // ��ֹ��ʾ��˸

			if (toupper(input[0]) == (this->Options[this->GetCorrectOption()]))
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

		this->GetRandOptions();
		this->SaveRecord();
	}
}

void Word::ChooseEnglish()
{
	while (true)
	{
		CheckOver();
		cout << "******************************************" << endl;
		cout << "  Ӣ��ѡ��ģʽ������exit�����˳���ǰģʽ" << endl;
		cout << "******************************************" << endl;
		cout << endl;
		cout << "����Ϊ��" << this->GetLineChinese() << " (" << this->current + 1 << "/4449)\n" << endl;
		cout << this->GetFourEnglish() << endl;

		this->current++;

		while (true)
		{
			string input;
			cin.clear();
			cout << "������ѡ�";
			cin >> input;
			Sleep(15); // ��ֹ��ʾ��˸

			if (toupper(input[0]) == (this->Options[this->GetCorrectOption()]))
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

		this->GetRandOptions();
		this->SaveRecord();
	}
}

void Word::InputEnglish()
{
	while (true)
	{
		CheckOver();
		cout << "******************************************" << endl;
		cout << "    ����ģʽ������exit�����˳���ǰģʽ" << endl;
		cout << "******************************************" << endl;
		cout << endl;
		cout << "������˼Ϊ��" << this->GetLineChinese() << " (" << this->current + 1 << "/4449)\n" << endl;

		string getEnglish = this->GetLineEnglish();
		this->current++;
		
		string input;
		while (true)
		{
			cin.clear();
			cout << "������:>";
			cin >> input;
			Sleep(15); // ��ֹ��ʾ��˸

			if (input.compare(getEnglish) == 0)
			{
				system("cls");
				break;
			}
			else if (input.compare("next") == 0)
			{
				cout << "��������ǣ�" << getEnglish << endl;
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
		
		this->SaveRecord();
	}
}

void Word::JumpRecord()
{
	string s;
	int jump = 0;
	while (true)
	{
		cout << "����������ת�ĵط�(" << current + 1 << "/4449):>";
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9')
		{
			jump = stoi(s) - 1;
			if (jump >= 0 && jump <= 4448)
			{
				current = jump;
				cout << "��ת�ɹ���" << endl;
				system("pause");
				return;
			}
		}
		cout << "��������ݣ����������룡" << endl;
	}
}

int Word::GetCorrectOption()
{
	int correct = -1;
	for (int i = 0; i < 4; i++)
	{
		if (randArray[i] == 0)
		{
			correct = i;
			break;
		}
	}
	return correct;
}

string Word::GetLineEnglish()
{
	return this->en[0][current];
}

string Word::GetFourChinese()
{
	string s;
	for (int i = 0; i < 4; i++)
	{
		s += Options[i];
		s += "��";
		s += ch[randArray[i]][current];
		s += '\n';
	}
	return s;
}

string Word::GetLineChinese()
{
	return this->ch[0][current];
}

string Word::GetFourEnglish()
{
	string s;
	for (int i = 0; i < 4; i++)
	{
		s += Options[i];
		s += "��";
		s += en[randArray[i]][current];
		s += '\n';
	}
	return s;
}

void Word::ClearRecord()
{
	this->current = 0;
	fin.open("./data/info.txt", ios::out);
	fin << current;
	fin.close();
	cout << "����ɹ�" << endl;
	system("pause");
}

void Word::SaveRecord()
{
	fin.open("./data/info.txt", ios::out);
	fin << current;
	fin.close();
}

void Word::CheckOver()
{
	if (current >= MAX_WORD_SIZE)
	{
		current = 0;
		cout << "��ϲ���Ѿ�������Ŷ�����Զ��Ѽ�¼����" << endl;
		system("pause");
		system("cls");
	}
}