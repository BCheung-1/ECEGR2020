##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab_4D
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/cheun/Documents/ECEGR2020
ProjectPath            :=C:/Users/cheun/Documents/ECEGR2020/Lab_4D
IntermediateDirectory  :=../build-$(ConfigurationName)/Lab_4D
OutDir                 :=../build-$(ConfigurationName)/Lab_4D
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=cheun
Date                   :=28/02/2022
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/Lab_4D/QueueArray.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Lab_4D/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\Lab_4D" mkdir "..\build-$(ConfigurationName)\Lab_4D"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\Lab_4D" mkdir "..\build-$(ConfigurationName)\Lab_4D"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/Lab_4D/.d:
	@if not exist "..\build-$(ConfigurationName)\Lab_4D" mkdir "..\build-$(ConfigurationName)\Lab_4D"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Lab_4D/QueueArray.c$(ObjectSuffix): QueueArray.c ../build-$(ConfigurationName)/Lab_4D/QueueArray.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/cheun/Documents/ECEGR2020/Lab_4D/QueueArray.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/QueueArray.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lab_4D/QueueArray.c$(DependSuffix): QueueArray.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lab_4D/QueueArray.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lab_4D/QueueArray.c$(DependSuffix) -MM QueueArray.c

../build-$(ConfigurationName)/Lab_4D/QueueArray.c$(PreprocessSuffix): QueueArray.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lab_4D/QueueArray.c$(PreprocessSuffix) QueueArray.c


-include ../build-$(ConfigurationName)/Lab_4D//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


