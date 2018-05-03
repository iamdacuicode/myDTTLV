//用于定义一般数据的宏定义
#ifndef SDTTLV_COMONDEF_H_
#define SDTTLV_COMONDEF_H_

#ifndef SDTTLV_EXPORTS
#define SDTTLV_API __declspec(dllexport)
#else
#define SDTTLV_API __declspec(dllimport)
#endif


namespace SDTTLV
{

	typedef enum tagValueType
	{
		nullValue = 0, /// 'null' value
		shortValue,    //short value
        intValue,      /// signed integer value
		uintValue,     /// unsigned integer value
		int64Value,   //long long value
		uint64Value,   //unsigned long long value
		realValue,     /// double value
		stringValue,   /// UTF-8 string value
		booleanValue,  /// bool value
		bytesValue,    //binary  value
		arrayValue,    /// array value (ordered list)
		objectValue,    /// object value (collection of name/value pairs).
		

	}ValueType;//use unsigned char 






};



#endif