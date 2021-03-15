@echo off
@set PATH=C:\KBApps\DevEnv\Cygwin\V2_3_1\bin;%PATH%
::@set PATH=C:\KBApps\DevEnv\Cygwin\V1_7_17\bin;%PATH%
set WORK_ROOT=%CD%
set CYGWIN=nodosfilewarning

bash -c "cgdb obj/test1.exe %*"
::bash -c "gdb --version"
