CC:=g++
AR:=ar rcs
SHELL=cmd.exe

GUI_EXTERNAL_DIR:=../External/MinGW/
GUI_MINGW_BUILD:=i686-w64-mingw32
GUI_SDL2:=$(GUI_EXTERNAL_DIR)SDL2-2.0.5/$(GUI_MINGW_BUILD)/
GUI_SDL2_image:=$(GUI_EXTERNAL_DIR)SDL2_image-2.0.1/$(GUI_MINGW_BUILD)/
GUI_SDL2_mixer:=$(GUI_EXTERNAL_DIR)SDL2_mixer-2.0.1/$(GUI_MINGW_BUILD)/
GUI_SDL2_net:=$(GUI_EXTERNAL_DIR)SDL2_net-2.0.1/$(GUI_MINGW_BUILD)/
GUI_SDL2_ttf:=$(GUI_EXTERNAL_DIR)SDL2_ttf-2.0.14/$(GUI_MINGW_BUILD)/


GUI_SRC_FILES:=$(wildcard ./GUI/*.cpp)
EXAMPLE_SRC_FILES:=$(wildcard ./Example/*.cpp)
GUI_O_FILES:=$(GUI_SRC_FILES:.cpp=.o)
EXAMPLE_O_FILES:=$(EXAMPLE_SRC_FILES:.cpp=.o)
INCLUDE_DIRS:=-I./Include/ -I./Example/ -I$(GUI_SDL2)include/SDL2 -I$(GUI_SDL2_image)include/SDL2 -I$(GUI_SDL2_mixer)include/SDL2 -I$(GUI_SDL2_net)include/SDL2 -I$(GUI_SDL2_ttf)include/SDL2
COMPILE_FLAG:=-fpermissive -g
LINK_FLAGS:=-Wl,--enable-stdcall-fixup
GUI_OUT_DIR:=Build
GUI_OUT_FILE_DLL:=$(GUI_OUT_DIR)/libGUI.dll
GUI_OUT_FILE_A:=$(GUI_OUT_DIR)/libGUI.a
#$(GUI_SDL2) $(GUI_SDL2_image) $(GUI_SDL2_mixer) $(GUI_SDL2_net) $(GUI_SDL2_ttf)
GUI_LINK_DIRS:= -L$(GUI_SDL2)lib -L$(GUI_SDL2_image)lib -L$(GUI_SDL2_mixer)lib -L$(GUI_SDL2_net)lib -L$(GUI_SDL2_ttf)lib
GUI_LINK_LIBS:=-lmingw32 -lSDL2main -lSDL2 -mwindows -lSDL2_mixer -lSDL2_ttf -lSDL2_image  -lSDL2_net
GUI_EXPORTS_DEF:=


.PHONY:nothing static-lib shared-lib example clean copy-dll

nothing:
	@echo use make static-lib|shared-lib|clean|example
	
static-lib:$(GUI_OUT_FILE_A)
	@echo DONE!
	
shared-lib:$(GUI_OUT_FILE_DLL)
	@echo DONE!

example:|$(GUI_OUT_DIR) $(GUI_OUT_FILE_A) $(EXAMPLE_O_FILES) copy-dll
	$(CC) -o $(GUI_OUT_DIR)/example.exe $(EXAMPLE_O_FILES) $(GUI_LINK_DIRS) -L$(GUI_OUT_DIR) -lGUI $(GUI_LINK_LIBS)  $(LINK_FLAGS) 

copy-dll:
	-copy /B /Y $(subst /,\,$(GUI_SDL2))bin\*.dll $(GUI_OUT_DIR)
	-copy /B /Y $(subst /,\,$(GUI_SDL2_image))bin\*.dll $(GUI_OUT_DIR)
	-copy /B /Y $(subst /,\,$(GUI_SDL2_mixer))bin\*.dll $(GUI_OUT_DIR)
	-copy /B /Y $(subst /,\,$(GUI_SDL2_net))bin\*.dll $(GUI_OUT_DIR)
	-copy /B /Y $(subst /,\,$(GUI_SDL2_ttf))bin\*.dll $(GUI_OUT_DIR)
	-xcopy /Y /E /I .\Example\Resources .\$(subst /,\,$(GUI_OUT_DIR))\Resources\
	
%.o:%.cpp
	-@echo compiling $< for $@
	$(CC) -c $(COMPILE_FLAG) $(INCLUDE_DIRS) $< -o $@

$(GUI_OUT_FILE_DLL):$(GUI_O_FILES) $(GUI_OUT_DIR)
	$(CC) -shared -fPIC -o $(GUI_OUT_FILE_DLL) $(GUI_O_FILES) $(GUI_LINK_DIRS) $(GUI_LINK_LIBS) $(LINK_FLAGS) $(GUI_EXPORTS_DEF)

$(GUI_OUT_FILE_A):$(GUI_O_FILES) $(GUI_OUT_DIR)
	$(AR) $(GUI_OUT_FILE_A) $(GUI_O_FILES)
	
$(GUI_OUT_DIR):
	-@echo Creating out dir
	-@mkdir $(GUI_OUT_DIR)

clean:
	-@echo cleaning
	-del .\GUI\*.o
	-del .\Example\*.o
	-rd /s /q .\$(GUI_OUT_DIR)
