#ifndef GATE_H
#define GATE_H
#include<string>
#include<vector>
#include<map>
using namespace std;

struct Node;

class Gate {
public:
	Gate();
	virtual bool output() = 0;
	virtual bool ifrun();
	virtual void set_node(Node* x);
	virtual Node* get_node();
	virtual bool get_out();
	virtual void set_in1(bool x);
	virtual bool get_in1();
	virtual void set_in2(bool x);
	virtual bool get_in2();
	virtual void set_seted1(bool x);
	virtual bool get_seted1();
	virtual void set_seted2(bool x);
	virtual bool get_seted2();
	virtual void set_seted3(bool x);
	virtual bool get_seted3();
	virtual void set_have_value1(bool x);
	virtual bool get_have_value1();
	virtual void set_have_value2(bool x);
	virtual bool get_have_value2();
	virtual int get_in_port();
    friend ostream& operator<<(ostream &o, const Gate* s) {
		o << s->out;
		return o;
	}
protected:
	bool out;
	bool in_1;
	bool in_2;
	int in_port;
	bool seted1;  //输入1引脚是否悬空
	bool seted2;  //输入2引脚是否悬空
	bool seted3;  //输出引脚是否悬空
	bool have_value1;   //输入1 是否有值
	bool have_value2;   //输入2 是否有值
	Node* device;
};

class gate_and :public Gate {
public:
	bool output();
};

class gate_or :public Gate {
public:
	bool output();
};

class gate_not :public Gate {
public:
	gate_not();
	bool output();
};

class gate_exclusive_or :public Gate {
public:
	bool output();
};

class gate_exclusive_nor :public Gate {
public:
	bool output();
};

class gate_nand :public Gate {
public:
	bool output();
};

class gate_nor :public Gate {
public:
	bool output();
};

class cross {
public:
	map<Node*, vector<Node*>> dot1; //记录与输入引脚1 相并连的输入引脚
	map<Node*, vector<Node*>> dot2; //记录与输入引脚2 相并连的输入引脚
};

struct Node {
	Gate* obj;
	Node* in1;
	Node* in2;
	vector<Node*> out;   //记录输出的接点地址 使用vector是因为输出可以有多个
	bool in1_cross;      //输入1是否有节点（是否有其他输入与其并联）
	bool in2_cross;      //输入2是否有节点（是否有其他输入与其并联）
	string name;         //记录节点的名字
	string pin1;         //记录引脚1名字
	string pin2;         //记录一脚2名字
	string pinout;       //记录输出引脚名字
	Node(Gate* device) {
		obj = device;
		in1_cross = false;
		in2_cross = false;
		in1 = nullptr;
		in2 = nullptr;
	}
};
#endif