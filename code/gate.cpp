#include "gate.h"

Gate::Gate() {
	in_port = 2;
	device = nullptr;
	seted1 = false;
	seted2 = false;
	seted3 = false;
	have_value1 = false;
	have_value1 = false;
}

bool Gate::ifrun()
{
	if ((seted1 == true || have_value1 == true) && (seted2 == true || have_value2 == true)) //当引脚不悬空 或 引脚有设定的值 可以运行
		return true;
	else
		return false;
}

void Gate::set_node(Node* x)
{
	device = x;
}

Node * Gate::get_node()
{
	return device;
}

bool Gate::get_out()
{
	return out;
}

void Gate::set_in1(bool x)
{
	in_1 = x;
}

bool Gate::get_in1()
{
	return in_1;
}

void Gate::set_in2(bool x)
{
	in_2 = x;
}

bool Gate::get_in2()
{
	return in_2;
}

void Gate::set_seted1(bool x)
{
	seted1 = x;
}

bool Gate::get_seted1()
{
	return seted1;
}

void Gate::set_seted2(bool x)
{
	seted2 = x;
}

bool Gate::get_seted2()
{
	return seted2;
}

void Gate::set_seted3(bool x)
{
	seted3 = x;
}

bool Gate::get_seted3()
{
	return seted3;
}

void Gate::set_have_value1(bool x)
{
	have_value1 = x;
}

bool Gate::get_have_value1()
{
	return have_value1;
}

void Gate::set_have_value2(bool x)
{
	have_value2 = x;
}

bool Gate::get_have_value2()
{
	return have_value2;
}

int Gate::get_in_port()
{
	return in_port;
}

bool gate_and::output()
{
	out = in_1&&in_2;
	return out;
}

bool gate_or::output()
{
	out = in_1 || in_2;
	return out;
}

gate_not::gate_not() // 对于非门 只有一个引脚可用 所以默认将in2悬空和有值状态设为 真
{
	in_port = 1;
	device = nullptr;
	seted1 = false;
	seted2 = true;
	seted3 = false;
	have_value1 = false;
	have_value2 = true;
}

bool gate_not::output()
{
	out = !in_1;
	return out;
}

bool gate_exclusive_or::output()
{
	out = (!in_1&&in_2) || (in_1 && !in_2);
	return out;
}

bool gate_exclusive_nor::output()
{
	out = (!in_1 && !in_2) || (in_1 &&in_2);
	return out;
}

bool gate_nand::output()
{
	out = !(in_1&&in_2);
	return out;
}

bool gate_nor::output()
{
	out = !(in_1 || in_2);
	return out;
}