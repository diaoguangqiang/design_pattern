#include <stdio.h>

#pragma once
class CSingleton
{
public:
	static CSingleton* getInstance() {
		return m_instance;
	}

	void fun();

private:
	CSingleton() { printf("初始化\n"); };
	~CSingleton() { printf("析构\n"); };

	//把复制构造函数和=操作符也设为私有,防止被复制
	CSingleton(const CSingleton&) { printf("拷贝构造\n"); } 
	CSingleton& operator=(const CSingleton&) { printf("赋值构造\n"); }

	static CSingleton* m_instance;

	class CGarbo
	{
		public:
			~CGarbo() {
				if ( CSingleton::m_instance )
				{
					delete m_instance;
					m_instance = 0;

					printf("回收\n");
				}
			}
	};

	static CGarbo garbo;
};


