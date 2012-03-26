TEST_APPS:=exampleapp1
TEST_LIBS:=examplelib1

CXXFLAGS:=-MMD -O0 -g -fPIC -fmessage-length=0 -Wall

.PHONY: all
all:$(TEST_APPS) $(TEST_LIBS)
	

-include $(addsuffix .d,$(TEST_APPS)) 
-include $(addsuffix .d,$(TEST_LIBS))
-include sharedlib.d

$(TEST_APPS): %: $(addsuffix .o,$(TEST_APPS)) sharedlib.o
	$(CXX) -rdynamic $^ -o $@ -ldl

$(TEST_LIBS): %: $(addsuffix .o,$(TEST_LIBS))
	$(CXX) -shared $^ -o $(addsuffix .so,$@)

.PHONY: clean 	
clean:
	$(RM) \
 	$(TEST_APPS) \
 	$(addsuffix .so,$(TEST_LIBS)) \
 	$(addsuffix .o,$(TEST_APPS)) \
 	$(addsuffix .o,$(TEST_LIBS)) \
 	$(addsuffix .d,$(TEST_APPS)) \
 	$(addsuffix .d,$(TEST_LIBS)) \
 	sharedlib.o sharedlib.d