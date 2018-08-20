#include"functions.h"
#include<iostream>
#include<Windows.h>

using namespace std;

int main()
{
	string cmd;
	while (1) {
		system("cls");
		cout << "Welcome to Simple Circuit" << endl << endl;
		cout << "Please choose your command:" << endl;
		cout << "1:creat  2:see  3:connect  4:set input  5:check & run  0:help  x:end" << endl;
		try {
			cin >> cmd;
			if(cmd.size()>1)
				throw runtime_error("Your command is illegal!!!");
			if (cmd == "x")
				break;
			switch (cmd[0]-'0')
			{
			case 0:
				help();
				break;
			case 1:
				creat();
				break;
			case 2:
				see();
				break;
			case 3:
				connect();
				break;
			case 4:
				set();
				break;
			case 5:
				run();
				break;
			default:
				throw runtime_error("Your command is illegal!!!");
				break;
			}
		}
		catch (runtime_error ex)
		{
			cout << ex.what() << endl;
			Sleep(1000);
		}
	}
	return 0;
}

