#include"Value.h"

namespace SDTTLV
{

 Value::Value()
 {

 }
Value::~ Value()
{

}

int Value::setValue(ValueType &type,short tag,void *Value,int &len,Value::ValueAndType *&vtRet)
{
 vtRet=NULL;
 
 if(type<=objectValue&&type>=nullValue)
 {
	Value::ValueAndType& vt_= ttv_[tag];
	vt_.type_=type;
	switch (type)
	{

	case nullValue: //= 0, /// 'null' value
		vt_.value_.null_=0;
		
		break;
	case	shortValue:    //short value
		vt_.value_.short_=*(short*)Value;

		
		break;
	case    intValue:      /// signed integer value
		vt_.value_.int_=*( int*)Value;
		
		break;
	case	uintValue:     /// unsigned integer value
		vt_.value_.uint_=*(unsigned int*)Value;
		
		break;
	case	int64Value:   //long long value
		ttv_[tag].value_.int64_=*(int64*)Value;
		
		break;
	case	uint64Value:   //unsigned long long value
		vt_.value_.uint64_=*(uint64*)Value;
		break;
	case	realValue:     /// double value
		vt_.value_.real_=*(double*)Value;
		break;
	case	stringValue:   /// UTF-8 string value
		{
			vt_.value_.string_=new TString;
			if(vt_.value_.string_)
			{
				bool bret= vt_.value_.string_->SetData((char*)Value,len);
				if(!bret)return -1;
			}
			else
				return -1;
		}
		break;
	case	booleanValue:  /// bool value

		vt_.value_.bool_=*(bool*)Value;
		break;
		
	case	bytesValue:    //binary  value
		{
			vt_.value_.bytes_=new TString;
			if(vt_.value_.bytes_)
			{
				bool bret= vt_.value_.bytes_->SetData((unsigned char*)Value,len);
				if(bret)
				{
				 
				}
				else
				{
				 return -1;
				}
			}
			else
				{
				  return -1;
				}
		}
		break;
	case	arrayValue:   /// array value (ordered list)
		{
			vt_.value_.array_=new TArray;
			if(vt_.value_.array_)
			{
				
			}
			else
			{
				 return -1;
			}
		}
		break;
	case	objectValue: 
		{
			vt_.value_.object_=new ObjectValues;
			if(vt_.value_.object_)
			{
				
			}
			else
			{
				 return -1;
			}
		}
		break;
	default:
		 return -1;
		break;
	}
	vtRet=&vt_;
	return 0;
	
 }
	
	return -2;
}

int Value::getValue(short tag,Value::ValueAndType* &vtRet)
{
	if(ttv_.find(tag)==ttv_.end())
	{		
		return -1;
	}	
	vtRet= &(ttv_[tag]);
	return 0;
}












};