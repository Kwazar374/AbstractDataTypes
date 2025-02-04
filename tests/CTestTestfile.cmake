# CMake generated Testfile for 
# Source directory: C:/DEV/REPOS/AbstractDataTypes/tests
# Build directory: C:/DEV/REPOS/AbstractDataTypes/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(QueueTests "C:/DEV/REPOS/AbstractDataTypes/tests/Debug/TestQueueArrayRepresentation.exe")
  set_tests_properties(QueueTests PROPERTIES  _BACKTRACE_TRIPLES "C:/DEV/REPOS/AbstractDataTypes/tests/CMakeLists.txt;17;add_test;C:/DEV/REPOS/AbstractDataTypes/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(QueueTests "C:/DEV/REPOS/AbstractDataTypes/tests/Release/TestQueueArrayRepresentation.exe")
  set_tests_properties(QueueTests PROPERTIES  _BACKTRACE_TRIPLES "C:/DEV/REPOS/AbstractDataTypes/tests/CMakeLists.txt;17;add_test;C:/DEV/REPOS/AbstractDataTypes/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(QueueTests "C:/DEV/REPOS/AbstractDataTypes/tests/MinSizeRel/TestQueueArrayRepresentation.exe")
  set_tests_properties(QueueTests PROPERTIES  _BACKTRACE_TRIPLES "C:/DEV/REPOS/AbstractDataTypes/tests/CMakeLists.txt;17;add_test;C:/DEV/REPOS/AbstractDataTypes/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(QueueTests "C:/DEV/REPOS/AbstractDataTypes/tests/RelWithDebInfo/TestQueueArrayRepresentation.exe")
  set_tests_properties(QueueTests PROPERTIES  _BACKTRACE_TRIPLES "C:/DEV/REPOS/AbstractDataTypes/tests/CMakeLists.txt;17;add_test;C:/DEV/REPOS/AbstractDataTypes/tests/CMakeLists.txt;0;")
else()
  add_test(QueueTests NOT_AVAILABLE)
endif()
subdirs("../_deps/googletest-build")
