!include "MUI2.nsh"

# define name of installer
OutFile "Kakrulacka_setup.exe"
 
# define installation directory
InstallDir $DESKTOP
 
# For removing Start Menu shortcut in Windows 7
RequestExecutionLevel user

!define PRODUCT_NAME "Karkulačka 1.0"
!define MUI_PRODUCT "Karkulačka 1.0"
!define MUI_BRANDINGTEXT "Karkulačka 1.0"
!define MUI_HEADERIMAGE
!define MUI_HEADERIMAGE_BITMAP "ikona.bmp"
!define MUI_WELCOMEFINISHPAGE_BITMAP "Welcome.bmp"
!define MUI_UNWELCOMEFINISHPAGE_BITMAP "Welcome.bmp"
!define MUI_FINISHPAGE_RUN "$INSTDIR\karkulacka\karkulacka.exe"

Name "${PRODUCT_NAME}"

 !insertmacro MUI_PAGE_WELCOME
 !insertmacro MUI_PAGE_DIRECTORY
 !insertmacro MUI_PAGE_INSTFILES
 !insertmacro MUI_PAGE_FINISH
  
!insertmacro MUI_LANGUAGE "Czech"

# start default section
Section
 
    CreateDirectory $INSTDIR\karkulacka
    # set the installation directory as the destination for the following actions
    SetOutPath $INSTDIR\karkulacka

    File "..\..\binarky\karkulacka.exe"
    File "..\..\binarky\*.dll"
    File "..\..\binarky\GUI.glade"
    File "..\..\binarky\help.html"
    File "VC_redist.x86.exe"

    # run redistributable package
    ExecWait '$INSTDIR\karkulacka\VC_redist.x86.exe /install /passive /norestart'


    # create the uninstaller
    WriteUninstaller "$INSTDIR\karkulacka\uninstall.exe"
 
    # create a shortcut named "new shortcut" in the start menu programs directory
    # point the new shortcut at the program uninstaller
    CreateShortCut "$SMPROGRAMS\odinstalovat_karkulacku.lnk" "$INSTDIR\karkulacka\uninstall.exe"
    CreateShortCut "$SMPROGRAMS\karkulacka.lnk" "$INSTDIR\karkulacka\karkulacka.exe"

SectionEnd
 
# uninstaller section start
Section "uninstall"
 
    # first, delete the uninstaller
    RMDir /r "$INSTDIR"
    
 
    # second, remove the link from the start menu
    Delete "$SMPROGRAMS\karkulacka.lnk"
    Delete "$SMPROGRAMS\odinstalovat_karkulacku.lnk"
 
# uninstaller section end
SectionEnd