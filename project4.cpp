#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;

enum { MAKE = 1, DEPOSIT = 2, WITHDRAW = 3, INQUIRE = 4, EXIT = 5 };

class Account {
private:
	int accID = -1;
	int balance = 0;
	char * cusName;

public:
	Account(int ID, int money, const char * Name) : accID(ID), balance(money)
	{
		cusName = new char[strlen(Name) + 1];
		strcpy(cusName, Name);
	}

	// ����������� ȣ���� ���� �ʹٸ�, explicit�� �ٿ���~
	Account(const Account &acc) : accID(acc.accID), balance(acc.balance)
	{
		cusName = new char[strlen(acc.cusName) + 1];
		strcpy(cusName, acc.cusName);
	}

	void ShowAccInfo()
	{
		cout << "���� ID : " << accID << "\n";
		cout << "�̸� : " << cusName << "\n";
		cout << "�ܾ� : " << balance << "\n\n";
	}

	int GetAccID() const
	{
		return accID;
	}

	void Deposit(int money)
	{
		this->balance += money;
	}

	bool Withdraw(int money)
	{
		if (balance < money)
			return false;
		else {
			this->balance -= money;
			return true;
		}
	}

	~Account()
	{
		delete[]cusName;
	}
};

Account * accArr[100];
int accNum = 0;

void ShowMenu()
{
	cout << "-----Menu-----" << "\n";
	cout << "1. ���°���" << "\n";
	cout << "2. �� ��" << "\n";
	cout << "3. �� ��" << "\n";
	cout << "4. �������� ��ü ���" << "\n";
	cout << "5. ���α׷� ����" << "\n\n";
	cout << "���� : ";
}

void MakeAccount()
{
	int id;
	char name[10];
	int money;
	cout << "[���°���]" << '\n';
	cout << "���� ID : ";
	cin >> id;
	cout << "�̸� : ";
	cin >> name;
	cout << "�Աݾ� : ";
	cin >> money;
	accArr[accNum] = new Account(id, money, name);
	accNum++;
}

void DepositMoney()
{
	cout << "[��		��]" << "\n";
	int id;
	cout << "����ID : ";
	cin >> id;
	int money;
	cout << "�Աݾ� : ";
	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << "\n\n";
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << "\n";
}

void WithdrawMoney()
{
	cout << "[��		��]" << "\n";
	int id;
	cout << "����ID : ";
	cin >> id;
	int money;
	cout << "��ݾ� : ";
	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money))
				cout << money << "�� ��� �Ϸ�\n\n";
			else
				cout << "�ܾ��� �����մϴ�\n\n";
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << "\n\n";
}

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << "\n";
	}
}

int main(void)
{
	int selectNum = 0;
	while (true) {
		ShowMenu();
		cin >> selectNum;
		cout << "\n";
		switch (selectNum) {
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			break;
		}
	}
	return 0;
}