# Microsoft Developer Studio Project File - Name="UPCGPS" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=UPCGPS - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "UPCGPS.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "UPCGPS.mak" CFG="UPCGPS - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "UPCGPS - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "UPCGPS - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "UPCGPS - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "UPCGPS - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "UPCGPS - Win32 Release"
# Name "UPCGPS - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\3.cpp
# End Source File
# Begin Source File

SOURCE=.\4.cpp
# End Source File
# Begin Source File

SOURCE=.\C10.cpp
# End Source File
# Begin Source File

SOURCE=.\C11.cpp
# End Source File
# Begin Source File

SOURCE=.\C12.cpp
# End Source File
# Begin Source File

SOURCE=.\C13.cpp
# End Source File
# Begin Source File

SOURCE=.\C14.cpp
# End Source File
# Begin Source File

SOURCE=.\C15.cpp
# End Source File
# Begin Source File

SOURCE=.\C16.cpp
# End Source File
# Begin Source File

SOURCE=.\C17.cpp
# End Source File
# Begin Source File

SOURCE=.\C18.cpp
# End Source File
# Begin Source File

SOURCE=.\C19.cpp
# End Source File
# Begin Source File

SOURCE=.\C20.cpp
# End Source File
# Begin Source File

SOURCE=.\C5.cpp
# End Source File
# Begin Source File

SOURCE=.\C6.cpp
# End Source File
# Begin Source File

SOURCE=.\C8.cpp
# End Source File
# Begin Source File

SOURCE=.\C88.cpp
# End Source File
# Begin Source File

SOURCE=.\C9.cpp
# End Source File
# Begin Source File

SOURCE=.\EGraph.cpp
# End Source File
# Begin Source File

SOURCE=.\Gym1.cpp
# End Source File
# Begin Source File

SOURCE=.\Register.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Tyc2.cpp
# End Source File
# Begin Source File

SOURCE=.\UPCGPS.cpp
# End Source File
# Begin Source File

SOURCE=.\UPCGPS.rc
# End Source File
# Begin Source File

SOURCE=.\UPCGPSDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\value.cpp
# End Source File
# Begin Source File

SOURCE=.\yjsssl0.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\3.h
# End Source File
# Begin Source File

SOURCE=.\4.h
# End Source File
# Begin Source File

SOURCE=.\C10.h
# End Source File
# Begin Source File

SOURCE=.\C11.h
# End Source File
# Begin Source File

SOURCE=.\C12.h
# End Source File
# Begin Source File

SOURCE=.\C13.h
# End Source File
# Begin Source File

SOURCE=.\C14.h
# End Source File
# Begin Source File

SOURCE=.\C15.h
# End Source File
# Begin Source File

SOURCE=.\C16.h
# End Source File
# Begin Source File

SOURCE=.\C17.h
# End Source File
# Begin Source File

SOURCE=.\C18.h
# End Source File
# Begin Source File

SOURCE=.\C19.h
# End Source File
# Begin Source File

SOURCE=.\C20.h
# End Source File
# Begin Source File

SOURCE=.\C5.h
# End Source File
# Begin Source File

SOURCE=.\C6.h
# End Source File
# Begin Source File

SOURCE=.\C8.h
# End Source File
# Begin Source File

SOURCE=.\C88.h
# End Source File
# Begin Source File

SOURCE=.\C9.h
# End Source File
# Begin Source File

SOURCE=.\EGraph.h
# End Source File
# Begin Source File

SOURCE=.\Gym1.h
# End Source File
# Begin Source File

SOURCE=.\MemDC.h
# End Source File
# Begin Source File

SOURCE=.\Register.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Tyc2.h
# End Source File
# Begin Source File

SOURCE=.\UPCGPS.h
# End Source File
# Begin Source File

SOURCE=.\UPCGPSDlg.h
# End Source File
# Begin Source File

SOURCE=.\value.h
# End Source File
# Begin Source File

SOURCE=.\yjsssl0.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\picture\10.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\11.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\12.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\13.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\14.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\15.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\16.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\17.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\18.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\19.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\20.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\21.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\22.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\23.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\24.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\25.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\26.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\27.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\28.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\29.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\30.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\31.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\32.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\33.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\34.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\35.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\51.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\52.bmp
# End Source File
# Begin Source File

SOURCE=.\picture\53.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor2.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor3.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor4.cur
# End Source File
# Begin Source File

SOURCE=.\res\UPCGPS.ico
# End Source File
# Begin Source File

SOURCE=.\res\UPCGPS.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
