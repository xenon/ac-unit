AC-Unit: A C unit testing framework.
https://github.com/xenon
Alexander Acker - September 22nd 2018
-------------------------------------------------------------------------------
What does it do?

Enables unit testing in C that is enabled at compile-time.
This results in two different executables, one for testing and one normal.

Why?
This removes all of the testing bloat from the program when you build it.

How?
Using a lot of macros that remove testing code if you are not testing.
-------------------------------------------------------------------------------
Example: Refer to the example directory for a test program.
Run make to build the normal and testing executable.

The testing executable writes a summary of tests to standard out.

-------------------------------------------------------------------------------
Notes:
(1) This code is quick and dirty and should be cleaned.
Macro syntax is especially ugly and cumbersome over multiple lines.

(2) This was created as an example/test of an idea and should by no means
be used in anything more than toy programs.
