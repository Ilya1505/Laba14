// stl c++.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Conio.h>
#include<Windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class MyException : public exception// класс наследник exception
{
private:
	int CodeError;// код ошибки
public:
	MyException(char *msg, int CodeError) :exception(msg)
	{
		this->CodeError = CodeError;
	}
	int Code()
	{
		return CodeError;
	}
};
template<typename T> class Sizeof// шаблон класса
{
private:
	T value;
public:
	Sizeof(T value)
	{
		this->value = value;
	}
	void SetValue(T value)
	{
		this->value = value;
	}
	T GetValue()
	{
		return value;
	}
	void DataTypeSize()
	{
		cout << "Размер элемента: " << sizeof(value) << " байт" << endl;
	}
};

class avtoshop// абстрактный класс
{
public:
	virtual void addTov() = 0;// чисто виртуальный метод
};

class engine// двигатель
{
private:
	int power;// мощность (л.с.)
	string name;// марка двигателя
	double weight;// вес
	int probeg;// пробег
	int resurs;// ресурс двигателя
public:
	engine &operator=(const engine &other)// перегрузка опрератора =
	{
		this->power = other.power;
		this->name = other.name;
		this->weight = other.weight;
		this->probeg = other.probeg;
		this->resurs = other.resurs;
		return *this;
	}
	engine(string init_name, double weight, int power, int probeg, int resurs)// конструктор с параметрами
	{
		this->name = init_name;
		this->weight = weight;
		this->power = power;
		this->probeg = probeg;
		this->resurs = resurs;
	}
	engine(string name)
	{
		this->name = name;
		this->weight = 50;
		this->power = 100;
		this->probeg = 0;
		this->resurs = 100;
	}
	engine()// конструктор без параметров
	{
		name = "No_Name";
		weight = 10;
		power = 100;
		probeg = 0;
		resurs = 300;
	}

	// сеттеры и геттеры
	void SetName(string name)
	{
		this->name = name;
	}
	void SetWeight(double weight)
	{
		this->weight = weight;
	}
	void SetPower(int power)
	{
		this->power = power;
	}
	void SetProbeg(int probeg)
	{
		this->probeg = probeg;
	}
	void SetResurs(int resurs)
	{
		this->resurs = resurs;
	}
	string GetName()
	{
		return name;
	}
	double GetwWight()
	{
		return weight;
	}
	int GetPower()
	{
		return power;
	}
	int GetProbeg()
	{
		return probeg;
	}
	int GetResurs()
	{
		return resurs;
	}
	void Remont()// ремонт двигателя
	{
		probeg = 0;
	}
	void Read()// ввод данных
	{
		fflush(stdin);
		cout << endl << "Марка двигателя: ";
		getline(cin, name);
		if (name == "") throw exception("Введена пустая строка марки двигателя!!!");
		cout << "Вес двигателя: ";
		cin >> weight;
		if (weight <10 || weight>5000) throw exception("Введен неккоректный вес двигателя!!!");
		cout << "Мощность двигателя: ";
		cin >> power;
		if (power <10 || power>1500) throw exception("Введена неккоректная мощность двигателя!!!");
		cout << "Пробег двигателя: ";
		cin >> probeg;
		if (probeg <0 || probeg>1000000) throw exception("Введен неккоректный пробег!!!");
		cout << "Ресурс двигателя: ";
		cin >> resurs;
		if (resurs <100 || resurs>5000000) throw exception("Введен неккоректный ресурс двигателя!!!");
	}
	void Print()// вывод данных
	{
		cout << "Марка двигателя: " << name << endl;
		cout << "Мощность двигателя: " << power << endl;
		cout << "Пробег двигателя: " << probeg << endl;
		cout << "Ресурс двигателя: " << resurs << endl;
		cout << "Масса двигателя: ";
		printf("%.4lf\n", weight);
	}
	~engine()// деструктор
	{

	}
};
class technika :public avtoshop// родительский класс всей техники, наследник абстрактного класса avtoshop
{
protected:
	int year;// год выпуска
	string name;// марка техники
	string color;// цвет техники
	double price;// цена
	int count;
	int petrol;// количество бензина (в литрах)
public:
	technika(const technika &other)// конструктор копирования
	{
		this->year = other.year;
		this->name = other.name;
		this->color = other.color;
		this->price = other.price;
		this->count = other.count;
		this->petrol = other.petrol;
	}
	technika(int year, string name, string color, double price, int count)// конструктор с параметрами
	{
		this->name = name;
		this->color = color;
		this->year = year;
		this->price = price;
		this->count = count;
		this->petrol = 0;
	}
	technika()// конструктор без параметров
	{
		name = "No_Name";
		color = "No_Color";
		year = 2020;
		price = 1000;
		count = 0;
		zapravka();// вызов виртуальной функции из функции базового класса
	}
	// сеттеры и геттеры
	void SetName(string name)
	{
		this->name = name;
	}
	void SetColor(string color)
	{
		this->color = color;
	}
	void SetYear(int year)
	{
		this->year = year;
	}
	void SetPrice(double price)
	{
		this->price = price;
	}
	void SetCount(int count)
	{
		this->count = count;
	}
	string GetName()
	{
		return name;
	}
	string GetColor()
	{
		return color;
	}
	int GetYear()
	{
		return year;
	}
	double GetPrice()
	{
		return price;
	}
	int GetCount()
	{
		return count;
	}
	int GetPetrol()
	{
		return petrol;
	}
	virtual void zapravka()// виртуальная функция
	{
		if (petrol == 0)
		{
			petrol = 100;
			cout << "Полный бак!(100л)" << endl;
		}
		else
		{
			cout << "ошибка, бак не пустой!" << endl;
		}
	}
	int Sell()
	{
		count--;
		cout << "Техника продана!" << endl;
		cout << "текущее количество: " << count << endl;
		return count;
	}
	void Print()// функкция вывода данных
	{
		cout << endl << "Марка: " << name << endl;
		cout << "Цвет: " << color << endl;
		cout << "Год выпуска: " << year << endl;
		cout << "Цена: ";
		printf("%.4lf\n", price);
		cout << "Количество: " << count << endl;
	}
	void Read()// функция ввода данных
	{
		fflush(stdin);
		cout << "Марка: ";
		getline(cin, name);
		if (name == "") throw exception("Введена пустая строка марки!!!");
		fflush(stdin);
		cout << "Цвет: ";
		getline(cin, color);
		if (color == "") throw exception("Введена пустая строка цвета!!!");
		cout << "Год выпуска: ";
		cin >> year;
		if (year<2000 || year>2020) throw exception("Введен неккоректный год выпуска!!!");
		cout << "Цена: ";
		cin >> price;
		if (price <= 0) throw exception("Введена неккоректная цена!!!");
		cout << "Количесвто: ";
		cin >> count;
		if (count <= 0) throw exception("Введено неккоректное количество!!!");
	}
	void addTov() override
	{
		count++;
		cout << "Добавлена 1 новая техника" << endl;
	}
	void Zapravit()// функция, вызывающая виртуальную функцию или переопределенную функцию
	{
		zapravka();
	}
};
class cars :public technika// производный класс "машины" от класса "техника"
{
private:
	engine dvs;// двигатель
	double timeToHundred;// время разгона до сотни

public:
	cars()
	{
		timeToHundred = 0;
	}
	cars(engine &dvs, double time, int year, string name, string color, double price, int count) :technika(year,
		name, color, price, count)
	{
		this->dvs = dvs;//установка двигателя
		this->timeToHundred = time;
	}
	void SetTime(double time)
	{
		this->timeToHundred = time;
	}
	double GetTime()
	{
		return timeToHundred;
	}
	void Modern(double NewWeight, int NewPower, int NewResurs)// модернизация
	{
		if (NewWeight<10 || NewWeight>500) throw MyException("Ошибка, некорректные данные модернизации!", 3);
		if (NewPower<50 || NewPower>1500) throw MyException("Ошибка, некорректное данные модернизации!", 4);
		if (NewResurs<500 || NewResurs>500000) throw MyException("Ошибка, некорректное данные модернизации!", 5);
		dvs.SetWeight(NewWeight);
		dvs.SetPower(NewPower);
		dvs.SetResurs(NewResurs);
		dvs.Remont();
	}
	int Sell(int count)// перегрузка метода базового класса
	{
		if (this->count < count) throw exception("неккоректное количество продаваемых машин!");
		this->count -= count;
		cout << "Техника продана!" << endl;
		cout << "текущее количество: " << this->count << endl;
	}
	void operator=(technika other)
	{
		this->name = other.GetName();
		this->color = other.GetColor();
		this->year = other.GetYear();
		this->price = other.GetPrice();
		this->count = other.GetCount();
		this->petrol = other.GetPetrol();
		this->timeToHundred = 0;
	}
	void zapravka() override// переопределенная функция базового класса
	{
		if (petrol != 100)
		{
			petrol += 10;
			cout << "заправка на 10 литров!" << endl;
		}
		else
		{
			cout << "не удалось заправиться, бак полный" << endl;
		}
	}
	void addTov() override
	{
		count += 3;
		cout << "Добавлено 3 новые машины" << endl;
	}
	int Drive(cars *avto, int km);
	friend void operator<<(ostream &o, cars c);// перегрузка оператора cout
	friend cars operator>>(istream &o, cars &c);// перегрузка оператора cin
};
void operator<<(ostream &o, cars c)
{
	cout << endl << "машина:" << endl;
	cout << "Марка: " << c.name << endl;
	cout << "Цвет: " << c.color << endl;
	cout << "Год выпуска: " << c.year << endl;
	cout << "Цена: ";
	printf("%.4lf\n", c.price);
	cout << "Количество: " << c.count << endl;
	cout << "Время разгона до сотни: " << c.timeToHundred << " секунд" << endl;
	c.dvs.Print();
}
cars operator>>(istream &o, cars &c)// перегрузка оператора cin
{
	cout << "машина:" << endl;
	fflush(stdin);
	cout << "Марка: ";
	getline(cin, c.name);
	if (c.name == "") throw exception("Введена пустая строка марки!!!");
	fflush(stdin);
	cout << "Цвет: ";
	getline(cin, c.color);
	if (c.color == "") throw exception("Введена пустая строка цвета!!!");
	cout << "Год выпуска: ";
	cin >> c.year;
	if (c.year<2000 || c.year>2020) throw exception("Введен неккоректный год выпуска!!!");
	cout << "Цена: ";
	cin >> c.price;
	if (c.price <= 0) throw exception("Введена неккоректная цена!!!");
	cout << "Количесвто: ";
	cin >> c.count;
	if (c.count <= 0) throw exception("Введено неккоректное количество!!!");
	cout << "время разгона до сотни: ";
	cin >> c.timeToHundred;
	if (c.timeToHundred<0 || c.timeToHundred>100000) throw exception("введено неккоректное время!!!");
	c.dvs.Read();
	return c;
}

int cars::Drive(cars *avto, int km)// возврат значений через указатель
{
	if (km<1) throw MyException("Ошибка, некорректное расстояние тест-драйва!", 0);
	if (km>100)throw MyException("Ошибка, некорректное расстояние тест-драйва!", 1);
	int ProbegAfterDrive;
	ProbegAfterDrive = avto->dvs.GetProbeg() + km;
	avto->dvs.SetProbeg(ProbegAfterDrive);
	avto->petrol -= 10;
	return ProbegAfterDrive;
}

class plane :public technika// производный класс "самолет" от класса "техника"
{
private:
	double MaxHeight;// максимальная высота полета (в метрах)
	double HourFly;// налет в часах
public:
	plane()
	{
		MaxHeight = 10000;
		HourFly = 0;
	}
	plane(double maxheight, double hourfly, int year, string name, string color, double price, int count) :technika(year,
		name, color, price, count)
	{
		MaxHeight = maxheight;
		HourFly = hourfly;
	}
	void SetHeight(double height)
	{
		this->MaxHeight = height;
	}
	void SetHourFly(double hour)
	{
		this->HourFly = hour;
	}
	double GetHeight()
	{
		return MaxHeight;
	}
	double GetHour()
	{
		return HourFly;
	}
	double Fly(double hour)// функция полета на определенное количество часов
	{
		if (hour < 0) throw exception("неккоректная продолжительность полета!");
		HourFly += hour;
		return HourFly;
	}
	void addTov() override
	{
		count += 2;
		cout << "Добавлено 2 новых самолета" << endl;
	}
	void Print()
	{
		cout << "самолет:" << endl;
		cout << "Марка: " << name << endl;
		cout << "Цвет: " << color << endl;
		cout << "Год выпуска: " << year << endl;
		cout << "Цена: ";
		printf("%.4lf\n", price);
		cout << "Количество: " << count << endl;
		cout << "максимальная высота полета: " << MaxHeight << endl;
		cout << "время налета: " << HourFly << "часов(а)" << endl;
	}
	void Read()
	{
		cout << "самолет:" << endl;
		fflush(stdin);
		cout << "Марка: ";
		getline(cin, name);
		if (name == "") throw exception("Введена пустая строка марки!!!");
		fflush(stdin);
		cout << "Цвет: ";
		getline(cin, color);
		if (color == "") throw exception("Введена пустая строка цвета!!!");
		cout << "Год выпуска: ";
		cin >> year;
		if (year<2000 || year>2020) throw exception("Введен неккоректный год выпуска!!!");
		cout << "Цена: ";
		cin >> price;
		if (price <= 0) throw exception("Введена неккоректная цена!!!");
		cout << "Количесвто: ";
		cin >> count;
		if (count <= 0) throw exception("Введено неккоректное количество!!!");
		cout << "максимальная высота полета: ";
		cin >> MaxHeight;
		cout << "время налета (в часах): ";
		cin >> HourFly;
	}
};

void addTov(avtoshop *ptr)
{
	ptr->addTov();
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);// подключение русскоязычного ввода/вывода
	SetConsoleOutputCP(1251);
	
	vector<technika> tk = {// создание и инициализация контейнера вектор
		technika(2020, "миг-28", "белый", 450, 1),
		technika(2020, "су-31", "белый", 400, 5),
		technika(2020, "су-50", "белый", 500, 1),
		plane(20000, 0, 2020, "як-01", "белый", 150, 5),
		plane(10000, 0, 2020, "ил-10", "зеленый", 200, 8),
		plane(10000, 0, 2020, "ту-200", "зеленый", 250, 8),
		plane(10000, 0, 2020, "пе-2", "зеленый", 800, 4),
	};
	vector<technika>::iterator it;// объявление итератора
	it = tk.begin();
	cout << "Данные после инициализации:" << endl;
	int i = 1;
	for (it; it != tk.end(); it++)
	{
		cout << "Техника номер " << i << endl;
		it->Print();
		i++;
	}
	
	sort(tk.begin(), tk.end(), [](technika &tk1, technika &tk2)// сортировка техники по цене
	{
		return tk1.GetPrice() > tk2.GetPrice();
	});
	cout << "После сортировки:" << endl;
	it = tk.begin();
	i = 1;
	for (it; it != tk.end(); it++)
	{
		cout << "Техника номер " << i << endl;
		it->Print();
		i++;
	}
	it = find_if(tk.begin(), tk.end(), [](technika &t1){
		return t1.GetPrice() < 200;
	});
	if (it == tk.end())
	{
		cout << "Подходящей техники нет" << endl;
	}
	else
	{
		it->Print();
		it->Sell();
	}
	getch();
	return 0;
}

