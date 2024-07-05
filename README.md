# Rust Std Hashmap C API Bindings

**This project is only for test and study purpose, not ready for production.**

### Generate dylib

1. Generate c header file:
    ```bash
    cbindgen --lang c --output include/hashmap_ffi.h
    ```

2. Generate dylib and pc file:
    ```bash
    cargo cinstall --destdir=./lib --prefix=/usr --libdir=/usr/local/lib
    ```

### Install dylib

1. Copy dylib into system
    ```bash
    sudo cp -a ./lib/* /
    ```

2. Check pkg-config
    ```bash
    pkg-config --libs --cflags hashmap_ffi_c
    ```

