@echo off
REM http://d.hatena.ne.jp/c-v/20061212/1165934347 コマンドライン上からVC++のビルドを呼び出す
REM http://oshiete.goo.ne.jp/qa/129968.html コマンドラインからのコンパイル(VC++6.0) - C&C++ - 教えて！goo
REM http://msdn.microsoft.com/ja-jp/library/f35ctcxw(v=VS.80).aspx コマンド ラインでのビルド Visual Studio 2005
REM if %1=="clear" goto clear 

setlocal
set TARGET=Lesson05
set VCPROJ= %TARGET%.vcproj
set SLN = %TARGET%.sln

REM call "C:\Program Files\Microsoft Visual Studio\VC98\Bin\vcvars32.bat"
@echo on
call "C:\Program Files\Microsoft Visual Studio 9.0\VC\bin\vcvars32.bat"
@echo off
REM msdev %DSP% /MAKE /REBUILD
REM 次の例では、MySolution の Debug ソリューション構成にある Debug プロジェクト ビルド構成を使用し、CSharpConsoleApp プロジェクトを削除し、リビルドします。 
REM devenv /rebuild Debug "C:\Documents and Settings\someuser\My Documents\Visual Studio\Projects\MySolution\MySolution.sln" /project "CSharpWinApp\CSharpWinApp.csproj" /projectconfig Debug 
REM devenv /rebuild Debug %SLN% /project %CSPROJ% /projectconfig Debug 
REM vcbuild  /rebuild %SLN%
REM vcbuild /rebuild %VCPROJ%
@echo on
"C:\Program Files\Microsoft Visual Studio 9.0\Common7\IDE\VCExpress.exe" %VCPROJ% /rebuild
cp Debug/%TARGET%.dll ./
REM rm -f Debug/*.*  Release/*.* ./*.suo
@echo off
endlocal
