TEST_APPS:=exampleapp1
TEST_LIBS:=examplelib1

CXXFLAGS:=-MMD -O0 -g -fPIC -fmessage-length=0 -Wall

.PHONY: all
all:$(TEST_APPS) $(TEST_LIBS)
	

-include $(addsuffix .d,$(TEST_APPS)) 
-include $(addsuffix .d,$(TEST_LIBS))
-include sharedlib.d

$(TEST_APPS): % : %.o sharedlib.o
	$(CXX) -static-libstdc++ -static-libgcc -rdynamic $^ -o $@ -ldl

.PHONY: $(TEST_LIBS)
$(TEST_LIBS): $(patsubst %,lib%.so,$(TEST_LIBS))
$(patsubst %,lib%.so,$(TEST_LIBS)): lib%.so: %.o
	$(CC) -static-libgcc -shared $^ -o $@

.PHONY: clean 	
clean:
	$(RM) \
 	$(TEST_APPS) \
 	$(addprefix lib,$(addsuffix .so,$(TEST_LIBS))) \
 	$(addsuffix .o,$(TEST_APPS)) \
 	$(addsuffix .o,$(TEST_LIBS)) \
 	$(addsuffix .d,$(TEST_APPS)) \
 	$(addsuffix .d,$(TEST_LIBS)) \
 	sharedlib.o sharedlib.d