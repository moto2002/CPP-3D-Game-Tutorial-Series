// Copyright (c) 2019 - 2020 PardCode
// All rights reserved.
//
// This file is part of CPP-3D-Game-Tutorial-Series Project, accessible from https://github.com/PardCode/CPP-3D-Game-Tutorial-Series
// You can redistribute it and/or modify it under the terms of the GNU
// General Public License 
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#include "ResourceManager.h"
#include <filesystem>

ResourceManager::ResourceManager()
{
}


ResourceManager::~ResourceManager()
{
}

ResourcePtr ResourceManager::createResourceFromFile(const wchar_t * file_path)
{

#if _MSC_VER >= 1900 && _MSC_VER <= 1916
	std::wstring full_path = std::experimental::filesystem::absolute(file_path);
#endif

#if _MSC_VER >= 1920
	std::wstring full_path = std::filesystem::absolute(file_path);
#endif


	auto it = m_map_resources.find(full_path);

	if (it != m_map_resources.end())
		return it->second;

	Resource* raw_res = this->createResourceFromFileConcrete(full_path.c_str());

	if (raw_res)
	{
		ResourcePtr res(raw_res);
		m_map_resources[full_path] = res;
		return res;
	}

	return nullptr;
}

