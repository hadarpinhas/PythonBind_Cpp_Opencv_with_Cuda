# PythonBind_Cpp_Opencv_with_Cuda

## Creating a python package containing c++ code with opencv compiled with cuda.

## Cuda includes and libs are added here as an example but not necessarily used.


### vs2019 make sure x64 and Release


## Adding includes and libraries of opencv with cuda

right click on the project -> properties:
1. On top set Configuration: Active(Release), Platform: Active(x64)
2. Configuration properties -> C/C++:
include Directories -> scroll down -> edit -> create new line (small little folder icon on the top-right) -> 
C:\opencv\install\include ; C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.8\include\

press Ok, Apply

3. Configuration properties -> Linker (The dirs that contains what we will use next: opencv_world455.lib, cudart.lib, nppist.lib):
General -> Additional Include Directories -> 
C:\opencv\install\x64\vc16\lib ; C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.8\lib\x64

Input -> Additional dependencies -> scroll down -> edit, add opencv_worldxxx.lib (or whatever opencv version opencv_world4100.lib you have in C:\opencv\install\x64\vc16\lib, or any other place you built opencv with cuda)

For cuda I also added ():

cudart.lib
nppist.lib
(add any other lib you need)

press Apply


## creating dll (pyd for python):
  
1. project properties -> General, configuration Type: Dynamic Library (.dll)
  
2. project properties -> C/C++ -> Additionl include directories: 
C:\Users\hadar\AppData\Local\Programs\Python\Python310\include; C:\Users\hadar\AppData\Local\Programs\Python\Python310\lib\site-packages\pybind11\include
                  
3. project properties -> Linker -> General, Output File: 
                  $(OutDir)$(TargetName)$(TargetExt)  change to: $(OutDir)$(TargetName).pyd, otherise  .dll file will be created, instead of .pyd in x64/Release
                  
4. project properties -> Linker -> General, Additionl Library directories: 
C:\Users\hadar\AppData\Local\Programs\Python\Python310\libs


## Build solution

on vs2019 toolbar: Build -> Build Solution (or ctrl+shift+B)

## Runing python package

From vscode for simplicity run "python test_pybind.py"
