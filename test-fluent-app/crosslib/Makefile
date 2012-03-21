LIBNAME   :=cross-library

SOURCES   :=sharedlib.cpp
OBJ       :=$(patsubst %.cpp,%.o,$(patsubst %.cc,%.o,$(patsubst %.c,%.o,$(SOURCES)))) 

########
#
#INCLUDE_LOG4CPLUS - absolute path to log4cplus
#INCLUDE_EXTERNALS - absolute path to externals dir
#
######
INCLUDEDIRS:=$(INCLUDE_EXTERNALS):$(INCLUDE_LOG4CPLUS)
FLAGS      +=-MMD -Wall -fdiagnostics-show-option -fmessage-length=0
LIBS       :=
CFLAGS     :=$(sort $(CFLAGS) $(patsubst %,-I%,$(subst :, ,$(INCLUDEDIRS))) $(FLAGS) )
CXXFLAGS   :=$(sort $(CXXFLAGS) $(patsubst %,-I%,$(subst :, ,$(INCLUDEDIRS))) $(FLAGS) )

.PHONY: build clean distclean
build : builtin.o

builtin.o: $(OBJ)
	$(LD) -Ur -o $@ $(OBJ) $(EXTOBJ)
	@echo "[+] $(LIBNAME).$(VERSION)"

-include $(OBJ:.o=.d)
	
	
clean:
	$(RM) $(OBJ) $(OBJ:.o=.d) $(LIBNAME).a builtin.o
	@echo "[-] $(LIBNAME).$(VERSION)"
distclean:clean
	