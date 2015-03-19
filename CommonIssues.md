# Introduction #

Mockitopp is a very powerful framework that uses some advanced (but portable!) C++ techniques to provide its features. Sometimes when using mockitopp, you may run into template-oriented compile issues, or runtime crashes, that are scary looking. Don't Panic!

# Increasing the maximum mockable methods and arguments #

mockitopp does have a built-in limit for the maximum number of methods it allows on a mocked class, as well as a limit on the number of arguments allowed on a given mocked class' method(s). These are due to the fact that mockitopp uses the m4 macro language to generate these aspects of the framework. The number is a relatively constrained default of 100 virtual methods and 20 arguments per method.

If you know that you will be mocking pure virtual classes with more than 100 methods, or mocking methods with more than 20 arguments, you should increase these values:

  * install 'scons' for your platform
  * edit the SConstruct file in mockitopp's source directory
  * increase the MOCKITOPP\_MAX\_VIRTUAL\_FUNCTIONS to the number of methods (plus some pasdding) on the largest pure virtual class you are expecting to mock
  * increase the MOCKITOPP\_MAX\_VIRTUAL\_FUNCTION\_ARITY to the number of arguments (plus some padding) on the pure virtual method with the largest number of arguments you are expecting to mock
  * type 'scons m4'
  * make sure you see the build output showing the execution of m4 to regenerate dynamic\_object.hpp, dynamic\_vfunction.hpp, etc
  * save/commit the mockitopp directory to your local source repository/fork, or make this regeneration part of your build script

Note that with the extra template classes and method overloads, the compile will get a little slower. For most, it's imperceptible.