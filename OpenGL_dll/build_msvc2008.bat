@echo off
REM http://d.hatena.ne.jp/c-v/20061212/1165934347 �R�}���h���C���ォ��VC++�̃r���h���Ăяo��
REM http://oshiete.goo.ne.jp/qa/129968.html �R�}���h���C������̃R���p�C��(VC++6.0) - C&C++ - �����āIgoo
REM http://msdn.microsoft.com/ja-jp/library/f35ctcxw(v=VS.80).aspx �R�}���h ���C���ł̃r���h Visual Studio 2005
REM if %1=="clear" goto clear 

setlocal
set TARGET=OpenGL
set VCPROJ= %TARGET%.vcproj
set SLN = %TARGET%.sln

REM call "C:\Program Files\Microsoft Visual Studio\VC98\Bin\vcvars32.bat"
@echo on
call "C:\Program Files\Microsoft Visual Studio 9.0\VC\bin\vcvars32.bat"
@echo off
REM msdev %DSP% /MAKE /REBUILD
REM ���̗�ł́AMySolution �� Debug �\�����[�V�����\���ɂ��� Debug �v���W�F�N�g �r���h�\�����g�p���ACSharpConsoleApp �v���W�F�N�g���폜���A���r���h���܂��B 
REM devenv /rebuild Debug "C:\Documents and Settings\someuser\My Documents\Visual Studio\Projects\MySolution\MySolution.sln" /project "CSharpWinApp\CSharpWinApp.csproj" /projectconfig Debug 
REM devenv /rebuild Debug %SLN% /project %CSPROJ% /projectconfig Debug 
REM vcbuild  /rebuild %SLN%
REM vcbuild /rebuild %VCPROJ%
@echo on
"C:\Program Files\Microsoft Visual Studio 9.0\Common7\IDE\VCExpress.exe" %VCPROJ% /rebuild
cp ../Debug/%TARGET%.dll ../
@echo off
REM rm -f Debug/*.*  Release/*.* ./*.suo
REM rm -f Debug/*.htm Debug/*.txt Debug/*.manifest Debug/*.res Debug/*.manifest Debug/*.ilk Debug/*.obj Debug/*.pdb Debug/*.dep Debug/*.idb Debug/*.pdb Release/*.htm Release/*.txt Release/*.manifest Release/*.res Release/*.manifest Release/*.ilk Release/*.obj Release/*.pdb Release/*.dep Release/*.idb Release/*.pdb
REM %TARGET%.exe

endlocal
