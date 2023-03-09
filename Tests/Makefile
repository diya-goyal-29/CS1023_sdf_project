GTDIR=../Package/gtest
SFMLDIR = /home/geetha/packages/SFML-2.5.1

GINCLUDEDIR=$(GTDIR)/include 
SINCLUDEDIR = $(SFMLDIR)/include

GLIBDIR=$(GTDIR)/build/lib 
SLIBDIR = $(SFMLDIR)/lib

CC=g++
CFLAGS=-c -g  -I $(GINCLUDEDIR) -I $(SINCLUDEDIR)
LIBFLAGS= -lgtest -lpthread -lgtest_main -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
CODEDIR = ../Code
SRCS =  $(CODEDIR)/cards.cpp $(CODEDIR)/properties.cpp dice.cpp build.cpp  sell.cpp mortgage.cpp main.cpp 
OBJS = $(addsuffix .o,$(basename $(SRCS))) 
EXE=tests
.PHONY	: clean all
OBJS_NEW = $(OBJS:../Code/%=%)

all : $(EXE)

$(EXE)	: $(OBJS) $(OBJS_NEW)
		$(CC) -o $@ -L $(GLIBDIR) -L $(SLIBDIR) $(OBJS_NEW)  $(LIBFLAGS)


$(OBJS) 	:	%.o	: %.cpp
		$(CC) $(CFLAGS) $(SRCS) $<

clean :
	rm $(OBJS_NEW) $(EXE)

