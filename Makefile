cc = g++
INCLUDE = -I./include -I./libs
LIBS= -lsfml-system -lsfml-graphics -lsfml-window

TARGET = out
SRCDIR = src
OBJDIR = build
TARGETDIR = bin

src = $(wildcard $(SRCDIR)/*.cpp)
objs = $(subst $(SRCDIR)/,$(OBJDIR)/, $(patsubst %.cpp, %.o, $(src)))

all: directories $(TARGET)

directories:
	mkdir -p $(TARGETDIR)
	mkdir -p $(OBJDIR) 

$(TARGET):$(objs)
	$(cc) -o $(TARGETDIR)/$(TARGET) $(objs) $(LIBS) 

$(objs):$(src)
	$(cc) -c $(INCLUDE) -o $@ $(patsubst %.o, %.cpp, $(subst build,src,$@))  


clean:
	rm -rf bin build

