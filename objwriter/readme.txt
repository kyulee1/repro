// copy .so here – 
cp ~/GitRepo/corert/src/build-objwriter/libobjwriter.so  .

// build repro.obj emitter
gcc ilstub.c -L. -lobjwriter


// make sure ld path is set to current to find .so
export LD_LIBRARY_PATH=.
./a.out

// check relocation
objdump -r repro.obj

// check disasm
objdump -d repro.obj

