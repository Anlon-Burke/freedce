@echo off
rem Build lt_client.exe with the Microsoft RPC runtime (MIDL and the C
rem compiler of Visual Studio), to test Windows clients against a DCE server.
rem
rem Usage: build_win.cmd [output directory]
rem Run it from an "x64 Native Tools Command Prompt", or set VCVARS to the
rem full path of vcvars64.bat.  The output directory defaults to the current
rem directory.
setlocal
set SRC=%~dp0
set OUT=%~1
if "%OUT%"=="" set OUT=%CD%
if not "%VCVARS%"=="" call "%VCVARS%" > nul
if not exist "%OUT%" mkdir "%OUT%"
cd /d "%OUT%" || exit /b 1

midl /nologo /env x64 /server none /h loadtest.h /cstub loadtest_c.c "%SRC%loadtest.idl"
if errorlevel 1 exit /b 1

cl /nologo /O2 /W3 /D_CRT_SECURE_NO_WARNINGS /I. /Fe:lt_client.exe ^
   "%SRC%lt_client.c" "%SRC%lt_data.c" "%SRC%lt_port.c" loadtest_c.c rpcrt4.lib
if errorlevel 1 exit /b 1
echo lt_client.exe built in %OUT%
