package com.company;
import java.util.*;
import java.util.ArrayList;
import java.text.ParseException;

public class Main {
    public static void main(String[] args)
    {
        boolean f;
        // самолет
        List<technika>massiv=new ArrayList<>();
        technika tk1 = new technika("як1","белый",2020,150,10,0);
        technika tk2 = new technika("ил50","зеленый",2020,500,5,0);
        plane pl1 = new plane("су50", "синий", 2020, 1000, 10, 10000,5,0);// конструктор со всеми параметрами
        plane pl2 = new plane("т150", "белый", 2020, 800, 10, 20000,0,0);// конструктор со всеми параметрами
        massiv.add(tk1);
        massiv.add(tk2);
        massiv.add(pl1);
        massiv.add(pl2);
        Collections.sort(massiv);
        System.out.println(System.lineSeparator()+"Данные после сортировки: ");
        Iterator<technika> it = massiv.iterator();
        technika IterTk;
        while(it.hasNext()){
            IterTk=it.next();
            System.out.println(IterTk);
        }
        it = massiv.iterator();
        String sellName="су50";
        f=false;
        while(it.hasNext())
        {
            IterTk=it.next();
            if(IterTk.GetName()==sellName)
            {
                f=true;
                IterTk.Sell();
            }
        }
        if(!f)
        {
            System.out.println("Подходящей техники не найдено");
        }
    }
    public static void AddTov(avtoShop tk)
    {
        tk.addTov();
    }
    public static void Zapravit(AZS tk)
    {
        tk.zapravka();
    }

}
class MyExceptionRead extends Exception// класс исключений при чтении данных, наследник общего класса Exception
{
    private int Code;
    MyExceptionRead(int Code)
    {
        this.Code=Code;
    }
    public String toString()
    {
        switch (Code)
        {
            case 1: return "некорректный ввод марки";
            case 2: return "некорректный ввод цвета";
            case 3: return "некорректный ввод года выпуска";
            case 4: return "некорректный ввод цены";
            case 5: return "некорректный ввод марки двигателя";
            case 6: return "некорректный ввод мощности";
            case 7: return "некорректный ввод пробега";
            case 8: return "некорректный ввод ресурса двигателя";
            case 9: return "некорректный ввод веса двигателя";
            case 10:return "некорректный ввод количества";
            case 11:return "некорректный ввод времени разгона";
            default: return "неизвестная ошибка";
        }

    }
}
class MyExceptionOther extends Exception// класс исключений при тест-драйве и модернизации, наследник общего класса Exception
{   private int Code;
    MyExceptionOther(int Code)
    {
        this.Code=Code;
    }
    public String toString()
    {
        if(Code==1) return "некорректное расстояние тест-драйва!";
        if(Code==2) return "введены некорректные параметры модернизации";
        return "неизвестная ошибка";
    }
}
interface AZS// интерфейс
{
    void zapravka();
}

abstract class avtoShop// абстрактный класс
{
    public abstract void addTov();// абстрактная функция
}
class engine implements Cloneable// двигатель, возможность клонирования
{
    private String name=new String();// марка двигателя
    private double weight;// вес
    private int power;// мощность (л.с.)
    private int probeg;// пробег
    private int resurs;// ресурс двигателя

    public engine(String name, double weight, int power, int probeg, int resurs)// конструктор со всеми параметрами
    {
        this.name=name;
        this.weight = weight;
        this.power = power;
        this.probeg = probeg;
        this.resurs = resurs;
    }
    public engine(String name)// конструктор с одним параметром
    {
        this.name=name;
        this.weight = 10;
        this.power = 100;
        this.probeg = 0;
        this.resurs = 1000;
    }
    public engine()// конструктор без параметров
    {
        name="no_name";
        weight = 10;
        power = 100;
        probeg = 0;
        resurs = 1000;
    }
    // сеттеры и геттеры
    public void SetName(String name)
    {
        this.name=name;
    }
    public void SetWeight(double weight)
    {
        this.weight = weight;
    }
    public void SetPower(int power)
    {
        this.power = power;
    }
    public void SetProbeg(int probeg)
    {
        this.probeg = probeg;
    }
    public void SetResurs(int resurs)
    {
        this.resurs = resurs;
    }
    public String GetName()
    {
        return name;
    }
    public double GetwWight()
    {
        return weight;
    }
    public int GetPower()
    {
        return power;
    }
    public int GetProbeg()
    {
        return probeg;
    }
    public int GetResurs()
    {
        return resurs;
    }
    public void Remont()// ремонт двигателя
    {
        probeg = 0;
    }
    public void Read() throws NumberFormatException, MyExceptionRead// ввод данных
    {
        Scanner read = new Scanner(System.in);
        System.out.println("Введите марку двигателя: ");
        name=read.nextLine();
        if(name.trim().length()==0) throw new MyExceptionRead(5);// создание пользовательского исключения, принимает код ошибки
        System.out.println("Введите мощность двигателя: ");
        power=Integer.parseInt(read.nextLine());
        if(power<50||power>1500) throw new MyExceptionRead(6);
        System.out.println("Введите пробег двигателя: ");
        probeg=Integer.parseInt(read.nextLine());
        if(probeg<0||probeg>1000000) throw new MyExceptionRead(7);
        System.out.println("Введите ресурс двигателя: ");
        resurs=Integer.parseInt(read.nextLine());
        if(resurs<0||resurs>1000000) throw new MyExceptionRead(8);
        System.out.println("Введите вес двигателя: ");
        weight=Double.parseDouble(read.nextLine());
        if(weight<10||weight>10000) throw new MyExceptionRead(9);
    }
    public String toString()// вывод данных
    {
        String en;
        en="Марка двигателя: " + name+"\n"+"Мощность двигателя: " + power+"\n"+"Пробег двигателя: " + probeg+
                "\n"+"Ресурс двигателя: " + resurs+"\n"+"Вес двигателя: " + weight+"\n";
        return en;
    }
    public Object clone()// глубокое клонирование
    {
        try{
            engine clone=(engine)super.clone();
        }catch (CloneNotSupportedException e){
            System.out.println(e.getMessage());
        }
        return this;
    }
};

class technika extends avtoShop implements AZS, Comparable<technika>// базовый класс
{
    protected String name = new String();// марка авто
    protected String color = new String();// цвет авто
    protected int year;// год выпуска
    protected double price;// цена
    protected int count;// количество авто
    protected double petrol;// количество бензина

    public technika(String name, String color, int yr, double pr, int co, double pt)// конструктор со всеми параметрами
    {
        this.name = name;
        this.color = color;
        this.year = yr;
        this.price = pr;
        this.count = co;
        this.petrol = pt;
    }

    public technika()// конструктор без параметров
    {
        name = "no_name";
        color = "no_color";
        year = 2000;
        price = 0;
        count = 0;
        petrol = 0;
    }

    // сеттеры и геттеры
    public void SetName(String name) {
        this.name = name;
    }

    public void SetYear(int year) {
        this.year = year;
    }

    public void SetPrice(double price) {
        this.price = price;
    }

    public void SetCount(int count) {
        this.count = count;
    }

    public String GetName() {
        return name;
    }

    public String GetColor() {
        return color;
    }

    public int GetYear() {
        return year;
    }

    public double GetPrice() {
        return price;
    }

    public int GetCount() {
        return count;
    }

    public void PutT() throws NumberFormatException, MyExceptionRead // выброс двух исключений в фунцкию Main
    {
        Scanner read = new Scanner(System.in);
        System.out.println("Введите марку техники: ");
        name = read.nextLine();
        if (name.trim().length() == 0) throw new MyExceptionRead(1);
        System.out.println("Введите цвет: ");
        color = read.nextLine();
        if (color.trim().length() == 0) throw new MyExceptionRead(2);
        System.out.println("Введите год выпуска: ");
        year = Integer.parseInt(read.nextLine());
        if (year < 2000 || year > 2020) throw new MyExceptionRead(3);
        System.out.println("Введите цену: ");
        price = Double.parseDouble(read.nextLine());
        if (price < 1 || price > 1000000) throw new MyExceptionRead(4);
        System.out.println("Введите количество: ");
        count = Integer.parseInt(read.nextLine());
        if (count < 0) throw new MyExceptionRead(10);
    }

    public String toString()// функция вывода данных
    {
        String tk;
        tk = "Марка: " + name + "\n" + "Цвет: " + color + "\n" + "Год выпуска: "
                + year + "\n" + "Цена: " + price + "\n" + "Количество: " + count + "\n";
        return tk;
    }

    public int Sell() {
        count--;
        System.out.println("Техника продана!");
        System.out.println("текущее количество: " + count);
        return count;
    }

    public void addTov()// перегрузка абстрактной функции
    {
        count++;
        System.out.println("Добавлена 1 новая техника");
    }

    public void zapravka() {
        if (petrol == 0) {
            petrol += 100;
            System.out.println("Бак полностью заправлен");
        } else System.out.println("100л залить нельзя, бак не пустой");
    }

    @Override
    public int compareTo(technika o) {
        if(this.price>o.price) return 1;
        else return -1;
    }
};
class cars extends technika implements AZS, Cloneable// глубокое клонирование (dvs также клонируется)
{
    private engine dvs;// двигатель
    private double timeToHundred;// время разгона до сотни

    public cars()
    {
        timeToHundred = 0;
        dvs = new engine();
    }
    public cars(String name, String color, int year, double price, int count, engine dvs, double time, double petrol)
    {
        super(name, color, year, price, count, petrol);
        this.dvs = dvs;//установка двигателя
        this.timeToHundred = time;
    }
    public void SetTime(double time)
    {
        this.timeToHundred = time;
    }
    public double GetTime()
    {
        return timeToHundred;
    }
    public void Read() throws NumberFormatException, MyExceptionRead
    {
        Scanner read = new Scanner(System.in);
        System.out.println("Введите марку авто: ");
        name=read.nextLine();
        if(name.trim().length()==0) throw new MyExceptionRead(1);
        System.out.println("Введите цвет: ");
        color=read.nextLine();
        if(color.trim().length()==0) throw new MyExceptionRead(2);
        System.out.println("Введите год выпуска: ");
        year=Integer.parseInt(read.nextLine());
        if(year<2000||year>2020) throw new MyExceptionRead(3);
        System.out.println("Введите цену: ");
        price=Double.parseDouble(read.nextLine());
        if(price<1||price>1000000) throw new MyExceptionRead(4);
        System.out.println("Введите количество: ");
        count=Integer.parseInt(read.nextLine());
        if(count<0) throw new MyExceptionRead(10);
        System.out.println("Введите время разгона до сотни: ");
        timeToHundred=Double.parseDouble(read.nextLine());
        if(timeToHundred<1||timeToHundred>10000) throw new MyExceptionRead(11);
        dvs.Read();
    }
    public String toString()// функция вывода данных
    {
        String avto;
        avto="Марка: "+name+"\n"+"Цвет: "+color+"\n"+"Год выпуска: "
                +year+"\n"+"Цена: "+price+"\n"+"Количество: "+count+"\n"+"Время разгона до сотни: "+timeToHundred+"\n";
        return avto+dvs.toString();
    }
    public int Drive(int km) throws MyExceptionOther// тест-драйв
    {
        int probeg;
        if(km<0||km>100) throw new MyExceptionOther(1);
        probeg=dvs.GetProbeg()+km;
        dvs.SetProbeg(probeg);
        return probeg;
    }
    public void Modern(double NewWeight, int NewPower, int NewResurs) throws  MyExceptionOther// модернизация
    {
        if(NewWeight<0||NewWeight>1500||
                NewPower<0||NewPower>1500||NewResurs<10||NewResurs>1000000) throw new MyExceptionOther(2);
        dvs.SetWeight(NewWeight);
        dvs.SetPower(NewPower);
        dvs.SetResurs(NewResurs);
        dvs.Remont();
    }
    public int Sell(int count)// перегрузка метода базового класса
    {
        this.count -= count;
        System.out.println("Техника продана!");
        System.out.println("текущее количество: " + this.count);
        return this.count;
    }
    public void addTov()// перегрузка абстрактной функции
    {
        count += 3;
        System.out.println("Добавлено 3 новые машины");
    }
    public void zapravka()
    {
        if(petrol<=90)
        {
            petrol+=10;
            System.out.println("Залито 10л бензина");
        }
        else System.out.println("10л залить нельзя, бак почти полный");
    }
    public Object clone()
    {
        try{
            cars clone=(cars)super.clone();
        }catch (CloneNotSupportedException e){
            System.out.println(e.getMessage());
        }
        return this;
    }
};
class plane extends technika implements AZS
{
    private double MaxHeight;// максимальная высота полета (в метрах)
    private double HourFly;// налет в часах

    public plane(String name, String color, int year, double price, int count, double maxheight, double hourfly, double petrol)
    {
        super(name, color, year, price, count, petrol);
        MaxHeight = maxheight;
        HourFly = hourfly;
    }
    public plane()
    {
        MaxHeight=10000;
        HourFly=0;
    }
    public void SetHeight(double height)
    {
        this.MaxHeight = height;
    }
    public void SetHourFly(double hour)
    {
        this.HourFly = hour;
    }
    public double GetHeight()
    {
        return MaxHeight;
    }
    double GetHour()
    {
        return HourFly;
    }
    public String toString()// функция вывода данных
    {
        String plane;
        plane="Марка: "+name+"\n"+"Цвет: "+color+"\n"+"Год выпуска: "
                +year+"\n"+"Цена: "+price+"\n"+"Количество: "+count+"\n"
                +"Максимальная высота полета: "+MaxHeight+"\n"+"Время налета в часах: "+HourFly+"\n";
        return plane;
    }
    public void Read() throws NumberFormatException, MyExceptionRead
    {
        Scanner read = new Scanner(System.in);
        System.out.println("Введите марку авто: ");
        name=read.nextLine();
        if(name.trim().length()==0) throw new MyExceptionRead(1);
        System.out.println("Введите цвет: ");
        color=read.nextLine();
        if(color.trim().length()==0) throw new MyExceptionRead(2);
        System.out.println("Введите год выпуска: ");
        year=Integer.parseInt(read.nextLine());
        if(year<2000||year>2020) throw new MyExceptionRead(3);
        System.out.println("Введите цену: ");
        price=Double.parseDouble(read.nextLine());
        if(price<1||price>1000000) throw new MyExceptionRead(4);
        System.out.println("Введите количество: ");
        count=Integer.parseInt(read.nextLine());
        if(count<0) throw new MyExceptionRead(10);
        System.out.println("Введите максимальную высоту полета: ");
        MaxHeight=Double.parseDouble(read.nextLine());
        System.out.println("Введите время налета в часах: ");
        MaxHeight=Double.parseDouble(read.nextLine());
    }
    public double Fly(double hour)// функция полета на определенное количество часов
    {
        petrol-=50;
        HourFly += hour;
        return HourFly;
    }
    public void addTov()// перегрузка абстрактной функции
    {
        count += 2;
        System.out.println("Добавлено 2 новых самолета");
    }
    public void zapravka()
    {
        if(petrol<=50)
        {
            petrol+=50;
            System.out.println("Залито 50л бензина");
        }
        else System.out.println("50л залить нельзя");
    }
};
class Sale<T extends technika>// шаблон класса для класса technica и всех его наследников
{
    private int CountSell;
    private T value;
    private double PriceWithSale;
    public Sale(T value, int CountSell)
    {
        this.value=value;
        this.CountSell=CountSell;
        this.PriceWithSale=0;
    }
    public double GetPriceWithSale()
    {
        if(CountSell<value.count)
        {
            if (CountSell < 5) {
                PriceWithSale=(value.price*(100-(CountSell*10)))/100; // нахождение цены со скидкой
            }
            else{
                PriceWithSale=value.price/2;
            }
        }
        else {
            System.out.println("Количество продоавемых машин превышает количество машин");
            PriceWithSale=0;
        }
        return PriceWithSale;
    }
};
