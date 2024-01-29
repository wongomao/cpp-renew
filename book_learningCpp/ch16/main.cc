import hello;
int main (void)
{
    greeter("World");
    return 0;
}
/*
compile with:
> g+= -fmodules-ts -std=c++2b -c hello.cc main.cc
*/