#pragma once
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h>
using namespace std;
class Word
{
	friend void InputModel(Word* word);
	friend void ClearRecord(Word* word);

public:
	const int MAX_WORD_SIZE = 4449;				// �ܹ��ĵ�������
	const char Options[4] = {'A','B','C','D'};  // 
	Word();
	~Word();
	string GetWord();		 // ��ȡӢ��
	int GetCorrectOption();  // ��ȡ��ȷ��ѡ��
	void Save();
	void GetInfo();
private:
	void GetOptions(); // ��ȡ�����ѡ��
	Word(const Word&); // ������������
	int current;
	string* ch[4];
	string* en; 
	int randArr[4];
	fstream fin;

};

