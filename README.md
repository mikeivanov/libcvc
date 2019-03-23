# libcvc

An experimental pure-C binding to OpenCV 4. 
Intended to be used with libffi. Incomplete. Pre-alpha quality.

License: MIT.

## Building

  1. Install OpenCV v 4.0.1 or later
  2. Checkout the repositiry
  3. Then:

        $ mkdir build && cd build
        $ cmake ..
        $ make

    This will generate `libcvc.so`. 
  4. Rename it to `libcvc.so.0.1` (yes, I know, but this is not important at this point).
  5. Either copy `libcvc.so.0.1` to `/usr/local/lib64` or 
     `export LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH`.

## An anticipatory FAQ

### Why this binding is necessary?

Since the OpenCV 4.0 release, the official C API had been completely stripped off
the project. As a result, developers working with all those scripting
languages out there lost access to OpenCV.

### OpenCV has got official Python and Java bindings, wasn't that enough?

There is also PyPy, and IronPython, and Ruby (with its variants), Tcl,
Lua, Common Lisp and many others -- none of them has access to OpenCV
via the official bindings.

### Why pure C?

Because it is the only practical way of making libraries callable via libffi.

### Why libffi?

Libffi is a de-facto standard and is available in virtually all
scripting languages.

### But most of the scripting lagnuages support C++ extensions (like RCpp). So, why C/libffi?

These C++ extensions are invariably implementation-specific, not
language-specific. One cannot just take a CPython extension and use it
with IronPython, for example. The same applies to Common Lisp and many
other languages. libffi closes this gap by allowing developers to do
exactly that: share extension libraries between implementations.

### How complete is LibCVC?

It is *very* far from being complete. It might be considered somewhat
usable at this point, depending on the task at hand.

However -- 100% completeness in terms of API coverage is not a
goal. The reason is that OpenCV API contains numerous C++ specific
artifacts that make no sense in other languages. Therefore, the goal
is to achieve semantic completeness instead. For example, among all variadic
OpenCV functions or methods solving the same problem, usually only the
most specific one is wrapped.

### Which languages/projects use LibCVC?

There is a Common Lisp wrapper - https://github.com/mikeivanov/see
