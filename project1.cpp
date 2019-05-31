#include <iostream>
using namespace std;

enum { MAKE = 1, DEPOSIT = 2, WITHDRAW = 3, INQUIRE = 4, EXIT = 5 };
const int NAME_LEN = 10;

typedef struct {
	int accID = -1;
	int balance = 0;
	char cusName[NAME_LEN];
}Account;

Account account[100];
int accNum = 0;

void ShowMenu()
{
	cout << "-----Menu-----" << "\n";
	cout << "1. ���°���" << "\n";
	cout << "2. �� ��" << "\n";
	cout << "3. �� ��" << "\n";
	cout << "4. �������� ��ü ���" << "\n";
	cout << "5. ���α׷� ����" << "\n";
	cout << "���� : ";
}

void MakeAccount()
{
	cout << "[���°���]" << '\n';
	cout << "���� ID : ";
	cin >> account[accNum].accID;
	cout << "�̸� : ";
	cin >> account[accNum].cusName;
	int money;
	cout << "�Աݾ� : ";
	cin >> money;
	account[accNum].balance += money;
	accNum++;
}

void DepositMoney()
{
	cout << "[��		��]" << "\n";
	int id;
	cout << "����ID : ";
	cin >> id;
	for (int i = 0; i < accNum; i++) {
		if (account[i].accID == id) {
			int money;
			cout << "�Աݾ� : ";
			cin >> money;
			account[i].balance += money;
			cout << "�ԱݿϷ�" << "\n";
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
	
	for (int i = 0; i < accNum; i++) {
		if (account[i].accID == id) {
			if (account[i].balance - money < 0) {
				cout << "�ܰ����" << "\n";
				return;
			}
			account[i].balance -= money;
			cout << money << "�� ��ݿϷ�" << "\n";
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << "\n";
}

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++) {
		cout << "���� ID : " << account[i].accID << "\n";
		cout << "�� �� : " << account[i].cusName << "\n";
		cout << "�� �� : " << account[i].balance << "\n";
	}
}

int main(void)
{
	int selectNum = 0;
	while (true) {
		ShowMenu();
		cin >> selectNum;
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