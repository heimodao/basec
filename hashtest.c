#include<stdio.h>

unsigned int BKDRHash(char *str);
unsigned int SDBMHash(char *str);
unsigned int RSHash(char *str);
unsigned int JSHash(char *str);
unsigned int ELFHash(char *str);
unsigned int DJBHash(char *str);



int main () {
	char str[] = "zengwei951013";
	char str2[] = "曾巍951013";
	printf("BKDR:%s(%d)\t%s(%d)\n",str,BKDRHash(str),str2,BKDRHash(str2));
	printf("SDBM:%s(%d)\t%s(%d)\n",str,SDBMHash(str),str2,SDBMHash(str2));
	printf("RS:%s(%d)\t%s(%d)\n",str,SDBMHash(str),str2,SDBMHash(str2));
	printf("JS:%s(%d)\t%s(%d)\n",str,SDBMHash(str),str2,SDBMHash(str2));
	printf("ELF:%s(%d)\t%s(%d)\n",str,SDBMHash(str),str2,SDBMHash(str2));
	printf("DJB:%s(%d)\t%s(%d)\n",str,SDBMHash(str),str2,SDBMHash(str2));
    return 0;
}


// BKDR Hash Function
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;   
 
    while (*str)
    {
        hash = hash * seed + (*str++);
    }    
    return (hash & 0x7FFFFFFF);
}

//SDBMHash
unsigned int SDBMHash(char *str)
{
    unsigned int hash = 0; 
   
    while (*str)
    {        
        // equivalent to: hash = 65599*hash + (*str++);
        hash = (*str++) + (hash << 6) + (hash << 16) - hash;
    }    
    return (hash & 0x7FFFFFFF);
}


// RS Hash Function
unsigned int RSHash(char *str)
{
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;    

    while (*str)
    {
        hash = hash * a + (*str++);
        a *= b;
    }    
    return (hash & 0x7FFFFFFF);
}

// JS Hash Function
unsigned int JSHash(char *str)
{
    unsigned int hash = 1315423911;    

    while (*str)
    {
        hash ^= ((hash << 5) + (*str++) + (hash >> 2));
    }    
    return (hash & 0x7FFFFFFF);
}

// ELF Hash Function
unsigned int ELFHash(char *str)
{
    unsigned int hash = 0;
    unsigned int x = 0;  
  
    while (*str)
    {
        hash = (hash << 4) + (*str++);        
        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }    
    return (hash & 0x7FFFFFFF);
}

// DJB Hash Function
unsigned int DJBHash(char *str)
{
    unsigned int hash = 5381; 
   
    while (*str)
    {
        hash += (hash << 5) + (*str++);
    }    
    return (hash & 0x7FFFFFFF);
}
