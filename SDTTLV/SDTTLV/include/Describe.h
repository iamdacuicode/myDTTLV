//用于定义value的相关属性和操作
#ifndef SDTTLV_DESCRIBE_H_
#define SDTTLV_DESCRIBE_H_


#include"comonDef.h"

#include<map>
#include<vector>
using namespace std;

namespace SDTTLV
{
	
	class DecribeTagName
	{
	public:
		DecribeTagName(){m_TagName.clear();};
		~DecribeTagName(){m_TagName.clear();};
		bool isHave(short tag)
		{
			if(m_TagName.find(tag)!=m_TagName.end())return true;
			return false;
		}

		bool isHave(string name)
		{
			if(m_NameTag.find(name)!=m_NameTag.end())return true;
			return false;
		}

		bool setTagName(short tag,string name)
		{
			if(isHave(tag)&&isHave(name))
			{
				m_TagName[tag]=name;
				m_NameTag[name]=tag;
				return true;
			}
			return false;
		}

		bool getNamebyTag(short tag,string &name)
		{
			if(isHave(tag))
			{
				name=m_TagName[tag];
				return true;
			}
			return false;
		}

		bool getTagbyName(string name,short &tag)
		{
			if(isHave(name))
			{
				tag=m_NameTag[name];
				return true;
			}
			return false;

		}

	public:
		map<short,string>m_TagName;
		map<string,short>m_NameTag;
	};

	class SDTTLV_API Describe
	{
	private:
#define DefaultID 0
#define SyncTransmissionID -1
		map<int ,DecribeTagName>m_decribe;//id inttheheader
	public:
		Describe(){};
		~Describe(){};
		
		
		int getDefaultID(){return  DefaultID;};//在没有设置字段对应时候添加默认id

		int getSyncTransmissionID(){return  SyncTransmissionID;};

		bool isHave(int iid);

	public:
		
		
	};


};
#endif