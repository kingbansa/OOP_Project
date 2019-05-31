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

	// 복사생성자의 호출을 막고 싶다면, explicit를 붙여줘~
	Account(const Account &acc) : accID(acc.accID), balance(acc.balance)
	{
		cusName = new char[strlen(acc.cusName) + 1];
		strcpy(cusName, acc.cusName);
	}

	void ShowAccInfo()
	{
		cout << "계좌 ID : " << accID << "\n";
		cout << "이름 : " << cusName << "\n";
		cout << "잔액 : " << balance << "\n\n";
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
	cout << "1. 계좌개설" << "\n";
	cout << "2. 입 금" << "\n";
	cout << "3. 출 금" << "\n";
	cout << "4. 계좌정보 전체 출력" << "\n";
	cout << "5. 프로그램 종료" << "\n\n";
	cout << "선택 : ";
}

void MakeAccount()
{
	int id;
	char name[10];
	int money;
	cout << "[개좌개설]" << '\n';
	cout << "계좌 ID : ";
	cin >> id;
	cout << "이름 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> money;
	accArr[accNum] = new Account(id, money, name);
	accNum++;
}

void DepositMoney()
{
	cout << "[입		금]" << "\n";
	int id;
	cout << "계좌ID : ";
	cin >> id;
	int money;
	cout << "입금액 : ";
	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입금완료" << "\n\n";
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << "\n";
}

void WithdrawMoney()
{
	cout << "[출		금]" << "\n";
	int id;
	cout << "계좌ID : ";
	cin >> id;
	int money;
	cout << "출금액 : ";
	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money))
				cout << money << "원 출금 완료\n\n";
			else
				cout << "잔액이 부족합니다\n\n";
		}
	}
	cout << "유효하지 않은 ID 입니다." << "\n\n";
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