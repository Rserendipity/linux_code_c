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
	const int MAX_WORD_SIZE = 4449;				// 总共的单词数量
	const char Options[4] = {'A','B','C','D'};  // 
	Word();
	~Word();
	string GetWord();		 // 获取英文
	int GetCorrectOption();  // 获取正确的选项
	void Save();
	void GetInfo();
private:
	void GetOptions(); // 获取随机的选项
	Word(const Word&); // 不允许拷贝构造
	int current;
	string* ch[4];
	string* en; 
	int randArr[4];
	fstream fin;

};

