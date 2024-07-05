use std::collections::HashMap;
use std::ffi::{CStr, CString};
use std::os::raw::c_char;

#[no_mangle]
pub extern "C" fn hashmap_new() -> *mut HashMap<CString, CString> {
    let map = Box::new(HashMap::new());
    Box::into_raw(map)
}

#[no_mangle]
pub extern "C" fn hashmap_insert(map: *mut HashMap<CString, CString>, key: *const c_char, value: *const c_char) {
    let map = unsafe {
        assert!(!map.is_null());
        &mut *map
    };
    let key_cstr = unsafe { CStr::from_ptr(key) };
    let value_cstr = unsafe { CStr::from_ptr(value) };
    map.insert(key_cstr.to_owned(), value_cstr.to_owned());
}

#[no_mangle]
pub extern "C" fn hashmap_get(map: *mut HashMap<CString, CString>, key: *const c_char) -> *const c_char {
    let map = unsafe {
        assert!(!map.is_null());
        &mut *map
    };
    let key_cstr = unsafe { CStr::from_ptr(key) };

    match map.get(key_cstr) {
        Some(value) => value.as_ptr(),
        None => std::ptr::null()
    }
}

#[no_mangle]
pub extern "C" fn hashmap_free(map: *mut HashMap<CString, CString>) {
    if !map.is_null() {
        unsafe { Box::from_raw(map); }
    }
}

