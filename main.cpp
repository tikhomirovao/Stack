#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

//класс Стек
class Stack
{
	//нижняя  граница стека(основание )
	const int EMPTY = -1;
	//верхняя граница стека(размер стека)
	int FULL;
	//индекс верхнего элемента(вершина стека)
	int top;
	//указатель на массив символов для хранения данных
	char* STR = nullptr;
public:
	//прототипы методов:
	//Конструктор принимающий в качестве параметра размер стека
	Stack(int);
	//деструктор
	~Stack();
	//метод добавления элемента в стек
	void Push(char);
	//метод извлечения элемента из стека
	char Pop(); //элемент будет удален из стека
	//метод очистки стека
	void Clear();
	//метод проверки стека на пустоту
	bool IsEmpty()const;
	//метод проверки стека на переполнение
	bool IsFull()const;
	//метод определения текущего кол-ва элементов в стеке
	int GetCount()const;
	//метод показа верхнего элемента без извленечния
	void Show()const;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(nullptr));

	//создаем стек с помощью конструктора с параметрами
	Stack Stroka(20);
	//работа со стеком до его границ
	while (!Stroka.IsFull()) //пока стек не заполнится
	{
		//заполняем стек случайными символами
		Stroka.Push(rand() % (127 - 33) + 33);
	}
	cout << "Текущее кол-во элементов в стеке: " << Stroka.GetCount() << endl;
	Stroka.Show();
	while (!Stroka.IsEmpty()) //пока стек не опустеет
	{
		cout << Stroka.Pop() << " ";
	}
	cout << "\nТекущее кол-во элементов в стеке: " << Stroka.GetCount() << endl;

}
//Конструктор принимающий в качестве параметра размер стека
Stack::Stack(int Size)
{
	//передаем  размер стека
	FULL = Size - 1;
	//выделяем память для хранения элементов стека
	STR = new char[FULL + 1] {};
	//проверка выделния памяти
	if (!STR) //проверка выделения памяти
	{
		cout << "Ошибка выделения памяти! Создан пустой стек!" << endl;
		Size = 0; //тогда создаем пустой стек
	}
	//при создании стек пуст
	top = EMPTY; //вершина совпадает с основанием
}
//деструктор
Stack::~Stack()
{
	if (STR) //если объект не "пустой"
	{
		delete[] STR;
		STR = nullptr;
		FULL = 0;
	}
}
//метод добавления элемента в стек
void Stack::Push(char S)
{
	//Если в стеке есть место, то увеличиваем индекс верхнего элемента на 1(смещаем вершину стека)
	//и добавляем новый элемент
	if (!IsFull()) STR[++top] = S; //++top;  STR[top] = S;
	else
	{
		//перед выводом сообщения нужно сменить кодировку
		int OCP = GetConsoleOutputCP();
		if (OCP != 1251)SetConsoleOutputCP(1251);

		cout << "Переполнение стека!" << endl; //борьба с переполнением!
		//можно добавить например очистку всего стека
		//Clear();
		if (OCP != 1251)SetConsoleOutputCP(OCP);
	}
}
//метод извлечения элемента из стека
char Stack::Pop()
{
	//Если в стеке элементы, то уменьшаем индекс верхнего элемента на 1(смещаем вершину стека)
	//и возвращаем верхний элемент
	if (!IsEmpty())return STR[top--]; //top--; STR[top+1];
	else
	{
		//перед выводом сообщения нужно сменить кодировку
		int OCP = GetConsoleOutputCP();
		if (OCP != 1251)SetConsoleOutputCP(1251);
		cout << "Стек пуст!" << endl; //борьба с переполнением!		
		if (OCP != 1251)SetConsoleOutputCP(OCP);
		return 0; //return -1; //можно использовать исключения
	}
}
//метод очистки стека
void Stack::Clear()
{
	//очистка стека происходит, путем переноса вершины к основанию стек
	top = EMPTY;
}
//метод проверки стека на пустоту
bool Stack::IsEmpty() const
{
	//стек пуст, когда вершина совпадает с основанием стека
	return top == EMPTY;
}
//метод проверки стека на переполнение
bool Stack::IsFull() const
{
	//стек полон, когда вершина совпадает с размером стека
	return top == FULL;
}
//метод определения текущего кол-ва элементов в стеке
int Stack::GetCount() const
{
	//текущее кол-во элементов в стеке
	return top + 1; //top - содержит индекс верхнего элемента массива
}
//метод показа верхнего элемента без извленечния
void Stack::Show() const
{
	//перед выводом сообщения нужно сменить кодировку
	int OCP = GetConsoleOutputCP();
	if (OCP != 1251)SetConsoleOutputCP(1251);
	//если в стеке есть элементы, то выводим на экран значение верхнего элемента стека
	if (!IsEmpty())
	{
		cout << "Верхний " << top + 1 << "-й элемент стека равен: ";
		//SetConsoleOutputCP(866);
		cout << STR[top] << endl;
		//SetConsoleOutputCP(OCP);
	}
	else
	{
		cout << "Стек пуст!" << endl;
		if (OCP != 1251)SetConsoleOutputCP(OCP);
	}
}