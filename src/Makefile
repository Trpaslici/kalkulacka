EXECUTABLE_PROFILING = Profiling.exe 
EXECUTABLE_GUI = karkulacka.exe
EXECUTABLE_DIRECTORY = ..\\binarky
SAMPLE_INPUT = ..\\src\\Profiling\\inputs\\1000sempls.txt
DOCUMENTATION = ..\\src\\Profiling\\inputs\\1000sempls.txt
INSTALLER = ..\\src\\Profiling\\inputs\\1000sempls.txt
LOGINS = xdrlic02_xblaze34_xbrhli02_xhrozn00
LOGINS_DIR = ..\\..\\$(LOGINS)
DOC_DIR = $(LOGINS_DIR)\\doc
INSTALLERS_DIR = $(LOGINS_DIR)\\install
REPO_DIR = $(LOGINS_DIR)\\repo
CXX = g++ 
CXXFLAGS = -g -Wall --std=c++11
.PHONY: all run profile clean help pack

all: run

run: $(EXECUTABLE_DIRECTORY)\\$(EXECUTABLE_GUI)
	cd $(EXECUTABLE_DIRECTORY) && $(EXECUTABLE_GUI)

profile: $(EXECUTABLE_DIRECTORY)\\$(EXECUTABLE_PROFILING)
	cd $(EXECUTABLE_DIRECTORY) && $(EXECUTABLE_PROFILING) < $(SAMPLE_INPUT)

clean: 
	if exist GUI\\Debug rd /s /q GUI\\Debug 
	if exist GUI\\Release rd /s /q GUI\\Release
	if exist Profiling\\Debug rd /s /q Profiling\\Debug 	
	if exist Profiling\\Release rd /s /q Profiling\\Release
	if exist Testy\\Release rd /s /q Testy\\Release
	cd  ..\\binarky && if exist *.ilk del /q *.ilk
	cd  ..\\binarky && if exist *.iobj del /q *.iobj
	cd  ..\\binarky && if exist *.ipdb del /q *.ipdb
	cd  ..\\binarky && if exist *.pdb del /q *.pdb
	if exist $(LOGINS_DIR) rd /s /q $(LOGINS_DIR)
	if exist $(LOGINS).zip del /q $(LOGINS).zip

help:
	echo "Adresar binarky obsahuje predkompilovane spustitelne soubory." 
	echo "Jejich rekompilaci muzete provest ve VS."
	echo "Pro kompilaci je treba mit nainstalovan balik gtk3.x" 

pack: clean
	md $(LOGINS_DIR)
	md $(DOC_DIR)
	md $(INSTALLERS_DIR)
	md $(REPO_DIR)
	copy $(DOCUMENTATION) $(DOC_DIR)\\Dokumentace.txt
	copy $(INSTALLER) $(INSTALLERS_DIR)\\karkulacka_setup.exe
	xcopy ..\\* $(REPO_DIR) /s /e /q
	powershell Compress-Archive $(LOGINS_DIR) $(LOGINS).zip
	if exist $(LOGINS_DIR) rd /s /q $(LOGINS_DIR)
