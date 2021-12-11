//COMPILE WITH: 'gcc ./main.c  -w  -w /opt/bah/libs/libgc.a -lpthread -lm -lsqlite3 -g'


#define noCheck(v) v
#define array(type)	struct{	type *data; long int length; long int elemSize; }
typedef array(char*)* __BAH_ARR_TYPE_cpstring;
long int __BAH__main(__BAH_ARR_TYPE_cpstring);

        #include "/opt/bah/libs/include/gc.h"
        int main(int argc, char ** argv) {
        GC_INIT();
        array(char*) * args = GC_MALLOC(sizeof(array(char*)));
        args->data = GC_MALLOC(sizeof(char*)*argc);
        memcpy(args->data, argv, sizeof(char*)*argc);
        args->elemSize = sizeof(char*);
        args->length = argc;
        long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);
        GC_FREE(args->data);
        GC_FREE(args);
        return r;
        };
        #define main(v) __BAH__main(v)
        #include <signal.h>
#include <string.h>
#define null (void *)0
#define true (int)1
#define false (int)0
#include <sys/mman.h>
#define SIZE_OF_INT 8
#define SIZE_OF_CHAR 1
#define SIZE_OF_INT32 4
#define SIZE_OF_FLOAT32 4
#define SIZE_OF_FLOAT 8
long int len(void * a){
long int i =  0;
noCheck( array ( void* ) *arr = a );
noCheck( i = arr -> length );
long int ____BAH_COMPILER_VAR_0 = i;
return ____BAH_COMPILER_VAR_0;
};
#include </opt/bah/libs/include/gc.h>
void * memoryAlloc(long int s){
void * ____BAH_COMPILER_VAR_1 = GC_MALLOC(s);
return ____BAH_COMPILER_VAR_1;
};
void destroy(void * a){
GC_FREE(a);
};
void clear(void * a){
noCheck( array ( void* ) *arr = a );
noCheck( destroy ( arr -> data ) );
noCheck( arr -> data = memoryAlloc ( sizeof ( 0 ) ) );
noCheck( arr -> length = 0 );
};
void * memoryRealloc(void * p,long int s){
void * ____BAH_COMPILER_VAR_2 = GC_REALLOC(p,s);
return ____BAH_COMPILER_VAR_2;
};
void cleanShutDown(){
exit(1);
return;
};
void append(void * a,void * b){
noCheck( array ( void* ) *arrA = a );
noCheck( array ( void* ) *arrB = b );
long int lenA =  0;
long int lenB =  0;
long int realSizeA =  0;
long int realSizeB =  0;
noCheck( lenA = len ( arrA ) );
noCheck( lenB = len ( arrB ) );
if ((lenB==0)) {
return;
}
if ((lenA==0)) {
noCheck( arrA -> data = arrB -> data );
noCheck( arrA -> length = arrB -> length );
return;
}
noCheck( realSizeA = lenA * arrA -> elemSize );
noCheck( realSizeB = lenB * arrB -> elemSize );
void * buff =  memoryAlloc(realSizeA + realSizeB + 32);
noCheck( memcpy ( buff , arrA -> data , realSizeA ) );
noCheck( memcpy ( buff + lenA , arrB -> data , realSizeB ) );
noCheck( arrA -> length = lenA + lenB );
noCheck( arrA -> data = buff );
};
void copy(void * a,void * b){
noCheck( array ( void* ) *arrA = a );
noCheck( array ( void* ) *arrB = b );
long int lenB =  0;
long int realSizeB =  0;
noCheck( lenB = len ( arrB ) );
noCheck( realSizeB = lenB * arrB -> elemSize );
noCheck( arrA -> data = memoryAlloc ( realSizeB ) );
noCheck( memcpy ( arrA -> data , arrB -> data , realSizeB ) );
noCheck( arrA -> length = arrB -> length );
};
#define PROT_READ 1
#define PROT_WRITE 2
#define PROT_READWRITE 3
#define MAP_SHARED 1
#define MAP_ANONYMOUS 32
void * sharedMemory(long int size){
if ((size==0)) {
size =  4096;
}
void * r =  mmap(0,size,PROT_READ + PROT_WRITE,MAP_SHARED + MAP_ANONYMOUS,-1,0);
void * ____BAH_COMPILER_VAR_6 = r;
return ____BAH_COMPILER_VAR_6;
};
void allocateArray(void * arr,long int nbElems){
noCheck( array ( void* ) *a = arr );
noCheck( a -> length = nbElems );
noCheck( a -> data = memoryAlloc ( nbElems * a -> elemSize ) );
};
typedef array(char)* __BAH_ARR_TYPE_char;
__BAH_ARR_TYPE_char ser(void * a);
__BAH_ARR_TYPE_char __serialize(void * a,long int s){
char * r =  memoryAlloc(s + 9);
memcpy(r,&s,8);
memcpy(noCheck( r + 8 ),a,s);
long int l =  s + 1;
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
noCheck( arr -> length = s + 8 );
noCheck( arr -> elemSize = 1 );
noCheck( arr -> data = r );
array(char)* ____BAH_COMPILER_VAR_7 = arr;
return ____BAH_COMPILER_VAR_7;
};
long int serlen(__BAH_ARR_TYPE_char data){
array(char)* sarr = memoryAlloc(sizeof(array(char)));

sarr->length = 8;
sarr->elemSize = sizeof(char);
sarr->data = memoryAlloc(sizeof(char) * 50);sarr->data[0] = data->data[0];
sarr->data[1] = data->data[1];
sarr->data[2] = data->data[2];
sarr->data[3] = data->data[3];
sarr->data[4] = data->data[4];
sarr->data[5] = data->data[5];
sarr->data[6] = data->data[6];
sarr->data[7] = data->data[7];
long int ____BAH_COMPILER_VAR_8 = noCheck( *sarr -> data );
return ____BAH_COMPILER_VAR_8;
};
void * unser(__BAH_ARR_TYPE_char data){
long int sptr =  serlen(data);
void * r =  memoryAlloc(sptr);
memcpy(r,noCheck( data -> data + 8 ),sptr);
void * ____BAH_COMPILER_VAR_9 = r;
return ____BAH_COMPILER_VAR_9;
};
char * concatCPSTRING(char * a,char * b){
long int lenA =  strlen(a);
long int lenB =  strlen(b);
char * r =  memoryAlloc(lenA + lenB + 1);
strncpy(r,a,lenA);
strcat(r,b);
char * ____BAH_COMPILER_VAR_10 = r;
return ____BAH_COMPILER_VAR_10;
};
char * __STR(char * a){
long int lenA =  strlen(a);
char * r =  memoryAlloc(lenA + 1);
strncpy(r,a,lenA);
char * ____BAH_COMPILER_VAR_11 = r;
return ____BAH_COMPILER_VAR_11;
};
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void print(char * s){
write((void *)1,s,strlen(s));
};
void panic(char * e){
if (strlen(e)) {
print(e);
print("\n");
cleanShutDown();
}
};
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <math.h>
void strCatOffset(char * dest,long int destLen,char * src,long int srcLen){
memcpy(noCheck( dest + destLen ),src,srcLen);
};
char cpstringCharAt(char * s,long int i){
char c =  (char)0;
noCheck( c = s [ i ] );
char ____BAH_COMPILER_VAR_12 = c;
return ____BAH_COMPILER_VAR_12;
};
char * charToString(char c){
char * s =  memoryAlloc(2);
strncpy(s,(char *)&c,1);
char * ____BAH_COMPILER_VAR_13 = s;
return ____BAH_COMPILER_VAR_13;
};
long int isUpper(char c){
if ((c>(char)64)) {
if ((c<(char)91)) {
long int ____BAH_COMPILER_VAR_14 = 1;
return ____BAH_COMPILER_VAR_14;
}
}
long int ____BAH_COMPILER_VAR_15 = 0;
return ____BAH_COMPILER_VAR_15;
};
long int isLower(char c){
if ((c>(char)96)) {
if ((c<(char)123)) {
long int ____BAH_COMPILER_VAR_16 = 1;
return ____BAH_COMPILER_VAR_16;
}
}
long int ____BAH_COMPILER_VAR_17 = 0;
return ____BAH_COMPILER_VAR_17;
};
long int isLetter(char s){
if (isUpper(s)) {
long int ____BAH_COMPILER_VAR_18 = 1;
return ____BAH_COMPILER_VAR_18;
}
if (isLower(s)) {
long int ____BAH_COMPILER_VAR_19 = 1;
return ____BAH_COMPILER_VAR_19;
}
long int ____BAH_COMPILER_VAR_20 = 0;
return ____BAH_COMPILER_VAR_20;
};
long int isNumber(char c){
if ((c>(char)47)) {
if ((c<(char)58)) {
long int ____BAH_COMPILER_VAR_21 = 1;
return ____BAH_COMPILER_VAR_21;
}
}
long int ____BAH_COMPILER_VAR_22 = 0;
return ____BAH_COMPILER_VAR_22;
};
long int isAlphaNumeric(char s){
if (isLetter(s)) {
long int ____BAH_COMPILER_VAR_23 = 1;
return ____BAH_COMPILER_VAR_23;
}
if (isNumber(s)) {
long int ____BAH_COMPILER_VAR_24 = 1;
return ____BAH_COMPILER_VAR_24;
}
long int ____BAH_COMPILER_VAR_25 = 0;
return ____BAH_COMPILER_VAR_25;
};
long int isSpace(char c){
if ((c==(char)32)) {
long int ____BAH_COMPILER_VAR_26 = 1;
return ____BAH_COMPILER_VAR_26;
}
if ((c==(char)9)) {
long int ____BAH_COMPILER_VAR_27 = 1;
return ____BAH_COMPILER_VAR_27;
}
if ((c==(char)10)) {
long int ____BAH_COMPILER_VAR_28 = 1;
return ____BAH_COMPILER_VAR_28;
}
if ((c==(char)11)) {
long int ____BAH_COMPILER_VAR_29 = 1;
return ____BAH_COMPILER_VAR_29;
}
if ((c==(char)13)) {
long int ____BAH_COMPILER_VAR_30 = 1;
return ____BAH_COMPILER_VAR_30;
}
long int ____BAH_COMPILER_VAR_31 = 0;
return ____BAH_COMPILER_VAR_31;
};
char * arrAsStr(__BAH_ARR_TYPE_char arr);
void println(char * s);
struct string {
char * content;
long int length;
void(*set)(struct string* this,char * s);
void(*append)(struct string* this,char * s);
void(*prepend)(struct string* this,char * s);
char(*charAt)(struct string* this,long int i);
long int(*compare)(struct string* this,char * s);
char *(*str)(struct string* this);
void(*replace)(struct string* this,char * nd,char * rl);
long int(*count)(struct string* this,char * need);
long int(*hasPrefix)(struct string* this,char * need);
long int(*hasSuffix)(struct string* this,char * need);
void(*trim)(struct string* this);
void(*trimLeft)(struct string* this,long int s);
void(*trimRight)(struct string* this,long int s);
struct string(*add)(struct string* this,struct string s2);
};
void string__set(struct string* this,char * s){
this->length =  strlen(s);
this->content =  (char *)memoryAlloc(this->length + 1);
strncpy(this->content,s,this->length);
};
void string__append(struct string* this,char * s){
long int sl =  strlen(s);
long int nl =  sl + this->length;
void * nc =  memoryRealloc(this->content,nl + 1);
if ((nc==null)) {
panic("Error appending to string, possibly due to memory shortage.");
}
this->content =  nc;
strCatOffset(this->content,this->length,s,sl);
this->length =  nl;
};
void string__prepend(struct string* this,char * s){
long int sl =  strlen(s);
long int nl =  this->length + sl;
char * tmpS =  this->content;
void * nc =  memoryAlloc(nl + 1);
if ((nc==null)) {
panic("Error appending to string, possibly due to memory shortage.");
}
this->content =  nc;
strncpy(this->content,s,sl);
strCatOffset(this->content,sl,tmpS,this->length);
destroy(tmpS);
this->length =  nl;
};
char string__charAt(struct string* this,long int i){
char c =  (char)0;
if ((i<this->length)) {
noCheck( c = this -> content [ i ] );
char ____BAH_COMPILER_VAR_32 = c;
return ____BAH_COMPILER_VAR_32;
}
char ____BAH_COMPILER_VAR_33 = c;
return ____BAH_COMPILER_VAR_33;
};
long int string__compare(struct string* this,char * s){
long int r =  strcmp(this->content,s);
if ((r==0)) {
long int ____BAH_COMPILER_VAR_34 = 1;
return ____BAH_COMPILER_VAR_34;
}
long int ____BAH_COMPILER_VAR_35 = 0;
return ____BAH_COMPILER_VAR_35;
};
char * string__str(struct string* this){
char * s =  this->content;
char * ____BAH_COMPILER_VAR_36 = s;
return ____BAH_COMPILER_VAR_36;
};
void string__replace(struct string* this,char * nd,char * rl){
struct string needle =  {};
needle.content= null;
needle.set = string__set;
needle.append = string__append;
needle.prepend = string__prepend;
needle.charAt = string__charAt;
needle.compare = string__compare;
needle.str = string__str;
needle.replace = string__replace;
needle.set((struct string*)&needle,nd);
struct string repl =  {};
repl.content= null;
repl.set = string__set;
repl.append = string__append;
repl.prepend = string__prepend;
repl.charAt = string__charAt;
repl.compare = string__compare;
repl.str = string__str;
repl.replace = string__replace;
repl.set((struct string*)&repl,rl);
long int i =  0;
long int si =  0;
long int replcBuffSart =  0;
long int replcBuffLength =  0;
array(char)* buff = memoryAlloc(sizeof(array(char)));

buff->length = 0;
buff->elemSize = sizeof(char);
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
char rc =  needle.charAt((struct string*)&needle,si);
if ((c==rc)) {
si =  si + 1;
if ((replcBuffLength==0)) {
replcBuffSart =  i;
}
replcBuffLength =  replcBuffLength + 1;
}
else {
if ((replcBuffLength>0)) {
si =  0;
long int j =  0;
while ((j<replcBuffLength)) {

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] =  this->charAt((struct string*)this,j + replcBuffSart);
buff->length = nLength+1;
} else {
buff->data[len(buff)] =  this->charAt((struct string*)this,j + replcBuffSart);
}
};
j =  j + 1;
};
replcBuffLength =  0;
}

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] =  c;
buff->length = nLength+1;
} else {
buff->data[len(buff)] =  c;
}
};
}
if ((si==needle.length)) {
replcBuffLength =  0;
long int ii =  0;
while ((ii<repl.length)) {
long int a =  ii;

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] =  repl.charAt((struct string*)&repl,ii);
buff->length = nLength+1;
} else {
buff->data[len(buff)] =  repl.charAt((struct string*)&repl,ii);
}
};
ii =  ii + 1;
};
si =  0;
}
i =  i + 1;
};
char * r =  arrAsStr(buff);
if ((replcBuffLength>0)) {
array(char)* replbuffStr = memoryAlloc(sizeof(array(char)));

replbuffStr->length = 0;
replbuffStr->elemSize = sizeof(char);
allocateArray(replbuffStr,replcBuffLength + 1);
long int j =  0;
while ((j<replcBuffLength)) {

{
long nLength = j;
if (replbuffStr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(replbuffStr->data, (nLength+50)*sizeof(char));
replbuffStr->data = newPtr;
}
replbuffStr->data[j] =  this->charAt((struct string*)this,j + replcBuffSart);
replbuffStr->length = nLength+1;
} else {
replbuffStr->data[j] =  this->charAt((struct string*)this,j + replcBuffSart);
}
};
j =  j + 1;
};
char * ____BAH_COMPILER_VAR_37 =arrAsStr(replbuffStr);char * ____BAH_COMPILER_VAR_38 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(r);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_37);
;                            
                        ____BAH_COMPILER_VAR_38 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_38+currStrOff, r, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_38+currStrOff, ____BAH_COMPILER_VAR_37, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    r =  ____BAH_COMPILER_VAR_38;
}
if (((void *)r!=null)) {
this->set((struct string*)this,r);
}
};
long int string__count(struct string* this,char * need){
long int i =  0;
long int count =  0;
struct string needle =  {};
needle.content= null;
needle.set = string__set;
needle.append = string__append;
needle.prepend = string__prepend;
needle.charAt = string__charAt;
needle.compare = string__compare;
needle.str = string__str;
needle.replace = string__replace;
needle.count = string__count;
needle.set((struct string*)&needle,need);
long int countIndex =  0;
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
char sc =  needle.charAt((struct string*)&needle,countIndex);
if ((c==sc)) {
countIndex =  countIndex + 1;
}
else {
countIndex =  0;
}
if ((countIndex==needle.length)) {
count =  count + 1;
countIndex =  0;
}
i =  i + 1;
};
long int ____BAH_COMPILER_VAR_39 = count;
return ____BAH_COMPILER_VAR_39;
};
long int string__hasPrefix(struct string* this,char * need){
long int i =  0;
long int nl =  strlen(need);
if ((this->length<nl)) {
long int ____BAH_COMPILER_VAR_40 = 0;
return ____BAH_COMPILER_VAR_40;
}
while ((i<nl)) {
char c =  this->charAt((struct string*)this,i);
char sc =  cpstringCharAt(need,i);
if ((c!=sc)) {
long int ____BAH_COMPILER_VAR_41 = 0;
return ____BAH_COMPILER_VAR_41;
}
i =  i + 1;
};
long int ____BAH_COMPILER_VAR_42 = 1;
return ____BAH_COMPILER_VAR_42;
};
long int string__hasSuffix(struct string* this,char * need){
long int nl =  strlen(need);
if ((this->length<nl)) {
long int ____BAH_COMPILER_VAR_43 = 0;
return ____BAH_COMPILER_VAR_43;
}
long int i =  this->length - nl;
long int needleIndex =  0;
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
char sc =  cpstringCharAt(need,needleIndex);
if ((c!=sc)) {
long int ____BAH_COMPILER_VAR_44 = 0;
return ____BAH_COMPILER_VAR_44;
}
needleIndex =  needleIndex + 1;
i =  i + 1;
};
long int ____BAH_COMPILER_VAR_45 = 1;
return ____BAH_COMPILER_VAR_45;
};
void string__trim(struct string* this){
if ((this->length==0)) {
return;
}
char fc =  this->charAt((struct string*)this,0);
if ((isSpace(fc)==0)) {
return;
}
long int i =  0;
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
if ((isSpace(c)==0)) {
break;
}
i =  i + 1;
};
if ((i>0)) {
this->length =  this->length - i;
char * tmpS =  memoryAlloc(this->length + 1);
memcpy(tmpS,noCheck( this->content + i ),this->length + 1);
this->content =  tmpS;
}
};
void string__trimLeft(struct string* this,long int s){
long int nSize =  this->length - s;
void * tmpS =  memoryAlloc(nSize);
memcpy(tmpS,noCheck( this->content + s ),nSize);
this->content =  tmpS;
this->length =  nSize;
};
void string__trimRight(struct string* this,long int s){
long int nSize =  this->length - s;
void * tmpS =  memoryAlloc(nSize);
memcpy(tmpS,this->content,nSize);
this->content =  tmpS;
this->length =  nSize;
};
struct string string__add(struct string* this,struct string s2){
struct string r =  {};
r.content= null;
r.set = string__set;
r.append = string__append;
r.prepend = string__prepend;
r.charAt = string__charAt;
r.compare = string__compare;
r.str = string__str;
r.replace = string__replace;
r.count = string__count;
r.hasPrefix = string__hasPrefix;
r.hasSuffix = string__hasSuffix;
r.trim = string__trim;
r.trimLeft = string__trimLeft;
r.trimRight = string__trimRight;
r.add = string__add;
r.length =  this->length + s2.length;
r.content =  memoryAlloc(r.length + 1);
strncpy(r.content,this->content,this->length);
strCatOffset(r.content,this->length,s2.content,s2.length);
struct string ____BAH_COMPILER_VAR_48 = r;
return ____BAH_COMPILER_VAR_48;
};
struct string string(char * s){
struct string a =  {};
a.content= null;
a.set = string__set;
a.append = string__append;
a.prepend = string__prepend;
a.charAt = string__charAt;
a.compare = string__compare;
a.str = string__str;
a.replace = string__replace;
a.count = string__count;
a.hasPrefix = string__hasPrefix;
a.hasSuffix = string__hasSuffix;
a.trim = string__trim;
a.trimLeft = string__trimLeft;
a.trimRight = string__trimRight;
a.add = string__add;
a.set((struct string*)&a,s);
struct string ____BAH_COMPILER_VAR_49 = a;
return ____BAH_COMPILER_VAR_49;
};
char * arrToStr(__BAH_ARR_TYPE_char arr){
long int strLen =  len(arr);
char * str =  memoryAlloc(strLen + 1);
noCheck( memcpy ( str , arr -> data , strLen ) );
char * ____BAH_COMPILER_VAR_50 = str;
return ____BAH_COMPILER_VAR_50;
};
__BAH_ARR_TYPE_char strToArr(char * str){
long int strLen =  strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
noCheck( arr -> data = memoryAlloc ( strLen + 1 ) );
noCheck( memcpy ( arr -> data , str , strLen ) );
noCheck( arr -> length = strLen );
array(char)* ____BAH_COMPILER_VAR_51 = arr;
return ____BAH_COMPILER_VAR_51;
};
char * arrAsStr(__BAH_ARR_TYPE_char arr){
char * ____BAH_COMPILER_VAR_52 = noCheck( arr -> data );
return ____BAH_COMPILER_VAR_52;
};
__BAH_ARR_TYPE_char strAsArr(char * str){
long int l =  strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
noCheck( arr -> length = l );
noCheck( arr -> data = str );
array(char)* ____BAH_COMPILER_VAR_53 = arr;
return ____BAH_COMPILER_VAR_53;
};
struct string intToString(long int i){
char * buff =  memoryAlloc(65);
void * ptri =  (void *)i;
sprintf(buff,"%d",ptri);
struct string r =  string(buff);
struct string ____BAH_COMPILER_VAR_54 = r;
return ____BAH_COMPILER_VAR_54;
};
char * intToStr(long int i){
char * buff =  memoryAlloc(50);
sprintf(buff,"%ld",i);
char * ____BAH_COMPILER_VAR_55 = buff;
return ____BAH_COMPILER_VAR_55;
};
char * floatToStr(double f){
char * buff =  memoryAlloc(50);
sprintf(buff,"%lf",f);
char * ____BAH_COMPILER_VAR_56 = buff;
return ____BAH_COMPILER_VAR_56;
};
long int strToInt(char * s){
long int ____BAH_COMPILER_VAR_57 = atol(s);
return ____BAH_COMPILER_VAR_57;
};
double strToFloat(char * s){
double ____BAH_COMPILER_VAR_58 = strtod(s,null);
return ____BAH_COMPILER_VAR_58;
};
long int stringToInt(struct string s){
long int i =  atol(s.content);
long int ____BAH_COMPILER_VAR_59 = i;
return ____BAH_COMPILER_VAR_59;
};
typedef array(struct string)* __BAH_ARR_TYPE_string;
__BAH_ARR_TYPE_string splitString(struct string s,char * sp){
struct string sep =  string(sp);
array(struct string)* res = memoryAlloc(sizeof(array(struct string)));

res->length = 0;
res->elemSize = sizeof(struct string);
struct string sepBuffer =  string("");
long int sepIndex =  0;
long int i =  0;
struct string replcBuff =  string("");
array(char)* tmpString = memoryAlloc(sizeof(array(char)));

tmpString->length = 0;
tmpString->elemSize = sizeof(char);
while ((i<s.length)) {
char c =  s.charAt((struct string*)&s,i);
char sepc =  sep.charAt((struct string*)&sep,sepIndex);
if ((c==sepc)) {
sepIndex =  sepIndex + 1;
char * ____BAH_COMPILER_VAR_60 =charToString(c);replcBuff.append((struct string*)&replcBuff,____BAH_COMPILER_VAR_60);
}
else {
if ((sepIndex>0)) {
sepIndex =  0;
char * ____BAH_COMPILER_VAR_61 =charToString(c);replcBuff.append((struct string*)&replcBuff,____BAH_COMPILER_VAR_61);
long int ii =  0;
while ((ii<replcBuff.length)) {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
}
};
ii =  ii + 1;
};
replcBuff.set((struct string*)&replcBuff,"");
}
else {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] =  c;
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] =  c;
}
};
}
}
if ((sepIndex==sep.length)) {
replcBuff.set((struct string*)&replcBuff,"");
struct string* elem = memoryAlloc(sizeof(struct string));
elem->content= null;
elem->set = string__set;
elem->append = string__append;
elem->prepend = string__prepend;
elem->charAt = string__charAt;
elem->compare = string__compare;
elem->str = string__str;
elem->replace = string__replace;
elem->count = string__count;
elem->hasPrefix = string__hasPrefix;
elem->hasSuffix = string__hasSuffix;
elem->trim = string__trim;
elem->trimLeft = string__trimLeft;
elem->trimRight = string__trimRight;
elem->add = string__add;
char * ____BAH_COMPILER_VAR_62 =arrToStr(tmpString);elem->set((struct string*)elem,____BAH_COMPILER_VAR_62);
long int lenRes =  len(res);

{
long nLength = lenRes;
if (res->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(res->data, (nLength+50)*sizeof(struct string));
res->data = newPtr;
}
res->data[lenRes] =  *elem;
res->length = nLength+1;
} else {
res->data[lenRes] =  *elem;
}
};
clear(tmpString);
sepIndex =  0;
}
i =  i + 1;
};
if ((replcBuff.length>0)) {
long int ii =  0;
while ((ii<replcBuff.length)) {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
}
};
ii =  ii + 1;
};
}
if ((len(tmpString)>0)) {
struct string* elem = memoryAlloc(sizeof(struct string));
elem->content= null;
elem->set = string__set;
elem->append = string__append;
elem->prepend = string__prepend;
elem->charAt = string__charAt;
elem->compare = string__compare;
elem->str = string__str;
elem->replace = string__replace;
elem->count = string__count;
elem->hasPrefix = string__hasPrefix;
elem->hasSuffix = string__hasSuffix;
elem->trim = string__trim;
elem->trimLeft = string__trimLeft;
elem->trimRight = string__trimRight;
elem->add = string__add;
char * ____BAH_COMPILER_VAR_63 =arrToStr(tmpString);elem->set((struct string*)elem,____BAH_COMPILER_VAR_63);
long int lenRes =  len(res);

{
long nLength = lenRes;
if (res->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(res->data, (nLength+50)*sizeof(struct string));
res->data = newPtr;
}
res->data[lenRes] =  *elem;
res->length = nLength+1;
} else {
res->data[lenRes] =  *elem;
}
};
}
array(struct string)* ____BAH_COMPILER_VAR_64 = res;
return ____BAH_COMPILER_VAR_64;
};
struct string joinString(__BAH_ARR_TYPE_string a,char * sep){
long int i =  0;
struct string s =  string("");
long int max =  len(a) - 1;
while ((i<len(a))) {
struct string e =  a->data[i];
if ((e.length==0)) {
i =  i + 1;
continue;
}
char * ____BAH_COMPILER_VAR_65 =e.str((struct string*)&e);struct string tmpS =  string(____BAH_COMPILER_VAR_65);
if ((i!=max)) {
tmpS.append((struct string*)&tmpS,sep);
}
char * ____BAH_COMPILER_VAR_66 =tmpS.str((struct string*)&tmpS);s.append((struct string*)&s,____BAH_COMPILER_VAR_66);
i =  i + 1;
};
struct string ____BAH_COMPILER_VAR_67 = s;
return ____BAH_COMPILER_VAR_67;
};
char * splitStringBefore(struct string s,char * sp){
struct string sep =  string(sp);
if ((sep.length>=s.length)) {
char * ____BAH_COMPILER_VAR_68 = "";
return ____BAH_COMPILER_VAR_68;
}
long int sepIndex =  0;
long int foundIndex =  0;
long int i =  0;
while ((i<s.length)) {
char c =  s.charAt((struct string*)&s,i);
char sc =  sep.charAt((struct string*)&sep,sepIndex);
if ((c==sc)) {
if ((sepIndex==0)) {
foundIndex =  i - 1;
}
sepIndex =  sepIndex + 1;
if ((sepIndex==sep.length)) {
long int max =  s.length - foundIndex - 1;
s.trimRight((struct string*)&s,max);
char * ____BAH_COMPILER_VAR_69 = s.str((struct string*)&s);
return ____BAH_COMPILER_VAR_69;
}
}
else {
foundIndex =  0;
sepIndex =  0;
}
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_70 = "";
return ____BAH_COMPILER_VAR_70;
};
struct string toLower(struct string s){
array(char)* ns = memoryAlloc(sizeof(array(char)));

ns->length = 0;
ns->elemSize = sizeof(char);
long int i =  0;
while ((i<s.length)) {
char c =  s.charAt((struct string*)&s,i);
if (isUpper(c)) {
c =  c + (char)32;
}

{
long nLength = len(ns);
if (ns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ns->data, (nLength+50)*sizeof(char));
ns->data = newPtr;
}
ns->data[len(ns)] =  c;
ns->length = nLength+1;
} else {
ns->data[len(ns)] =  c;
}
};
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_71 =arrToStr(ns);struct string ____BAH_COMPILER_VAR_72 = string(____BAH_COMPILER_VAR_71);
return ____BAH_COMPILER_VAR_72;
};
int strHasPrefix(char * s,char * need){
long int i =  0;
long int nl =  strlen(need);
long int sl =  strlen(s);
if ((sl<nl)) {
int ____BAH_COMPILER_VAR_73 = false;
return ____BAH_COMPILER_VAR_73;
}
while ((i<nl)) {
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {
int ____BAH_COMPILER_VAR_74 = false;
return ____BAH_COMPILER_VAR_74;
}
i =  i + 1;
};
int ____BAH_COMPILER_VAR_75 = true;
return ____BAH_COMPILER_VAR_75;
};
int strHasSuffix(char * s,char * need){
long int sl =  strlen(s);
long int nl =  strlen(need);
if ((nl>sl)) {
int ____BAH_COMPILER_VAR_76 = false;
return ____BAH_COMPILER_VAR_76;
}
long int i =  sl - nl;
while ((i<sl)) {
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {
int ____BAH_COMPILER_VAR_77 = false;
return ____BAH_COMPILER_VAR_77;
}
i =  i + 1;
};
int ____BAH_COMPILER_VAR_78 = true;
return ____BAH_COMPILER_VAR_78;
};
void strTrimLeft(char ** s,long int i){
long int ls =  strlen(*s);
char * ns =  memoryAlloc(ls - i + 1);
memcpy(ns,noCheck( *s + i ),ls - i);
*s =  ns;
};
void strTrimRight(char ** s,long int i){
long int ls =  strlen(*s);
char * ns =  memoryAlloc(ls - i + 1);
memcpy(ns,*s,ls - i);
*s =  ns;
};
void strTrim(char ** s){
long int l =  strlen(*s);
long int i =  0;
while ((i<l)) {
char c =  cpstringCharAt(*s,i);
if ((isSpace(c)==0)) {
break;
}
i =  i + 1;
};
*s =  noCheck( *s + i );
};
long int strCount(char * src,char * needle){
long int i =  0;
long int count =  0;
long int countIndex =  0;
long int sl =  strlen(src);
long int nl =  strlen(needle);
while ((i<sl)) {
char c =  cpstringCharAt(src,i);
char sc =  cpstringCharAt(needle,countIndex);
if ((c==sc)) {
countIndex =  countIndex + 1;
}
else {
countIndex =  0;
}
if ((countIndex==nl)) {
count =  count + 1;
countIndex =  0;
}
i =  i + 1;
};
long int ____BAH_COMPILER_VAR_79 = count;
return ____BAH_COMPILER_VAR_79;
};
char * stdinput(long int len){
char * buff =  memoryAlloc(len);
fgets(buff,len,noCheck( stdin ));
char * ____BAH_COMPILER_VAR_80 = buff;
return ____BAH_COMPILER_VAR_80;
};
void println(char * s){
write((void *)1,s,strlen(s));
write((void *)1,"\n",1);
};
struct fileStream {
FILE* handle;
long int(*isValid)(struct fileStream* this);
void(*open)(struct fileStream* this,char * path,char * mode);
void(*close)(struct fileStream* this);
long int(*getPos)(struct fileStream* this);
void(*setPos)(struct fileStream* this,long int i);
long int(*getSize)(struct fileStream* this);
void(*rewind)(struct fileStream* this);
char(*getChar)(struct fileStream* this);
void(*setChar)(struct fileStream* this,char c);
void(*createFile)(struct fileStream* this,char * path);
long int(*writeFile)(struct fileStream* this,char * content);
void(*writePtr)(struct fileStream* this,void * a,long int s);
long int(*readPtr)(struct fileStream* this,void * a,long int s);
char *(*readContent)(struct fileStream* this);
array(char)*(*readBytes)(struct fileStream* this);
void(*writeBytes)(struct fileStream* this,array(char)* d);
};
long int fileStream__isValid(struct fileStream* this){
if ((this->handle==null)) {
long int ____BAH_COMPILER_VAR_81 = 0;
return ____BAH_COMPILER_VAR_81;
}
long int ____BAH_COMPILER_VAR_82 = 1;
return ____BAH_COMPILER_VAR_82;
};
void fileStream__open(struct fileStream* this,char * path,char * mode){
this->handle =  fopen(path,mode);
};
void fileStream__close(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
return;
}
fclose(this->handle);
};
long int fileStream__getPos(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
long int ____BAH_COMPILER_VAR_84 = 0;
return ____BAH_COMPILER_VAR_84;
}
long int ____BAH_COMPILER_VAR_85 = ftell(this->handle);
return ____BAH_COMPILER_VAR_85;
};
void fileStream__setPos(struct fileStream* this,long int i){
if ((this->isValid((struct fileStream*)this)==0)) {
return;
}
fseek(this->handle,i,0);
};
long int fileStream__getSize(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
long int ____BAH_COMPILER_VAR_87 = -1;
return ____BAH_COMPILER_VAR_87;
}
long int oldPos =  this->getPos((struct fileStream*)this);
fseek(this->handle,0,2);
long int size =  ftell(this->handle);
this->setPos((struct fileStream*)this,oldPos);
long int ____BAH_COMPILER_VAR_88 = size;
return ____BAH_COMPILER_VAR_88;
};
void fileStream__rewind(struct fileStream* this){
rewind(this->handle);
};
char fileStream__getChar(struct fileStream* this){
char c =  getc(this->handle);
char ____BAH_COMPILER_VAR_89 = c;
return ____BAH_COMPILER_VAR_89;
};
void fileStream__setChar(struct fileStream* this,char c){
fputc(c,this->handle);
};
void fileStream__createFile(struct fileStream* this,char * path){
this->open((struct fileStream*)this,path,"w");
this->close((struct fileStream*)this);
};
long int fileStream__writeFile(struct fileStream* this,char * content){
if ((this->isValid((struct fileStream*)this)==0)) {
long int ____BAH_COMPILER_VAR_90 = -1;
return ____BAH_COMPILER_VAR_90;
}
fputs(content,this->handle);
long int ____BAH_COMPILER_VAR_91 = 1;
return ____BAH_COMPILER_VAR_91;
};
void fileStream__writePtr(struct fileStream* this,void * a,long int s){
fwrite(a,s,1,this->handle);
};
long int fileStream__readPtr(struct fileStream* this,void * a,long int s){
long int ____BAH_COMPILER_VAR_92 = fread(a,s,1,this->handle);
return ____BAH_COMPILER_VAR_92;
};
char * fileStream__readContent(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
char * ____BAH_COMPILER_VAR_93 = "invalid";
return ____BAH_COMPILER_VAR_93;
}
long int sz =  this->getSize((struct fileStream*)this);
char * r =  memoryAlloc(sz + 1);
long int l =  fread(r,1,sz,this->handle);
if ((sz!=l)) {
array(char)* rarr =  strAsArr(r);

{
long nLength = l;
if (rarr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(rarr->data, (nLength+50)*sizeof(char));
rarr->data = newPtr;
}
rarr->data[l] =  (char)0;
rarr->length = nLength+1;
} else {
rarr->data[l] =  (char)0;
}
};
}
char * ____BAH_COMPILER_VAR_94 = r;
return ____BAH_COMPILER_VAR_94;
};
__BAH_ARR_TYPE_char fileStream__readBytes(struct fileStream* this){
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
allocateArray(r,this->getSize((struct fileStream*)this));
this->readPtr((struct fileStream*)this,noCheck( r -> data ),len(r));
array(char)* ____BAH_COMPILER_VAR_95 = r;
return ____BAH_COMPILER_VAR_95;
};
void fileStream__writeBytes(struct fileStream* this,__BAH_ARR_TYPE_char d){
this->writePtr((struct fileStream*)this,noCheck( d -> data ),len(d));
};
struct fileMap {
long int handle;
long int size;
char *(*open)(struct fileMap* this,char * fileName);
long int(*isValid)(struct fileMap* this);
void(*close)(struct fileMap* this);
};
char * fileMap__open(struct fileMap* this,char * fileName){
this->handle =  open(fileName,noCheck( O_RDWR ),noCheck( S_IRUSR | S_IWUSR ));
struct stat sb =  {};
fstat(this->handle,&sb);
this->size =  sb.st_size;
char * file =  mmap(0,sb.st_size,noCheck( PROT_READ | PROT_WRITE ),noCheck( MAP_SHARED ),this->handle,0);
char * ____BAH_COMPILER_VAR_96 = file;
return ____BAH_COMPILER_VAR_96;
};
long int fileMap__isValid(struct fileMap* this){
if ((this->handle<0)) {
long int ____BAH_COMPILER_VAR_97 = 0;
return ____BAH_COMPILER_VAR_97;
}
long int ____BAH_COMPILER_VAR_98 = 1;
return ____BAH_COMPILER_VAR_98;
};
void fileMap__close(struct fileMap* this){
close(this->handle);
};
__BAH_ARR_TYPE_cpstring listFiles(char * dir){
array(char *)* files = memoryAlloc(sizeof(array(char *)));

files->length = 0;
files->elemSize = sizeof(char *);
DIR* d =  opendir(dir);
struct dirent* file =  readdir(d);
while ((file!=null)) {
long int lf =  len(files);
if ((strcmp(file->d_name,".")==0)) {
file =  readdir(d);
continue;
}
if ((strcmp(file->d_name,"..")==0)) {
file =  readdir(d);
continue;
}

{
long nLength = lf;
if (files->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(files->data, (nLength+50)*sizeof(char *));
files->data = newPtr;
}
files->data[lf] =  file->d_name;
files->length = nLength+1;
} else {
files->data[lf] =  file->d_name;
}
};
file =  readdir(d);
};
closedir(d);
array(char *)* ____BAH_COMPILER_VAR_99 = files;
return ____BAH_COMPILER_VAR_99;
};
long int fileExists(char * path){
long int is =  access(path,0);
if ((is==0)) {
long int ____BAH_COMPILER_VAR_100 = 1;
return ____BAH_COMPILER_VAR_100;
}
long int ____BAH_COMPILER_VAR_101 = 0;
return ____BAH_COMPILER_VAR_101;
};
int removeFile(char * name){
if ((remove(name)==0)) {
int ____BAH_COMPILER_VAR_102 = true;
return ____BAH_COMPILER_VAR_102;
}
int ____BAH_COMPILER_VAR_103 = false;
return ____BAH_COMPILER_VAR_103;
};
#define FLAG_TYPE_CPSTRING 0
#define FLAG_TYPE_INT 1
#define FLAG_TYPE_FLOAT 2
#define FLAG_TYPE_BOOL 3
struct flag {
char * name;
char * help;
char * content;
long int cont_int;
double cont_float;
long int isSet;
long int type;
};
struct flags {
array(struct flag*)* flags;
array(char *)* args;
void(*addString)(struct flags* this,char * name,char * help);
void(*addBool)(struct flags* this,char * name,char * help);
void(*addInt)(struct flags* this,char * name,char * help);
void(*addFloat)(struct flags* this,char * name,char * help);
void(*invalidate)(struct flags* this);
struct flag*(*getFlag)(struct flags* this,struct string name);
char *(*get)(struct flags* this,char * name);
long int(*getInt)(struct flags* this,char * name);
double(*getFloat)(struct flags* this,char * name);
long int(*isSet)(struct flags* this,char * name);
void(*parse)(struct flags* this,array(char *)* args);
};
void flags__addString(struct flags* this,char * name,char * help){
struct flag* f = memoryAlloc(sizeof(struct flag));
f->name= null;
f->help= null;
f->content= null;
f->name =  name;
f->help =  help;
f->type =  FLAG_TYPE_CPSTRING;
long int lf =  len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] =  f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] =  f;
}
};
};
void flags__addBool(struct flags* this,char * name,char * help){
struct flag* f = memoryAlloc(sizeof(struct flag));
f->name= null;
f->help= null;
f->content= null;
f->name =  name;
f->help =  help;
f->type =  FLAG_TYPE_BOOL;
long int lf =  len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] =  f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] =  f;
}
};
};
void flags__addInt(struct flags* this,char * name,char * help){
struct flag* f = memoryAlloc(sizeof(struct flag));
f->name= null;
f->help= null;
f->content= null;
f->name =  name;
f->help =  help;
f->type =  FLAG_TYPE_INT;
long int lf =  len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] =  f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] =  f;
}
};
};
void flags__addFloat(struct flags* this,char * name,char * help){
struct flag* f = memoryAlloc(sizeof(struct flag));
f->name= null;
f->help= null;
f->content= null;
f->name =  name;
f->help =  help;
f->type =  FLAG_TYPE_FLOAT;
long int lf =  len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] =  f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] =  f;
}
};
};
void flags__invalidate(struct flags* this){
print("Usage of ");
print(this->args->data[0]);
println(":");
long int i =  0;
while ((i<len(this->flags))) {
struct flag* flag =  this->flags->data[i];
print("    -");
print(flag->name);
if ((flag->type==FLAG_TYPE_CPSTRING)) {
println(" (string)");
}
else if ((flag->type==FLAG_TYPE_BOOL)) {
println(" (bool)");
}
else if ((flag->type==FLAG_TYPE_INT)) {
println(" (int)");
}
else if ((flag->type==FLAG_TYPE_FLOAT)) {
println(" (float)");
}
print("\t");
println(flag->help);
i =  i + 1;
};
exit(1);
};
struct flag* flags__getFlag(struct flags* this,struct string name){
long int i =  0;
while ((i<len(this->flags))) {
struct flag* flag =  this->flags->data[i];
if (name.compare((struct string*)&name,flag->name)) {
struct flag* ____BAH_COMPILER_VAR_104 = flag;
return ____BAH_COMPILER_VAR_104;
}
i =  i + 1;
};
struct flag* z = memoryAlloc(sizeof(struct flag));
z->name= null;
z->help= null;
z->content= null;
z->isSet =  0;
struct flag* ____BAH_COMPILER_VAR_105 = z;
return ____BAH_COMPILER_VAR_105;
};
char * flags__get(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_106 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_106);
char * ctn =  flag->content;
char * ____BAH_COMPILER_VAR_107 = ctn;
return ____BAH_COMPILER_VAR_107;
};
long int flags__getInt(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_108 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_108);
if ((flag->type!=FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_109 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Flag '");
long int strLen_1 = strlen(flag->name);
long int strLen_2 = strlen("' is not int.");
;                            
                        ____BAH_COMPILER_VAR_109 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_109+currStrOff, "Flag '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_109+currStrOff, flag->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_109+currStrOff, "' is not int.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * error =  ____BAH_COMPILER_VAR_109;
panic(error);
}
long int ctn =  flag->cont_int;
long int ____BAH_COMPILER_VAR_110 = ctn;
return ____BAH_COMPILER_VAR_110;
};
double flags__getFloat(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_111 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_111);
if ((flag->type!=FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_112 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Flag '");
long int strLen_1 = strlen(flag->name);
long int strLen_2 = strlen("' is not float.");
;                            
                        ____BAH_COMPILER_VAR_112 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_112+currStrOff, "Flag '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_112+currStrOff, flag->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_112+currStrOff, "' is not float.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * error =  ____BAH_COMPILER_VAR_112;
panic(error);
}
double ctn =  flag->cont_float;
double ____BAH_COMPILER_VAR_113 = ctn;
return ____BAH_COMPILER_VAR_113;
};
long int flags__isSet(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_114 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_114);
long int ctn =  flag->isSet;
long int ____BAH_COMPILER_VAR_115 = ctn;
return ____BAH_COMPILER_VAR_115;
};
void flags__parse(struct flags* this,__BAH_ARR_TYPE_cpstring args){
struct flag* currentFlag= null;
int isVal =  false;
this->args =  args;
long int i =  1;
while ((i<len(args))) {
struct string argName =  string(args->data[i]);
if ((isVal==true)) {
currentFlag->content =  argName.str((struct string*)&argName);
if ((currentFlag->type==FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_116 =argName.str((struct string*)&argName);currentFlag->cont_int =  atoi(____BAH_COMPILER_VAR_116);
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_117 =argName.str((struct string*)&argName);currentFlag->cont_float =  strtod(____BAH_COMPILER_VAR_117,0);
}
isVal =  false;
}
else {
if ((argName.charAt((struct string*)&argName,0)!=45)) {
i =  i + 1;
continue;
}
argName.trimLeft((struct string*)&argName,1);
if (argName.compare((struct string*)&argName,"help")) {
this->invalidate((struct flags*)this);
}
else if (argName.compare((struct string*)&argName,"h")) {
this->invalidate((struct flags*)this);
}
currentFlag =  this->getFlag((struct flags*)this,argName);
if ((currentFlag==null)) {
this->invalidate((struct flags*)this);
}
currentFlag->isSet =  1;
if ((currentFlag->type!=FLAG_TYPE_BOOL)) {
isVal =  true;
}
}
i =  i + 1;
};
if ((isVal==true)) {
if ((currentFlag->type!=FLAG_TYPE_BOOL)) {
this->invalidate((struct flags*)this);
}
}
};
struct command {
char * command;
int error;
long int status;
FILE* handle;
char *(*run)(struct command* this);
};
char * command__run(struct command* this){
char * cm =  this->command;
if ((this->error==false)) {
char * ____BAH_COMPILER_VAR_118 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
                        ____BAH_COMPILER_VAR_118 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_118+currStrOff, cm, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_118+currStrOff, " 2>/dev/null", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    cm =  ____BAH_COMPILER_VAR_118;
}
else {
char * ____BAH_COMPILER_VAR_119 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
                        ____BAH_COMPILER_VAR_119 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_119+currStrOff, cm, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_119+currStrOff, " 2>&1", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    cm =  ____BAH_COMPILER_VAR_119;
}
this->handle =  popen(cm,"r");
if ((this->handle==null)) {
char * ____BAH_COMPILER_VAR_120 = "";
return ____BAH_COMPILER_VAR_120;
}
char * buff =  memoryAlloc(1025);
char * res =  "";
while (((void *)fgets(buff,1024,this->handle)!=null)) {
char * ____BAH_COMPILER_VAR_121 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(res);
long int strLen_1 = strlen(buff);
;                            
                        ____BAH_COMPILER_VAR_121 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_121+currStrOff, res, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_121+currStrOff, buff, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    res =  ____BAH_COMPILER_VAR_121;
};
this->status =  pclose(this->handle);
char * ____BAH_COMPILER_VAR_122 = res;
return ____BAH_COMPILER_VAR_122;
};
struct command command(char * s){
struct command cmd =  {};
cmd.command= null;
cmd.error = true;
cmd.status = 0;
cmd.handle= null;
cmd.run = command__run;
cmd.command =  s;
struct command ____BAH_COMPILER_VAR_123 = cmd;
return ____BAH_COMPILER_VAR_123;
};
long int exec(char * s,__BAH_ARR_TYPE_cpstring args){
long int r;
array(char *)* nArgs = memoryAlloc(sizeof(array(char *)));

nArgs->length = 0;
nArgs->elemSize = sizeof(char *);

{
long nLength = 0;
if (nArgs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nArgs->data, (nLength+50)*sizeof(char *));
nArgs->data = newPtr;
}
nArgs->data[0] =  s;
nArgs->length = nLength+1;
} else {
nArgs->data[0] =  s;
}
};
long int i =  0;
while ((i<len(args))) {

{
long nLength = i + 1;
if (nArgs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nArgs->data, (nLength+50)*sizeof(char *));
nArgs->data = newPtr;
}
nArgs->data[i + 1] =  args->data[i];
nArgs->length = nLength+1;
} else {
nArgs->data[i + 1] =  args->data[i];
}
};
i =  i + 1;
};

{
long nLength = i + 2;
if (nArgs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nArgs->data, (nLength+50)*sizeof(char *));
nArgs->data = newPtr;
}
nArgs->data[i + 2] =  (char *)0;
nArgs->length = nLength+1;
} else {
nArgs->data[i + 2] =  (char *)0;
}
};
noCheck( r = execvp ( s , nArgs -> data ) );
long int ____BAH_COMPILER_VAR_124 = r;
return ____BAH_COMPILER_VAR_124;
};
#include <sqlite3.h>
#include <stddef.h>
struct reflectElement {
long int size;
char * type;
char * name;
int isArray;
struct reflectElement* arrayElem;
int isStruct;
array(struct reflectElement)* structLayout;
long int offset;
void * value;
void *(*calculateOffset)(struct reflectElement* this,void * origin);
};
void * reflectElement__calculateOffset(struct reflectElement* this,void * origin){
char * base =  origin;
void * ____BAH_COMPILER_VAR_125 = noCheck( base + this->offset );
return ____BAH_COMPILER_VAR_125;
};
typedef array(struct reflectElement)* __BAH_ARR_TYPE_reflectElement;
struct reflectElement __reflect(void * v,long int s,char * t,char * n,int isArr,struct reflectElement* ae,int isStruct,__BAH_ARR_TYPE_reflectElement sl,long int offset){
struct reflectElement re =  {};
re.type= null;
re.name= null;
re.arrayElem= null;
re.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            re.structLayout->length = 0;
            re.structLayout->elemSize = sizeof(struct reflectElement);
            re.value= null;
re.calculateOffset = reflectElement__calculateOffset;
re.size =  s;
re.type =  t;
re.name =  n;
re.isArray =  isArr;
re.arrayElem =  ae;
re.isStruct =  isStruct;
re.structLayout =  sl;
re.value =  v;
re.offset =  offset;
struct reflectElement ____BAH_COMPILER_VAR_126 = re;
return ____BAH_COMPILER_VAR_126;
};
void dbResponse_scan_inner(struct reflectElement e,char * val){
if (((void *)val==null)) {
return;
}
if ((strcmp(e.type, "int") == 0)) {
long int* ep =  e.value;
*ep =  strToInt(val);
}
else if ((strcmp(e.type, "cpstring") == 0)) {
char ** ep =  e.value;
*ep =  val;
}
else if ((strcmp(e.type, "float") == 0)) {
double* ep =  e.value;
*ep =  strToFloat(val);
}
else if ((strcmp(e.type, "bool") == 0)) {
int* ep =  e.value;
*ep =  (int)strToInt(val);
}
};
struct dbResponseRow {
array(char *)* argv;
array(char *)* cols;
void(*scan)(struct dbResponseRow* this,struct reflectElement e);
};
void dbResponseRow__scan(struct dbResponseRow* this,struct reflectElement e){
if ((e.isStruct==true)) {
long int i =  0;
while ((i<len(this->cols))) {
long int j =  0;
while ((j<len(e.structLayout))) {
struct reflectElement m =  e.structLayout->data[j];
m.value =  m.calculateOffset((struct reflectElement*)&m,e.value);
if ((strcmp(m.name, this->cols->data[i]) == 0)) {
dbResponse_scan_inner(m,this->argv->data[i]);
break;
}
j =  j + 1;
};
i =  i + 1;
};
}
else {
dbResponse_scan_inner(e,this->argv->data[0]);
}
};
struct dbResponse {
array(struct dbResponseRow*)* rows;
char * err;
void(*panic)(struct dbResponse* this);
void(*scan)(struct dbResponse* this,struct reflectElement e);
};
void dbResponse__panic(struct dbResponse* this){
if (((void *)this->err!=null)) {
panic(this->err);
}
};
void dbResponse__scan(struct dbResponse* this,struct reflectElement e){
if ((len(this->rows)==0)) {
return;
}
if ((e.isArray==true)) {
struct reflectElement* ae =  e.arrayElem;
if ((ae->isStruct==true)) {
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);
arr =  e.value;
long int i =  0;
while ((i<len(this->rows))) {
struct dbResponseRow* r =  this->rows->data[i];
ae->value =  memoryAlloc(ae->size);
r->scan((struct dbResponseRow*)r,*ae);

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(void *));
arr->data = newPtr;
}
arr->data[i] =  ae->value;
arr->length = nLength+1;
} else {
arr->data[i] =  ae->value;
}
};
i =  i + 1;
};
}
else if ((strcmp(ae->type, "int") == 0)) {
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);
arr =  e.value;
long int i =  0;
while ((i<len(this->rows))) {
struct dbResponseRow* r =  this->rows->data[i];
long int v;
r->scan((struct dbResponseRow*)r,__reflect(&v, sizeof(long int), "int", "v", 0, 0, 0, 0, 0));

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(long int));
arr->data = newPtr;
}
arr->data[i] =  v;
arr->length = nLength+1;
} else {
arr->data[i] =  v;
}
};
i =  i + 1;
};
}
else if ((strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
arr =  e.value;
long int i =  0;
while ((i<len(this->rows))) {
struct dbResponseRow* r =  this->rows->data[i];
double v;
r->scan((struct dbResponseRow*)r,__reflect(&v, sizeof(double), "float", "v", 0, 0, 0, 0, 0));

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(double));
arr->data = newPtr;
}
arr->data[i] =  v;
arr->length = nLength+1;
} else {
arr->data[i] =  v;
}
};
i =  i + 1;
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
arr =  e.value;
long int i =  0;
while ((i<len(this->rows))) {
struct dbResponseRow* r =  this->rows->data[i];
char * v =  "";
r->scan((struct dbResponseRow*)r,__reflect(v, sizeof(char *), "cpstring", "v", 0, 0, 0, 0, 0));

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(char *));
arr->data = newPtr;
}
arr->data[i] =  v;
arr->length = nLength+1;
} else {
arr->data[i] =  v;
}
};
i =  i + 1;
};
}
else if ((strcmp(ae->type, "bool") == 0)) {
array(int)* arr = memoryAlloc(sizeof(array(int)));

arr->length = 0;
arr->elemSize = sizeof(int);
arr =  e.value;
long int i =  0;
while ((i<len(this->rows))) {
struct dbResponseRow* r =  this->rows->data[i];
int v;
r->scan((struct dbResponseRow*)r,__reflect(&v, sizeof(int), "bool", "v", 0, 0, 0, 0, 0));

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(int));
arr->data = newPtr;
}
arr->data[i] =  v;
arr->length = nLength+1;
} else {
arr->data[i] =  v;
}
};
i =  i + 1;
};
}
}
else {
struct dbResponseRow* r =  this->rows->data[0];
r->scan((struct dbResponseRow*)r,e);
}
};
long int fillDBresponse(void * data,long int argc,char ** argv,char ** azColName){
struct dbResponse* dbr =  data;
struct dbResponseRow* row = memoryAlloc(sizeof(struct dbResponseRow));
row->argv = memoryAlloc(sizeof(array(char *)));
            row->argv->length = 0;
            row->argv->elemSize = sizeof(char *);
            row->cols = memoryAlloc(sizeof(array(char *)));
            row->cols->length = 0;
            row->cols->elemSize = sizeof(char *);
            row->scan = dbResponseRow__scan;
long int i =  0;
while ((i<argc)) {
char * col =  noCheck( azColName [ i ] );
char * arg =  noCheck( argv [ i ] );

{
long nLength = i;
if (row->cols->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(row->cols->data, (nLength+50)*sizeof(char *));
row->cols->data = newPtr;
}
row->cols->data[i] =  __STR(col);
row->cols->length = nLength+1;
} else {
row->cols->data[i] =  __STR(col);
}
};

{
long nLength = i;
if (row->argv->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(row->argv->data, (nLength+50)*sizeof(char *));
row->argv->data = newPtr;
}
row->argv->data[i] =  __STR(arg);
row->argv->length = nLength+1;
} else {
row->argv->data[i] =  __STR(arg);
}
};
i =  i + 1;
};

{
long nLength = len(dbr->rows);
if (dbr->rows->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(dbr->rows->data, (nLength+50)*sizeof(struct dbResponseRow*));
dbr->rows->data = newPtr;
}
dbr->rows->data[len(dbr->rows)] =  row;
dbr->rows->length = nLength+1;
} else {
dbr->rows->data[len(dbr->rows)] =  row;
}
};
long int ____BAH_COMPILER_VAR_129 = 0;
return ____BAH_COMPILER_VAR_129;
};
struct db {
sqlite3* DB;
int(*open)(struct db* this,char * fileName);
void(*close)(struct db* this);
struct dbResponse*(*exec)(struct db* this,char * sql);
};
int db__open(struct db* this,char * fileName){
int ____BAH_COMPILER_VAR_130 = (sqlite3_open(fileName,&this->DB)==0);
return ____BAH_COMPILER_VAR_130;
};
void db__close(struct db* this){
sqlite3_close(this->DB);
};
struct dbResponse* db__exec(struct db* this,char * sql){
struct dbResponse* resp = memoryAlloc(sizeof(struct dbResponse));
resp->rows = memoryAlloc(sizeof(array(struct dbResponseRow*)));
            resp->rows->length = 0;
            resp->rows->elemSize = sizeof(struct dbResponseRow*);
            resp->err = null;
resp->panic = dbResponse__panic;
resp->scan = dbResponse__scan;
sqlite3_exec(this->DB,sql,fillDBresponse,resp,&resp->err);
struct dbResponse* ____BAH_COMPILER_VAR_131 = resp;
return ____BAH_COMPILER_VAR_131;
};
#define JSON_TYPE_STRING 0
#define JSON_TYPE_INT 1
#define JSON_TYPE_FLOAT 2
#define JSON_TYPE_ARRAY 3
#define JSON_TYPE_MAP 4
char * toJson(struct reflectElement e);
struct jsonElement {
long int type;
char * key;
char * content;
array(struct jsonElement*)* children;
struct jsonElement*(*map)(struct jsonElement* this,char * key);
char *(*str)(struct jsonElement* this);
void(*scan)(struct jsonElement* this,struct reflectElement e);
};
struct jsonElement* jsonElement__map(struct jsonElement* this,char * key){
long int l =  len(this->children);
long int i =  0;
while ((i<l)) {
struct jsonElement* elem =  this->children->data[i];
char fc =  cpstringCharAt(elem->key,0);
if ((fc==(char)34)) {
array(char)* nk = memoryAlloc(sizeof(array(char)));

nk->length = 0;
nk->elemSize = sizeof(char);
long int lk =  strlen(elem->key);
long int j =  1;
while ((j<lk - 1)) {
char c =  cpstringCharAt(elem->key,j);

{
long nLength = j-1;
if (nk->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nk->data, (nLength+50)*sizeof(char));
nk->data = newPtr;
}
nk->data[j-1] =  c;
nk->length = nLength+1;
} else {
nk->data[j-1] =  c;
}
};
j =  j + 1;
};
if ((strcmp(arrAsStr(nk), key) == 0)) {
struct jsonElement* ____BAH_COMPILER_VAR_132 = elem;
return ____BAH_COMPILER_VAR_132;
}
}
else {
if ((strcmp(elem->key, key) == 0)) {
struct jsonElement* ____BAH_COMPILER_VAR_133 = elem;
return ____BAH_COMPILER_VAR_133;
}
}
i =  i + 1;
};
void * z =  (void *)0;
struct jsonElement* ____BAH_COMPILER_VAR_134 = z;
return ____BAH_COMPILER_VAR_134;
};
char * jsonElement__str(struct jsonElement* this){
char * ctn =  this->content;
char * ____BAH_COMPILER_VAR_135 = ctn;
return ____BAH_COMPILER_VAR_135;
};
void jsonElement__scan(struct jsonElement* this,struct reflectElement e){
if ((e.isStruct==true)) {
long int i =  0;
while ((i<len(e.structLayout))) {
struct reflectElement m =  e.structLayout->data[i];
struct jsonElement* ov =  this->map((struct jsonElement*)this,m.name);
if ((ov!=null)) {
ov->scan((struct jsonElement*)ov,m);
}
i =  i + 1;
};
}
else if ((strcmp(e.type, "int") == 0)) {
long int* ep =  e.value;
*ep =  strToInt(this->content);
}
else if ((strcmp(e.type, "cpstring") == 0)) {
char ** ep =  e.value;
*ep =  memoryAlloc(strlen(this->content));
strcpy(*ep,this->content);
}
else if ((strcmp(e.type, "float") == 0)) {
double* ep =  e.value;
*ep =  strToFloat(this->content);
}
else if ((strcmp(e.type, "bool") == 0)) {
int* ep =  e.value;
if (((strcmp(this->content, "1") == 0)||(strcmp(this->content, "true") == 0))) {
*ep =  true;
}
else {
*ep =  false;
}
}
else if ((e.isArray==true)) {
struct reflectElement* ae =  e.arrayElem;
if ((strcmp(ae->type, "int") == 0)) {
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(this->children))) {
struct jsonElement* c =  this->children->data[i];

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(long int));
arr->data = newPtr;
}
arr->data[i] =  strToInt(c->content);
arr->length = nLength+1;
} else {
arr->data[i] =  strToInt(c->content);
}
};
i =  i + 1;
};
}
else if ((strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(this->children))) {
struct jsonElement* c =  this->children->data[i];

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(double));
arr->data = newPtr;
}
arr->data[i] =  strToFloat(c->content);
arr->length = nLength+1;
} else {
arr->data[i] =  strToFloat(c->content);
}
};
i =  i + 1;
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(this->children))) {
struct jsonElement* c =  this->children->data[i];

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(char *));
arr->data = newPtr;
}
arr->data[i] =  memoryAlloc(strlen(c->content));
arr->length = nLength+1;
} else {
arr->data[i] =  memoryAlloc(strlen(c->content));
}
};
strcpy(arr->data[i],c->content);
i =  i + 1;
};
}
else if ((ae->isStruct==true)) {
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);
arr =  e.value;
long int i =  0;
while ((i<len(this->children))) {
struct jsonElement* c =  this->children->data[i];
void * ne =  memoryAlloc(ae->size);
long int j =  0;
while ((j<len(ae->structLayout))) {
struct reflectElement m =  ae->structLayout->data[j];
m.value =  m.calculateOffset((struct reflectElement*)&m,ne);
struct jsonElement* ov =  c->map((struct jsonElement*)c,m.name);
if ((ov!=null)) {
ov->scan((struct jsonElement*)ov,m);
}
j =  j + 1;
};

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(void *));
arr->data = newPtr;
}
arr->data[i] =  ne;
arr->length = nLength+1;
} else {
arr->data[i] =  ne;
}
};
i =  i + 1;
};
}
}
};
struct jsonElement* parseJson(char * s){
struct jsonElement* jsonElem = memoryAlloc(sizeof(struct jsonElement));
jsonElem->key= null;
jsonElem->content= null;
jsonElem->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            jsonElem->children->length = 0;
            jsonElem->children->elemSize = sizeof(struct jsonElement*);
            jsonElem->map = jsonElement__map;
jsonElem->str = jsonElement__str;
jsonElem->scan = jsonElement__scan;
long int lenS =  strlen(s);
long int i =  0;
while ((i<lenS)) {
if ((isSpace(cpstringCharAt(s,i))==0)) {
break;
}
i =  i + 1;
};
char fc =  cpstringCharAt(s,i);
if ((fc==91)) {
jsonElem->type =  JSON_TYPE_ARRAY;
}
else if ((fc==123)) {
jsonElem->type =  JSON_TYPE_MAP;
}
else if ((fc==(char)34)) {
jsonElem->type =  JSON_TYPE_STRING;
array(char)* ns = memoryAlloc(sizeof(array(char)));

ns->length = 0;
ns->elemSize = sizeof(char);
i =  i + 1;
while ((i<lenS - 1)) {

{
long nLength = len(ns);
if (ns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ns->data, (nLength+50)*sizeof(char));
ns->data = newPtr;
}
ns->data[len(ns)] =  cpstringCharAt(s,i);
ns->length = nLength+1;
} else {
ns->data[len(ns)] =  cpstringCharAt(s,i);
}
};
i =  i + 1;
};
jsonElem->content =  arrToStr(ns);
}
else if (isNumber(fc)) {
int isFloat =  false;
while ((i<lenS)) {
if ((cpstringCharAt(s,i)==46)) {
isFloat =  true;
break;
}
i =  i + 1;
};
if ((isFloat==true)) {
jsonElem->type =  JSON_TYPE_FLOAT;
}
else {
jsonElem->type =  JSON_TYPE_INT;
}
jsonElem->content =  s;
}
else {
jsonElem->type =  JSON_TYPE_STRING;
jsonElem->content =  s;
}
if ((jsonElem->type==JSON_TYPE_ARRAY)) {
i =  i + 1;
long int trim =  1;
long int j =  lenS-1;
while ((j>=0)) {
char c =  cpstringCharAt(s,j);
if (isSpace(c)) {
trim =  trim + 1;
}
else {
break;
}
j =  j - 1;
};
while ((i<lenS - 1)) {
char c =  cpstringCharAt(s,i);
if ((isSpace(c)==0)) {
break;
}
i =  i + 1;
};
array(char)* currentElem = memoryAlloc(sizeof(array(char)));

currentElem->length = 0;
currentElem->elemSize = sizeof(char);
long int currentBracks =  0;
long int currentBraces =  0;
long int currentQuotes =  0;
long int elemIndex =  0;
while ((i<lenS - trim)) {
char c =  cpstringCharAt(s,i);
if ((c==(char)34)) {
if ((currentQuotes==0)) {
currentQuotes =  1;
}
else {
currentQuotes =  0;
}
}
else if ((c==91)) {
currentBracks =  currentBracks + 1;
}
else if ((c==93)) {
currentBracks =  currentBracks - 1;
}
else if ((c==123)) {
currentBraces =  currentBraces + 1;
}
else if ((c==125)) {
currentBraces =  currentBraces - 1;
}
long int total =  currentBracks + currentBraces + currentQuotes;
if ((total>0)) {

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
}
};
i =  i + 1;
continue;
}
if ((c==44)) {
char * ____BAH_COMPILER_VAR_136 =arrToStr(currentElem);
{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  parseJson(____BAH_COMPILER_VAR_136);
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  parseJson(____BAH_COMPILER_VAR_136);
}
};
clear(currentElem);
elemIndex =  elemIndex + 1;
}
else {
if (isSpace(c)) {
i =  i + 1;
continue;
}

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
}
};
}
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_137 =arrToStr(currentElem);
{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  parseJson(____BAH_COMPILER_VAR_137);
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  parseJson(____BAH_COMPILER_VAR_137);
}
};
}
else if ((jsonElem->type==JSON_TYPE_MAP)) {
i =  i + 1;
long int trim =  1;
long int j =  lenS-1;
while ((j>=0)) {
char c =  cpstringCharAt(s,j);
if (isSpace(c)) {
trim =  trim + 1;
}
else {
break;
}
j =  j - 1;
};
while ((i<lenS - 1)) {
char c =  cpstringCharAt(s,i);
if ((isSpace(c)==0)) {
break;
}
i =  i + 1;
};
array(char)* currentElem = memoryAlloc(sizeof(array(char)));

currentElem->length = 0;
currentElem->elemSize = sizeof(char);
array(char)* currentKey = memoryAlloc(sizeof(array(char)));

currentKey->length = 0;
currentKey->elemSize = sizeof(char);
long int isVal =  0;
long int currentBracks =  0;
long int currentBraces =  0;
long int currentQuotes =  0;
long int elemIndex =  0;
while ((i<lenS - trim)) {
char c =  cpstringCharAt(s,i);
if ((c==(char)34)) {
if ((currentQuotes==0)) {
currentQuotes =  1;
}
else {
currentQuotes =  0;
}
}
else if ((c==91)) {
currentBracks =  currentBracks + 1;
}
else if ((c==93)) {
currentBracks =  currentBracks - 1;
}
else if ((c==123)) {
currentBraces =  currentBraces + 1;
}
else if ((c==125)) {
currentBraces =  currentBraces - 1;
}
long int total =  currentBracks + currentBraces + currentQuotes;
if ((total>0)) {
if ((isVal==1)) {

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
}
};
}
else {

{
long nLength = len(currentKey);
if (currentKey->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentKey->data, (nLength+50)*sizeof(char));
currentKey->data = newPtr;
}
currentKey->data[len(currentKey)] =  c;
currentKey->length = nLength+1;
} else {
currentKey->data[len(currentKey)] =  c;
}
};
}
i =  i + 1;
continue;
}
if ((c==58)) {
isVal =  1;
}
else if ((c==44)) {
char * ____BAH_COMPILER_VAR_138 =arrToStr(currentElem);struct jsonElement* elem =  parseJson(____BAH_COMPILER_VAR_138);
elem->key =  arrToStr(currentKey);
clear(currentElem);
clear(currentKey);
isVal =  0;

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  elem;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  elem;
}
};
elemIndex =  elemIndex + 1;
}
else {
if (isSpace(c)) {
i =  i + 1;
continue;
}
if ((isVal==1)) {

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
}
};
}
else {

{
long nLength = len(currentKey);
if (currentKey->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentKey->data, (nLength+50)*sizeof(char));
currentKey->data = newPtr;
}
currentKey->data[len(currentKey)] =  c;
currentKey->length = nLength+1;
} else {
currentKey->data[len(currentKey)] =  c;
}
};
}
}
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_139 =arrToStr(currentElem);struct jsonElement* elem =  parseJson(____BAH_COMPILER_VAR_139);
elem->key =  arrToStr(currentKey);

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  elem;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  elem;
}
};
}
struct jsonElement* ____BAH_COMPILER_VAR_140 = jsonElem;
return ____BAH_COMPILER_VAR_140;
};
char * toJson__inner(struct reflectElement e,int isMember,long int tabs){
void ** v =  e.value;
if ((*v==null)) {
char * ____BAH_COMPILER_VAR_141 = "null";
return ____BAH_COMPILER_VAR_141;
}
if ((e.isStruct==true)) {
tabs =  tabs + 1;
char * tabsStr =  "";
long int i =  0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_142 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
                        ____BAH_COMPILER_VAR_142 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_142+currStrOff, tabsStr, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_142+currStrOff, "\t", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tabsStr =  ____BAH_COMPILER_VAR_142;
i =  i + 1;
};
char * s =  "{\n";
i =  0;
while ((i<len(e.structLayout))) {
struct reflectElement m =  e.structLayout->data[i];
i =  i + 1;
if ((i<len(e.structLayout))) {
char * ____BAH_COMPILER_VAR_143 =toJson__inner(m,true,tabs);char * ____BAH_COMPILER_VAR_144 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("\"");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\": ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_143);
long int strLen_6 = strlen(",\n");
;                            
                        ____BAH_COMPILER_VAR_144 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_144+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_144+currStrOff, tabsStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_144+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_144+currStrOff, m.name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_144+currStrOff, "\": ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_144+currStrOff, ____BAH_COMPILER_VAR_143, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_144+currStrOff, ",\n", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_144;
}
else {
char * ____BAH_COMPILER_VAR_145 =toJson__inner(m,true,tabs);char * ____BAH_COMPILER_VAR_146 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("\"");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\": ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_145);
long int strLen_6 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_146 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_146+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_146+currStrOff, tabsStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_146+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_146+currStrOff, m.name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_146+currStrOff, "\": ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_146+currStrOff, ____BAH_COMPILER_VAR_145, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_146+currStrOff, "\n", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_146;
}
};
tabs =  tabs - 1;
tabsStr =  "";
i =  0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_147 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
                        ____BAH_COMPILER_VAR_147 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_147+currStrOff, tabsStr, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_147+currStrOff, "\t", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tabsStr =  ____BAH_COMPILER_VAR_147;
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_148 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("}");
;                            
                        ____BAH_COMPILER_VAR_148 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_148+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_148+currStrOff, tabsStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_148+currStrOff, "}", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_148;
char * ____BAH_COMPILER_VAR_149 = s;
return ____BAH_COMPILER_VAR_149;
}
else if ((strcmp(e.type, "int") == 0)) {
long int* ip =  e.value;
char * ____BAH_COMPILER_VAR_150 = intToStr(*ip);
return ____BAH_COMPILER_VAR_150;
}
else if ((strcmp(e.type, "float") == 0)) {
double* fp =  e.value;
char * ____BAH_COMPILER_VAR_151 = floatToStr(*fp);
return ____BAH_COMPILER_VAR_151;
}
else if ((strcmp(e.type, "cpstring") == 0)) {
if ((isMember==false)) {
struct string s =  string(e.value);
s.replace((struct string*)&s,"\"","\\\"");
s.replace((struct string*)&s,"\n","\\\n");
char * ____BAH_COMPILER_VAR_152 =s.str((struct string*)&s);char * ____BAH_COMPILER_VAR_153 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_152);
long int strLen_2 = strlen("\"");
;                            
                        ____BAH_COMPILER_VAR_153 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_153+currStrOff, "\"", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_153+currStrOff, ____BAH_COMPILER_VAR_152, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_153+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * ____BAH_COMPILER_VAR_154 = ____BAH_COMPILER_VAR_153;
return ____BAH_COMPILER_VAR_154;
}
else {
char ** sp =  e.value;
struct string s =  string(*sp);
s.replace((struct string*)&s,"\"","\\\"");
s.replace((struct string*)&s,"\n","\\\n");
char * ____BAH_COMPILER_VAR_155 =s.str((struct string*)&s);char * ____BAH_COMPILER_VAR_156 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_155);
long int strLen_2 = strlen("\"");
;                            
                        ____BAH_COMPILER_VAR_156 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_156+currStrOff, "\"", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_156+currStrOff, ____BAH_COMPILER_VAR_155, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_156+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * ____BAH_COMPILER_VAR_157 = ____BAH_COMPILER_VAR_156;
return ____BAH_COMPILER_VAR_157;
}
}
else if ((e.isArray==true)) {
char * s =  "[";
struct reflectElement* ae =  e.arrayElem;
if ((strcmp(ae->type, "int") == 0)) {
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_158 =intToStr(arr->data[i]);char * ____BAH_COMPILER_VAR_159 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_158);
;                            
                        ____BAH_COMPILER_VAR_159 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_159+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_159+currStrOff, ____BAH_COMPILER_VAR_158, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_159;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_160 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_160 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_160+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_160+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_160;
}
};
}
else if ((strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_161 =floatToStr(arr->data[i]);char * ____BAH_COMPILER_VAR_162 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_161);
;                            
                        ____BAH_COMPILER_VAR_162 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_162+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_162+currStrOff, ____BAH_COMPILER_VAR_161, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_162;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_163 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_163 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_163+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_163+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_163;
}
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr =  e.value;
arr =  *arrPtr;
char * ____BAH_COMPILER_VAR_164 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_164 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_164+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_164+currStrOff, "\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_164;
long int i =  0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_165 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(arr->data[i]);
;                            
                        ____BAH_COMPILER_VAR_165 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_165+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_165+currStrOff, arr->data[i], strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_165;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_166 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
                        ____BAH_COMPILER_VAR_166 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_166+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_166+currStrOff, ",\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_166;
}
else {
char * ____BAH_COMPILER_VAR_167 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_167 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_167+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_167+currStrOff, "\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_167;
}
};
}
else if ((ae->isStruct==true)) {
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);
arr =  e.value;
long int i =  0;
while ((i<len(arr))) {
void * arrElem =  arr->data[i];
ae->value =  arrElem;
long int j =  0;
while ((j<len(ae->structLayout))) {
struct reflectElement m =  ae->structLayout->data[j];
m.value =  m.calculateOffset((struct reflectElement*)&m,ae->value);

{
long nLength = j;
if (ae->structLayout->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ae->structLayout->data, (nLength+50)*sizeof(struct reflectElement));
ae->structLayout->data = newPtr;
}
ae->structLayout->data[j] =  m;
ae->structLayout->length = nLength+1;
} else {
ae->structLayout->data[j] =  m;
}
};
j =  j + 1;
};
char * ____BAH_COMPILER_VAR_168 =toJson__inner(*ae,false,tabs);char * ____BAH_COMPILER_VAR_169 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_168);
;                            
                        ____BAH_COMPILER_VAR_169 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_169+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_169+currStrOff, ____BAH_COMPILER_VAR_168, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_169;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_170 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
                        ____BAH_COMPILER_VAR_170 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_170+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_170+currStrOff, ",\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_170;
}
else {
char * ____BAH_COMPILER_VAR_171 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_171 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_171+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_171+currStrOff, "\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_171;
}
};
}
char * ____BAH_COMPILER_VAR_172 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("]");
;                            
                        ____BAH_COMPILER_VAR_172 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_172+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_172+currStrOff, "]", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_172;
char * ____BAH_COMPILER_VAR_173 = s;
return ____BAH_COMPILER_VAR_173;
}
char * ____BAH_COMPILER_VAR_174 = "";
return ____BAH_COMPILER_VAR_174;
};
char * toJson(struct reflectElement e){
char * ____BAH_COMPILER_VAR_175 = toJson__inner(e,false,0);
return ____BAH_COMPILER_VAR_175;
};
char * BPM_DIR= null;
struct db DB;
void genBPMdir(){
char * ____BAH_COMPILER_VAR_176 =getenv("HOME");char * ____BAH_COMPILER_VAR_177 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_176);
long int strLen_1 = strlen("/.bpm");
;                            
                        ____BAH_COMPILER_VAR_177 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_177+currStrOff, ____BAH_COMPILER_VAR_176, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_177+currStrOff, "/.bpm", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    BPM_DIR =  ____BAH_COMPILER_VAR_177;
mkdir(BPM_DIR,0700);
};
void dbGuard(){
genBPMdir();
char * ____BAH_COMPILER_VAR_178 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BPM_DIR);
long int strLen_1 = strlen("/db.db");
;                            
                        ____BAH_COMPILER_VAR_178 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_178+currStrOff, BPM_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_178+currStrOff, "/db.db", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    if ((fileExists(____BAH_COMPILER_VAR_178)==0)) {
{};
DB.DB= null;
DB.open = db__open;
DB.close = db__close;
DB.exec = db__exec;
char * ____BAH_COMPILER_VAR_179 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BPM_DIR);
long int strLen_1 = strlen("/db.db");
;                            
                        ____BAH_COMPILER_VAR_179 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_179+currStrOff, BPM_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_179+currStrOff, "/db.db", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    if ((DB.open((struct db*)&DB,____BAH_COMPILER_VAR_179)==false)) {
panic("Errror creating BPM database.");
}
DB.exec((struct db*)&DB,"CREATE TABLE packages(\n            name TEXT PRIMARY KEY NOT NULL,\n            url TEXT NOT NULL,\n            ver FLOAT NOT NULL\n        )");
DB.exec((struct db*)&DB,"CREATE TABLE deps(\n            pkg TEXT PRIMARY KEY NOT NULL,\n            parent TEXT NOT NULL\n        )");
DB.close((struct db*)&DB);
struct fileStream fs =  {};
fs.handle= null;
fs.isValid = fileStream__isValid;
fs.open = fileStream__open;
fs.close = fileStream__close;
fs.getPos = fileStream__getPos;
fs.setPos = fileStream__setPos;
fs.getSize = fileStream__getSize;
fs.rewind = fileStream__rewind;
fs.getChar = fileStream__getChar;
fs.setChar = fileStream__setChar;
fs.createFile = fileStream__createFile;
fs.writeFile = fileStream__writeFile;
fs.writePtr = fileStream__writePtr;
fs.readPtr = fileStream__readPtr;
fs.readContent = fileStream__readContent;
fs.readBytes = fileStream__readBytes;
fs.writeBytes = fileStream__writeBytes;
char * ____BAH_COMPILER_VAR_180 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BPM_DIR);
long int strLen_1 = strlen("/sources.json");
;                            
                        ____BAH_COMPILER_VAR_180 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_180+currStrOff, BPM_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_180+currStrOff, "/sources.json", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    fs.open((struct fileStream*)&fs,____BAH_COMPILER_VAR_180,"w");
fs.writeFile((struct fileStream*)&fs,"\n        [\n            \"https://github.com\"\n        ]");
fs.close((struct fileStream*)&fs);
}
};
__BAH_ARR_TYPE_cpstring readSources(){
struct fileStream fs =  {};
fs.handle= null;
fs.isValid = fileStream__isValid;
fs.open = fileStream__open;
fs.close = fileStream__close;
fs.getPos = fileStream__getPos;
fs.setPos = fileStream__setPos;
fs.getSize = fileStream__getSize;
fs.rewind = fileStream__rewind;
fs.getChar = fileStream__getChar;
fs.setChar = fileStream__setChar;
fs.createFile = fileStream__createFile;
fs.writeFile = fileStream__writeFile;
fs.writePtr = fileStream__writePtr;
fs.readPtr = fileStream__readPtr;
fs.readContent = fileStream__readContent;
fs.readBytes = fileStream__readBytes;
fs.writeBytes = fileStream__writeBytes;
char * ____BAH_COMPILER_VAR_181 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BPM_DIR);
long int strLen_1 = strlen("/sources.json");
;                            
                        ____BAH_COMPILER_VAR_181 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_181+currStrOff, BPM_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_181+currStrOff, "/sources.json", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    fs.open((struct fileStream*)&fs,____BAH_COMPILER_VAR_181,"r");
print("Reading sources... ");
array(char *)* sources = memoryAlloc(sizeof(array(char *)));

sources->length = 0;
sources->elemSize = sizeof(char *);
char * ____BAH_COMPILER_VAR_182 =fs.readContent((struct fileStream*)&fs);struct jsonElement* root =  parseJson(____BAH_COMPILER_VAR_182);

        struct reflectElement ____BAH_COMPILER_VAR_183 = __reflect(0, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);
        root->scan((struct jsonElement*)root,__reflect(&sources, sizeof(array(char *)*), "[]cpstring", "sources", 1, &____BAH_COMPILER_VAR_183, 0, 0, 0));
if ((len(sources)==0)) {
char * ____BAH_COMPILER_VAR_184 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("no sources found!\nAdd a source in '");
long int strLen_1 = strlen(BPM_DIR);
long int strLen_2 = strlen("/sources.json'");
;                            
                        ____BAH_COMPILER_VAR_184 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_184+currStrOff, "no sources found!\nAdd a source in '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_184+currStrOff, BPM_DIR, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_184+currStrOff, "/sources.json'", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    panic(____BAH_COMPILER_VAR_184);
}
println("ok");
fs.close((struct fileStream*)&fs);
array(char *)* ____BAH_COMPILER_VAR_185 = sources;
return ____BAH_COMPILER_VAR_185;
};
struct package {
char * name;
char * url;
double ver;
array(char *)* deps;
};
struct dep {
char * pkg;
char * parent;
};
#include <stdlib.h>
char * absPath(char * path){
char * z =  (char *)0;
char * p =  realpath(path,z);
char * ____BAH_COMPILER_VAR_186 = p;
return ____BAH_COMPILER_VAR_186;
};
char * getCurrentPath(){
char * cwd =  memoryAlloc(4096);
getcwd(cwd,4096);
char * ____BAH_COMPILER_VAR_187 = cwd;
return ____BAH_COMPILER_VAR_187;
};
int isInside(char * basePath,char * subPath){
char * abs1 =  absPath(basePath);
char * abs2 =  absPath(subPath);
int ____BAH_COMPILER_VAR_188 = (strHasPrefix(subPath,basePath)==true);
return ____BAH_COMPILER_VAR_188;
};
void setCurrentPath(char * s){
chdir(s);
};
#define BAH_DIR "/opt/bah"
char * getNameFromURL(char * u){
array(char)* p =  strAsArr(u);
long int nbSlash =  0;
long int i =  len(p)-1;
while ((i>=0)) {
if ((p->data[i]==47)) {
nbSlash =  nbSlash + 1;
}
if ((nbSlash==2)) {
break;
}
i =  i - 1;
};
struct string np =  string(u);
np.trimLeft((struct string*)&np,i + 1);
char * ____BAH_COMPILER_VAR_189 = np.str((struct string*)&np);
return ____BAH_COMPILER_VAR_189;
};
char * getAuthorFromName(char * n){
array(char)* p =  strAsArr(n);
long int i =  len(p)-1;
while ((i>=0)) {
if ((p->data[i]==47)) {
break;
}
i =  i - 1;
};
struct string np =  string(n);
np.trimRight((struct string*)&np,len(p) - i);
char * ____BAH_COMPILER_VAR_190 = np.str((struct string*)&np);
return ____BAH_COMPILER_VAR_190;
};
double getVer(){
struct command cmd =  command("bah -v");
char * ____BAH_COMPILER_VAR_191 =cmd.run((struct command*)&cmd);struct string ver =  string(____BAH_COMPILER_VAR_191);
ver.trimLeft((struct string*)&ver,23);
ver.trimRight((struct string*)&ver,24);
array(struct string)* parts =  splitString(ver," (build ");
ver =  parts->data[0];
struct string build =  parts->data[1];
char * ____BAH_COMPILER_VAR_192 =ver.str((struct string*)&ver);char * ____BAH_COMPILER_VAR_193 =build.str((struct string*)&build);char * ____BAH_COMPILER_VAR_194 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_192);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_193);
;                            
                        ____BAH_COMPILER_VAR_194 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_194+currStrOff, ____BAH_COMPILER_VAR_192, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_194+currStrOff, ____BAH_COMPILER_VAR_193, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    double ____BAH_COMPILER_VAR_195 = strToFloat(____BAH_COMPILER_VAR_194);
return ____BAH_COMPILER_VAR_195;
};
char * getGitURL(){
struct command cmd =  command("git config --get remote.origin.url");
char * r =  null;
r =  cmd.run((struct command*)&cmd);
if (((cmd.status!=0)||((void *)r==null))) {
panic("Cannot wrap package that is not in a git repository.\nMake sure that you add the remote origin before wrapping the package.");
}
strTrimRight(&r,1);
char * ____BAH_COMPILER_VAR_196 = r;
return ____BAH_COMPILER_VAR_196;
};
void wrapPackage(){
struct package* p = memoryAlloc(sizeof(struct package));
p->name= null;
p->url= null;
p->deps = memoryAlloc(sizeof(array(char *)));
            p->deps->length = 0;
            p->deps->elemSize = sizeof(char *);
            p->url =  getGitURL();
p->name =  getNameFromURL(p->url);
p->ver =  getVer();
struct fileStream fs =  {};
fs.handle= null;
fs.isValid = fileStream__isValid;
fs.open = fileStream__open;
fs.close = fileStream__close;
fs.getPos = fileStream__getPos;
fs.setPos = fileStream__setPos;
fs.getSize = fileStream__getSize;
fs.rewind = fileStream__rewind;
fs.getChar = fileStream__getChar;
fs.setChar = fileStream__setChar;
fs.createFile = fileStream__createFile;
fs.writeFile = fileStream__writeFile;
fs.writePtr = fileStream__writePtr;
fs.readPtr = fileStream__readPtr;
fs.readContent = fileStream__readContent;
fs.readBytes = fileStream__readBytes;
fs.writeBytes = fileStream__writeBytes;
fs.open((struct fileStream*)&fs,"./bpm.mod","w");

        struct reflectElement ____BAH_COMPILER_VAR_198 = __reflect(0, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);
        
        array(struct reflectElement) * ____BAH_COMPILER_VAR_197 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_197->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_197->length = 4;
        ____BAH_COMPILER_VAR_197->data = memoryAlloc(____BAH_COMPILER_VAR_197->length * ____BAH_COMPILER_VAR_197->elemSize);
        ____BAH_COMPILER_VAR_197->data[0] = __reflect((char **)((char*)(p) + offsetof(struct package, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct package, name));
____BAH_COMPILER_VAR_197->data[1] = __reflect((char **)((char*)(p) + offsetof(struct package, url)), sizeof(char *), "cpstring", "url", 0, 0, 0, 0, offsetof(struct package, url));
____BAH_COMPILER_VAR_197->data[2] = __reflect((double*)((char*)(p) + offsetof(struct package, ver)), sizeof(double), "float", "ver", 0, 0, 0, 0, offsetof(struct package, ver));
____BAH_COMPILER_VAR_197->data[3] = __reflect((array(char *)**)((char*)(p) + offsetof(struct package, deps)), sizeof(array(char *)*), "[]cpstring", "deps", 1, &____BAH_COMPILER_VAR_198, 0, 0, offsetof(struct package, deps));
char * ____BAH_COMPILER_VAR_199 =toJson(__reflect(p, sizeof(struct package*), "package*", "p", 0, 0, 1, ____BAH_COMPILER_VAR_197, 0));fs.writeFile((struct fileStream*)&fs,____BAH_COMPILER_VAR_199);
fs.close((struct fileStream*)&fs);
};
char * findUrl(__BAH_ARR_TYPE_cpstring sources,char * name){
long int i =  0;
while ((i<len(sources))) {
char * ____BAH_COMPILER_VAR_200 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(sources->data[i]);
long int strLen_1 = strlen("/");
long int strLen_2 = strlen(name);
;                            
                        ____BAH_COMPILER_VAR_200 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_200+currStrOff, sources->data[i], strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_200+currStrOff, "/", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_200+currStrOff, name, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * url =  ____BAH_COMPILER_VAR_200;
char * ____BAH_COMPILER_VAR_201 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("git ls-remote ");
long int strLen_1 = strlen(url);
;                            
                        ____BAH_COMPILER_VAR_201 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_201+currStrOff, "git ls-remote ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_201+currStrOff, url, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    struct command cmd =  command(____BAH_COMPILER_VAR_201);
cmd.run((struct command*)&cmd);
if ((cmd.status==0)) {
char * ____BAH_COMPILER_VAR_202 = url;
return ____BAH_COMPILER_VAR_202;
}
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_203 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot find package '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("'.\nPlease check '");
long int strLen_3 = strlen(BPM_DIR);
long int strLen_4 = strlen("/sources.json'.");
;                            
                        ____BAH_COMPILER_VAR_203 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_203+currStrOff, "Cannot find package '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_203+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_203+currStrOff, "'.\nPlease check '", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_203+currStrOff, BPM_DIR, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_203+currStrOff, "/sources.json'.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    panic(____BAH_COMPILER_VAR_203);
char * ____BAH_COMPILER_VAR_204 = "";
return ____BAH_COMPILER_VAR_204;
};
int isInstalled(char * name){
int installed =  false;
{};
DB.DB= null;
DB.open = db__open;
DB.close = db__close;
DB.exec = db__exec;
char * ____BAH_COMPILER_VAR_205 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BPM_DIR);
long int strLen_1 = strlen("/db.db");
;                            
                        ____BAH_COMPILER_VAR_205 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_205+currStrOff, BPM_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_205+currStrOff, "/db.db", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    DB.open((struct db*)&DB,____BAH_COMPILER_VAR_205);
char * ____BAH_COMPILER_VAR_206 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("SELECT * FROM packages WHERE name = '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("'");
;                            
                        ____BAH_COMPILER_VAR_206 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_206+currStrOff, "SELECT * FROM packages WHERE name = '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_206+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_206+currStrOff, "'", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct dbResponse* resp =  DB.exec((struct db*)&DB,____BAH_COMPILER_VAR_206);
struct package* p = memoryAlloc(sizeof(struct package));
p->name= null;
p->url= null;
p->deps = memoryAlloc(sizeof(array(char *)));
            p->deps->length = 0;
            p->deps->elemSize = sizeof(char *);
            
        struct reflectElement ____BAH_COMPILER_VAR_208 = __reflect(0, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);
        
        array(struct reflectElement) * ____BAH_COMPILER_VAR_207 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_207->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_207->length = 4;
        ____BAH_COMPILER_VAR_207->data = memoryAlloc(____BAH_COMPILER_VAR_207->length * ____BAH_COMPILER_VAR_207->elemSize);
        ____BAH_COMPILER_VAR_207->data[0] = __reflect((char **)((char*)(p) + offsetof(struct package, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct package, name));
____BAH_COMPILER_VAR_207->data[1] = __reflect((char **)((char*)(p) + offsetof(struct package, url)), sizeof(char *), "cpstring", "url", 0, 0, 0, 0, offsetof(struct package, url));
____BAH_COMPILER_VAR_207->data[2] = __reflect((double*)((char*)(p) + offsetof(struct package, ver)), sizeof(double), "float", "ver", 0, 0, 0, 0, offsetof(struct package, ver));
____BAH_COMPILER_VAR_207->data[3] = __reflect((array(char *)**)((char*)(p) + offsetof(struct package, deps)), sizeof(array(char *)*), "[]cpstring", "deps", 1, &____BAH_COMPILER_VAR_208, 0, 0, offsetof(struct package, deps));
resp->scan((struct dbResponse*)resp,__reflect(p, sizeof(struct package*), "package*", "p", 0, 0, 1, ____BAH_COMPILER_VAR_207, 0));
if (((p!=null)&&((void *)p->name!=null))) {
installed =  true;
}
DB.close((struct db*)&DB);
int ____BAH_COMPILER_VAR_209 = installed;
return ____BAH_COMPILER_VAR_209;
};
void installPackage(char * name);
void installPackageFromURL(char * url){
array(char *)* sources =  readSources();
char * name =  getNameFromURL(url);
struct string src =  string(url);
src.trimRight((struct string*)&src,strlen(name) + 1);
int found =  false;
long int i =  0;
while ((i<len(sources))) {
if ((strcmp(sources->data[i], src.str((struct string*)&src)) == 0)) {
found =  false;
break;
}
i =  i + 1;
};
if ((found==false)) {
char * ____BAH_COMPILER_VAR_210 =src.str((struct string*)&src);char * ____BAH_COMPILER_VAR_211 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Package '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("' comes from the source '");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_210);
long int strLen_4 = strlen("'. Should you add it? [Y/n] ");
;                            
                        ____BAH_COMPILER_VAR_211 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_211+currStrOff, "Package '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_211+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_211+currStrOff, "' comes from the source '", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_211+currStrOff, ____BAH_COMPILER_VAR_210, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_211+currStrOff, "'. Should you add it? [Y/n] ", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    println(____BAH_COMPILER_VAR_211);
char * resp =  stdinput(1);
if ((strcmp(resp, "Y") == 0)) {
char * ____BAH_COMPILER_VAR_212 =src.str((struct string*)&src);char * ____BAH_COMPILER_VAR_213 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Adding '");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_212);
long int strLen_2 = strlen("'...");
;                            
                        ____BAH_COMPILER_VAR_213 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_213+currStrOff, "Adding '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_213+currStrOff, ____BAH_COMPILER_VAR_212, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_213+currStrOff, "'...", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    print(____BAH_COMPILER_VAR_213);

{
long nLength = len(sources);
if (sources->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(sources->data, (nLength+50)*sizeof(char *));
sources->data = newPtr;
}
sources->data[len(sources)] =  src.str((struct string*)&src);
sources->length = nLength+1;
} else {
sources->data[len(sources)] =  src.str((struct string*)&src);
}
};
struct fileStream fs =  {};
fs.handle= null;
fs.isValid = fileStream__isValid;
fs.open = fileStream__open;
fs.close = fileStream__close;
fs.getPos = fileStream__getPos;
fs.setPos = fileStream__setPos;
fs.getSize = fileStream__getSize;
fs.rewind = fileStream__rewind;
fs.getChar = fileStream__getChar;
fs.setChar = fileStream__setChar;
fs.createFile = fileStream__createFile;
fs.writeFile = fileStream__writeFile;
fs.writePtr = fileStream__writePtr;
fs.readPtr = fileStream__readPtr;
fs.readContent = fileStream__readContent;
fs.readBytes = fileStream__readBytes;
fs.writeBytes = fileStream__writeBytes;
char * ____BAH_COMPILER_VAR_214 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BPM_DIR);
long int strLen_1 = strlen("/sources.json");
;                            
                        ____BAH_COMPILER_VAR_214 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_214+currStrOff, BPM_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_214+currStrOff, "/sources.json", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    fs.open((struct fileStream*)&fs,____BAH_COMPILER_VAR_214,"w");

        struct reflectElement ____BAH_COMPILER_VAR_215 = __reflect(0, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);
        char * ____BAH_COMPILER_VAR_216 =toJson(__reflect(&sources, sizeof(array(char *)*), "[]cpstring", "sources", 1, &____BAH_COMPILER_VAR_215, 0, 0, 0));fs.writeFile((struct fileStream*)&fs,____BAH_COMPILER_VAR_216);
fs.close((struct fileStream*)&fs);
println("ok");
}
else {
return;
}
}
installPackage(name);
};
void registerPackage(struct package* p){
print("Updating database... ");
{};
DB.DB= null;
DB.open = db__open;
DB.close = db__close;
DB.exec = db__exec;
char * ____BAH_COMPILER_VAR_218 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BPM_DIR);
long int strLen_1 = strlen("/db.db");
;                            
                        ____BAH_COMPILER_VAR_218 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_218+currStrOff, BPM_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_218+currStrOff, "/db.db", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    DB.open((struct db*)&DB,____BAH_COMPILER_VAR_218);
char * ____BAH_COMPILER_VAR_219 =floatToStr(p->ver);char * ____BAH_COMPILER_VAR_220 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("INSERT INTO packages VALUES('");
long int strLen_1 = strlen(p->name);
long int strLen_2 = strlen("', '");
long int strLen_3 = strlen(p->url);
long int strLen_4 = strlen("', ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_219);
long int strLen_6 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_220 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_220+currStrOff, "INSERT INTO packages VALUES('", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_220+currStrOff, p->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_220+currStrOff, "', '", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_220+currStrOff, p->url, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_220+currStrOff, "', ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_220+currStrOff, ____BAH_COMPILER_VAR_219, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_220+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    struct dbResponse* resp =  DB.exec((struct db*)&DB,____BAH_COMPILER_VAR_220);
resp->panic((struct dbResponse*)resp);
println("ok");
println("Checking dependecies...");
long int i =  0;
while ((i<len(p->deps))) {
if ((strcmp(p->deps->data[i], "") == 0)) {
i =  i + 1;
continue;
}
installPackageFromURL(p->deps->data[i]);
char * ____BAH_COMPILER_VAR_221 =getNameFromURL(p->deps->data[i]);char * ____BAH_COMPILER_VAR_222 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("INSERT INTO deps VALUES('");
long int strLen_1 = strlen(p->name);
long int strLen_2 = strlen("', '");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_221);
long int strLen_4 = strlen("')");
;                            
                        ____BAH_COMPILER_VAR_222 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_222+currStrOff, "INSERT INTO deps VALUES('", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_222+currStrOff, p->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_222+currStrOff, "', '", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_222+currStrOff, ____BAH_COMPILER_VAR_221, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_222+currStrOff, "')", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    resp =  DB.exec((struct db*)&DB,____BAH_COMPILER_VAR_222);
resp->panic((struct dbResponse*)resp);
i =  i + 1;
};
DB.close((struct db*)&DB);
};
void removePackageFiles(char * name){
setCurrentPath(BAH_DIR);
char * ____BAH_COMPILER_VAR_223 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("yes | rm -r ");
long int strLen_1 = strlen(name);
;                            
                        ____BAH_COMPILER_VAR_223 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_223+currStrOff, "yes | rm -r ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_223+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    struct command cmd =  command(____BAH_COMPILER_VAR_223);
cmd.run((struct command*)&cmd);
};
void installPackage(char * name){
array(char *)* sources =  readSources();
char * url =  findUrl(sources,name);
char * dir =  getAuthorFromName(name);
setCurrentPath(BAH_DIR);
int installed =  isInstalled(name);
if ((installed==false)) {
char * ____BAH_COMPILER_VAR_224 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Installing '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("'.");
;                            
                        ____BAH_COMPILER_VAR_224 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_224+currStrOff, "Installing '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_224+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_224+currStrOff, "'.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    println(____BAH_COMPILER_VAR_224);
mkdir(dir,0700);
setCurrentPath(dir);
print("Clonning repository... ");
char * ____BAH_COMPILER_VAR_225 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("git clone ");
long int strLen_1 = strlen(url);
long int strLen_2 = strlen("");
;                            
                        ____BAH_COMPILER_VAR_225 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_225+currStrOff, "git clone ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_225+currStrOff, url, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_225+currStrOff, "", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct command cmd =  command(____BAH_COMPILER_VAR_225);
cmd.run((struct command*)&cmd);
char * ____BAH_COMPILER_VAR_226 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("../");
long int strLen_1 = strlen(name);
;                            
                        ____BAH_COMPILER_VAR_226 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_226+currStrOff, "../", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_226+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    setCurrentPath(____BAH_COMPILER_VAR_226);
array(char *)* files =  listFiles(".");
println("ok");
int found =  false;
long int i =  0;
while ((i<len(files))) {
char * f =  files->data[i];
if ((strcmp(f, "bpm.mod") == 0)) {
found =  true;
break;
}
i =  i + 1;
};
if ((found==false)) {
removePackageFiles(name);
panic("No BPM package found. Aborting.");
}
struct package* p = memoryAlloc(sizeof(struct package));
p->name= null;
p->url= null;
p->deps = memoryAlloc(sizeof(array(char *)));
            p->deps->length = 0;
            p->deps->elemSize = sizeof(char *);
            struct fileStream fs =  {};
fs.handle= null;
fs.isValid = fileStream__isValid;
fs.open = fileStream__open;
fs.close = fileStream__close;
fs.getPos = fileStream__getPos;
fs.setPos = fileStream__setPos;
fs.getSize = fileStream__getSize;
fs.rewind = fileStream__rewind;
fs.getChar = fileStream__getChar;
fs.setChar = fileStream__setChar;
fs.createFile = fileStream__createFile;
fs.writeFile = fileStream__writeFile;
fs.writePtr = fileStream__writePtr;
fs.readPtr = fileStream__readPtr;
fs.readContent = fileStream__readContent;
fs.readBytes = fileStream__readBytes;
fs.writeBytes = fileStream__writeBytes;
fs.open((struct fileStream*)&fs,"./bpm.mod","r");
char * ____BAH_COMPILER_VAR_227 =fs.readContent((struct fileStream*)&fs);struct jsonElement* root =  parseJson(____BAH_COMPILER_VAR_227);
fs.close((struct fileStream*)&fs);

        struct reflectElement ____BAH_COMPILER_VAR_229 = __reflect(0, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);
        
        array(struct reflectElement) * ____BAH_COMPILER_VAR_228 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_228->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_228->length = 4;
        ____BAH_COMPILER_VAR_228->data = memoryAlloc(____BAH_COMPILER_VAR_228->length * ____BAH_COMPILER_VAR_228->elemSize);
        ____BAH_COMPILER_VAR_228->data[0] = __reflect((char **)((char*)(p) + offsetof(struct package, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct package, name));
____BAH_COMPILER_VAR_228->data[1] = __reflect((char **)((char*)(p) + offsetof(struct package, url)), sizeof(char *), "cpstring", "url", 0, 0, 0, 0, offsetof(struct package, url));
____BAH_COMPILER_VAR_228->data[2] = __reflect((double*)((char*)(p) + offsetof(struct package, ver)), sizeof(double), "float", "ver", 0, 0, 0, 0, offsetof(struct package, ver));
____BAH_COMPILER_VAR_228->data[3] = __reflect((array(char *)**)((char*)(p) + offsetof(struct package, deps)), sizeof(array(char *)*), "[]cpstring", "deps", 1, &____BAH_COMPILER_VAR_229, 0, 0, offsetof(struct package, deps));
root->scan((struct jsonElement*)root,__reflect(p, sizeof(struct package*), "package*", "p", 0, 0, 1, ____BAH_COMPILER_VAR_228, 0));
if ((strcmp(p->url, url) != 0)) {
println("WARNING: URL missmatch, this package could be stolen or compromised.");
}
registerPackage(p);
}
else {
char * ____BAH_COMPILER_VAR_230 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Updating '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("'.");
;                            
                        ____BAH_COMPILER_VAR_230 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_230+currStrOff, "Updating '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_230+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_230+currStrOff, "'.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    println(____BAH_COMPILER_VAR_230);
setCurrentPath(name);
struct command cmd =  command("git pull origin main");
cmd.run((struct command*)&cmd);
}
};
void removePackage(char * name);
void removeDpendency(char * name){
{};
DB.DB= null;
DB.open = db__open;
DB.close = db__close;
DB.exec = db__exec;
char * ____BAH_COMPILER_VAR_231 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BPM_DIR);
long int strLen_1 = strlen("/db.db");
;                            
                        ____BAH_COMPILER_VAR_231 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_231+currStrOff, BPM_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_231+currStrOff, "/db.db", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    DB.open((struct db*)&DB,____BAH_COMPILER_VAR_231);
char * ____BAH_COMPILER_VAR_232 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("SELECT COUNT(*) FROM deps WHERE pkg = '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("'");
;                            
                        ____BAH_COMPILER_VAR_232 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_232+currStrOff, "SELECT COUNT(*) FROM deps WHERE pkg = '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_232+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_232+currStrOff, "'", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct dbResponse* resp =  DB.exec((struct db*)&DB,____BAH_COMPILER_VAR_232);
long int nb =  0;
resp->scan((struct dbResponse*)resp,__reflect(&nb, sizeof(long int), "int", "nb", 0, 0, 0, 0, 0));
if ((nb==0)) {
removePackage(name);
}
DB.close((struct db*)&DB);
};
void removePackage(char * name){
if ((isInstalled(name)==false)) {
char * ____BAH_COMPILER_VAR_233 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("No package called '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("' is installed.");
;                            
                        ____BAH_COMPILER_VAR_233 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_233+currStrOff, "No package called '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_233+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_233+currStrOff, "' is installed.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    panic(____BAH_COMPILER_VAR_233);
}
{};
DB.DB= null;
DB.open = db__open;
DB.close = db__close;
DB.exec = db__exec;
char * ____BAH_COMPILER_VAR_234 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BPM_DIR);
long int strLen_1 = strlen("/db.db");
;                            
                        ____BAH_COMPILER_VAR_234 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_234+currStrOff, BPM_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_234+currStrOff, "/db.db", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    DB.open((struct db*)&DB,____BAH_COMPILER_VAR_234);
char * ____BAH_COMPILER_VAR_235 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Removing package '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("'... ");
;                            
                        ____BAH_COMPILER_VAR_235 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_235+currStrOff, "Removing package '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_235+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_235+currStrOff, "'... ", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    print(____BAH_COMPILER_VAR_235);
char * ____BAH_COMPILER_VAR_236 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("DELETE FROM packages WHERE name = '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("'");
;                            
                        ____BAH_COMPILER_VAR_236 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_236+currStrOff, "DELETE FROM packages WHERE name = '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_236+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_236+currStrOff, "'", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    DB.exec((struct db*)&DB,____BAH_COMPILER_VAR_236);
removePackageFiles(name);
println("ok");
println("Removing dependencies.");
char * ____BAH_COMPILER_VAR_237 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("SELECT parent FROM deps WHERE pkg = '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("'");
;                            
                        ____BAH_COMPILER_VAR_237 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_237+currStrOff, "SELECT parent FROM deps WHERE pkg = '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_237+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_237+currStrOff, "'", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct dbResponse* resp =  DB.exec((struct db*)&DB,____BAH_COMPILER_VAR_237);
array(char *)* deps = memoryAlloc(sizeof(array(char *)));

deps->length = 0;
deps->elemSize = sizeof(char *);

        struct reflectElement ____BAH_COMPILER_VAR_238 = __reflect(0, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);
        resp->scan((struct dbResponse*)resp,__reflect(&deps, sizeof(array(char *)*), "[]cpstring", "deps", 1, &____BAH_COMPILER_VAR_238, 0, 0, 0));
long int i =  0;
while ((i<len(deps))) {
removeDpendency(deps->data[i]);
i =  i + 1;
};
DB.close((struct db*)&DB);
};
struct flags flags;
long int main(__BAH_ARR_TYPE_cpstring args){
{};
flags.flags = memoryAlloc(sizeof(array(struct flag*)));
            flags.flags->length = 0;
            flags.flags->elemSize = sizeof(struct flag*);
            flags.args = memoryAlloc(sizeof(array(char *)));
            flags.args->length = 0;
            flags.args->elemSize = sizeof(char *);
            flags.addString = flags__addString;
flags.addBool = flags__addBool;
flags.addInt = flags__addInt;
flags.addFloat = flags__addFloat;
flags.invalidate = flags__invalidate;
flags.getFlag = flags__getFlag;
flags.get = flags__get;
flags.getInt = flags__getInt;
flags.getFloat = flags__getFloat;
flags.isSet = flags__isSet;
flags.parse = flags__parse;
flags.addBool((struct flags*)&flags,"wrap","To wrap a package.");
flags.addBool((struct flags*)&flags,"list","To list all packages.");
flags.addString((struct flags*)&flags,"install","To install a package.");
flags.addString((struct flags*)&flags,"remove","To remove a package.");
flags.addString((struct flags*)&flags,"deps","To list all dependecies of a package.");
flags.parse((struct flags*)&flags,args);
dbGuard();
if ((flags.isSet((struct flags*)&flags,"wrap")==1)) {
wrapPackage();
}
else if ((flags.isSet((struct flags*)&flags,"install")==1)) {
char * arg =  flags.get((struct flags*)&flags,"install");
if ((strcmp(arg, "itself") == 0)) {
struct string ____BAH_COMPILER_VAR_239 =string(args->data[0]);array(struct string)* parts =  splitString(____BAH_COMPILER_VAR_239," ");
struct string name =  parts->data[0];
char * ____BAH_COMPILER_VAR_240 =name.str((struct string*)&name);char * ____BAH_COMPILER_VAR_241 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("cp ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_240);
long int strLen_2 = strlen(" /bin/bpm & chmod +x /bin/bpm");
;                            
                        ____BAH_COMPILER_VAR_241 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_241+currStrOff, "cp ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_241+currStrOff, ____BAH_COMPILER_VAR_240, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_241+currStrOff, " /bin/bpm & chmod +x /bin/bpm", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct command cmd =  command(____BAH_COMPILER_VAR_241);
cmd.run((struct command*)&cmd);
if ((cmd.status!=0)) {
panic("Please run as sudo.");
}
}
else {
installPackage(arg);
}
}
else if ((flags.isSet((struct flags*)&flags,"remove")==1)) {
char * ____BAH_COMPILER_VAR_242 =flags.get((struct flags*)&flags,"remove");removePackage(____BAH_COMPILER_VAR_242);
}
else if ((flags.isSet((struct flags*)&flags,"list")==1)) {
{};
DB.DB= null;
DB.open = db__open;
DB.close = db__close;
DB.exec = db__exec;
char * ____BAH_COMPILER_VAR_243 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BPM_DIR);
long int strLen_1 = strlen("/db.db");
;                            
                        ____BAH_COMPILER_VAR_243 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_243+currStrOff, BPM_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_243+currStrOff, "/db.db", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    DB.open((struct db*)&DB,____BAH_COMPILER_VAR_243);
struct dbResponse* resp =  DB.exec((struct db*)&DB,"SELECT * FROM packages");
array(struct package*)* packages = memoryAlloc(sizeof(array(struct package*)));

packages->length = 0;
packages->elemSize = sizeof(struct package*);

        struct reflectElement ____BAH_COMPILER_VAR_245 = __reflect(0, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);
        
        array(struct reflectElement) * ____BAH_COMPILER_VAR_244 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_244->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_244->length = 4;
        ____BAH_COMPILER_VAR_244->data = memoryAlloc(____BAH_COMPILER_VAR_244->length * ____BAH_COMPILER_VAR_244->elemSize);
        ____BAH_COMPILER_VAR_244->data[0] = __reflect((char **)((char*)(0) + offsetof(struct package, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct package, name));
____BAH_COMPILER_VAR_244->data[1] = __reflect((char **)((char*)(0) + offsetof(struct package, url)), sizeof(char *), "cpstring", "url", 0, 0, 0, 0, offsetof(struct package, url));
____BAH_COMPILER_VAR_244->data[2] = __reflect((double*)((char*)(0) + offsetof(struct package, ver)), sizeof(double), "float", "ver", 0, 0, 0, 0, offsetof(struct package, ver));
____BAH_COMPILER_VAR_244->data[3] = __reflect((array(char *)**)((char*)(0) + offsetof(struct package, deps)), sizeof(array(char *)*), "[]cpstring", "deps", 1, &____BAH_COMPILER_VAR_245, 0, 0, offsetof(struct package, deps));

        struct reflectElement ____BAH_COMPILER_VAR_246 = __reflect(0, sizeof(struct package*), "package*", "", 0, 0, 1, ____BAH_COMPILER_VAR_244, 0);
        resp->scan((struct dbResponse*)resp,__reflect(packages, sizeof(array(struct package*)*), "[]package*", "packages", 1, &____BAH_COMPILER_VAR_246, 0, 0, 0));
long int i =  0;
while ((i<len(packages))) {
struct package* p =  packages->data[i];
if (((void *)p->name!=null)) {
char * ____BAH_COMPILER_VAR_247 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("-> ");
long int strLen_1 = strlen(p->name);
long int strLen_2 = strlen(" (");
long int strLen_3 = strlen(p->url);
long int strLen_4 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_247 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_247+currStrOff, "-> ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_247+currStrOff, p->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_247+currStrOff, " (", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_247+currStrOff, p->url, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_247+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    println(____BAH_COMPILER_VAR_247);
}
else {
char * ____BAH_COMPILER_VAR_248 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("-> ");
long int strLen_1 = strlen(p->url);
long int strLen_2 = strlen("");
;                            
                        ____BAH_COMPILER_VAR_248 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_248+currStrOff, "-> ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_248+currStrOff, p->url, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_248+currStrOff, "", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    println(____BAH_COMPILER_VAR_248);
}
i =  i + 1;
};
DB.close((struct db*)&DB);
}
else if ((flags.isSet((struct flags*)&flags,"deps")==1)) {
char * name =  flags.get((struct flags*)&flags,"deps");
if ((isInstalled(name)==false)) {
char * ____BAH_COMPILER_VAR_249 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("No package called '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("' is installed.");
;                            
                        ____BAH_COMPILER_VAR_249 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_249+currStrOff, "No package called '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_249+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_249+currStrOff, "' is installed.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    panic(____BAH_COMPILER_VAR_249);
}
{};
DB.DB= null;
DB.open = db__open;
DB.close = db__close;
DB.exec = db__exec;
char * ____BAH_COMPILER_VAR_250 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BPM_DIR);
long int strLen_1 = strlen("/db.db");
;                            
                        ____BAH_COMPILER_VAR_250 = memoryAlloc(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_250+currStrOff, BPM_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_250+currStrOff, "/db.db", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    DB.open((struct db*)&DB,____BAH_COMPILER_VAR_250);
char * ____BAH_COMPILER_VAR_251 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("SELECT parent FROM deps WHERE pkg = '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("'");
;                            
                        ____BAH_COMPILER_VAR_251 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_251+currStrOff, "SELECT parent FROM deps WHERE pkg = '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_251+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_251+currStrOff, "'", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct dbResponse* resp =  DB.exec((struct db*)&DB,____BAH_COMPILER_VAR_251);
array(char *)* deps = memoryAlloc(sizeof(array(char *)));

deps->length = 0;
deps->elemSize = sizeof(char *);

        struct reflectElement ____BAH_COMPILER_VAR_252 = __reflect(0, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);
        resp->scan((struct dbResponse*)resp,__reflect(&deps, sizeof(array(char *)*), "[]cpstring", "deps", 1, &____BAH_COMPILER_VAR_252, 0, 0, 0));
long int i =  0;
while ((i<len(deps))) {
struct package* p = memoryAlloc(sizeof(struct package));
p->name= null;
p->url= null;
p->deps = memoryAlloc(sizeof(array(char *)));
            p->deps->length = 0;
            p->deps->elemSize = sizeof(char *);
            char * ____BAH_COMPILER_VAR_253 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("SELECT * FROM packages WHERE name = '");
long int strLen_1 = strlen(deps->data[i]);
long int strLen_2 = strlen("'");
;                            
                        ____BAH_COMPILER_VAR_253 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_253+currStrOff, "SELECT * FROM packages WHERE name = '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_253+currStrOff, deps->data[i], strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_253+currStrOff, "'", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    resp =  DB.exec((struct db*)&DB,____BAH_COMPILER_VAR_253);

        struct reflectElement ____BAH_COMPILER_VAR_255 = __reflect(0, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);
        
        array(struct reflectElement) * ____BAH_COMPILER_VAR_254 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_254->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_254->length = 4;
        ____BAH_COMPILER_VAR_254->data = memoryAlloc(____BAH_COMPILER_VAR_254->length * ____BAH_COMPILER_VAR_254->elemSize);
        ____BAH_COMPILER_VAR_254->data[0] = __reflect((char **)((char*)(p) + offsetof(struct package, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct package, name));
____BAH_COMPILER_VAR_254->data[1] = __reflect((char **)((char*)(p) + offsetof(struct package, url)), sizeof(char *), "cpstring", "url", 0, 0, 0, 0, offsetof(struct package, url));
____BAH_COMPILER_VAR_254->data[2] = __reflect((double*)((char*)(p) + offsetof(struct package, ver)), sizeof(double), "float", "ver", 0, 0, 0, 0, offsetof(struct package, ver));
____BAH_COMPILER_VAR_254->data[3] = __reflect((array(char *)**)((char*)(p) + offsetof(struct package, deps)), sizeof(array(char *)*), "[]cpstring", "deps", 1, &____BAH_COMPILER_VAR_255, 0, 0, offsetof(struct package, deps));
resp->scan((struct dbResponse*)resp,__reflect(p, sizeof(struct package*), "package*", "p", 0, 0, 1, ____BAH_COMPILER_VAR_254, 0));
char * ____BAH_COMPILER_VAR_256 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("-> ");
long int strLen_1 = strlen(p->name);
long int strLen_2 = strlen(" (");
long int strLen_3 = strlen(p->url);
long int strLen_4 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_256 = memoryAlloc(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_256+currStrOff, "-> ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_256+currStrOff, p->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_256+currStrOff, " (", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_256+currStrOff, p->url, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_256+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    println(____BAH_COMPILER_VAR_256);
i =  i + 1;
};
DB.close((struct db*)&DB);
}
println("Done!");
long int ____BAH_COMPILER_VAR_257 = 0;
return ____BAH_COMPILER_VAR_257;
};
