# ------------------------------------------------
# Generic Makefile
#
# Authors: Soundharya Bommi Raja Bommannan,Aniruudh Kannan,Adhithyan Haridas
# Date   : 2020-04-22
#
# Changelog :
# 2020-04-16: Inital Draft
# 2020-04-22: Makefile final draft
#
# ------------------------------------------------

# project name (generate executable with this name)
TARGET   = SABM

# change these to proper directories where each file should be
SRCDIR     	 = src
SRCTESTDIR	 = test
OBJDIR    	 = obj
BINDIR    	 = bin
INCDIR	  	 = include
INCTESTDIR	 = test/include

CC       = gcc
# compiling flags here
LM = -lm
CFLAGS   = -Wall

INC      := -I$(INCDIR) -I$(INCTESTDIR)
SOURCES  := $(wildcard $(SRCDIR)/*.c)
TSOURCES := $(wildcard $(SRCTESTDIR)/*.c)
OBJECTS1 := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJECTS2 := $(TSOURCES:$(SRCTESTDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS1) $(OBJECTS2)
	@mkdir -p $(BINDIR)

	@$(CC) $(OBJECTS1) $(OBJECTS2) -o $@ $(LM) 
	@echo "Linking complete!"

$(OBJECTS1): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)

	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ $(LM) 
	@echo "Compiled "$<" successfully!"

$(OBJECTS2): $(OBJDIR)/%.o : $(SRCTESTDIR)/%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ $(LM)  
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(rm) $(OBJECTS1) $(OBJECTS2) $(BINDIR)/$(TARGET)
	@echo "Cleanup complete!"
