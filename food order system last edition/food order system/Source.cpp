#include <iostream>
#include<fstream>
#include<string>
#include<algorithm>
#define size 30
using namespace std;
int a[size] = {};// declaring array of counters each item has its own counter in this array with index = ID -1
float price = 0;
void menu(); // Mozzamel
void search(int ID[], int count);//Abdallah Mohsen
void cases(int ID[], int i, float& price);//Hana Mohsen
void order(int ID[], int& count);//Abdallah Mohsen
void edit(int ID[], int count);//Hagar Essam
void del(int ID[], int count, float& price);//Hagar Ahmed
void add(int ID[], int& count, float& price);//Hagar Essam
void show_order(int ID[], int count);//Hana Mohsen
void checkout(float price);// Mozzamel
struct signUp
{
	string firstname;
	string lastname;
	string address;
	string email;
	string password;
	int phoneNumber = 0;
};
struct login
{
	string email, em;
	string password, pass;
	string firstname;
	string secondname;
	string phone;
	string address;
};
signUp user();
login check();
// Mohammed Samir & Mohab Tarek
int main()
{
	int ID[100], count = 0;
	int choice;
	cout << "\t\t\t==============================================================\n";
	cout << "\t\t\t*               welcome to our food order system             *\n";
	cout << "\t\t\t==============================================================\n\n\n";
	cout << "\t    _      menu       _\n";
	cout << "                                                                     \n\n";
	cout << "\t| press 1 to LOGIN             |" << endl;
	cout << "\t| press 2 to CREATE ACCOUNT    |" << endl;
	cout << "\t| press 0 to Exit              |" << endl;
	cout << "\n\t Please enter your choice : ";
	cin >> choice;
	cout << endl;
	system("cls");
	switch (choice)
	{
	case 1:
		check();
		menu();
		search(ID, count);
		order(ID, count);
		edit(ID, count);
		break;
	case 2:
		user();
		menu();
		search(ID, count);
		order(ID, count);
		edit(ID, count);
		break;
	case 0:
		cout << "\t\t\t***" << endl;
		cout << "\n\t\t\t\t\t * THANK YOU FOR VISITING US * " << endl;
		cout << "\n\t\t\t***" << endl;
		break;
	default:
		system("cls");
		cout << "\t\t\t***";
		cout << "\n\t\t\t          Please select from the options given below \n\n";
		main();

	}
	//system("pause");
	return 0;
}
// Mohammed Samir & Mohab Tarek
signUp user()
{
	signUp s;
	system("cls");
	cout << "\t================================\n";
	cout << "\t||=======> Enter first name  : ";
	cin >> s.firstname;
	cout << "\t||=======> Enter last name   : ";
	cin >> s.lastname;
	cout << "\t||=======> Enter the address : ";
	cin.ignore();
	getline(cin, s.address);
	cout << "\t||=======> Enter your phone number : ";
	cin >> s.phoneNumber;
	cout << "\t||=======> Enter the email : ";
	cin >> s.email;
	cout << "\t||=======> Enter the password : ";
	cin >> s.password;
	ofstream in("record.txt", ios::app);
	in << s.email << "\t" << s.password << "\t" << s.firstname
		<< " " << s.lastname << "\t" << s.address << "\t" << s.phoneNumber << endl;
	system("cls");
	cout << "\t\t\t\t\t***\n";
	cout << "\t\t\t\t\t   Registration is successful ! \n";
	cout << "\t\t\t\t\t***\n";
	return s;
}
// Mohammed Samir & Mohab Tarek
login check()
{
	int choice2;
	char k;
	login l;
	int count = 0;
	int choice;
	system("cls");
	cout << "\t\t\t * Please enter the email and the password : " << endl;
	cout << "\t\t\t EMAIL... ";
	cin >> l.email;
	cout << "\t\t\t PASSWORD... ";
	cin >> l.password;
	ifstream in("record.txt", ios::app);
	while (!in.eof())
	{
		in >> l.em >> l.pass;
		if (l.em == l.email && l.pass == l.password)
		{
			count = 1;
			getline(in, l.firstname, '\t');
			getline(in, l.secondname, '\t');
			getline(in, l.address, '\t');
			in >> l.phone;

		}
	}
	in.close();
	if (count == 1)
	{
		system("cls");
		cout << "*\n";
		cout << "\n\t\t\t\t\ YOUR LOGIN IS SUCCESSFUL \n\t\t\t\t\ THANKS FOR LOGGING IN ! \n";
		cout << "*\n";
		cout << "do you want to show your information (press y to yes n to no) : ";
		cin >> k;
		if (k == 'y' || k == 'Y')
		{
			cout << "\t*********************************************\n\n";
			cout << "\t\tname : " << l.secondname << endl;
			cout << "\t\tyour adress : " << l.address << endl;
			cout << "\t\tyour phone number : " << l.phone << endl;
			cout << "\n\t*********************************************\n";
			cout << "\t\tpress 1 to return to menu :";
			cin >> choice2;
			switch (choice2)
			{
			case 1:menu();
				system("cls");

				break;
			}
		}
		else if (k == 'n' || k == 'N')
		{
			menu();
		}

	}
	else
	{
		cout << "*\n";
		cout << "\n\t\t\t\t\ LOGIN ERROR \n\t\t\t\t\ PLEASE CHECK YOUR EMAIL AND PASSWORD \n";
		cout << "*\n";
		cout << " press 0 to return to menu or press 1 to try again";
		cin >> choice;
		switch (choice)
		{
		case 0:main();
			break;
		case 1:check();
			break;
		}
	}
	return l;
}
//Mozzamel
void menu()
{
	cout << "\t\t Welcome to our food system\t\t " << endl;
	cout << "\n***********************************************************" << endl;
	cout << "\t\t\t MEALS \t\t\t\t" << endl;
	cout << "\n***********************************************************" << endl;
	cout << " ID \t\t name \t\t\t\t price  \t\t " << endl;
	cout << "\t\t *\t\t\t\t *" << endl;
	cout << " 1 \t\t roast beef with rice \t\t 120.00 L.E \t\t\n 2 \t\t roast chicken with rice \t 120.00 L.E \t\t\n";
	cout << " 3 \t\t chicken grill with rice \t 130.00 L.E \t\t\n 4 \t\t hawawshi \t\t\t 40.00 L.E \t\t\n";
	cout << " 5 \t\t kofta with rice \t\t 100.00 L.E \t\t\n 6 \t\t spaghetti \t\t\t 40.00L.E \t\t\n ";
	cout << "7 \t\t meat casserole with rice \t 140.00 L.E \t\n 8 \t\t chicken casserole with rice \t 140.00L.E \t\t\n ";
	cout << "9 \t\t sea food soup \t\t\t 70.00 L.E \t\t\n 10 \t\t kofta with spaghetti \t\t 120.00L.E \t\t\n";
	cout << "\n***********************************************************" << endl;
	cout << "\t\t\t SANDWICHES \t\t\t" << endl;
	cout << "\n***********************************************************" << endl;
	cout << " ID \t\t name \t\t\t\t price  \t\t " << endl;
	cout << "\t\t *\t\t\t\t *" << endl;
	cout << " 11 \t\t chicken fillet \t\t 30.00 L.E \t\t\n 12 \t\t Grand chicken spicy\t\t 40.00 L.E \t\t\n ";
	cout << "13 \t\t spicy chicken \t\t\t 35.00 L.E \t\t\n 14 \t\t egg with sheese wrap\t\t 15.00 L.E \t\t\n";
	cout << " 15 \t\t spicy chicken with egg \t 40.00 L.E \t\t\n 16 \t\t chicken with egg\t\t 36.00 L.E\t\t\n ";
	cout << "17 \t\t cheese burger \t\t\t 50.00 L.E \t\t\n 18 \t\t spicy crispy chicken\t\t 55.00 L.E\t\t\n";
	cout << " 19 \t\t crispy chicken sw \t\t 45.00 L.E \t\t\n 20 \t\t double cheese burger\t\t 55.00 L.E\t\t\n";
	cout << "\n***********************************************************" << endl;
	cout << "\t\t\t DRINKS \t\t\t\t" << endl;
	cout << "\n***********************************************************" << endl;
	cout << " ID \t\t name \t\t\t\t price  \t\t " << endl;
	cout << "\t\t *\t\t\t\t *" << endl;
	cout << " 21 \t\t ice tea \t\t\t 30.00 L.E \t\t\n 22 \t\t ice coffee \t\t\t 35.00 L.E \t\t\n";
	cout << " 23 \t\t ice choclate \t\t\t 35.00 L.E \t\t\n 24 \t\t smothie \t\t\t 20.00 L.E \t\t\n";
	cout << " 25 \t\t orange juce \t\t\t 15.00 L.E \t\t\n 26 \t\t mojito \t\t\t 16.00 L.E \t\t\n";
	cout << " 27 \t\t tea \t\t\t\t 10.00 L.E \t\t\n 28 \t\t turkish coffee \t\t 20.00 L.E \t\t\n";
	cout << " 29 \t\t hot chocolate \t\t\t 25.00 L.E \t\t\n 30 \t\t cappuccino \t\t\t 25.00 L.E \t\t\n";
	cout << "\n***********************************************************" << endl;
}
// Abdallah Mohsen
void search(int ID[], int count)
{
	string food[size] = { "roast beef with rice", "roast chicken with rice" , "chicken grill with rice" , "hawawshi" , " kofta with rice" , " spaghetti" , " meat casserole with rice" , "chicken casserole with rice" , "sea food soup" , "kofta with spaghetti" , "chicken fillet" , "grand chicken spicy" , "spicy chicken" , "egg with cheese wrap" , "spicy chicken with egg" , "chicken with egg" , "cheese burger" , " spicy crispy chicken" , "crispy chicken sw" , "double cheese burger" , "ice tea" , "ice coffee" , "ice choclate" , "smothie" , "orange juce" , "mojito" , "tea" , " turkish coffee" , "hot chocolate" , "cappuccino" };
	string search;
	bool ch = 0;
	int num;
	char  x;

	do
	{
		cout << "\nDo you want search in menu (y/n) :  ";
		cin >> x;
		if (x == 'Y' || x == 'y')
		{
			cout << "\nenter the meal / drink / dessert you want to search for :  ";
			cin.ignore();
			getline(cin, search);
			transform(search.begin(), search.end(), search.begin(), ::tolower);
			for (int j = 0; j < 30; j++)
			{
				if (search == food[j])
				{
					ch = 1;
					num = j + 1; // ID num of the food item
					break;
				}
				else
					ch = 0;
			}
			if (ch == 1)cout << "\nthis meal is found \nthe number of this is  :  " << num << endl;
			else cout << "\nthis meal is not found in the menu" << endl;
			cout << "\n***********************************************************" << endl;
			continue;
		}
		else if (x == 'N' || x == 'n')	break;
		else
		{
			cout << "PLEASE ANSWER WITH (Y/N) ONLY !! ";
			continue;
		}
	} while (true);
}
//Hana Mohsen
void cases(int ID[], int i, float& price)
{
	switch (ID[i])
	{
	case 1:  price += 120 * a[0]; cout << a[0] << "\t\t\t roast beef with rice \t\t " << "Meals\t\t\t" << 120.00 * a[0] << " L.E" << endl; break;
	case 2:  price += 120 * a[1]; cout << a[1] << "\t\t\t roast chicken with rice \t" << "Meals\t\t\t" << 120.00 * a[1] << " L.E" << endl; break;
	case 3:  price += 130 * a[2]; cout << a[2] << "\t\t\t chicken grill with rice \t" << "Meals\t\t\t" << 130.00 * a[2] << " L.E" << endl; break;
	case 4:  price += 40 * a[3]; cout << a[3] << "\t\t\t hawawshi \t\t\t" << "Meals\t\t\t" << 40.00 * a[3] << " L.E " << endl; break;
	case 5:  price += 100 * a[4]; cout << a[4] << "\t\t\t kofta with rice \t\t" << "Meals\t\t\t" << 100.00 * a[4] << " L.E " << endl; break;
	case 6:  price += 40 * a[5]; cout << a[5] << "\t\t\t spaghetti \t\t\t" << "Meals\t\t\t" << 40.00 * a[5] << "L.E" << endl; break;
	case 7:  price += 140 * a[6]; cout << a[6] << "\t\t\t meat casserole with rice \t" << "Meals\t\t\t" << 140.00 * a[6] << "L.E" << endl; break;
	case 8:  price += 140 * a[7]; cout << a[7] << "\t\t\t chicken casserole with rice \t" << "Meals\t\t\t" << 140.00 * a[7] << "L.E" << endl; break;
	case 9:  price += 70 * a[8]; cout << a[8] << "\t\t\t sea food soup \t\t\t " << "Meals\t\t\t" << 70.00 * a[8] << "L.E" << endl; break;
	case 10: price += 120 * a[9]; cout << a[9] << "\t\t\t kofta with spaghetti \t\t" << "Meals\t\t\t" << 120.00 * a[9] << "L.E" << endl; break;
	case 11: price += 30 * a[10]; cout << a[10] << "\t\t\t chicken fillet \t\t" << "Meals\t\t\t" << 30.00 * a[10] << "L.E" << endl; break;
	case 12: price += 40 * a[11]; cout << a[11] << "\t\t\t Grand chicken spicy\t\t" << "Sandeiches\t\t\t" << 40.00 * a[11] << "L.E" << endl; break;
	case 13: price += 35 * a[12]; cout << a[12] << "\t\t\t spicy chicken \t\t\t" << "Sandeiches\t\t\t" << 35.00 * a[12] << "L.E" << endl; break;
	case 14: price += 15 * a[13]; cout << a[13] << "\t\t\t egg with sheese wrap\t\t" << "Sandeiches\t\t\t" << 15.00 * a[13] << "L.E" << endl; break;
	case 15: price += 40 * a[14]; cout << a[14] << "\t\t\t spicy chicken with egg \t" << "Sandeiches\t\t\t" << 40.00 * a[14] << "L.E" << endl; break;
	case 16: price += 36 * a[15]; cout << a[15] << "\t\t\t chicken with egg\t\t" << "Sandeiches\t\t\t" << 36.00 * a[15] << "L.E" << endl; break;
	case 17: price += 50 * a[16]; cout << a[16] << "\t\t\t cheese burger \t\t\t" << "Sandeiches\t\t\t" << 50.00 * a[16] << "L.E" << endl; break;
	case 18: price += 55 * a[17]; cout << a[17] << "\t\t\t spicy crispy chicken\t\t" << "Sandeiches\t\t\t" << 55.00 * a[17] << "L.E" << endl; break;
	case 19: price += 45 * a[18]; cout << a[18] << "\t\t\t crispy chicken sw \t\t" << "Sandeiches\t\t\t" << 45.00 * a[18] << "L.E" << endl; break;
	case 20: price += 55 * a[19]; cout << a[19] << "\t\t\t double cheese burger\t\t " << "Sandeiches\t\t\t" << 55.00 * a[19] << "L.E" << endl; break;
	case 21: price += 30 * a[20]; cout << a[20] << "\t\t\t ice tea \t\t\t" << "Sandeiches\t\t\t" << 30.00 * a[20] << "L.E" << endl; break;
	case 22: price += 35 * a[21]; cout << a[21] << "\t\t\t ice coffee \t\t\t" << "Drinks\t\t\t" << 35.00 * a[21] << "L.E" << endl; break;
	case 23: price += 35 * a[22]; cout << a[22] << "\t\t\t ice choclate \t\t\t" << "Drinks\t\t\t" << 35.00 * a[22] << "L.E" << endl; break;
	case 24: price += 20 * a[23]; cout << a[23] << "\t\t\t smothie \t\t\t" << "Drinks\t\t\t" << 20.00 * a[23] << "L.E" << endl; break;
	case 25: price += 15 * a[24]; cout << a[24] << "\t\t\t orange juce \t\t\t" << "Drinks\t\t\t" << 15.00 * a[24] << "L.E" << endl; break;
	case 26: price += 16 * a[25]; cout << a[25] << "\t\t\t mojito \t\t\t" << "Drinks\t\t\t" << 16.00 * a[25] << "L.E" << endl; break;
	case 27: price += 10 * a[26]; cout << a[26] << "\t\t\t tea \t\t\t\t" << "Drinks\t\t\t" << 10.00 * a[26] << "L.E" << endl; break;
	case 28: price += 20 * a[27]; cout << a[27] << "\t\t\t turkish coffee \t\t" << "Drinks\t\t\t" << 20.00 * a[27] << "L.E" << endl; break;
	case 29: price += 25 * a[28]; cout << a[28] << "\t\t\t hot chocolate \t\t\t" << "Drinks\t\t\t" << 25.00 * a[28] << "L.E" << endl; break;
	case 30: price += 25 * a[29]; cout << a[29] << "\t\t\t cappuccino \t\t\t" << "Drinks\t\t\t" << 25.00 * a[29] << "L.E" << endl; break;
	default: price += 0;
	}
}
// Abdallah Mohsen
void order(int ID[], int& count)
{
	int arr[size] = { 0 }, quantity;
	int  c = 1, u;
	cout << "\nTIME TO ORDER ( write the ID of the food item , to end the order enter 0) : " << endl;
	for (int i = 0; i < 100; i++)
	{
		// the user should enter number between 1 to 30 (the ID of the food item )
		cout << "\nitem NO " << c++ << " is :  ";
		cin >> ID[i];
		u = ID[i] - 1;
		if (ID[i] > 30) cout << " not found please try again !" << endl;
		else if (ID[i] > 0 && ID[i] <= 30)
		{
			if (arr[u] != 1)
				count++;
		}
		else break;

		// the quantity of the food item he want 
		arr[u] = 1;
		cout << "\nthe quantity is :  ";
		cin >> quantity;
		if (arr[u] == 1)
		{
			a[u] += quantity;
		}
		else
			a[u] = quantity;


	}
	show_order(ID, count);
}
//Hagar Essam 
void edit(int ID[], int count)
{
	int choice;
	cout << "\n\t __________________________________________\n\n";
	cout << "\t| press 1 to delete an item you ordered      |\n";
	cout << "\t| press 2 to add an item to your order       |\n";
	cout << "\t| press 0 to show the check                  |\n";
	cout << "\t ____________________________________________\n";
	cout << "\n\t Please enter your choice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		del(ID, count, price);
		edit(ID, count);
		break;
	case 2:
		add(ID, count, price);
		edit(ID, count);
		break;
	case 0:
		price = 0;
		show_order(ID, count);
		checkout(price);
		break;
	}
}
//hagar ahmed
void del(int ID[], int count, float& price)
{
	int x;
	do
	{
		cout << "\nEnter the ID of the order number you want to delete (to stop deleting enter 0) :  ";
		cin >> x;
		if (x == 0) break;
		else {
			cout << "\n***********************************************************" << endl;
			cout << "\nYOU ORDERED :" << endl;
			cout << "QUANTITY\t\tITEM NAME\t\t\t\TYPE\t\t\tTOTAL" << endl;
			cout << "  \t\t\t\t\t*\t\t\t*" << endl;
			for (int j = 0; j < count; j++)
			{
				if (ID[j] != x)
				{
					cases(ID, j, price);
				}
				else
				{
					ID[j] = 0;
					continue;
				}
			}
		}
		cout << "\n***********************************************************" << endl;
	} while (x != 0);
	price = 0;
}
//Hagar Essam
void add(int ID[], int& count, float& price)
{
	int i, previousquantity;
	bool keepgoing;
	do
	{
		i = count;
		keepgoing = true;
		cout << "\nwrite the ID of the food item you want to add (to stop adding enter 0):  ";
		cin >> ID[i];
		int u = ID[i] - 1;
		if (ID[i] == 0)
		{
			keepgoing = false;
			break;
		}
		// the user should enter number between 1 to 30 (the ID of the food item )
		else if (ID[i] > 0 && ID[i] <= 30)
		{
			count++;
			cout << "\nthe quantity is :  ";
			if (a[u] == 0)
			{
				cin >> a[u];
				cout << "\nyou added : " << endl;
				cases(ID, i, price);
				cout << "\n***********************************************************" << endl;
			}
			else
			{
				previousquantity = a[u];
				cin >> a[u];
				cout << "you added : " << endl;
				cases(ID, i, price);
				cout << "\n***********************************************************" << endl;
				a[u] += previousquantity;
				ID[i] = 0;
			}
			i++;
			continue;
		}
		else
		{
			cout << " not found please try again !" << endl;
			continue;
		}
	} while (keepgoing == true);
	price = 0;
}
//Hana Mohsen
void show_order(int ID[], int count)
{
	cout << "\n***********************************************************" << endl;
	cout << "YOU ORDERED :" << endl;
	cout << "\nQUANTITY\t\tITEM NAME\t\t\t\TYPE\t\t\tTOTAL" << endl;
	cout << " *\t\t\t\t\t*\t\t\t*" << endl;
	for (int i = 0; i < count; i++)
	{
		cases(ID, i, price);
	}
	cout << "\n***********************************************************" << endl;
	cout << "\nITEMS PRICE  ( WITHOUT 15% TAX ) :  " << price << endl;

}
//Mozzamel
void checkout(float price)
{
	float UserWallet;
	float tax = price * 0.15;
	cout << "\nTHE TAX (%15) IS :  " << tax << endl;
	cout << "TOTAL PRICE IS  :  " << price + tax << endl;
	cout << "\n***********************************************************" << endl;
	cout << "THE MONEY YOU WILL PAY IS :  ";
	cin >> UserWallet;
	if (UserWallet >= (price + tax)) cout << "* the rest of your money is :   " << UserWallet - (price + tax) << endl;
	else if (UserWallet < (price + tax)) {
		cout << " * sorry.. your money isnt enough * " << endl;
		cout << "THE MONEY YOU WILL PAY IS :  ";
		cin >> UserWallet;
		if (UserWallet >= (price + tax)) cout << "* the rest of your money is :   " << UserWallet - (price + tax) << endl;

	}
	cout << "\n***********************************************************" << endl;
	cout << "\n\t * THANK YOU FOR VISITING US * " << endl;
	cout << "\n***********************************************************" << endl;
}