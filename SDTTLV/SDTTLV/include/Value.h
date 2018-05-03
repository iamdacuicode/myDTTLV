//用于定义value的相关属性和操作
#ifndef SDTTLV_VALUE_H_
#define SDTTLV_VALUE_H_

#include"comonDef.h"
#include<map>
#include<vector>
using namespace std;
namespace SDTTLV
{

class data// 存储string和字节数组
{
private:
	char *m_pData;
	bool m_bString;
	unsigned int m_length;
public:
	data(){m_bString=true;m_pData=0;m_length=0;};
	~data(){if(m_pData)delete m_pData;};
public:
	bool SetData(char *pData,unsigned int len)
	{
		if(pData!=0)return false;
		m_length=len;
		m_pData = new char[m_length+1];
		if(m_pData)
		{
			memcpy(m_pData,pData,m_length);
			m_pData[m_length]=0;
		}
		else
			return false;

		
		return true;
	}

	bool SetData(unsigned char *pData,unsigned int len)
	{
		if(pData!=0)return false;
		m_length=len;
		m_pData = new char[m_length];
		if(m_pData)
		{
			memcpy(m_pData,pData,m_length);
		}
		else
			return false;
		m_bString=false;
		return true;
	}

	int getData(std::string &pData)
	{
		//memcpy();
		if(m_bString)
		{
		 if(m_length<=0)return 0;
		 
		 pData=m_pData;
		}
		else
			return -1;

		return (int)m_length;
	}

	int getData(unsigned char *&pData)
	{
		if(m_bString==false)
		{
			if(m_length<=0)return 0;

			pData= new unsigned char[m_length];
			if(pData)
			{
				memcpy(pData,m_pData,m_length);
			}
			else
				return -1;
		}
		else
			return -1;

		return m_length;

	}

	int getData(char *&pData)
	{
		if(m_bString)
		{
			if(m_length<=0)return 0;

			pData= new  char[m_length];
			if(pData)
			{
				memcpy(pData,m_pData,m_length);
			}
			else
				return -1;
		}
		else
			return -1;

		return m_length;
	}

	unsigned int getLength(){return m_length;}

};

class	SDTTLV_API Value
{
private:
	typedef data Tbinary;
	typedef data TString;
    typedef short TagType;
	typedef std::map<TagType, Value> ObjectValues;
	typedef long long int64;
	typedef vector<Value> TArray;
	typedef unsigned long long uint64;


union ValueHolder {	
	void *null_;
	short short_;
    int int_;
    unsigned int uint_;
	int64 int64_;
	uint64 uint64_;
    double real_;
    bool bool_;
	Tbinary *bytes_;
    TString* string_;
	TArray* array_;
    ObjectValues* object_;
 } ;

struct ValueAndType
{
	ValueType type_;
	ValueHolder value_;
};

map<short,ValueAndType>ttv_;

private:

public:
	
	int setValue(ValueType &type,short tag,void *Value,int &len,ValueAndType* &vtRet);
	int getValue(short tag,ValueAndType* &vtRet);
public:
      Value();
	  ~ Value();



};



};



#endif