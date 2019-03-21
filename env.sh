apt-get install build-essential git gcc gnu-efi bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo libcloog-isl-dev texinfo nasm
export PREFIX="/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

mkdir tempsrc
cd tempsrc
wget https://ftp.gnu.org/gnu/binutils/binutils-2.32.tar.xz
wget https://ftp.gnu.org/gnu/gcc/gcc-8.3.0/gcc-8.3.0.tar.xz
tar xf binutils-2.32.tar.xz binutils-2.32/
tar xf gcc-8.3.0.tar.xz gcc-8.3.0/

mkdir build-binutils
cd build-binutils
../binutils-2.32/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install
cd ..

mkdir build-gcc
cd build-gcc
../gcc-8.3.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc
cd ..

echo "export PATH=\"/opt/cross/bin:\$PATH\"" >> ~/.profile

cd ..
rm -rf tempsrc
