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
	fin.open("./data/en.txt", ios::in);
	en = new string[MAX_WORD_SIZE];
	for (int i = 0; i < MAX_WORD_SIZE; i++)
	{
		fin.getline(temp, MAX_WORD_SIZE);
		en[i] += temp;
	}
	fin.close();

	// ��ȡ��ǰ�ļ�¼
	fin.open("./data/info.txt", ios::in);
	fin >> this->current;
	fin.close();

	// ��ȡ�����ѡ��
	GetOptions();

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
	delete[] en;
}

string Word::GetWord()
{
	string s;
	// ���Ӣ��
	s += "Ӣ��Ϊ��";
	s += en[current];
	s += "(";
	s += to_string(current+1);
	s += "/4449)";
	s += "\n\n";

	GetOptions();

	// �������
	for (int i = 0; i < 4; i++)
	{
		s += Options[i];
		s += "��";
		s += ch[randArr[i]][current];
		s += '\n';
	}

	// ��¼
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
	// ��ȡ0~3�Ĳ��ظ������������Ϊѡ��
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		randArr[i] = -1; // �ȸ���-1�������ظ�
	}
	i = 0;
	while (i < 4)
	{
		int temp = rand() % 4;
		if (randArr[0] != temp && randArr[1] != temp && randArr[2] != temp && randArr[3] != temp)
		{
			// ��ȡ�������ֵ�����������ֵ����ͬ��ʱ������鸳ֵ��Ȼ�� i++
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
