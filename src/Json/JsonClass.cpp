#include "Json/JsonClass.h"


namespace json_functions {


	std::string RandomJsonPrettyPrint(json objectDump)
	{
		std::string tmp = objectDump.dump(2);
		return tmp;
	}


}


namespace json_struct {



}