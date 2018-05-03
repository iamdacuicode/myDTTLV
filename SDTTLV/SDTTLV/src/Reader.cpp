#include"Reader.h"

namespace SDTTLV
{
	Value &Reader::Parse(void *pData,int srcLen)
	{
		unsigned char *p=(unsigned char *)pData;
		int hlen=7;
		while(p&&srcLen)
		{
			
			unsigned  char type=0;
			short tag=0;
			int vLen=0;
			memcpy(&type,p,1);
			memcpy(&tag,p+1,2);
			memcpy(&vLen,p+3,4);
			
			p=p+3;
			root.setValue((ValueType)type,tag,(void*)p,);
			


		}
		
		
		return root;
	}


	char *Reader::getValue(char *p,int &srcLen,unsigned char &type,short &tag,int vLen,unsigned char *&pValue)
	{
		return 0;
	}
};