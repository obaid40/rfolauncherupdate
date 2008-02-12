@echo off

diskw\home\admin\program\pskill.exe Apache.exe
IF NOT ERRORLEVEL 1 goto started
set Disk=%1
IF "%Disk%"=="" set Disk=w
rem create the disk
subst %Disk%: "diskw"
IF ERRORLEVEL 1 goto hint
set apachepath=\usr\local\apache2\
set apacheit=%Disk%:%apachepath%bin\Apache.exe -f %apachepath%conf\httpd.conf -d %apachepath%.
set programit=%Disk%:\home\admin\program\
set closeit=%programit%close.bat %Disk%
%Disk%:
cd \usr\local\php
start \usr\local\mysql\bin\mysqld-nt.exe --defaults-file=/usr/local/mysql/bin/my-small.cnf
CLS
echo The server is working on the disk %Disk%:\ [http/127.0.0.1/a/]
start %Disk%:\home\admin\WWW\redirect.html
start %programit%miniserv.exe "%apacheit%" "%closeit%"
goto end
:hint
CLS
echo The disk %Disk% is busy. Use start.bat [disk letter]
goto pause
:started
CLS
echo ERROR!!! 
echo One of the instances of Apache server is started. Use stop.bat
:pause
echo .
pause
:end