for /f "delims=" %%i in ('dir /b /a-d /s "*.exe"') do call del %%i 
for /f "delims=" %%i in ('dir /b /a-d /s "*.obj"') do call del %%i
for /f "delims=" %%i in ('dir /b /a-d /s "*.spec"') do call del %%i
pause