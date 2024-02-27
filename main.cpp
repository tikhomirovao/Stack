#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

//����� ����
class Stack
{
	//������  ������� �����(��������� )
	const int EMPTY = -1;
	//������� ������� �����(������ �����)
	int FULL;
	//������ �������� ��������(������� �����)
	int top;
	//��������� �� ������ �������� ��� �������� ������
	char* STR = nullptr;
public:
	//��������� �������:
	//����������� ����������� � �������� ��������� ������ �����
	Stack(int);
	//����������
	~Stack();
	//����� ���������� �������� � ����
	void Push(char);
	//����� ���������� �������� �� �����
	char Pop(); //������� ����� ������ �� �����
	//����� ������� �����
	void Clear();
	//����� �������� ����� �� �������
	bool IsEmpty()const;
	//����� �������� ����� �� ������������
	bool IsFull()const;
	//����� ����������� �������� ���-�� ��������� � �����
	int GetCount()const;
	//����� ������ �������� �������� ��� �����������
	void Show()const;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(nullptr));

	//������� ���� � ������� ������������ � �����������
	Stack Stroka(20);
	//������ �� ������ �� ��� ������
	while (!Stroka.IsFull()) //���� ���� �� ����������
	{
		//��������� ���� ���������� ���������
		Stroka.Push(rand() % (127 - 33) + 33);
	}
	cout << "������� ���-�� ��������� � �����: " << Stroka.GetCount() << endl;
	Stroka.Show();
	while (!Stroka.IsEmpty()) //���� ���� �� ��������
	{
		cout << Stroka.Pop() << " ";
	}
	cout << "\n������� ���-�� ��������� � �����: " << Stroka.GetCount() << endl;

}
//����������� ����������� � �������� ��������� ������ �����
Stack::Stack(int Size)
{
	//��������  ������ �����
	FULL = Size - 1;
	//�������� ������ ��� �������� ��������� �����
	STR = new char[FULL + 1] {};
	//�������� �������� ������
	if (!STR) //�������� ��������� ������
	{
		cout << "������ ��������� ������! ������ ������ ����!" << endl;
		Size = 0; //����� ������� ������ ����
	}
	//��� �������� ���� ����
	top = EMPTY; //������� ��������� � ����������
}
//����������
Stack::~Stack()
{
	if (STR) //���� ������ �� "������"
	{
		delete[] STR;
		STR = nullptr;
		FULL = 0;
	}
}
//����� ���������� �������� � ����
void Stack::Push(char S)
{
	//���� � ����� ���� �����, �� ����������� ������ �������� �������� �� 1(������� ������� �����)
	//� ��������� ����� �������
	if (!IsFull()) STR[++top] = S; //++top;  STR[top] = S;
	else
	{
		//����� ������� ��������� ����� ������� ���������
		int OCP = GetConsoleOutputCP();
		if (OCP != 1251)SetConsoleOutputCP(1251);

		cout << "������������ �����!" << endl; //������ � �������������!
		//����� �������� �������� ������� ����� �����
		//Clear();
		if (OCP != 1251)SetConsoleOutputCP(OCP);
	}
}
//����� ���������� �������� �� �����
char Stack::Pop()
{
	//���� � ����� ��������, �� ��������� ������ �������� �������� �� 1(������� ������� �����)
	//� ���������� ������� �������
	if (!IsEmpty())return STR[top--]; //top--; STR[top+1];
	else
	{
		//����� ������� ��������� ����� ������� ���������
		int OCP = GetConsoleOutputCP();
		if (OCP != 1251)SetConsoleOutputCP(1251);
		cout << "���� ����!" << endl; //������ � �������������!		
		if (OCP != 1251)SetConsoleOutputCP(OCP);
		return 0; //return -1; //����� ������������ ����������
	}
}
//����� ������� �����
void Stack::Clear()
{
	//������� ����� ����������, ����� �������� ������� � ��������� ����
	top = EMPTY;
}
//����� �������� ����� �� �������
bool Stack::IsEmpty() const
{
	//���� ����, ����� ������� ��������� � ���������� �����
	return top == EMPTY;
}
//����� �������� ����� �� ������������
bool Stack::IsFull() const
{
	//���� �����, ����� ������� ��������� � �������� �����
	return top == FULL;
}
//����� ����������� �������� ���-�� ��������� � �����
int Stack::GetCount() const
{
	//������� ���-�� ��������� � �����
	return top + 1; //top - �������� ������ �������� �������� �������
}
//����� ������ �������� �������� ��� �����������
void Stack::Show() const
{
	//����� ������� ��������� ����� ������� ���������
	int OCP = GetConsoleOutputCP();
	if (OCP != 1251)SetConsoleOutputCP(1251);
	//���� � ����� ���� ��������, �� ������� �� ����� �������� �������� �������� �����
	if (!IsEmpty())
	{
		cout << "������� " << top + 1 << "-� ������� ����� �����: ";
		//SetConsoleOutputCP(866);
		cout << STR[top] << endl;
		//SetConsoleOutputCP(OCP);
	}
	else
	{
		cout << "���� ����!" << endl;
		if (OCP != 1251)SetConsoleOutputCP(OCP);
	}
}