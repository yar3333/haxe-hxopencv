@echo off
cd %~dp0\..\bin
set NEKOPATH=%NEKOPATH%;..\..\library\ndll\Windows
neko Main.n
