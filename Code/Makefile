FMTDIR=/home/geetha/packages/SFML-2.5.1
INCLUDEDIR=$(FMTDIR)/include
LIBDIR=$(FMTDIR)/lib
CC=g++
# CFLAGS=-c -g -Wall -Werror -pedantic -pedantic-errors -I $(INCLUDEDIR)
CFLAGS=-c -g -I $(INCLUDEDIR)
LIBFLAGS=-lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio

SRCS=cards.cpp properties.cpp start.cpp BoardCode.cpp diceRoller.cpp jail.cpp community_chest.cpp chance.cpp mortgage_or_unmortgage.cpp build_and_sell.cpp playing_cards.cpp trade.cpp main.cpp 
OBJS=$(addsuffix .o,$(basename $(SRCS))) 
EXE=monopoly
.PHONY	: clean all

all : $(EXE)

$(EXE)	: $(OBJS)
		$(CC) -o $@ -L $(LIBDIR) $(OBJS) $(LIBFLAGS)


$(OBJS)	:	%.o	: %.cpp
		$(CC) $(CFLAGS) $<


clean :
	rm $(OBJS) $(EXE)
