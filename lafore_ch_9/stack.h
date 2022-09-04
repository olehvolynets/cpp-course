class Stack
{
protected:
   static const int MAX = 3;

   int st[MAX];
   int top;
public:
   Stack()
       : top(-1)
   {
   }

   void push(int var);
   int pop();
};

class Stack2 : public Stack
{
public:
    void push(int var);
    int pop();
};
