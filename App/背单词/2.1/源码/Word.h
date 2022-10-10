#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
class Word
{
public:
	const int MAX_WORD_SIZE = 4449;				  // �ܹ��ĵ�������
	const char Options[4] = { 'A','B','C','D' };  // ѡ������

	Word();   // ���죬��ȡ���еĵ�����Ϣ
	~Word();  // �������������еĵ�����Ϣ

	void ChooseChinses();  // ѡ����ģʽ
	void ChooseEnglish();  // ѡӢ��ģʽ
	void InputEnglish();   // ����Ӣ��ģʽ
	void ClearRecord();    // �����¼
	void JumpRecord();	   // ��ת��¼

private:
	Word(const Word&);	      //��ֹ��������

	void GetRandOptions();    // ��ȡ�����ѡ��
	int GetCorrectOption();   // ��ȡ��ȷ��ѡ��
	void SaveRecord();        // �����¼
	void CheckOver();         // ����Ƿ��Ѿ����꣬�����Ժ���Զ�����

	string GetLineEnglish();  // ��ȡһ��Ӣ��
	string GetFourChinese();  // ��ȡ��������
							  
	string GetLineChinese();  // ��ȡһ������
	string GetFourEnglish();  // ��ȡ����Ӣ��
							  
	int current;		      // ��¼
	int randArray[4];	      // ��ȡ�������Ϊѡ��
	string* ch[4];		      // �洢����
	string* en[4];		      // �洢Ӣ��
	fstream fin;		      // �ļ���
};

