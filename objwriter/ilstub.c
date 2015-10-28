#include <stdio.h>
extern void* InitObjWriter(const char *ObjectFilePath); extern void FinishObjWriter(void* OW);
extern void SwitchSection(void* OW, const char *SectionName);
extern void EmitAlignment(void* OW, int ByteAlignment);
extern void EmitIntValue(void* OW, unsigned long long Value, unsigned Size);
extern void EmitSymbolDef(void* OW, const char* SymbolName);
extern void EmitSymbolRef(void* OW, const char* SymboleName, int Size, char IsPCRelative, int Delta );
#define TRUE 0
char byte[] = {0xe8, 0, 0, 0,0, 0x48, 0xc7, 0xc0, 0x3, 0,0,0, 0xc3};
int main()
{
 int i=0;
 int size = 14;
 printf("Start object emission\n");
 void* OW = InitObjWriter("repro.obj");
 if (!OW) {
	printf("Error fail to init ObjWriter\n");
	return 1;
 }

 SwitchSection(OW, "text");
 EmitSymbolDef(OW, "foo");
 for(i=0; i<size; i++) {
	if (i==1) {
		// relocation at 1
		EmitSymbolRef(OW, "goo", 4, 1,0);
		i += 3;
		continue;
	}
	EmitIntValue(OW, byte[i], 1); 
 }


 SwitchSection(OW, "data");
 EmitSymbolDef(OW, "eetype");
	EmitSymbolRef(OW, "foo", 8, 0,0);

 FinishObjWriter(OW);
 return 0;
}
