//���ڶ���value��������ԺͲ���
#ifndef SDTTLV_WRITER_H_
#define SDTTLV_WRITER_H_


#include"Value.h"
#include"Base.h"
#include"comonDef.h"

#include<map>
#include<vector>
using namespace std;

namespace SDTTLV
{
	

	class SDTTLV_API Writer : public baseReaderWriter
	{
	public:
		Writer(){};
		~Writer(){};
	public:
		void * toData(Value &root,int &len);

		char *toStyleString(Value &root);//������������string���ͽṹ����� 
		
	};


};
#endif