@echo off
:START
cls
echo 'Create a Virtual Hard Drive during startup that contains the trace files.'
set input=
set /p input= Enter the path of the tracefiles:
echo '%input%'
echo 'Creating a bat script in the startup folder'
echo 'Using as default link path: '%input%'
@echo off
echo @echo off> "%appdata%\Microsoft\Windows\Start Menu\Programs\Startup\canids-vhd-traces.bat"
echo :START>> "%appdata%\Microsoft\Windows\Start Menu\Programs\Startup\canids-vhd-traces.bat"
echo cls>> "%appdata%\Microsoft\Windows\Start Menu\Programs\Startup\canids-vhd-traces.bat"
echo subst M: %input%>> "%appdata%\Microsoft\Windows\Start Menu\Programs\Startup\canids-vhd-traces.bat"
pause