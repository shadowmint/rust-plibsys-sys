extern crate cmake;

fn main() {
    let dst = cmake::build("plibsys");
    println!("cargo:rustc-link-search=native={}/lib", dst.display());
    println!("cargo:rustc-link-lib=static=plibsysstatic");
}
