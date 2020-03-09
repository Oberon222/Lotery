#include <iostream>
#include <string>
#include <ctime>
#include <list>
using namespace std;
int money = 0;
int YesNo = 0;
int add_money = 0;
int numb_door = 0;
int Door[7];
int counter = 6;
int counterPrize = 3;

int Prize(int Door[], int size, int money, int YesNo, int counterPrize) {
	cout << "You want to guess what door your prize is - press 1 if you want to stop the game - press 2.";
	cin >> YesNo;
	if (YesNo == 1 && money>50) {
		money -= 50;
		cout << "In your account -> " << money << " $" << endl;
		for (int i = 0; i < size; i++) {
			Door[i] = rand() % 7;
			cout << " Choose one of the ten doors behind which your prize lies ->";
			cin >> numb_door;
		
			if (Door[numb_door-1] == 1) {
				cout << "Congratulations !!! You won the Yacht !!!" << endl;
				return 0;

			}
			else if (Door[numb_door-1] == 2) {
				cout << "Congratulations !!! You won the House !!!" << endl;
				return 0;
			}

			else if (Door[numb_door-1] == 3) {
				cout << "Congratulations !!! You won the Car !!!" << endl;
				return 0;
			}
			else if (Door[numb_door-1] == 4) {
				cout << "Congratulations !!! You won the PC !!!" << endl;
				return 0;
			}
			else if (Door[numb_door-1] == 5) {
				cout << "Congratulations !!! You won the 1$ !!!" << endl;
				return 0;
			}
			else if (Door[numb_door-1] == 6) {
				cout << "Congratulations !!! You won the 1 000 000 $ !!!" << endl;
				return 0;
			}

			else {
				cout << "Unfortunately you didn't win anything ..." << endl;
				Prize(Door, size, money, YesNo, counterPrize -1);
				return 0;
			}
		}
	}

	if (YesNo == 1 && money < 50)
	{
		cout << "Not enough money in the account!" << endl;
		cout << "Add money -> " << endl;
		cin >> add_money;
		money += add_money;
		Prize(Door, size, money, YesNo, counter - 1);
	}
	else  {
		cout << "Goodbye" << endl;
	}
}

void myNewFunction() {
	//lalal
}

int lottery (int money,int counter) {
	int numb = rand() % 5;
	int player_numb = 0;
	   
		money -= 200;
		cout << "In your account -> " << money << " $" << endl;
		cout << "Enter your number from 1 to 5 ->";
		cin >> player_numb;
		if (money > 0 && player_numb == numb) {
			cout << "Congratulations, you guessed the number !!!" << endl;
			Prize(Door,  10,  money, YesNo, counter);
		}
		
		if (money > 0 && player_numb != numb && counter >=0) {
			cout << "Unfortunately you didn't guess the number ..." << endl;
			counter--;
			cout << "Want to try again - press 1, if you want to finish the game - press 2" << endl;
			cin >> YesNo;
			if (YesNo == 1 && money>200) {
				lottery(money,counter-1);
			}
			else if (YesNo == 1 && money < 200) 
			{
				cout << "Not enough money in the account!" << endl;
				cout << "Add money -> " << endl;
				cin >> add_money;
				money += add_money;
				lottery(money, counter - 1);
			}

			else {
				cout << "Goodbye" << endl;
				return 0;
			}
		}

		if (money < 0) {
			cout << "Not enough money in the account!" << endl;
			cout << "Add money -> " << endl;
			cin >> add_money;
			money += add_money;		
			lottery(money,counter-1);
		}
		if (counter < 0) {
			cout << "You have made every attempt to guess the number." << endl;
			return 0;
		}
}


int main() {
	srand(time(0));
	cout << "Enter money ->";
	cin >> money;
	cout << "If you want to start the game - press 1, if not - press 2" << endl;
	cin >> YesNo;
	if (YesNo == 1) {
		lottery(money,counter);
	}
	else {
		cout << "Good luck next time" << endl;
	}
	
	system("pause");
	return 0;
}