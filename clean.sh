#!/bin/bash

MSBUILD=C:/Windows/Microsoft.NET/Framework/v4.0.30319/msbuild.exe

$MSBUILD CppUtil/Cpputil.vcxproj //t:Clean
$MSBUILD TestCppUtil/TestCppUtil.vcxproj	//t:Clean
rm -r bin

