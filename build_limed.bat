@echo off
cls
rem path=C:\Programs\cygwin\bin;%PATH%
::path=C:\Programok\cygwin\bin;%PATH%
@PATH=C:\Programok\cygwin64\bin\;%PATH%
rem set TMPDIR=c:\tmp
@set WORK_ROOT=%CD%

::C:
::chdir C:\Programs\cygwin\bin

rem start "FESI make" bash --login -i -c "make_fesi"
rem bash --login -i -c "ls -l ma*"
rem bash --login -i -c "cd $WORKROOT|ls"
rem bash --login -i -c "make -C $WORK_ROOT -f makefile.dos %1 %2 %3 %4"
bash --login -i -c "make -C $WORK_ROOT %1 %2 %3 %4"
