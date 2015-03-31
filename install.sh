#!/bin/bash

MSBUILD=C:/Windows/Microsoft.NET/Framework/v4.0.30319/msbuild.exe

mkdir -p bin

$MSBUILD CppUtil/Cpputil.vcxproj //p:Configuration=Debug
$MSBUILD TestCppUtil/TestCppUtil.vcxproj //p:Configuration=Debug

$MSBUILD CppUtil/Cpputil.vcxproj //p:Configuration=Release
$MSBUILD TestCppUtil/TestCppUtil.vcxproj //p:Configuration=Release
cp CppUtil/bin/*.dll bin/
cp TestCppUtil/bin/*.exe bin/
