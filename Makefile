BUILD_DIR = build
SOURCE_DIR = src
SOURCE_FILES := $(wildcard $(SOURCE_DIR)/*.cpp) \
				$(wildcard $(SOURCE_DIR)/*.c) \
			   	$(wildcard $(SOURCE_DIR)/game/*.cpp) \
               	$(wildcard $(SOURCE_DIR)/engine/*.cpp) \
				$(wildcard $(SOURCE_DIR)/engine/component/*.cpp) \
				$(wildcard $(SOURCE_DIR)/engine/system/*.cpp) \
               	$(wildcard $(SOURCE_DIR)/utils/*.cpp)
OBJECTS := $(patsubst $(SOURCE_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCE_FILES))
EXECUTABLE = $(BUILD_DIR)/main.exe

CXX = g++
CXXFLAGS = -I$(SOURCE_DIR)/include -L$(SOURCE_DIR)/lib
LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

all: build run

build: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJECTS) $(LIBS)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run:
	./$(EXECUTABLE)

clean:
	del /S /Q build\*.o && del build\*.exe	