#include <iostream>
using namespace std;

// класс односвязного списка
class List
{
public:
	List(); // конструктор списка(вынесен вне класса)
	~List();// деструктор списка(вынесен вне класса)

	void push(double data); // метод, добавляющий элемент в list
	int getsize() const { return size; } //метод, позволяющий получить размер списка
	bool isempty() const { return size == 0; } // проверка, пустой ли список
	double pop(); // метод, удаляющий элемент из list

private:
	// класс узла списка 
	class Node
	{
	public:
		Node* next; // указатель на следующий узел
		double data;// хранимое значение узла
		Node(double data) : data(data), next(nullptr) {} // конструктор класса Node
	};
	Node* head; // указатель на начало List
	int size; // размер list (кол-во элементов)
};

// конструктор списка 
List::List()
{
	size = 0;
	head = nullptr;
}
// деструктор списка
List::~List()
{
	while (size > 0); // работает, пока список не опустел
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
}


// метод push, добавляющий элемент в начало списка
void List::push(double data)
{
	Node* newnode = new Node(data);
	newnode->next = head;
	head = newnode;
	size++;
}

// метод pop, удаляющий элемент из начала списка и возвращающий его значение 
double List::pop()
{
	if (isempty()) // проверка, пуст ли список
	{
		return -1;
	}
	Node* temp = head;
	double data = head->data;
	head = head->next;
	delete temp;
	size--;
	return data;
}
// функция для вывода положительных элементов в обратном порядке
void printPos(List& list)
{
	while (!list.isempty()) // пока список не пуст, если элемент (data) > 0, то он выводится
	{
		double data = list.pop();
		if (data > 0)
		{
			cout << data << endl;
		}
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	bool humanFriendly = true; // отслеживает тип интерфейса
	if (argc > 1) // анализируются аргументы командной строки. Если их кол-во > 1, то запускается human friendly
	{
		string arg = argv[1];
		humanFriendly = (arg == "true");
	}

	// объявляется односвязный список list
	List lst;
	if (humanFriendly) // если работает human friendly 
	{
		cout << "Введите числа, которые хотите добавить в односвязный список. В конце введите 0 для завершения: " << endl;
	}

	double number = 1; // объявление новой переменной типа double 
	while (number != 0) // заполнение списка с помощью метода push
	{
		cin >> number;
		if (number != 0)
		{
			lst.push(number);
		}
	}
	if (humanFriendly) // если human friendly 
	{
		cout << "Положительные элементы списка, написанные в обратном порядке: " << endl;
	}
	printPos(lst); // вызов функции printPos для вывода положительных элементов в обратном порядке
	return 0;
}