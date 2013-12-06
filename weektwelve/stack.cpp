
template <typename T>
stack<T>::stack(int s)
{
   maxSize = s;
   data = new T[maxSize];
   top = -1;
   actual = 0;
}

template <typename T>
stack<T>::stack(const stack& s)
{
   maxSize = s.maxSize;
   data = new T[maxSize];
   if(!s.empty())
   {
      for(int i = 0; i < maxSize; i++)
      {
         data[i] = s.data[i];
      }
   }
   top = s.top;
   actual = s.actual;
}

template <typename T>
stack<T>::~stack()
{
   delete[] data;
   data = NULL;
}

template <typename T>
stack<T>& stack<T>::operator=(const stack& s)
{
   maxSize = s.maxSize;
   delete[] data;
   data = new T[maxSize];
   if(!s.empty())
   {
      for(int i = 0; i < maxSize; i++)
      {
         data[i] = s.data[i];
      }
   }
   top = s.top;
   actual = s.actual;
}

template <typename T>
bool stack<T>::push(T toPush)
{
   if(!full())
   {
      top++;
      data[top] = toPush;
      return true;
   }
   return false;
}

template <typename T>
bool stack<T>::pop(T& popper)
{
   if(!empty())
   {
      popper = data[top];
      top--;
      return true;
   }
   return false;
}

template <typename T>
bool stack<T>::empty() const
{
   if(top < 0)
      return true;
   return false;
}

template <typename T>
bool stack<T>::full() const
{
   if(top >= maxSize - 1)
      return true;
   return false;
}

template <typename T>
bool stack<T>::clear()
{
   top = -1;
}

template <typename T>
void stack<T>::print() const
{
   if(empty())
      return;
   cout << '[' << data[top] << "] ";
   for(int i = top-1; i >= 0; i--)
   {
      cout << data[i] << " ";
   }
   cout << endl;
}
