#include "Word.h"

Word::Word()
{
	// 转存数组
	char* temp = new char[MAX_WORD_SIZE];

	// 每次temp分配的地址肯定不一样，直接用temp的地址作为随机种子
	srand((unsigned int)temp);

	// 读取所有的中文含义
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

	// 读取所有的英语单词
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

	// 读取以前的记录
	fin.open("./data/info.txt", ios::in);
	fin >> this->current;
	fin.close();

	// 获取随机的选项
	GetRandOptions();

	// 销毁临时开辟的空间
	delete[] temp;
}

Word::~Word()
{
	// 销毁保存中文的string
	for (int i = 0; i < 4; i++)
	{
		delete[] ch[i];
	}
	// 销毁保存英文的string
	for (int i = 0; i < 4; i++)
	{
		delete[] en[i];
	}
}

void Word::GetRandOptions()
{
	// 获取0~3的不重复的随机数，作为选项
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		randArray[i] = -1; // 先给上-1，以免重复
	}
	i = 0;
	while (i < 4)
	{
		int temp = rand() % 4;
		if (randArray[0] != temp && randArray[1] != temp && randArray[2] != temp && randArray[3] != temp)
		{
			// 获取到的随机值和数组的其他值都不同的时候给数组赋值，然后 i++
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
		cout << "  中文选择模式，输入exit可以退出当前模式" << endl;
		cout << "******************************************" << endl;
		cout << endl;
		cout << "英文为："<< this->GetLineEnglish() << " (" << this->current + 1 << "/4449)\n" << endl;
		cout << this->GetFourChinese() << endl;
		this->current++;
		
		while (true)
		{
			string input;
			cin.clear();
			cout << "请输入选项：";
			cin >> input;
			Sleep(15); // 防止显示闪烁

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
				cout << "不是这个选项哦" << endl;
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
		cout << "  英文选择模式，输入exit可以退出当前模式" << endl;
		cout << "******************************************" << endl;
		cout << endl;
		cout << "中文为：" << this->GetLineChinese() << " (" << this->current + 1 << "/4449)\n" << endl;
		cout << this->GetFourEnglish() << endl;

		this->current++;

		while (true)
		{
			string input;
			cin.clear();
			cout << "请输入选项：";
			cin >> input;
			Sleep(15); // 防止显示闪烁

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
				cout << "不是这个选项哦" << endl;
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
		cout << "    输入模式，输入exit可以退出当前模式" << endl;
		cout << "******************************************" << endl;
		cout << endl;
		cout << "中文意思为：" << this->GetLineChinese() << " (" << this->current + 1 << "/4449)\n" << endl;

		string getEnglish = this->GetLineEnglish();
		this->current++;
		
		string input;
		while (true)
		{
			cin.clear();
			cout << "请输入:>";
			cin >> input;
			Sleep(15); // 防止显示闪烁

			if (input.compare(getEnglish) == 0)
			{
				system("cls");
				break;
			}
			else if (input.compare("next") == 0)
			{
				cout << "这个单词是：" << getEnglish << endl;
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
		
		this->SaveRecord();
	}
}

void Word::JumpRecord()
{
	string s;
	int jump = 0;
	while (true)
	{
		cout << "输入你想跳转的地方(" << current + 1 << "/4449):>";
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9')
		{
			jump = stoi(s) - 1;
			if (jump >= 0 && jump <= 4448)
			{
				current = jump;
				cout << "跳转成功！" << endl;
				system("pause");
				return;
			}
		}
		cout << "错误的数据，请重新输入！" << endl;
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
		s += "：";
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
		s += "：";
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
	cout << "清除成功" << endl;
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
		cout << "恭喜，已经背完了哦，将自动把记录归零" << endl;
		system("pause");
		system("cls");
	}
}