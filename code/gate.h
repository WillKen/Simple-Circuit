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
	bool seted1;  //����1�����Ƿ�����
	bool seted2;  //����2�����Ƿ�����
	bool seted3;  //��������Ƿ�����
	bool have_value1;   //����1 �Ƿ���ֵ
	bool have_value2;   //����2 �Ƿ���ֵ
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
	map<Node*, vector<Node*>> dot1; //��¼����������1 �ಢ������������
	map<Node*, vector<Node*>> dot2; //��¼����������2 �ಢ������������
};

struct Node {
	Gate* obj;
	Node* in1;
	Node* in2;
	vector<Node*> out;   //��¼����Ľӵ��ַ ʹ��vector����Ϊ��������ж��
	bool in1_cross;      //����1�Ƿ��нڵ㣨�Ƿ��������������䲢����
	bool in2_cross;      //����2�Ƿ��нڵ㣨�Ƿ��������������䲢����
	string name;         //��¼�ڵ������
	string pin1;         //��¼����1����
	string pin2;         //��¼һ��2����
	string pinout;       //��¼�����������
	Node(Gate* device) {
		obj = device;
		in1_cross = false;
		in2_cross = false;
		in1 = nullptr;
		in2 = nullptr;
	}
};
#endif