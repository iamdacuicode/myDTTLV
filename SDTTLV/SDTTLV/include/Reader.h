//用于定义value的相关属性和操作
#ifndef SDTTLV_READER_H_
#define SDTTLV_READER_H_


#include"Value.h"
#include"Base.h"
#include"comonDef.h"

#include<map>
#include<vector>
using namespace std;

namespace SDTTLV
{
	

	class SDTTLV_API Reader :public baseReaderWriter
	{
	public:
		Reader(){};
		~Reader(){};

	public:
		Value &Parse(void *pData,int len);

	private:
		char *getValue(char *p,int &srcLen,unsigned char &type,short &tag,int vLen,unsigned char *&pValue);

		
		
	};


};
#endif