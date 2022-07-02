#! /bin/sh
export PREFIX="$HOME/opt/cross" # The binary files will install in here.  
export TARGET=i686-elf # CPU target architecure.
export PATH="$PREFIX/bin:$PATH" # Append path to current path on terminal.

mkdir -p $PREFIX # Create folder if doesn't exist.
if ! which -- $TARGET-as; then
mkdir -p build-binutils
# Build tools and other utils
cd build-binutils
../binutils-2.37.90/configure --prefix=$PREFIX  --target=$TARGET --with-sysroot --disable-nls --disable-werror
make
make install
which -- $TARGET-as || echo $TARGET was installed.
fi
# Build gcc compiler
mkdir -p build-gcc
cd gcc-9.5.0/
../gcc-9.5.0/configure --target=$TARGET --prefix=$PREFIX --disable-nls --enable-languages=c --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc

