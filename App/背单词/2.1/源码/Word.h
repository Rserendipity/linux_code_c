#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
class Word
{
public:
	const int MAX_WORD_SIZE = 4449;				  // 总共的单词数量
	const char Options[4] = { 'A','B','C','D' };  // 选项数组

	Word();   // 构造，读取所有的单词信息
	~Word();  // 析构，销毁所有的单词信息

	void ChooseChinses();  // 选中文模式
	void ChooseEnglish();  // 选英文模式
	void InputEnglish();   // 输入英文模式
	void ClearRecord();    // 清除记录
	void JumpRecord();	   // 跳转记录

private:
	Word(const Word&);	      //禁止拷贝构造

	void GetRandOptions();    // 获取随机数选项
	int GetCorrectOption();   // 获取正确的选项
	void SaveRecord();        // 保存记录
	void CheckOver();         // 检查是否已经背完，背完以后会自动清零

	string GetLineEnglish();  // 获取一行英文
	string GetFourChinese();  // 获取四行中文
							  
	string GetLineChinese();  // 获取一行中文
	string GetFourEnglish();  // 获取四行英文
							  
	int current;		      // 记录
	int randArray[4];	      // 获取随机数作为选项
	string* ch[4];		      // 存储中文
	string* en[4];		      // 存储英文
	fstream fin;		      // 文件流
};

