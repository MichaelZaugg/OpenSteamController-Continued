@echo off
set DIR="Program Files (x86)\Steam\steamapps\common\SteamVR"
set DRIVE=C:
echo SteamVR install expected at %DRIVE%\%DIR%
echo Attempting to Flash
cd /D %DRIVE%
cd %DIR%
echo Current Dir is: %cd%
tools\lighthouse\bin\win32\lighthouse_watchman_update.exe -D tools\lighthouse\firmware\vr_controller\archive\htc_vrc_dongle_1461100729_2016_04_19.bin
PAUSE