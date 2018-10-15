#include "stdafx.h"
#include "CppUnitTest.h"

#include "../ifc2gltf_share/main.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ifc2gltf_test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestIfcParseLib)
		{
			int nR = kagula::TestIfcParseLib("E:\\testIFC\\cube.ifc");
			char buf[256] = { 0 };
			sprintf(buf, "%d", nR);
			Logger::WriteMessage(buf);
		}

		TEST_METHOD(TestConvertIfc2glTF)
		{
		}
	};
}