#!/bin/bash
MSBUILD=C:/Windows/Microsoft.NET/Framework/v4.0.30319/msbuild.exe

./clean.sh

mkdir bin

$MSBUILD CppUtil/CppUtil.vcxproj //t:Clean
$MSBUILD TestCppUtil/TestCppUtil.vcxproj //t:Clean

$MSBUILD CppUtil/CppUtil.vcxproj //p:Configuration=Debug
$MSBUILD CppUtil/CppUtil.vcxproj //p:Configuration=Release
$MSBUILD TestCppUtil/TestCppUtil.vcxproj //p:Configuration=Debug
$MSBUILD TestCppUtil/TestCppUtil.vcxproj //p:Configuration=Release

./copy.sh

