
CROSS =   
CC = $(CROSS)gcc  
CXX = $(CROSS)g++  
DEBUG = -g -O2  
CFLAGS = $(DEBUG) -Wall -c  
RM = rm -rf  
  
SRCS = $(wildcard ./*.cpp)  
OBJS = $(patsubst %.cpp, %.o, $(SRCS))  
  
VERSION = 1.0.0.0  
TARGET = test.$(VERSION)  
  
$(TARGET) : $(OBJS)  
    $(CXX) $^ -o $@  
  
$(OBJS):%.o : %.cpp  
    $(CXX) $(CFLAGS) $< -o $@  
  
  
clean:  
    $(RM) $(TARGET) *.o 