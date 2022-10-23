@cd E:\Code\git\SoftwareEngineering
@git pull
@git add -A
@git status
choice /T 30 /C yn /N /D y /M "If you comfirm to push, please press key 'y', or you press any other key or waiting over 30 seconds will kill this push execuation."
@if %errorlevel%==1 git commit -m 'cbf' && git push

@if %errorlevel%==2 pause