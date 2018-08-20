#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include"gate.h"
#include<iostream>
#include<Windows.h>
using namespace std;

int AND_num = 0;   //记录各个门的个数
int OR_num = 0;
int NOT_num = 0;
int EO_num = 0;
int EN_num = 0;
int NAND_num = 0;
int NOR_num = 0;
vector <Node> library;   //存放所有门
Gate* cptr = nullptr;
Node* nptr = nullptr;
cross cdot;         //输入的节点

void help();
void creat();
void see();
void connect();
void set();
void run();
void creat_name(Node*, string, int);
void check_pin();

void help() {
	system("cls");
	cout <<endl<< "Please read \"README\" and the REPORT carefully!!!" << endl<<endl;
	cout<<"【create】\n"
		"根据用户输入，产生对应的器件，并将Node和class匹配，自动生成器件名和引脚名\n"
		"【see】\n"
		"显示引脚状态，显示引脚的当前值\n"
		"【connect】\n"
		"格式————【pin name + pin name】(There is no space around '+'!Press - 1 to end)\n"
		"按指令连接器件，其中一些操作，会抛出异常。如：输出与输出连接，自身输入和自身输出相连；如果指令格式错误或器件名错误或器件不存在也会抛出异常。\n"
		"【set value】\n"
		"格式————【pin name = X】(X = 0 or 1.There is no space around '='!Press - 1 to end)\n"
		"为当前悬空引脚赋值。如果指令格式错误或器件名错误或器件不存在会抛出异常。\n"
		"赋值为0表示低电平，赋值为1或任意非零整数表示高电平。\n"
		"注意：为实现对一组器件的重复测试，程序设定，在第一个赋值操作开始时，将所有器件的当前值都重置。即，每次赋值操作都会覆盖所有器件之前的值。\n"
		"【check & run】\n"
		"对于所有器件，输入引脚不悬空，或悬空但被赋值，即可进行下一步检测。\n"
		"检查是否有环，并运行。\n"
		"思路：对library中所有门 只有当两个输入引脚都被赋值，该门才能进行运算，运行后将结果赋给下一个门。 以这种方式，在while中循环一次，至少有一个门会进行运算并为下个门赋值，while的最多循环次数与门个数相同。即，while循环次数大于门的总个数时就出现了环，报错！！！\n"
		"运行完后，可以按0 查看每个门的每个引脚的值\n"
		"注：运行结束后，可返回主菜单，再选择set value 进行另一组赋值，再运行。"<<endl;
	system("pause");
}

void creat()         //创建门
{
	string cmd;
	int num;
	int i;
	do {
		system("cls");
		cout << "Which kind of gate do you want to creat?(Press -1 to end)" << endl;
		cout << "1:and gate  2:or gate 3:not gate  4:exclusive or  5:exclusive nor  6:nand  7:nor" << endl;
		try {
			cin >> cmd;
			if (cmd == "-1")
				break;
			if (cmd.size()>1)                                                       //“throw runtime_error” 检测cmd输入和num输入的规范性
				throw runtime_error("Your command is illegal!!!");
			if (cmd[0] - '0'<0 || cmd[0] - '0'>7)
				throw runtime_error("Your command is illegal!!!");
			cout << "How many gates do you want to creat?" << endl;
			cin >> num;
			if (num <= 0) {
				throw runtime_error("The number of the gate must be positive!!!");
			}
			switch (cmd[0] - '0') {
			case 1:
				for (i = 0; i < num; i++) {
					AND_num++;
					cptr = new gate_and;      //创建门 class
					nptr = new Node(cptr);    //创建门 node
					creat_name(nptr, "and", AND_num);   //创建Node中的各个名字
					cptr->set_node(nptr);
					nptr->obj = cptr;
					library.push_back(*nptr);  
				}
				cout << "You have greated " << num << " AND Gate(s)" << endl << endl;
				break;
			case 2:    //同case1
				for (i = 0; i < num; i++) {
					OR_num++;
					cptr = new gate_or;
					nptr = new Node(cptr);
					creat_name(nptr, "or", OR_num);
					cptr->set_node(nptr);
					nptr->obj = cptr;
					library.push_back(*nptr);
				}
				cout << "You have greated " << num << " OR Gate(s)" << endl;
				break;
			case 3:    //同case1
				for (i = 0; i < num; i++) {
					NOT_num++;
					cptr = new gate_not;
					nptr = new Node(cptr);
					creat_name(nptr, "not", NOT_num);
					cptr->set_node(nptr);
					nptr->obj = cptr;
					library.push_back(*nptr);
				}
				cout << "You have greated " << num << " NOT Gate(s)" << endl;
				break;
			case 4:    //同case1
				for (i = 0; i < num; i++) {
					EO_num++;
					cptr = new gate_exclusive_or;
					nptr = new Node(cptr);
					creat_name(nptr, "exclusiveOR", EO_num);
					cptr->set_node(nptr);
					nptr->obj = cptr;
					library.push_back(*nptr);
				}
				cout << "You have greated " << num << " exclusive_or Gate(s)" << endl;
				break;
			case 5:     //同case1
				for (i = 0; i < num; i++) {
					EN_num++;
					cptr = new gate_exclusive_nor;
					nptr = new Node(cptr);
					creat_name(nptr, "exclusiveNOR", EN_num);
					cptr->set_node(nptr);
					nptr->obj = cptr;
					library.push_back(*nptr);
				}
				cout << "You have greated " << num << " exclusive_nor Gate(s)" << endl;
				break;
			case 6:    //同case1
				for (i = 0; i < num; i++) {
					NAND_num++;
					cptr = new gate_nand;
					nptr = new Node(cptr);
					creat_name(nptr, "nand", NAND_num);
					cptr->set_node(nptr);
					nptr->obj = cptr;
					library.push_back(*nptr);
				}
				cout << "You have greated " << num << " NAND Gate(s)" << endl << endl;
				break;
			case 7:    //同case1
				for (i = 0; i < num; i++) {
					NOR_num++;
					cptr = new gate_nor;
					nptr = new Node(cptr);
					creat_name(nptr, "nor", NOR_num);
					cptr->set_node(nptr);
					nptr->obj = cptr;
					library.push_back(*nptr);
				}
				cout << "You have greated " << num << " NOR Gate(s)" << endl;
				break;
			default:
				throw runtime_error("Your command is illegal!!!");
			}
		}
		catch (runtime_error ex) {
			cout << ex.what() << endl;
		}
		Sleep(1000);
	} while (1);
	Sleep(200);
}

void see()
{
	system("cls");
	cout << "You have " << AND_num << " AND Gates" << endl;
	cout << "You have " << OR_num << " OR Gates" << endl;
	cout << "You have " << NOT_num << " NOT Gates" << endl;
	cout << "You have " << EO_num << " exclusive_or Gates" << endl;
	cout << "You have " << EN_num << " exclusive_nor Gates" << endl;
	cout << "You have " << NAND_num << " NAND Gates" << endl;
	cout << "You have " << NOR_num << " NOR Gates" << endl;
	cout << "These pins are available:" << endl << endl;
	check_pin();
	system("pause");
}

void connect() {
	string line; //用户输入指令
	string port1; //引脚1名称
	string port2; //引脚2名称
	string gate1; //门1名称
	string gate2; //门2名称
	Node* n1 = nullptr;  // 门指针
	Node* n2 = nullptr;
	int pos, i;
	while (line != "-1") {
		system("cls");
		cout << "These pins are available:" << endl << endl;
		check_pin();
		cout << "Please connect in a format like: \"pin name+pin name\"(There is no space around '+'! Press -1 to end)" << endl;
		try {
			cin >> line;
			if (line == "-1")
				break;
			pos = line.find('+');          
			if (pos <= 0)
				throw runtime_error("Check your command's format!!!");  //检查指令格式
			for (i = 0; i < pos; i++) {
				port1 += line[i];
			}
			for (++i; i < line.length(); i++) {
				port2 += line[i];
			}
			pos = port1.find('_');    //检查门的名称或格式
			if (pos <= 0)
				throw runtime_error("Check your command's format or pin's name!!!");
			for (i = 0; i < pos; i++) {
				gate1 += port1[i];
			}
			pos = port2.find('_');   //检查门的名称或格式
			if (pos <= 0)         
				throw runtime_error("Check your command's format or pin's name!!!");
			for (i = 0; i < pos; i++) {
				gate2 += port2[i];
			}
			for (i = 0; i < library.size(); i++) {
				if (library[i].name == gate1) {
					n1 = &library[i];
				}
				if (library[i].name == gate2) {
					n2 = &library[i];
				}
			}
			if (n1 == nullptr || n2 == nullptr)       //检查该门是否存在
				throw runtime_error("Check your pin's name!!!");
			if (port1.back() != 't'&&port2.back() != 't') {
				if (port1.back() != '2') {
					if (n1->obj->get_seted1() == false) {
						cdot.dot1[n1].push_back(n2);
						n1->in1_cross = true;
					}
					else {
						throw runtime_error("Something wrong!!!");    //不允许a+b b+c c+d ,只能a+b a+c a+d  (其中 a,b,c,d均为输入引脚)
					}
				}
				else {
					if (n1->obj->get_seted2() == false) {
						cdot.dot2[n1].push_back(n2);
						n1->in2_cross = true;
					}
					else {
						throw runtime_error("Something wrong!!!");   //不允许a+b b+c c+d ,只能a+b a+c a+d  (其中 a,b,c,d均为输入引脚)
					}
				}
				if (port2.back() != '2')
					n2->obj->set_seted1(true);
				else
					n2->obj->set_seted2(true);
			}
			else {
				if (port1.back() == 't'&& port2.back() == 't')
					throw runtime_error("WARNING:you can't put two \"out\" pins together!!!");   //两个输出不能相连
				if (n1 == n2)
					throw runtime_error("WARNING:there might be an Infinite loop!!!");  //自身输入和输出不能相连
				switch (port1.back()) {
				case 't':
					n1->out.push_back(n2);
					n1->obj->set_seted3(true);
					break;
				case '1':
					n1->in1 = n2;
					n1->obj->set_seted1(true);
					break;
				case '2':
					n1->in2 = n2;
					n1->obj->set_seted2(true);
					break;
				case'n':
					n1->in1 = n2;
					n1->obj->set_seted1(true);
					break;
				}
				switch (port2.back()) {
				case 't':
					n2->out.push_back(n1);
					n2->obj->set_seted3(true);
					break;
				case '1':
					n2->in1 = n1;
					n2->obj->set_seted1(true);
					break;
				case '2':
					n2->in2 = n1;
					n2->obj->set_seted2(true);
					break;
				}
			}
			line = "";
			port1 = "";
			port2 = "";
			gate1 = "";
			gate2 = "";
		}
		catch (runtime_error ex) {
			cout << ex.what() << endl;
			Sleep(1000);
		}
	}
	system("pause");
}

void set() {
	string line;
	string port;
	bool value;
	string gate;
	Node* n = nullptr;
	int pos, i, j;
	bool first = true;
	while (line != "-1") {
		system("cls");
		cout << "These pins are available:" << endl << endl;
		check_pin();
		cout << "Please connect in a format like: \"pin name=X\"(X=0 or 1.There is no space around '='! Press -1 to end)" << endl;
		try {
			cin >> line;
			if (line == "-1")
				break;
			pos = line.find('=');  //检查指令格式
			if (pos <= 0)
				throw runtime_error("Check your command's format!!!");
			for (i = 0; i < pos; i++) {
				port += line[i];
			}
			if (line[++i] == '0')
				value = false;
			else
				value = true;
			pos = port.find('_');  //检查门的名称或格式 
			if (pos <= 0)
				throw runtime_error("Check your pin's name!!!");
			for (i = 0; i < pos; i++) {
				gate += port[i];
			}
			for (i = 0; i < library.size(); i++) {
				if (library[i].name == gate) {
					n = &library[i];
				}
			}
			if (n == nullptr)
				throw runtime_error("Check your pin's name!!!");   //检查门是否存在
			if (port.back() == 't')
				throw runtime_error("You can't set a value for the output!!!");    //不能为输出引脚赋值
			if (first == true) {                                     
				first = false;
				for (j = 0; j < library.size(); j++) {        //开始设定后 将所有门的 是否有值状态设为 假。  可以实现重复设置
					library[j].obj->set_have_value1(false);
					if (library[j].obj->get_in_port() != 1)
						library[j].obj->set_have_value2(false);
				}
			}
			switch (port.back()) {
			case '1':
				n->obj->set_in1(value);
				n->obj->set_have_value1(true);
				if (n->in1_cross == true) {
					for (j = 0; j < cdot.dot1[n].size(); j++) {    //如果有其他输入 与该引脚相连 为其他输入赋值
						if (cdot.dot1[n][j]->obj->get_have_value1() == false) {
							cdot.dot1[n][j]->obj->set_in1(value);
							cdot.dot1[n][j]->obj->set_have_value1(true);
						}
						else if (cdot.dot1[n][j]->obj->get_have_value2() == false) {
							cdot.dot1[n][j]->obj->set_in2(value);
							cdot.dot1[n][j]->obj->set_have_value2(true);
						}
					}
				}
				break;
			case '2':
				n->obj->set_in2(value);
				n->obj->set_have_value2(true);
				if (n->in2_cross == true) {
					for (j = 0; j < cdot.dot2[n].size(); j++) {    //如果有其他输入 与该引脚相连 为其他输入赋值
						if (cdot.dot2[n][j]->obj->get_have_value1() == false) {
							cdot.dot2[n][j]->obj->set_in1(value);
							cdot.dot2[n][j]->obj->set_have_value1(true);
						}
						else if (cdot.dot2[n][j]->obj->get_have_value2() == false) {
							cdot.dot2[n][j]->obj->set_in2(value);
							cdot.dot2[n][j]->obj->set_have_value2(true);
						}
					}
				}
				break;
			case 'n':
				n->obj->set_in1(value);
				if (n->in1_cross == true) {
					for (j = 0; j < cdot.dot1[n].size(); j++) {          //如果有其他输入 与该引脚相连 为其他输入赋值
						if (cdot.dot1[n][j]->obj->get_have_value1() == false) {
							cdot.dot1[n][j]->obj->set_in1(value);
							cdot.dot1[n][j]->obj->set_have_value1(true);
						}
						else if (cdot.dot1[n][j]->obj->get_have_value2() == false) {
							cdot.dot1[n][j]->obj->set_in2(value);
							cdot.dot1[n][j]->obj->set_have_value2(true);
						}
					}
				}
				n->obj->set_have_value1(true);
				break;
			}
			line = "";
			port = "";
			gate = "";
		}
		catch (runtime_error ex)
		{
			cout << ex.what() << endl;
			Sleep(1000);
		}
	}
	system("pause");
}

void run() {
	system("cls");
	int i, j, cmd;
	int ctime;
	bool result = false;
	if (library.empty()) {   //检查设计是否为空
		cout << "The design is empty. Please creat atleast one gate and set inputs." << endl;
	}
	try {
		ctime = 0;
		for (i = 0; i < library.size(); i++) {
			if (!library[i].obj->ifrun()) {   //检查是否存在引脚悬空 和 悬空引脚是否被赋值
				cout << "There are some pins with no input(s). Please connect them or set inputs." << endl << endl;
				throw 1;
			}
		}
 //检查是否有环，并运行      
//思路：对library中所有门 只有当两个输入引脚都被赋值，该门才能运行，运行后将结果赋给下一个门。 
//以这种方式，在while中循环一次，至少有一个门会运行，最多运行次数与门个数相同，否则就出现了环，报错！！！
			while (!result) {
			if (ctime>library.size() + 1)
				throw runtime_error("The design is wrong. Infinite loop!!!!");
			result = true;
			for (i = 0; i < library.size(); i++) {
				if (library[i].obj->get_have_value1() == true && library[i].obj->get_have_value2() == true) {
					library[i].obj->output();
					if (!library[i].out.empty()) {
						for (j = 0; j < library[i].out.size(); j++) {
							if (library[i].out[j]->obj->get_have_value1() == false) {
								library[i].out[j]->obj->set_in1(library[i].obj->get_out());
								library[i].out[j]->obj->set_have_value1(true);
							}
							else if (library[i].out[j]->obj->get_have_value2() == false) {
								library[i].out[j]->obj->set_in2(library[i].obj->get_out());
								library[i].out[j]->obj->set_have_value2(true);
							}
						}
					}
				}
				else {
					result = false;
				}
			}
			ctime++;
		}
		if (library.empty())
			result = false;
		if (result == true) {  //如果有结果 输出
			for (i = 0; i < library.size(); i++) {
				if (library[i].out.empty()) {
					cout << "--------------------" << endl;
					cout << library[i].name << " :  " << library[i].obj << endl;
				}
			}
			cout << "--------------------" << endl;
			cout << "press [0] to watch each gates input(s) and output." << endl;
			cin >> cmd;
			if (cmd == 0) {   //按0 查看所有门的状态
				for (i = 0; i < library.size(); i++) {
					if (library[i].obj->get_in_port() == 2) {
						cout << library[i].pin1 << " :  " << library[i].obj->get_in1() << endl;
						cout << library[i].pin2 << " :  " << library[i].obj->get_in2() << endl;
						cout << library[i].pinout << " :  " << library[i].obj << endl << endl;
					}
					else {
						cout << library[i].pin1 << " :  " << library[i].obj->get_in1() << endl;
						cout << library[i].pinout << " :  " << library[i].obj << endl << endl;
					}
				}
			}
		}
		system("pause");
	}
	catch (int) {
		check_pin();
		system("pause");
	}
}

void creat_name(Node* t, string s, int n) {
	t->name = s + to_string(n);
	if (s != "not") {
		t->pin1 = t->name + "_in1";
		t->pin2 = t->name + "_in2";
	}
	else {
		t->pin1 = t->name + "_in";
		t->pin2 = t->name + "_in";
	}
	t->pinout = t->name + "_out";
}

void check_pin() {
	int i;
	for (i = 0; i < library.size(); i++)
	{
		if (library[i].obj->get_seted1() == false) {
			cout << "  in:   " << library[i].pin1;
			if (library[i].obj->get_have_value1() == true) {
				cout << "  with value: " << library[i].obj->get_in1() << endl;
			}
			else {
				cout << "  with no value" << endl;
			}
		}
		if (library[i].obj->get_seted2() == false) {
			cout << "  in:   " << library[i].pin2;
			if (library[i].obj->get_have_value2() == true) {
				cout << "  with value: " << library[i].obj->get_in2() << endl;
			}
			else {
				cout << "  with no value" << endl;
			}
		}
		cout << "  out:  " << library[i].pinout;
		cout <<"  has " <<library[i].out.size()<<" connections"<<endl;
		if (library[i].obj->get_seted1() == false || library[i].obj->get_seted2() == false || library[i].obj->get_seted3() == false)
			cout << endl;
	}
	cout << endl;
}

#endif