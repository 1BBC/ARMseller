#include <iostream>
#include <conio.h>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <iomanip> //прапори 

using namespace std;

class Human //Людина
{
	char PIB[50];

	char Address[60];
	char Phone[20];
public:
	Human(){}
	Human(char* pib, char* address, char* phone)
	{
		strcpy(PIB, pib);
		strcpy(Address, address);
		strcpy(Phone, phone);
	}

	char* get_pib() { return PIB; }

	char* get_address() { return Address; }

	char* get_phone() { return Phone; }

	void add_human()
	{
			cin.ignore();
			cout << "Прізвише та ім'я: ";
			cin.getline(PIB, sizeof(PIB));

			cout << "Адрес:            ";
			cin.getline(Address, sizeof(Address));

			cout << "Номер телефону:   ";
			cin.getline(Phone, sizeof(Phone));
	}

	void show_human()
	{
		cout << "ПІБ:            " << PIB << endl;
		cout << "Адрес:          " << Address << endl;
		cout << "Номер телефону: " << Phone << endl;
	}

	virtual void write() = 0;

	virtual ~Human(){}
};

class Subscribers : public Human //Абоненти
{
	char Passport_ID[50];
public:
	Subscribers()
	{
		strcpy(Passport_ID, " ");
	}
	Subscribers(char* passport_ID, char* pib, char* addres, char* phone) : Human(pib, addres, phone)
	{
		strcpy(Passport_ID, passport_ID);
	}
	

	
	void add_subscribers()
	{
        Human::add_human();
		cout << "Номер паспорта: ";
		cin.getline(Passport_ID, sizeof(Passport_ID));

	}

	void show_subscribers()
	{
        Human::show_human();
		cout << "Номер паспорта: " << Passport_ID << endl;
	}

	void write()
	{
		ofstream file("Subscribers.bin", ios::binary | ios::app);
		file.write((char*)this, sizeof(*this));
		file.close();
	}

	void read(int position = 0)
	{
		ifstream file("Subscribers.bin", ios::binary);
		if (file.is_open())
		{
			file.seekg(position * sizeof(*this));
			file.read((char*)this, sizeof(*this));
		}
		file.close();
	}

	int count_File()
	{
		ifstream file("Subscribers.bin", ios::binary);
		if (file.is_open())
		{
			file.seekg(0, ios::end);
			return (int)file.tellg() / sizeof(Subscribers);
		}
		else
			return 0;
	}

	bool search(char *pib)
	{
		if (!strcmp(pib, get_pib()))
			return true;
		else
			return false;
	}
};

class Books //Книги
{
	char Name[50];
	char Author[50]; //Автор
	int Date_of_creation; //Дата створення
	int Books_cost; //Вартість книги
	int Count_Book; //Кількість книг
public:
	Books() : Date_of_creation(0), Books_cost(0)
	{
		strcpy(Name, " ");
		strcpy(Author, " ");
	}
	Books(char* name, char* author, int date, int books_cost)
	{
		strcpy(Name, name);
		strcpy(Author, author);
		Date_of_creation = date;
		Books_cost = books_cost;
	}
	
	char* get_name() { return Name; }
	void s_name(char* name) { strcpy(Name, name); }
	
	int get_books_cost(){ return Books_cost; }
	void s_books_cost(int books_cost){ Books_cost = books_cost; }
	
	int get_count() { return Count_Book; }
	void set_count(int count) { Count_Book = count;}
	
	void add_books()
	{
		cin.ignore();
		cout << "Назва книги:        ";
		cin.getline(Name, sizeof(Name));
		cout << "Автор:              ";
		cin.getline(Author, sizeof(Author));

		while (true)
		{           
			cout << "Рік видання:        ";
			cin >> Date_of_creation;
			if (Date_of_creation > 2017 || Date_of_creation < 1000)
			{
				cout << " ПОМИЛКА: Ви ввели невірну дату!" << endl;
			}
			else
			{
				break;
			}
		}

		while (true)
		{           
			cout << "Ціна книги:         ";
			cin >> Books_cost;
			if (Books_cost < 0)
			{
				cout << " ПОМИЛКА: Ви ввели невірну ціну!" << endl;
			}
			else
			{
				break;
			}
		}
		
		while(true)
		{
			cout << "Кількість книг: ";
			cin >> Count_Book;
			
			if(Count_Book < 1)
			{
				cout << "Ви ввели невірні дані! " << endl << endl;
			}
			else
				break;
		}
	}

	void show_books()
	{
		cout << "Назва:          " << Name << endl;
		cout << "Автор:          " << Author << endl;
		cout << "Рік видання:    " << Date_of_creation << "р." << endl;
		cout << "Ціна:           " << Books_cost << "грн."<< endl;
		cout << "Кількість книг: " << Count_Book << endl;
	}

	void write()
	{
		ofstream file("Books.bin", ios::binary | ios::app);
		file.write((char*)this, sizeof(*this));
		file.close();
	}

	void read(int position = 0)
	{
		ifstream file("Books.bin", ios::binary);
		if (file.is_open())
		{
			file.seekg(position * sizeof(*this));
			file.read((char*)this, sizeof(*this));
		}
		file.close();
	}

	int count_File()
	{
		ifstream file("Books.bin", ios::binary);
		if (file.is_open())
		{
			file.seekg(0, ios::end);
			return (int)file.tellg() / sizeof(Books);
		}
		else
			return 0;
	}

	bool search(char* name)
	{
		if (!strcmp(Name, name))
			return true;
		else
			return false;
	}
};

class Extradition //Видача
{
	char Extradition_Name[50]; // Книга
	char Extradition_PIB[50];  // Абонент
	int Cost;
	int Date_day; //Дата видачі книги 
	int Date_month;
	int Date_year;
	
	
public:
	Extradition()
	{
		strcpy(Extradition_Name, " "); //Книга
		strcpy(Extradition_PIB, " ");  //Абонент
		Date_day = 0; //Дата видачі
		Date_month = 0;
		Date_year = 0;
		Cost = 0;
	}
	Extradition(char* extradition_Name, char* extradition_PIB, int cost, int date_day, int date_month, int date_year)
	{
		strcpy(Extradition_Name, extradition_Name);
		strcpy(Extradition_PIB, extradition_PIB);
		Cost = cost;
		Date_day = date_day;
		Date_month = date_month;
		Date_year = date_year;
		//Total_Cost = cost;
	}
	
	int get_cost(){ return Cost; }
	void s_cost(int cost){ Cost = cost; }
	
	void add(vector<Books> &books, vector<Subscribers> subscribers)
	{
		while (true)
		{
			cin.ignore();
			while (true)
			{
				int k = 0;
				cout << "Книга: ";
				cin.getline(Extradition_Name, sizeof(Extradition_Name));
				for (int i(0); i < books.size(); i++)
				{
					if (!strcmp(Extradition_Name, books[i].get_name()))
					{
						if(books[i].get_count() > 0)
						{
							Cost =  books[i].get_books_cost();
							k++;
							books[i].set_count(books[i].get_count() - 1);
						}
						else
						{
							cout << "Даних книг уже немає! " << endl << endl;
						}
					}
				}
				if (k > 0)
				{
					break;
				}
				else
				{
					cout << "Такої книги немає!" << endl;
					cout << "Повторіть Ввід!" << endl << endl;
				}
			}
			
			while (true)
			{
				int k = 0;
				cout << "Абонент: ";
				cin.getline(Extradition_PIB, sizeof(Extradition_PIB));
				for (int i(0); i < subscribers.size(); i++)
				{
					if (!strcmp(Extradition_PIB, subscribers[i].get_pib()))
					{
						k++;
					}
				}
				if (k > 0)
				{
					break;
				}
				else
				{
					cout << "Такого абонента немає!" << endl;
					cout << "Повторіть Ввід!" << endl << endl;
				}
			}
				cout << endl << "\tДата " << endl;
			cout << "День:     ";
			cin >> Date_day;
			cout << "Місяць:   ";
			cin >> Date_month;
			cout << "Рік:      ";
			cin >> Date_year;
			break;
	}
	}

	void show()
	{
		cout << "Книга:    " << Extradition_Name << endl;
		cout << "Абонент:  " << Extradition_PIB << endl;
		cout << "Ціна:     " << Cost << endl;
		cout << "Дата:     " << Date_day <<"/"<< Date_month << "/" <<Date_year << endl;
	    	
	}

	void write()
	{
		ofstream file("Extradition.bin", ios::binary | ios::app);
		file.write((char*)this, sizeof(*this));
		file.close();
	}

	void read(int position = 0)
	{
		ifstream file("Extradition.bin", ios::binary);
		if (file.is_open())
		{
			file.seekg(position * sizeof(*this));
			file.read((char*)this, sizeof(*this));
		}
		file.close();
	}

	static int count_File()
	{
		ifstream file("Extradition.bin", ios::binary);
		if (file.is_open())
		{
			file.seekg(0, ios::end);
			return (int)file.tellg() / sizeof(Books);
		}
		else
			return 0;
	}

	bool search_Name(char *name)
	{
		if (!strcmp(name, Extradition_Name))
			return true;
		else
			return false;
	}
	
	
	
	bool search_PIB(char *pib)
	{
		if (!strcmp(pib, Extradition_PIB))
			return true;
		else
			return false;
	}
};


//Прототипи функцій
//Меню
void Books_Menu(vector<Books>&);
void Subscribers_Menu(vector<Subscribers>&);
void Extradition_Menu(vector<Extradition>&, vector<Books>&, vector<Subscribers>&);
void Search_Extradition_Menu(vector<Extradition>&);

//Книги
void Read_Books(vector<Books>&);
void Add_Books(vector<Books> &);
void Show_Books(vector<Books>);
void Search_Books(vector<Books>);

//Абоненти
void Read_Subscribers(vector<Subscribers>&);
void Add_Subscribers(vector<Subscribers> &);
void Show_Subscribers(vector<Subscribers>);
void Search_Subscribers(vector<Subscribers>);

//Видача
void Write_Books(vector<Books> &);
void Read_Extradition(vector<Extradition>&);
void Add_Extradition(vector<Extradition> &, vector<Books>&, vector<Subscribers>);
void Show_Extradition(vector<Extradition>);
void Delete_Extradition(vector<Extradition>);
void Search_Extradition_Name(vector<Extradition>);
void Search_Extradition_PIB(vector<Extradition>);

void INFO()
{
	system("cls");
	cout << "ИНФО" << endl << endl ;
	
	_getch();
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//////////////////////////

	vector<Books> books;
	Read_Books(books);
	
    vector<Subscribers> subscribers;
	Read_Subscribers(subscribers);
	
	vector<Extradition> extradition;
	Read_Extradition(extradition);

	/////////////////////////

	while (true)
	{
		system("cls");
		cout << "\tГоловне меню" << endl << endl;
		cout << "1. Книги " << endl;
		cout << "2. Абоненти " << endl;
		cout << "3. Продаж " << endl;
		cout << "9. INFO " << endl;
		cout << "0. Вийти" << endl;
		cout << endl << ": ";

		int item;
		cin >> item;

		switch (item)
		{
		case 1: Books_Menu(books); break;
		case 2: Subscribers_Menu(subscribers); break;
		case 3: Extradition_Menu(extradition, books, subscribers); break;
		case 9: INFO(); break;
		case 0: exit(0);
		default:
		{
			cout << endl << "Некоректний ввід!" << endl;
			cout << "Щоб знову зробити вибір, нажміть будь-яку кнопку: ";
			_getch();
			continue;
		}
		}
	}

	_getch();
	return 0;
}

void Write_Books(vector<Books> &books)
{
	ofstream file("Books.bin", ios::binary | ios::trunc);

	for (int i(0); i < books.size(); i++)
	{
		file.write((char*)&books[i], sizeof(books[i]));
	}

	file.close();
}

//Зчитування з фалів 
void Read_Books(vector<Books> &books)
{
	Books temp;
	int i = 0;

	if (temp.count_File() != 0)
		while (i < temp.count_File())
		{
			temp.read(i);
			books.push_back(temp);
			i++;
		}
}

void Read_Extradition(vector<Extradition> &extradition)
{
	Extradition temp;
	int i = 0;

	if (Extradition::count_File() != 0)
		while (i < Extradition::count_File())
		{
			temp.read(i);
			extradition.push_back(temp);
			i++;
		}
}

void Read_Subscribers(vector<Subscribers> &subscribers)
{
	Subscribers temp;
	int i = 0;

	if (temp.count_File() != 0)
		while (i < temp.count_File())
		{
			temp.read(i);
			subscribers.push_back(temp);
			i++;
		}
}


//Книги меню
void Books_Menu(vector<Books>& books)
{
	int item;
	while (true)
	{
		system("cls");
		cout << "\tКниги." << endl << endl;
		cout << "1. Вивести всі книги " << endl;
		cout << "2. Додати книгу " << endl;
		cout << "3. Пошук книги " << endl;
		cout << endl <<"0. Назад " << endl;
		cout << endl << ": ";


		cin >> item;
		switch (item)
		{
		case 1: Show_Books(books); break;
		case 2: Add_Books(books); break;
		case 3: Search_Books(books); break;
		case 0: return;
		default:
		{
			cout << endl << "Некоректний ввід!" << endl;
			cout << "Щоб знову зробити вибір, нажміть будь-яку кнопку: ";
			_getch();
			continue;
		}
		}
	}
}

//Абоненти меню
void Subscribers_Menu(vector<Subscribers>& subscribers)
{
	int item;
	while (true)
	{
		system("cls");
		cout << "\tАбоненти" << endl << endl;
		cout << "1. Вивести всіх абонентів " << endl;
		cout << "2. Додати абонента " << endl;
		cout << "3. Пошук абонента " << endl;
		cout << endl <<"0. Назад" << endl;
		cout << endl << ": ";


		cin >> item;
		switch (item)
		{
		case 1: Show_Subscribers(subscribers); break;
		case 2: Add_Subscribers(subscribers); break;
		case 3: Search_Subscribers(subscribers); break;
		case 0: return;
		default:
		{
			std::cout << endl << "Некоректний ввід!" << endl;
			std::cout << "Щоб знову зробити вибір, нажміть будь-яку кнопку: ";
			_getch();
			continue;
		}
		}
	}
}

//Видача меню
void Extradition_Menu(vector<Extradition>& extradition, vector<Books>& books, vector<Subscribers>& subscribers)
{
	int item;
	while (true)
	{
		system("cls");
		cout << "\tПродаж" << endl << endl;
		cout << "1. Вивести всі продажі " << endl;
		cout << "2. Оформити замовлення " << endl;
		cout << "3. Пошук " << endl;
		cout << endl <<"0. Назад " << endl;
		cout << endl << ": ";


		cin >> item;
		switch (item)
		{
		case 1: Show_Extradition(extradition); break;
		case 2: Add_Extradition(extradition, books, subscribers); break;
		case 3: Search_Extradition_Menu(extradition); break;
		case 0: return;
		default:
		{
			cout << endl << "Некоректний ввід!" << endl;
			cout << "Щоб знову зробити вибір, нажміть будь-яку кнопку: ";
			_getch();
			continue;
		}
		}
	}
}
//Видача меню для пошуку 
void Search_Extradition_Menu(vector<Extradition>& extradition)
{
	int item;
	while (true)
	{
		system("cls");
		cout << "\t Пошук" << endl << endl;
		cout << "1. Пошук по книзі " << endl;
		cout << "2. Пошук по абоненту " << endl;
		cout << endl << endl <<"0. Назад " << endl;
		cout << endl << ": ";


		cin >> item;
		switch (item)
		{
		case 1: Search_Extradition_Name(extradition); break;
		case 2: Search_Extradition_PIB(extradition); break;
		case 0: return;
		default:
		{
			cout << endl << "Некоректний ввід!" << endl;
			cout << "Щоб знову зробити вибір, нажміть будь-яку кнопку: ";
			_getch();
			continue;
		}
		}
	}
}

//Функції для книг
void Search_Books(vector<Books> books)
{
	system("cls");
    cout << "\tПошук книги" << endl << endl;
	char name[30];
	cout << "Введіть назву книги для пошуку : ";
	cin.ignore();
	cin.getline(name, sizeof(name));
	cout << endl;

	int i = 0;
	cout << "Результати пошуку: " << endl << endl;
	while (i < books.size())
	{
		if (books[i].search(name))
		{
			books[i].show_books();
			cout << endl;
		}
		i++;
	}

	cout << "\nЩоб повернутися назад в меню нажміть будь-яку кнопку: ";
	_getch();
}

void Add_Books(vector<Books>& books)
{
	system("cls");
	cout << "\t Добавити Книгу " << endl << endl;
	Books temp;
	temp.add_books();
	temp.write();

	books.push_back(temp);

	cout << "Книгу додано!" << endl;
	cout << " Щоб повернутися назад в меню нажміть будь-яку кнопку: ";
	_getch();
}

void Show_Books(vector<Books> books)
{
	system("cls");
	cout << "\tКниги " << endl << endl;
	for (int i(0); i < books.size(); i++)
	{
		books[i].show_books();
		cout << endl;
	}

	cout << "Щоб знову зробити вибір, нажміть будь-яку кнопку: ";
	_getch();
}

//Функції для абонентів
void Search_Subscribers(vector<Subscribers> subscribers)
{
	system("cls");
    cout << "\tПошук абонента" << endl << endl;
	char pib[30];
	cout << "Введіть ПІБ абонента : ";
	cin.ignore();
	cin.getline(pib, sizeof(pib));
	cout << endl;

	int i = 0;
	cout << "Результат пошуку: " << endl << endl;
	while (i < subscribers.size())
	{
		if (subscribers[i].search(pib))
		{
			subscribers[i].show_subscribers();
			cout << endl;
		}
		i++;
	}

	cout << "\nЩоб повернутися назад в меню нажміть будь-яку кнопку: ";
	_getch();
}

void Add_Subscribers(vector<Subscribers>& subscribers)
{
	system("cls");
	cout << "\t Добавити абонента: " << endl << endl;
	Subscribers temp;
	temp.add_subscribers();
	temp.write();

	subscribers.push_back(temp);

	cout << "Абонента додано!" << endl;
	cout << " Щоб повернутися назад в меню нажміть будь-яку кнопку: ";
	_getch();
}

void Show_Subscribers(vector<Subscribers> subscribers)
{
	system("cls");
	cout << "\tАбоненти " << endl << endl;
	for (int i(0); i < subscribers.size(); i++)
	{
		subscribers[i].show_subscribers();
		cout << endl;
	}

	cout << "Щоб знову зробити вибір, нажміть будь-яку кнопку: ";
	_getch();
}


//Функції для видачі
void Show_Extradition(vector<Extradition> extradition)
{
	int sumcost = 0; 
	int sumbooks = 0;
	system("cls");
	cout << "\t\t\tПродані книги " << endl << endl;
	for (int i(0); i < extradition.size(); i++)
	{
				extradition[i].show();
				sumcost = sumcost + extradition[i].get_cost();
				sumbooks ++;
				cout << endl;
	}
cout << "\t\t\tСтатистика " << endl << endl;		
cout << "Кількість проданих книг: " << sumbooks << endl;
cout << "Каса:                    " << sumcost << "грн." << endl << endl;

	cout << endl<< endl <<"Щоб знову зробити вибір, нажміть будь-яку кнопку: ";
	_getch();
}

void Add_Extradition(vector<Extradition>& extradition, vector<Books>& books, vector<Subscribers> subscribers)
{
	system("cls");
	cout << "\t Офрмлення замовлення: " << endl << endl;
	Extradition temp;
	temp.add(books, subscribers);
	temp.write();
	extradition.push_back(temp);
	Write_Books(books);

	cout << "Замовлення успішно оформлене!";
	cout << " Щоб повернутися назад в меню нажміть будь-яку кнопку: ";
	_getch();
}

void Search_Extradition_Name(vector<Extradition> extradition)
{
	system("cls");
    cout << "\tПошук проданого" << endl << endl;
	char extradition_Name[50];
	cout << "Введіть книгу для пошуку : ";
	cin.ignore();
	cin.getline(extradition_Name, sizeof(extradition_Name));
	cout << endl;

	int i = 0;
	int sumbooks = 0;
	int sumcost = 0;
	cout << "Результати пошуку: " << endl << endl;
	while (i < extradition.size())
	{
		if (extradition[i].search_Name(extradition_Name))
		{
			extradition[i].show();
			sumbooks ++;
			sumcost = sumcost + extradition[i].get_cost();
			cout << endl;
		}
		i++;
	}

cout << "\t\t\tСтатистика " << endl << endl;		
cout << "Книга була куплена " << sumbooks << " раз(и)."<< endl;
cout << "Книга принесла магазину " << sumcost << "грн." << endl << endl;

	cout << endl<< endl <<"Щоб знову зробити вибір, нажміть будь-яку кнопку: ";
	_getch();
}

void Search_Extradition_PIB(vector<Extradition> extradition)
{
	system("cls");
    cout << "\tПошук проданого" << endl << endl;
	char extradition_PIB[50];
	cout << "Введіть абонента для пошуку : ";
	cin.ignore();
	cin.getline(extradition_PIB, sizeof(extradition_PIB));
	cout << endl;

	int i = 0;
	int sumbooks = 0;
	int sumcost = 0;
	cout << "Результати пошуку: " << endl << endl;
	while (i < extradition.size())
	{
		if (extradition[i].search_PIB(extradition_PIB))
		{
			extradition[i].show();
			sumbooks ++;
			sumcost = sumcost + extradition[i].get_cost();
			cout << endl;
		}
		i++;
	}

cout << "\t\t\tСтатистика " << endl << endl;		
cout << "Даний абонент купив " << sumbooks << " книги." << endl;
cout << "Даний абонент витратив " << sumcost << "грн." << endl << endl;

	cout << endl<< endl <<"Щоб знову зробити вибір, нажміть будь-яку кнопку: ";
	_getch();
}


