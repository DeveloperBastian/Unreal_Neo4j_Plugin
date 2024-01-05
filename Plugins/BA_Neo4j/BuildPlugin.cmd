@echo off
:: This will build the plugin against an installed version of the Unreal Engine
:: it assumes this file is executed in the same directoy as your .plugin file
:: Adapt the paths to your engine and to the package folder - first two lines per engine section
SET baseDir=%cd%
SET plugin=BA_Neo4j.uplugin

:: 5.0
rem only thing to define per engine is the path to the engines base dir (%engine%) and the dir to store the current package into (%current%):
SET engine="D:\3D\UE_5.0"
SET engineVersion=5.0

SET current=%baseDir%\Packages\%engineVersion%
IF NOT EXIST %current% ( rmdir /s /q %current%)
CALL %engine%\Engine\Build\BatchFiles\RunUAT.bat BuildPlugin -Plugin=%baseDir%\%plugin% -Package=%current% -Rocket
IF EXIST %current%\Intermediate ( rmdir /s /q %current%\Intermediate )
IF EXIST "%current%\Binaries" ( rmdir /s /q %current%\Binaries )
tar -a -c -f %engineVersion%.zip %current%
IF EXIST %current% ( rmdir /s /q %current% )

:: 5.1
rem only thing to define per engine is the path to the engines base dir (%engine%) and the dir to store the current package into (%current%):
SET engine="D:\3D\UE_5.1"
SET engineVersion=5.1

SET current=%baseDir%\Packages\%engineVersion%
IF NOT EXIST %current% ( rmdir /s /q %current%)
CALL %engine%\Engine\Build\BatchFiles\RunUAT.bat BuildPlugin -Plugin=%baseDir%\%plugin% -Package=%current% -Rocket
IF EXIST %current%\Intermediate ( rmdir /s /q %current%\Intermediate )
IF EXIST "%current%\Binaries" ( rmdir /s /q %current%\Binaries )
tar -a -c -f %engineVersion%.zip %current%
IF EXIST %current% ( rmdir /s /q %current% )

:: 5.2
rem only thing to define per engine is the path to the engines base dir (%engine%) and the dir to store the current package into (%current%):
SET engine="D:\3D\UE_5.2"
SET engineVersion=5.2

SET current=%baseDir%\Packages\%engineVersion%
IF NOT EXIST %current% ( rmdir /s /q %current%)
CALL %engine%\Engine\Build\BatchFiles\RunUAT.bat BuildPlugin -Plugin=%baseDir%\%plugin% -Package=%current% -Rocket
IF EXIST %current%\Intermediate ( rmdir /s /q %current%\Intermediate )
IF EXIST "%current%\Binaries" ( rmdir /s /q %current%\Binaries )
tar -a -c -f %engineVersion%.zip %current%
IF EXIST %current% ( rmdir /s /q %current% )

:: 5.3
rem only thing to define per engine is the path to the engines base dir (%engine%) and the dir to store the current package into (%current%):
SET engine="D:\3D\UE_5.3"
SET engineVersion=5.3

SET current=%baseDir%\Packages\%engineVersion%
IF NOT EXIST %current% ( rmdir /s /q %current%)
CALL %engine%\Engine\Build\BatchFiles\RunUAT.bat BuildPlugin -Plugin=%baseDir%\%plugin% -Package=%current% -Rocket
IF EXIST %current%\Intermediate ( rmdir /s /q %current%\Intermediate )
IF EXIST "%current%\Binaries" ( rmdir /s /q %current%\Binaries )
tar -a -c -f %engineVersion%.zip %current%
IF EXIST %current% ( rmdir /s /q %current% )







