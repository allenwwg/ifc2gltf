#ifndef _IFC2GLTF_SHARE_H_
#define _IFC2GLTF_SHARE_H_

#ifdef _WIN32
#ifdef IFC2GLTF_SHARE_EXPORT
#define _IFC2GLTF_SHARE_ _declspec(dllexport)
#else
#define _IFC2GLTF_SHARE_ _declspec(dllimport)
#pragma comment(lib,"ifc2gltf_share")
#endif // _DLL
#endif // _WIN32

#endif // !IFC2GLTF_SHARE_H_
