#ifndef _IFC2GLTF_SHARE_MAIN_H
#define  _IFC2GLTF_SHARE_MAIN_H

#include <functional>//ʹ��std::function����������ͷ�ļ�

#include "ifc2gltf_share.h"

namespace kagula
{
	typedef struct tagKagulaGLTFData
	{
	}KagulaGLTFData;

	int _IFC2GLTF_SHARE_ TestIfcParseLib(const char* fileName);
	int _IFC2GLTF_SHARE_ ParseIfcFile(const char* fileName, 
		std::function<int(int, const char* message)> monitor,
		KagulaGLTFData &output);
}

#endif // DEBUG
