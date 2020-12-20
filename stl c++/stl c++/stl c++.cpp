// stl c++.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <Conio.h>
#include<Windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class MyException : public exception// ����� ��������� exception
{
private:
	int CodeError;// ��� ������
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
template<typename T> class Sizeof// ������ ������
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
		cout << "������ ��������: " << sizeof(value) << " ����" << endl;
	}
};

class avtoshop// ����������� �����
{
public:
	virtual void addTov() = 0;// ����� ����������� �����
};

class engine// ���������
{
private:
	int power;// �������� (�.�.)
	string name;// ����� ���������
	double weight;// ���
	int probeg;// ������
	int resurs;// ������ ���������
public:
	engine &operator=(const engine &other)// ���������� ���������� =
	{
		this->power = other.power;
		this->name = other.name;
		this->weight = other.weight;
		this->probeg = other.probeg;
		this->resurs = other.resurs;
		return *this;
	}
	engine(string init_name, double weight, int power, int probeg, int resurs)// ����������� � �����������
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
	engine()// ����������� ��� ����������
	{
		name = "No_Name";
		weight = 10;
		power = 100;
		probeg = 0;
		resurs = 300;
	}

	// ������� � �������
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
	void Remont()// ������ ���������
	{
		probeg = 0;
	}
	void Read()// ���� ������
	{
		fflush(stdin);
		cout << endl << "����� ���������: ";
		getline(cin, name);
		if (name == "") throw exception("������� ������ ������ ����� ���������!!!");
		cout << "��� ���������: ";
		cin >> weight;
		if (weight <10 || weight>5000) throw exception("������ ������������ ��� ���������!!!");
		cout << "�������� ���������: ";
		cin >> power;
		if (power <10 || power>1500) throw exception("������� ������������ �������� ���������!!!");
		cout << "������ ���������: ";
		cin >> probeg;
		if (probeg <0 || probeg>1000000) throw exception("������ ������������ ������!!!");
		cout << "������ ���������: ";
		cin >> resurs;
		if (resurs <100 || resurs>5000000) throw exception("������ ������������ ������ ���������!!!");
	}
	void Print()// ����� ������
	{
		cout << "����� ���������: " << name << endl;
		cout << "�������� ���������: " << power << endl;
		cout << "������ ���������: " << probeg << endl;
		cout << "������ ���������: " << resurs << endl;
		cout << "����� ���������: ";
		printf("%.4lf\n", weight);
	}
	~engine()// ����������
	{

	}
};
class technika :public avtoshop// ������������ ����� ���� �������, ��������� ������������ ������ avtoshop
{
protected:
	int year;// ��� �������
	string name;// ����� �������
	string color;// ���� �������
	double price;// ����
	int count;
	int petrol;// ���������� ������� (� ������)
public:
	technika(const technika &other)// ����������� �����������
	{
		this->year = other.year;
		this->name = other.name;
		this->color = other.color;
		this->price = other.price;
		this->count = other.count;
		this->petrol = other.petrol;
	}
	technika(int year, string name, string color, double price, int count)// ����������� � �����������
	{
		this->name = name;
		this->color = color;
		this->year = year;
		this->price = price;
		this->count = count;
		this->petrol = 0;
	}
	technika()// ����������� ��� ����������
	{
		name = "No_Name";
		color = "No_Color";
		year = 2020;
		price = 1000;
		count = 0;
		zapravka();// ����� ����������� ������� �� ������� �������� ������
	}
	// ������� � �������
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
	virtual void zapravka()// ����������� �������
	{
		if (petrol == 0)
		{
			petrol = 100;
			cout << "������ ���!(100�)" << endl;
		}
		else
		{
			cout << "������, ��� �� ������!" << endl;
		}
	}
	int Sell()
	{
		count--;
		cout << "������� �������!" << endl;
		cout << "������� ����������: " << count << endl;
		return count;
	}
	void Print()// �������� ������ ������
	{
		cout << endl << "�����: " << name << endl;
		cout << "����: " << color << endl;
		cout << "��� �������: " << year << endl;
		cout << "����: ";
		printf("%.4lf\n", price);
		cout << "����������: " << count << endl;
	}
	void Read()// ������� ����� ������
	{
		fflush(stdin);
		cout << "�����: ";
		getline(cin, name);
		if (name == "") throw exception("������� ������ ������ �����!!!");
		fflush(stdin);
		cout << "����: ";
		getline(cin, color);
		if (color == "") throw exception("������� ������ ������ �����!!!");
		cout << "��� �������: ";
		cin >> year;
		if (year<2000 || year>2020) throw exception("������ ������������ ��� �������!!!");
		cout << "����: ";
		cin >> price;
		if (price <= 0) throw exception("������� ������������ ����!!!");
		cout << "����������: ";
		cin >> count;
		if (count <= 0) throw exception("������� ������������ ����������!!!");
	}
	void addTov() override
	{
		count++;
		cout << "��������� 1 ����� �������" << endl;
	}
	void Zapravit()// �������, ���������� ����������� ������� ��� ���������������� �������
	{
		zapravka();
	}
};
class cars :public technika// ����������� ����� "������" �� ������ "�������"
{
private:
	engine dvs;// ���������
	double timeToHundred;// ����� ������� �� �����

public:
	cars()
	{
		timeToHundred = 0;
	}
	cars(engine &dvs, double time, int year, string name, string color, double price, int count) :technika(year,
		name, color, price, count)
	{
		this->dvs = dvs;//��������� ���������
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
	void Modern(double NewWeight, int NewPower, int NewResurs)// ������������
	{
		if (NewWeight<10 || NewWeight>500) throw MyException("������, ������������ ������ ������������!", 3);
		if (NewPower<50 || NewPower>1500) throw MyException("������, ������������ ������ ������������!", 4);
		if (NewResurs<500 || NewResurs>500000) throw MyException("������, ������������ ������ ������������!", 5);
		dvs.SetWeight(NewWeight);
		dvs.SetPower(NewPower);
		dvs.SetResurs(NewResurs);
		dvs.Remont();
	}
	int Sell(int count)// ���������� ������ �������� ������
	{
		if (this->count < count) throw exception("������������ ���������� ����������� �����!");
		this->count -= count;
		cout << "������� �������!" << endl;
		cout << "������� ����������: " << this->count << endl;
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
	void zapravka() override// ���������������� ������� �������� ������
	{
		if (petrol != 100)
		{
			petrol += 10;
			cout << "�������� �� 10 ������!" << endl;
		}
		else
		{
			cout << "�� ������� �����������, ��� ������" << endl;
		}
	}
	void addTov() override
	{
		count += 3;
		cout << "��������� 3 ����� ������" << endl;
	}
	int Drive(cars *avto, int km);
	friend void operator<<(ostream &o, cars c);// ���������� ��������� cout
	friend cars operator>>(istream &o, cars &c);// ���������� ��������� cin
};
void operator<<(ostream &o, cars c)
{
	cout << endl << "������:" << endl;
	cout << "�����: " << c.name << endl;
	cout << "����: " << c.color << endl;
	cout << "��� �������: " << c.year << endl;
	cout << "����: ";
	printf("%.4lf\n", c.price);
	cout << "����������: " << c.count << endl;
	cout << "����� ������� �� �����: " << c.timeToHundred << " ������" << endl;
	c.dvs.Print();
}
cars operator>>(istream &o, cars &c)// ���������� ��������� cin
{
	cout << "������:" << endl;
	fflush(stdin);
	cout << "�����: ";
	getline(cin, c.name);
	if (c.name == "") throw exception("������� ������ ������ �����!!!");
	fflush(stdin);
	cout << "����: ";
	getline(cin, c.color);
	if (c.color == "") throw exception("������� ������ ������ �����!!!");
	cout << "��� �������: ";
	cin >> c.year;
	if (c.year<2000 || c.year>2020) throw exception("������ ������������ ��� �������!!!");
	cout << "����: ";
	cin >> c.price;
	if (c.price <= 0) throw exception("������� ������������ ����!!!");
	cout << "����������: ";
	cin >> c.count;
	if (c.count <= 0) throw exception("������� ������������ ����������!!!");
	cout << "����� ������� �� �����: ";
	cin >> c.timeToHundred;
	if (c.timeToHundred<0 || c.timeToHundred>100000) throw exception("������� ������������ �����!!!");
	c.dvs.Read();
	return c;
}

int cars::Drive(cars *avto, int km)// ������� �������� ����� ���������
{
	if (km<1) throw MyException("������, ������������ ���������� ����-������!", 0);
	if (km>100)throw MyException("������, ������������ ���������� ����-������!", 1);
	int ProbegAfterDrive;
	ProbegAfterDrive = avto->dvs.GetProbeg() + km;
	avto->dvs.SetProbeg(ProbegAfterDrive);
	avto->petrol -= 10;
	return ProbegAfterDrive;
}

class plane :public technika// ����������� ����� "�������" �� ������ "�������"
{
private:
	double MaxHeight;// ������������ ������ ������ (� ������)
	double HourFly;// ����� � �����
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
	double Fly(double hour)// ������� ������ �� ������������ ���������� �����
	{
		if (hour < 0) throw exception("������������ ����������������� ������!");
		HourFly += hour;
		return HourFly;
	}
	void addTov() override
	{
		count += 2;
		cout << "��������� 2 ����� ��������" << endl;
	}
	void Print()
	{
		cout << "�������:" << endl;
		cout << "�����: " << name << endl;
		cout << "����: " << color << endl;
		cout << "��� �������: " << year << endl;
		cout << "����: ";
		printf("%.4lf\n", price);
		cout << "����������: " << count << endl;
		cout << "������������ ������ ������: " << MaxHeight << endl;
		cout << "����� ������: " << HourFly << "�����(�)" << endl;
	}
	void Read()
	{
		cout << "�������:" << endl;
		fflush(stdin);
		cout << "�����: ";
		getline(cin, name);
		if (name == "") throw exception("������� ������ ������ �����!!!");
		fflush(stdin);
		cout << "����: ";
		getline(cin, color);
		if (color == "") throw exception("������� ������ ������ �����!!!");
		cout << "��� �������: ";
		cin >> year;
		if (year<2000 || year>2020) throw exception("������ ������������ ��� �������!!!");
		cout << "����: ";
		cin >> price;
		if (price <= 0) throw exception("������� ������������ ����!!!");
		cout << "����������: ";
		cin >> count;
		if (count <= 0) throw exception("������� ������������ ����������!!!");
		cout << "������������ ������ ������: ";
		cin >> MaxHeight;
		cout << "����� ������ (� �����): ";
		cin >> HourFly;
	}
};

void addTov(avtoshop *ptr)
{
	ptr->addTov();
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);// ����������� �������������� �����/������
	SetConsoleOutputCP(1251);
	
	vector<technika> tk = {// �������� � ������������� ���������� ������
		technika(2020, "���-28", "�����", 450, 1),
		technika(2020, "��-31", "�����", 400, 5),
		technika(2020, "��-50", "�����", 500, 1),
		plane(20000, 0, 2020, "��-01", "�����", 150, 5),
		plane(10000, 0, 2020, "��-10", "�������", 200, 8),
		plane(10000, 0, 2020, "��-200", "�������", 250, 8),
		plane(10000, 0, 2020, "��-2", "�������", 800, 4),
	};
	vector<technika>::iterator it;// ���������� ���������
	it = tk.begin();
	cout << "������ ����� �������������:" << endl;
	int i = 1;
	for (it; it != tk.end(); it++)
	{
		cout << "������� ����� " << i << endl;
		it->Print();
		i++;
	}
	
	sort(tk.begin(), tk.end(), [](technika &tk1, technika &tk2)// ���������� ������� �� ����
	{
		return tk1.GetPrice() > tk2.GetPrice();
	});
	cout << "����� ����������:" << endl;
	it = tk.begin();
	i = 1;
	for (it; it != tk.end(); it++)
	{
		cout << "������� ����� " << i << endl;
		it->Print();
		i++;
	}
	it = find_if(tk.begin(), tk.end(), [](technika &t1){
		return t1.GetPrice() < 200;
	});
	if (it == tk.end())
	{
		cout << "���������� ������� ���" << endl;
	}
	else
	{
		it->Print();
		it->Sell();
	}
	getch();
	return 0;
}

