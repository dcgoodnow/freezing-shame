
void StringCopy(const char* strA, char* strB) 
{
   while(*strA != '\0')
   {
      *strB = *strA;
      strA++;
      strB++;
   }
   *strB = '\0';  //null-terminated
}

int length(char* string)
{
   int i = 0;
   while(*string != '\0')
   {
      string++;
    	i++;
   }
   return i+1;
}

bool StringCompare(char* a, char* b)
{
   while(*a != '\0' || *b != '\0')
   {
      if(*a != *b)
         return false;
      a++;
      b++;
   }
   return true;
}

void StringConcat(char* a, char* b)
{
   while(*a != '\0')
      a++;
   for(int i = 0; i < length(b), i++)
   {
      *a = *b;
      a++;
      b++;
   }
   *(++a) = '\0';
   return;
}

