#include "stdafx.h"
#include "CppUnitTest.h"

#include "network/protocol/NetObjectProtocol.h"
#include "network/NetType.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MagicZooCoreUnitTest
{
	TEST_CLASS(NetObjectProtocolUnitTest)
	{
	public:
		
		#define PROTOCOL  "\
<o name='UserData'/>\
	<p name='id' tpe='uint32' default='0'/>\
	<p name='account' type='string' default=''/>\
	<p name='level' type='uint8' default='1' />\
</o>\
\
<o name='LoginRequest'>\
	<p name='account' type='string' />\
	<p name='password' type='string' />\
</o>\
\
<o name='LoginResponse'>\
	<p name='result' type='uint8' />\
	<p name='message' type='string' />\
	<p name = 'userData' type = 'UserData' / >\
	<p name = 'friendList' type='array' intype='UserData' />\
	<p name = 'certificate' type='binary' />\
	<p name = 'props' type='array' intype='uint32' />\
</o>\
 "

		TEST_METHOD(createProtocolTest)
		{
			// TODO: Your test code here
			NetObjectProtocol protocol(PROTOCOL);

			Assert::IsTrue(protocol.definedObject.size() == 3,L"对象定数量不符。");

			Assert::IsTrue(protocol.definedObject[0] != nullptr&& protocol.definedObject[0]==protocol.definedObjectMap["UserData"]);

			Assert::IsTrue(protocol.definedObject[1] != nullptr&& protocol.definedObject[1] == protocol.definedObjectMap["LoginRequest"]);

			Assert::IsTrue(protocol.definedObject[2] != nullptr&& protocol.definedObject[2] == protocol.definedObjectMap["LoginResponse"]);


			auto userData = protocol.definedObject[0];
			auto loginRequest = protocol.definedObject[1];
			auto loginResponse = protocol.definedObject[2];

			Assert::IsTrue(userData->id == 0);
			Assert::IsTrue(loginRequest->id == 1);
			Assert::IsTrue(loginResponse->id == 2);

			Assert::IsTrue(userData->name=="UserData");
			Assert::IsTrue(loginRequest->name=="LoginRequest");
			Assert::IsTrue(loginResponse->name == "LoginResponse");

			Assert::IsTrue(userData->property.size()==3);
			Assert::IsTrue(loginRequest->property.size() == 2);
			Assert::IsTrue(loginResponse->property.size() == 6);

			Assert::IsTrue(userData->property[0] != nullptr && userData->property[0]==userData->propertyMap["id"]);
			Assert::IsTrue(userData->property[1] != nullptr && userData->property[1] == userData->propertyMap["account"]);
			Assert::IsTrue(userData->property[2] != nullptr && userData->property[2] == userData->propertyMap["level"]);

			Assert::IsTrue(loginRequest->property[0] != nullptr && loginRequest->property[0] == loginRequest->propertyMap["account"]);
			Assert::IsTrue(loginRequest->property[1] != nullptr && loginRequest->property[1] == loginRequest->propertyMap["password"]);

			Assert::IsTrue(loginResponse->property[0] != nullptr && loginResponse->property[0] == loginResponse->propertyMap["result"]);
			Assert::IsTrue(loginResponse->property[1] != nullptr && loginResponse->property[1] == loginResponse->propertyMap["message"]);
			Assert::IsTrue(loginResponse->property[2] != nullptr && loginResponse->property[2] == loginResponse->propertyMap["userData"]);
			Assert::IsTrue(loginResponse->property[3] != nullptr && loginResponse->property[3] == loginResponse->propertyMap["friendList"]);
			Assert::IsTrue(loginResponse->property[4] != nullptr && loginResponse->property[4] == loginResponse->propertyMap["certificate"]);
			Assert::IsTrue(loginResponse->property[5] != nullptr && loginResponse->property[5] == loginResponse->propertyMap["props"]);

			Assert::IsTrue(userData->propertyMap["id"]->id == 0 && userData->propertyMap["id"]->name=="id");
			Assert::IsTrue(userData->propertyMap["account"]->id = 1 && userData->propertyMap["account"]->name == "account");
			Assert::IsTrue(userData->propertyMap["level"]->id = 2 && userData->propertyMap["level"]->name == "level");

			Assert::IsTrue(loginRequest->propertyMap["account"]->id == 0 && loginRequest->propertyMap["account"]->name=="account");
			Assert::IsTrue(loginRequest->propertyMap["password"]->id = 1 && loginRequest->propertyMap["password"]->name == "password");

			Assert::IsTrue(loginResponse->propertyMap["result"]->id == 0 && loginResponse->propertyMap["result"]->name == "result");
			Assert::IsTrue(loginResponse->propertyMap["message"]->id = 1 && loginResponse->propertyMap["message"]->name == "message");
			Assert::IsTrue(loginResponse->propertyMap["userData"]->id == 2 && loginResponse->propertyMap["userData"]->name == "userData");
			Assert::IsTrue(loginResponse->propertyMap["message"]->id = 3 && loginResponse->propertyMap["message"]->name == "message");
			Assert::IsTrue(loginResponse->propertyMap["certificate"]->id == 4 && loginResponse->propertyMap["certificate"]->name == "certificate");
			Assert::IsTrue(loginResponse->propertyMap["props"]->id = 5 && loginResponse->propertyMap["props"]->name == "props");


			Assert::IsTrue(userData->propertyMap["id"]->type ==NetType::UINT32);
			Assert::IsTrue(userData->propertyMap["id"]->defaultValue == "0");
			Assert::IsTrue(userData->propertyMap["account"]->type == NetType::STRING);
			Assert::IsTrue(userData->propertyMap["account"]->defaultValue == "");
			Assert::IsTrue(userData->propertyMap["level"]->type == NetType::UINT8);
			Assert::IsTrue(userData->propertyMap["level"]->defaultValue == "1");

			Assert::IsTrue(loginRequest->propertyMap["account"]->type == NetType::STRING);
			Assert::IsTrue(loginRequest->propertyMap["account"]->defaultValue == "");
			Assert::IsTrue(loginRequest->propertyMap["password"]->type == NetType::STRING);
			Assert::IsTrue(loginRequest->propertyMap["password"]->defaultValue == "");


			Assert::IsTrue(loginResponse->propertyMap["result"]->type == NetType::UINT8);
			Assert::IsTrue(loginResponse->propertyMap["result"]->defaultValue == "0");
			Assert::IsTrue(loginResponse->propertyMap["message"]->type == NetType::STRING);
			Assert::IsTrue(loginResponse->propertyMap["message"]->defaultValue == "");
			Assert::IsTrue(loginResponse->propertyMap["userData"]->type == "UserData");
			Assert::IsTrue(loginResponse->propertyMap["userData"]->defaultValue == "");
			Assert::IsTrue(loginResponse->propertyMap["friendList"]->type == NetType::ARRAY);
			Assert::IsTrue(loginResponse->propertyMap["friendList"]->inType == "UserData");
			Assert::IsTrue(loginResponse->propertyMap["certificate"]->type == NetType::BINARY);
			Assert::IsTrue(loginResponse->propertyMap["props"]->type == NetType::ARRAY);
			Assert::IsTrue(loginResponse->propertyMap["props"]->inType == NetType::UINT32);



		}

	};
}