#include "singleton.h"

CSingleton* CSingleton::m_instance = new CSingleton();

int main() {

	CSingleton* g_instance1 = CSingleton::getInstance();
	CSingleton* g_instance2 = g_instance1; //拷贝构造
	CSingleton* g_instance3 = 0;
	g_instance3 = g_instance2; //赋值构造
	CSingleton* g_instance4 = CSingleton::getInstance();

	g_instance1->fun();
	g_instance2->fun();
	g_instance3->fun();
	g_instance4->fun();

	return 0;
}