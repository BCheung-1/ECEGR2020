##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab_3
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/cheun/Documents/ECEGR2020
ProjectPath            :=C:/Users/cheun/Documents/ECEGR2020/Lab_3
IntermediateDirectory  :=../build-$(ConfigurationName)/Lab_3
OutDir                 :=../build-$(ConfigurationName)/Lab_3
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=cheun
Date                   :=14/02/2022
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
Objects0=../build-$(ConfigurationName)/Lab_3/part2.c$(ObjectSuffix) ../build-$(ConfigurationName)/Lab_3/main.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Lab_3/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\Lab_3" mkdir "..\build-$(ConfigurationName)\Lab_3"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\Lab_3" mkdir "..\build-$(ConfigurationName)\Lab_3"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/Lab_3/.d:
	@if not exist "..\build-$(ConfigurationName)\Lab_3" mkdir "..\build-$(ConfigurationName)\Lab_3"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Lab_3/part2.c$(ObjectSuffix): part2.c ../build-$(ConfigurationName)/Lab_3/part2.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/cheun/Documents/ECEGR2020/Lab_3/part2.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/part2.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lab_3/part2.c$(DependSuffix): part2.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lab_3/part2.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lab_3/part2.c$(DependSuffix) -MM part2.c

../build-$(ConfigurationName)/Lab_3/part2.c$(PreprocessSuffix): part2.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lab_3/part2.c$(PreprocessSuffix) part2.c

../build-$(ConfigurationName)/Lab_3/main.c$(ObjectSuffix): main.c ../build-$(ConfigurationName)/Lab_3/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/cheun/Documents/ECEGR2020/Lab_3/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lab_3/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lab_3/main.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lab_3/main.c$(DependSuffix) -MM main.c

../build-$(ConfigurationName)/Lab_3/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lab_3/main.c$(PreprocessSuffix) main.c


-include ../build-$(ConfigurationName)/Lab_3//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


