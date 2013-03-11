# 64-bit binaries
mkdir -p x86_64
cp /usr/local/bin/as2transition x86_64/.
cp /usr/local/bin/f2lp x86_64/.
cp /usr/local/bin/cplus2asp.bin x86_64/.
cp -r /usr/local/lib/cplus2asp x86_64/.
cp scripts/* x86_64/.
ln -s ../../tests x86_64/tests

