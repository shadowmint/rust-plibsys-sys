# plibsys-sys

This is a rust binding for the excellent plibsys library:

https://github.com/saprykin/plibsys

## Rebuild bindgen bindings

    cd plibsys
    mkdir build
    cd build
    cmake ..
    make
    cp plibsysconfig.h ../src
    cd ../src
    bindgen plibsys.h --match=p > ../../lib.rs

Then check that all the tests still pass.

Notice that bindgen cannot easily parse `#include <...>` and
the current source has been modified to change all code in the
form `#include <ptypes.h>` to `#include "ptypes.h"`.

When importing a new bundled version of plibsys, make sure these
changes are reflected in the commited version.

## License

Notice that plibsys is released under the terms of GNU LGPLv2 or higher license,
and this crate statically links to that library. As such, using this crate will
have license implications.
