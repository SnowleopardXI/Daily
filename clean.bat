for /f "delims=" %%i in ('dir /b /a-d /s "*.exe"') do call del %%i 
for /f "delims=" %%i in ('dir /b /a-d /s "*.obj"') do call del %%i
for /f "delims=" %%i in ('dir /b /a-d /s "*.spec"') do call del %%i
for /f "delims=" %%i in ('dir /b /a-d /s "tempCodeRunnerFile.c"') do call del %%i
for /f "delims=" %%i in ('dir /b /a-d /s "*.exe.stackdump"') do call del %%i
for /f "delims=" %%i in ('dir /b /a-d /s "*.out"') do call del %%i
pause