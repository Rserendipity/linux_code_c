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
	fin.open("./data/en.txt", ios::in);
	en = new string[MAX_WORD_SIZE];
	for (int i = 0; i < MAX_WORD_SIZE; i++)
	{
		fin.getline(temp, MAX_WORD_SIZE);
		en[i] += temp;
	}
	fin.close();

	// 读取以前的记录
	fin.open("./data/info.txt", ios::in);
	fin >> this->current;
	fin.close();

	// 获取随机的选项
	GetOptions();

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
	delete[] en;
}

string Word::GetWord()
{
	string s;
	// 存放英文
	s += "英文为：";
	s += en[current];
	s += "(";
	s += to_string(current+1);
	s += "/4449)";
	s += "\n\n";

	GetOptions();

	// 存放中文
	for (int i = 0; i < 4; i++)
	{
		s += Options[i];
		s += "：";
		s += ch[randArr[i]][current];
		s += '\n';
	}

	// 记录
	current++;

	return s;
}

int Word::GetCorrectOption()
{
	int correct = -1;
	for (int i = 0; i < 4; i++)
	{
		if (randArr[i] == 0)
		{
			correct = i;
			break;
		}
	}
	return correct;
}

void Word::GetOptions()
{
	// 获取0~3的不重复的随机数，作为选项
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		randArr[i] = -1; // 先给上-1，以免重复
	}
	i = 0;
	while (i < 4)
	{
		int temp = rand() % 4;
		if (randArr[0] != temp && randArr[1] != temp && randArr[2] != temp && randArr[3] != temp)
		{
			// 获取到的随机值和数组的其他值都不同的时候给数组赋值，然后 i++
			randArr[i] = temp;
			i++;
		}
	}
}

void Word::Save()
{
	fin.open("./data/info.txt", ios::out | ios::in);
	fin << current;
	fin.close();
}

void Word::GetInfo()
{
	fin.open("./data/info.txt", ios::out | ios::in);
	fin >> current;
	fin.close();
}
