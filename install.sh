#!/bin/bash

MSBUILD=C:/Windows/Microsoft.NET/Framework/v4.0.30319/msbuild.exe

$MSBUILD CppUtil/Cpputil.vcxproj //t:Clean
$MSBUILD TestCppUtil/TestCppUtil.vcxproj	//t:Clean
rm -r bin
mkdir bin

$MSBUILD CppUtil/Cpputil.vcxproj //p:Configuration=Debug
$MSBUILD TestCppUtil/TestCppUtil.vcxproj //p:Configuration=Debug

$MSBUILD CppUtil/Cpputil.vcxproj //p:Configuration=Release
$MSBUILD TestCppUtil/TestCppUtil.vcxproj //p:Configuration=Release
cp CppUtil/bin/*.dll bin/
cp TestCppUtil/bin/*.exe bin/
