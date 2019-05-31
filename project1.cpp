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
	cout << "1. 계좌개설" << "\n";
	cout << "2. 입 금" << "\n";
	cout << "3. 출 금" << "\n";
	cout << "4. 계좌정보 전체 출력" << "\n";
	cout << "5. 프로그램 종료" << "\n";
	cout << "선택 : ";
}

void MakeAccount()
{
	cout << "[개좌개설]" << '\n';
	cout << "계좌 ID : ";
	cin >> account[accNum].accID;
	cout << "이름 : ";
	cin >> account[accNum].cusName;
	int money;
	cout << "입금액 : ";
	cin >> money;
	account[accNum].balance += money;
	accNum++;
}

void DepositMoney()
{
	cout << "[입		금]" << "\n";
	int id;
	cout << "계좌ID : ";
	cin >> id;
	for (int i = 0; i < accNum; i++) {
		if (account[i].accID == id) {
			int money;
			cout << "입금액 : ";
			cin >> money;
			account[i].balance += money;
			cout << "입금완료" << "\n";
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
	
	for (int i = 0; i < accNum; i++) {
		if (account[i].accID == id) {
			if (account[i].balance - money < 0) {
				cout << "잔고부족" << "\n";
				return;
			}
			account[i].balance -= money;
			cout << money << "원 출금완료" << "\n";
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << "\n";
}

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++) {
		cout << "게좌 ID : " << account[i].accID << "\n";
		cout << "이 름 : " << account[i].cusName << "\n";
		cout << "잔 액 : " << account[i].balance << "\n";
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