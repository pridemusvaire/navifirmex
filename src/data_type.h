/*
http://code.google.com/p/navifirmex/
Copyright (C) 2011  Just Fancy (Just_Fancy@live.com)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#ifndef __DATA_TYPE_H__
#define __DATA_TYPE_H__

#include <vector>
// #include <map>
#include "Tim/TString.h"

//NOKIA产品
struct Product
{
	Product()/*:id(0)*/{}
	Product(/*const long &i*/const Tim::TString &i, const Tim::TString &t, const Tim::TString &n)
		:id(i), type(t), name(n)
	{}
	//long		 id;	//<productID xsi:type="xsd:long">		用于查询Release
	Tim::TString id;	//long表示范围的不能满足这里的xsd:long，LONGLONG不好使
	Tim::TString type;	//<productType xsi:type="xsd:string">	RM-XXX
	Tim::TString name;	//<marketName xsi:type="xsd:string">	Nokia XXX
	Tim::TString image;	//图片所在ZIP URL
};

//版本
struct Release
{
	Release()/*:id(0)*/{}
	Release(/*const long &i*/const Tim::TString &i, const Tim::TString &v)
		:id(i), ver(v)
	{}
	//long		 id;	//<releaseID xsi:type="xsd:long">		用于查询Variants列表
	Tim::TString id;
	Tim::TString ver;	//<version xsi:type="xsd:string">		版本号
};

//std::map<long, Tim::TString> Release;

struct FileInfo
{
	FileInfo():size(0){}
	FileInfo(const Tim::TString &n, const Tim::TString &u, const long &s)
		:name(n), url(u), size(s)
	{}
	Tim::TString name;	//<fileName xsi:type="xsd:string">
	Tim::TString url;	//<downloadURL xsi:type="xsd:string">
	long		 size;	//<fileSize xsi:type="xsd:long">
};

struct Variant
{
	Variant(){}
	Variant(const Tim::TString &n, const Tim::TString &c)
		:name(n), code(c)
	{}
//	long		 id;		//variantID xsi:type="xsd:long">
	Tim::TString name;		//<name xsi:type="xsd:string">			CODE名
	Tim::TString code;		//<productCode xsi:type="xsd:string">	CODE
	std::vector<FileInfo> vFiles;
};

class GUIWnd;

struct GetImageProcParam
{
	GetImageProcParam()
		:pWnd(0)
	{}

	GUIWnd *pWnd;
	Tim::TString fileToSave;
	Tim::TString fileUrl;
};

#endif	//__DATA_TYPE_H__