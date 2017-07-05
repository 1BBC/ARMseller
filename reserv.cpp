#include <iostream>
#include <conio.h>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <iomanip> //������� 

using namespace std;

class Human //������
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
			cout << "������� �� ��'�: ";
			cin.getline(PIB, sizeof(PIB));

			cout << "�����:            ";
			cin.getline(Address, sizeof(Address));

			cout << "����� ��������:   ";
			cin.getline(Phone, sizeof(Phone));
	}

	void show_human()
	{
		cout << "ϲ�:            " << PIB << endl;
		cout << "�����:          " << Address << endl;
		cout << "����� ��������: " << Phone << endl;
	}

	virtual void write() = 0;

	virtual ~Human(){}
};

class Subscribers : public Human //��������
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
		cout << "����� ��������: ";
		cin.getline(Passport_ID, sizeof(Passport_ID));

	}

	void show_subscribers()
	{
        Human::show_human();
		cout << "����� ��������: " << Passport_ID << endl;
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

class Books //�����
{
	char Name[50];
	char Author[50]; //�����
	int Date_of_creation; //���� ���������
	int Books_cost; //������� �����
	int Count_Book; //ʳ������ ����
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
		cout << "����� �����:        ";
		cin.getline(Name, sizeof(Name));
		cout << "�����:              ";
		cin.getline(Author, sizeof(Author));

		while (true)
		{           
			cout << "г� �������:        ";
			cin >> Date_of_creation;
			if (Date_of_creation > 2017 || Date_of_creation < 1000)
			{
				cout << " �������: �� ����� ������ ����!" << endl;
			}
			else
			{
				break;
			}
		}

		while (true)
		{           
			cout << "ֳ�� �����:         ";
			cin >> Books_cost;
			if (Books_cost < 0)
			{
				cout << " �������: �� ����� ������ ����!" << endl;
			}
			else
			{
				break;
			}
		}
		
		while(true)
		{
			cout << "ʳ������ ����: ";
			cin >> Count_Book;
			
			if(Count_Book < 1)
			{
				cout << "�� ����� ����� ���! " << endl << endl;
			}
			else
				break;
		}
	}

	void show_books()
	{
		cout << "�����:          " << Name << endl;
		cout << "�����:          " << Author << endl;
		cout << "г� �������:    " << Date_of_creation << "�." << endl;
		cout << "ֳ��:           " << Books_cost << "���."<< endl;
		cout << "ʳ������ ����: " << Count_Book << endl;
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

class Extradition //������
{
	char Extradition_Name[50]; // �����
	char Extradition_PIB[50];  // �������
	int Cost;
	int Date_day; //���� ������ ����� 
	int Date_month;
	int Date_year;
	
	
public:
	Extradition()
	{
		strcpy(Extradition_Name, " "); //�����
		strcpy(Extradition_PIB, " ");  //�������
		Date_day = 0; //���� ������
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
				cout << "�����: ";
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
							cout << "����� ���� ��� ����! " << endl << endl;
						}
					}
				}
				if (k > 0)
				{
					break;
				}
				else
				{
					cout << "���� ����� ����!" << endl;
					cout << "�������� ���!" << endl << endl;
				}
			}
			
			while (true)
			{
				int k = 0;
				cout << "�������: ";
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
					cout << "������ �������� ����!" << endl;
					cout << "�������� ���!" << endl << endl;
				}
			}
				cout << endl << "\t���� " << endl;
			cout << "����:     ";
			cin >> Date_day;
			cout << "̳����:   ";
			cin >> Date_month;
			cout << "г�:      ";
			cin >> Date_year;
			break;
	}
	}

	void show()
	{
		cout << "�����:    " << Extradition_Name << endl;
		cout << "�������:  " << Extradition_PIB << endl;
		cout << "ֳ��:     " << Cost << endl;
		cout << "����:     " << Date_day <<"/"<< Date_month << "/" <<Date_year << endl;
	    	
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


//��������� �������
//����
void Books_Menu(vector<Books>&);
void Subscribers_Menu(vector<Subscribers>&);
void Extradition_Menu(vector<Extradition>&, vector<Books>&, vector<Subscribers>&);
void Search_Extradition_Menu(vector<Extradition>&);

//�����
void Read_Books(vector<Books>&);
void Add_Books(vector<Books> &);
void Show_Books(vector<Books>);
void Search_Books(vector<Books>);

//��������
void Read_Subscribers(vector<Subscribers>&);
void Add_Subscribers(vector<Subscribers> &);
void Show_Subscribers(vector<Subscribers>);
void Search_Subscribers(vector<Subscribers>);

//������
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
	cout << "����" << endl << endl ;
	
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
		cout << "\t������� ����" << endl << endl;
		cout << "1. ����� " << endl;
		cout << "2. �������� " << endl;
		cout << "3. ������ " << endl;
		cout << "9. INFO " << endl;
		cout << "0. �����" << endl;
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
			cout << endl << "����������� ���!" << endl;
			cout << "��� ����� ������� ����, ������ ����-��� ������: ";
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

//���������� � ���� 
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


//����� ����
void Books_Menu(vector<Books>& books)
{
	int item;
	while (true)
	{
		system("cls");
		cout << "\t�����." << endl << endl;
		cout << "1. ������� �� ����� " << endl;
		cout << "2. ������ ����� " << endl;
		cout << "3. ����� ����� " << endl;
		cout << endl <<"0. ����� " << endl;
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
			cout << endl << "����������� ���!" << endl;
			cout << "��� ����� ������� ����, ������ ����-��� ������: ";
			_getch();
			continue;
		}
		}
	}
}

//�������� ����
void Subscribers_Menu(vector<Subscribers>& subscribers)
{
	int item;
	while (true)
	{
		system("cls");
		cout << "\t��������" << endl << endl;
		cout << "1. ������� ��� �������� " << endl;
		cout << "2. ������ �������� " << endl;
		cout << "3. ����� �������� " << endl;
		cout << endl <<"0. �����" << endl;
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
			std::cout << endl << "����������� ���!" << endl;
			std::cout << "��� ����� ������� ����, ������ ����-��� ������: ";
			_getch();
			continue;
		}
		}
	}
}

//������ ����
void Extradition_Menu(vector<Extradition>& extradition, vector<Books>& books, vector<Subscribers>& subscribers)
{
	int item;
	while (true)
	{
		system("cls");
		cout << "\t������" << endl << endl;
		cout << "1. ������� �� ������ " << endl;
		cout << "2. �������� ���������� " << endl;
		cout << "3. ����� " << endl;
		cout << endl <<"0. ����� " << endl;
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
			cout << endl << "����������� ���!" << endl;
			cout << "��� ����� ������� ����, ������ ����-��� ������: ";
			_getch();
			continue;
		}
		}
	}
}
//������ ���� ��� ������ 
void Search_Extradition_Menu(vector<Extradition>& extradition)
{
	int item;
	while (true)
	{
		system("cls");
		cout << "\t �����" << endl << endl;
		cout << "1. ����� �� ���� " << endl;
		cout << "2. ����� �� �������� " << endl;
		cout << endl << endl <<"0. ����� " << endl;
		cout << endl << ": ";


		cin >> item;
		switch (item)
		{
		case 1: Search_Extradition_Name(extradition); break;
		case 2: Search_Extradition_PIB(extradition); break;
		case 0: return;
		default:
		{
			cout << endl << "����������� ���!" << endl;
			cout << "��� ����� ������� ����, ������ ����-��� ������: ";
			_getch();
			continue;
		}
		}
	}
}

//������� ��� ����
void Search_Books(vector<Books> books)
{
	system("cls");
    cout << "\t����� �����" << endl << endl;
	char name[30];
	cout << "������ ����� ����� ��� ������ : ";
	cin.ignore();
	cin.getline(name, sizeof(name));
	cout << endl;

	int i = 0;
	cout << "���������� ������: " << endl << endl;
	while (i < books.size())
	{
		if (books[i].search(name))
		{
			books[i].show_books();
			cout << endl;
		}
		i++;
	}

	cout << "\n��� ����������� ����� � ���� ������ ����-��� ������: ";
	_getch();
}

void Add_Books(vector<Books>& books)
{
	system("cls");
	cout << "\t �������� ����� " << endl << endl;
	Books temp;
	temp.add_books();
	temp.write();

	books.push_back(temp);

	cout << "����� ������!" << endl;
	cout << " ��� ����������� ����� � ���� ������ ����-��� ������: ";
	_getch();
}

void Show_Books(vector<Books> books)
{
	system("cls");
	cout << "\t����� " << endl << endl;
	for (int i(0); i < books.size(); i++)
	{
		books[i].show_books();
		cout << endl;
	}

	cout << "��� ����� ������� ����, ������ ����-��� ������: ";
	_getch();
}

//������� ��� ��������
void Search_Subscribers(vector<Subscribers> subscribers)
{
	system("cls");
    cout << "\t����� ��������" << endl << endl;
	char pib[30];
	cout << "������ ϲ� �������� : ";
	cin.ignore();
	cin.getline(pib, sizeof(pib));
	cout << endl;

	int i = 0;
	cout << "��������� ������: " << endl << endl;
	while (i < subscribers.size())
	{
		if (subscribers[i].search(pib))
		{
			subscribers[i].show_subscribers();
			cout << endl;
		}
		i++;
	}

	cout << "\n��� ����������� ����� � ���� ������ ����-��� ������: ";
	_getch();
}

void Add_Subscribers(vector<Subscribers>& subscribers)
{
	system("cls");
	cout << "\t �������� ��������: " << endl << endl;
	Subscribers temp;
	temp.add_subscribers();
	temp.write();

	subscribers.push_back(temp);

	cout << "�������� ������!" << endl;
	cout << " ��� ����������� ����� � ���� ������ ����-��� ������: ";
	_getch();
}

void Show_Subscribers(vector<Subscribers> subscribers)
{
	system("cls");
	cout << "\t�������� " << endl << endl;
	for (int i(0); i < subscribers.size(); i++)
	{
		subscribers[i].show_subscribers();
		cout << endl;
	}

	cout << "��� ����� ������� ����, ������ ����-��� ������: ";
	_getch();
}


//������� ��� ������
void Show_Extradition(vector<Extradition> extradition)
{
	int sumcost = 0; 
	int sumbooks = 0;
	system("cls");
	cout << "\t\t\t������ ����� " << endl << endl;
	for (int i(0); i < extradition.size(); i++)
	{
				extradition[i].show();
				sumcost = sumcost + extradition[i].get_cost();
				sumbooks ++;
				cout << endl;
	}
cout << "\t\t\t���������� " << endl << endl;		
cout << "ʳ������ �������� ����: " << sumbooks << endl;
cout << "����:                    " << sumcost << "���." << endl << endl;

	cout << endl<< endl <<"��� ����� ������� ����, ������ ����-��� ������: ";
	_getch();
}

void Add_Extradition(vector<Extradition>& extradition, vector<Books>& books, vector<Subscribers> subscribers)
{
	system("cls");
	cout << "\t ��������� ����������: " << endl << endl;
	Extradition temp;
	temp.add(books, subscribers);
	temp.write();
	extradition.push_back(temp);
	Write_Books(books);

	cout << "���������� ������ ���������!";
	cout << " ��� ����������� ����� � ���� ������ ����-��� ������: ";
	_getch();
}

void Search_Extradition_Name(vector<Extradition> extradition)
{
	system("cls");
    cout << "\t����� ���������" << endl << endl;
	char extradition_Name[50];
	cout << "������ ����� ��� ������ : ";
	cin.ignore();
	cin.getline(extradition_Name, sizeof(extradition_Name));
	cout << endl;

	int i = 0;
	int sumbooks = 0;
	int sumcost = 0;
	cout << "���������� ������: " << endl << endl;
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

cout << "\t\t\t���������� " << endl << endl;		
cout << "����� ���� ������� " << sumbooks << " ���(�)."<< endl;
cout << "����� �������� �������� " << sumcost << "���." << endl << endl;

	cout << endl<< endl <<"��� ����� ������� ����, ������ ����-��� ������: ";
	_getch();
}

void Search_Extradition_PIB(vector<Extradition> extradition)
{
	system("cls");
    cout << "\t����� ���������" << endl << endl;
	char extradition_PIB[50];
	cout << "������ �������� ��� ������ : ";
	cin.ignore();
	cin.getline(extradition_PIB, sizeof(extradition_PIB));
	cout << endl;

	int i = 0;
	int sumbooks = 0;
	int sumcost = 0;
	cout << "���������� ������: " << endl << endl;
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

cout << "\t\t\t���������� " << endl << endl;		
cout << "����� ������� ����� " << sumbooks << " �����." << endl;
cout << "����� ������� �������� " << sumcost << "���." << endl << endl;

	cout << endl<< endl <<"��� ����� ������� ����, ������ ����-��� ������: ";
	_getch();
}


