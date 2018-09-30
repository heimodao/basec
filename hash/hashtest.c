#include<stdio.h>

unsigned int BKDRHash(char *str);
unsigned int SDBMHash(char *str);
unsigned int RSHash(char *str);
unsigned int JSHash(char *str);
unsigned int ELFHash(char *str);
unsigned int DJBHash(char *str);
unsigned int PJWHash(char* str);
unsigned int DEKHash(char* str, unsigned int len);
unsigned int FNVHash(char* str);
unsigned int APHash(char* str, unsigned int len);


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

//P. J. Weinberger Hash Function
unsigned int PJWHash(char* str)
{
   const unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
   const unsigned int ThreeQuarters     = (unsigned int)((BitsInUnsignedInt  * 3) / 4);
   const unsigned int OneEighth         = (unsigned int)(BitsInUnsignedInt / 8);
   const unsigned int HighBits          = (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
   unsigned int hash              = 0;
   unsigned int test              = 0;
   while (*str)
   {
      hash = (hash << OneEighth) + (*str++);
      if((test = hash & HighBits)  != 0)
      {
         hash = (( hash ^ (test >> ThreeQuarters)) & (~HighBits));
      }
   }
   return hash;
}

unsigned int DEKHash(char* str, unsigned int len)
{
   unsigned int hash = len;
   unsigned int i    = 0;
   for(i = 0; i < len; str++, i++)
   {
      hash = ((hash << 5) ^ (hash >> 27)) ^ (*str);
   }
   return hash;
}

unsigned int FNVHash(char* str)
{
   const unsigned int fnv_prime = 0x811C9DC5;
   unsigned int hash      = 0;
   while(*str)
   {
      hash *= fnv_prime;
      hash ^= (*str++);
   }
   return hash;
}
/* End Of FNV Hash Function */

unsigned int APHash(char* str, unsigned int len)
{
   unsigned int hash = 0xAAAAAAAA;
   unsigned int i    = 0;
   for(i = 0; i < len; str++, i++)
   {
      hash ^= ((i & 1) == 0) ? (  (hash <<  7) ^ (*str) * (hash >> 3)) :
                               (~((hash << 11) + (*str) ^ (hash >> 5)));
   }
   return hash;
}

int main () {
	char str[] = "wenruo";
	char str2[] = "zw@linkzw.com";
	printf("BKDR:%s(%d)\t%s(%d)\n",str,BKDRHash(str),str2,BKDRHash(str2));
	printf("SDBM:%s(%d)\t%s(%d)\n",str,SDBMHash(str),str2,SDBMHash(str2));
	printf("RS:%s(%d)\t%s(%d)\n",str,SDBMHash(str),str2,SDBMHash(str2));
	printf("JS:%s(%d)\t%s(%d)\n",str,SDBMHash(str),str2,SDBMHash(str2));
	printf("ELF:%s(%d)\t%s(%d)\n",str,SDBMHash(str),str2,SDBMHash(str2));
	printf("DJB:%s(%d)\t%s(%d)\n",str,SDBMHash(str),str2,SDBMHash(str2));
	printf("PJW:%s(%d)\t%s(%d)\n",str,PJWHash(str),str2,PJWHash(str2));
	//printf("DEK:%s(%d)\t%s(%d)\n",str,DEKHash(str),str2,DEKHash(str2));
	printf("FNV:%s(%d)\t%s(%d)\n",str,FNVHash(str),str2,FNVHash(str2));
    return 0;
}


