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
	CSingleton() { printf("��ʼ��\n"); };
	~CSingleton() { printf("����\n"); };

	//�Ѹ��ƹ��캯����=������Ҳ��Ϊ˽��,��ֹ������
	CSingleton(const CSingleton&) { printf("��������\n"); } 
	CSingleton& operator=(const CSingleton&) { printf("��ֵ����\n"); }

	static CSingleton* m_instance;

	class CGarbo
	{
		public:
			~CGarbo() {
				if ( CSingleton::m_instance )
				{
					delete m_instance;
					m_instance = 0;

					printf("����\n");
				}
			}
	};

	static CGarbo garbo;
};


