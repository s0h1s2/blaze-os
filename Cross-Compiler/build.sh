#! /bin/sh
PREFIX="$HOME/opt/cross" # The binary files will install in here.  
TARGET=i686-elf # CPU target architecure.
BINUTIL_VERSION="2.37"
GCC_VERSION="9.5.0"

mkdir -p ${PREFIX} # Create folder if doesn't exist.

download_binutils(){
	file="binutils-${BINUTIL_VERSION}.tar.gz";
	wget "http://ftpmirror.gnu.org/binutils/${file}";
	tar -xvf ${file};
	
}

make_binutils(){
	# extract file 
	file="binutils-${BINUTIL_VERSION}";
	mkdir -p build-binutils
	cd build-binutils
	../${file}/configure --prefix=$PREFIX  --target=$TARGET --with-sysroot --disable-nls --disable-werror
	make
	make install
}

download_gcc(){
	file="gcc-${GCC_VERSION}.tar.gz";
	wget "http://ftpmirror.gnu.org/gcc/gcc-${GCC_VERSION}/${file}";
	tar -xvf ${file};
}
make_gcc(){
	file="gcc-${GCC_VERSION}";
	mkdir -p build-gcc
	cd build-gcc
	../gcc-9.5.0/configure --target=${TARGET} --prefix=${PREFIX} --disable-nls --enable-languages=c --without-headers
	make all-gcc
	make all-target-libgcc
	make install-gcc
	make install-target-libgcc

}

download_binutils && make_binutils;
download_gcc && make_gcc;
