// Copyright (c) 2019 - 2020 PardCode
// All rights reserved.
//
// This file is part of CPP-3D-Game-Tutorial-Series Project, accessible from https://github.com/PardCode/CPP-3D-Game-Tutorial-Series
// You can redistribute it and/or modify it under the terms of the GNU
// General Public License 
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#pragma once
#include "Resource.h"
#include <d3d11.h>

class Texture: public Resource
{
public:
	Texture(const wchar_t* full_path);
	~Texture();
private:
	ID3D11Resource * m_texture = nullptr;
	ID3D11ShaderResourceView *m_shader_res_view = nullptr;
private:
	friend class DeviceContext;
};

