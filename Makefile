# A sample Makefile for building Google Test and using it in user
# tests.  Please tweak it to suit your environment and project.  You
# may want to move it to your project's root directory.
#
# SYNOPSIS:
#
#   make [all]  - makes everything.
#   make TARGET - makes the given target.
#   make clean  - removes all files generated by make.

# Please tweak the following variable definitions as needed by your
# project, except GTEST_HEADERS, which you can use in your own targets
# but shouldn't modify.

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = ./googletest/googletest

# Where to find user code.
USER_DIR = ./src

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++1y

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = graph graph_unittest

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# House-keeping build targets.

all : $(TESTS)

clean :
	rm -rf gtest_main.a $(TESTS) *.o *.gch
	rm -f ./src/*.o

test :
	find . -name '*_unittest' -exec {} \;


# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

listNode.o : $(USER_DIR)/listNode.cpp $(USER_DIR)/listNode.hpp
	$(CXX) $(CXXFLAGS) -o $@ $^

node.o : $(USER_DIR)/node.cpp $(USER_DIR)/node.hpp
	$(CXX) $(CXXFLAGS) -o $@ $^

graph.o : $(USER_DIR)/graph.cpp $(USER_DIR)/graph.hpp
	$(CXX) $(CXXFLAGS) -o $@ $(USER_DIR)/*.cpp

main.o : $(USER_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

graph : $(USER_DIR)/node.o $(USER_DIR)/graph.o $(USER_DIR)/listNode.o $(USER_DIR)/main.o $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $(USER_DIR)/*.o

unit_test.o : $(USER_DIR)/listNode.cpp $(USER_DIR)/listNode.hpp \
				   $(USER_DIR)/node.cpp $(USER_DIR)/node.hpp \
				   $(USER_DIR)/graph.cpp $(USER_DIR)/graph.hpp \
				   $(USER_DIR)/unit_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $(USER_DIR)/unit_test.cpp

graph_unittest : $(USER_DIR)/unit_test.o $(USER_DIR)/listNode.o $(USER_DIR)/node.o $(USER_DIR)/graph.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread -o $@ $^

.PHONY:
	all clean test
