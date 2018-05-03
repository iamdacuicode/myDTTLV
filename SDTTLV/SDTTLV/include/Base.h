//用于定义value的相关属性和操作
#ifndef SDTTLV_BASE_H_
#define SDTTLV_BASE_H_


#include"Value.h"

#include"comonDef.h"

#include<map>
#include<vector>
using namespace std;

namespace SDTTLV
{
	

	class SDTTLV_API baseReaderWriter
	{
	public:
		baseReaderWriter(){};
		~baseReaderWriter(){};
		Value root;//指向第一个节点
	
	};


};
#endif