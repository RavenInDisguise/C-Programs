#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int arreglo[5];
    for (int i=0; i<=5; i++)
        cout<<arreglo[i]<<endl;


    cout<<"-------"<<endl;
    
    struct Estructura{
        float x,y;
    }*d;

    int *a;
    float *b;
    char *c;


    a=new int;
    b=new float;
    c=new char;
    d=new Estructura;
    cout<<sizeof(d)<<endl;


    *a=10;
    *b=10.50;
    *c='M';
    d->x=12.1;
    d->y=13.6;

    cout<<*a<<endl;
    cout<<*b<<endl;
    cout<<*c<<endl;
    cout<<d->x<<endl;
    cout<<d->y<<endl;

    cout<<"-------"<<endl;

    char *m1;
    m1=new char;
    *m1='M';
    cout<<*m1<<endl;


    cout<<"-------"<<endl;
    struct pack3 
    { 
        int a;
    };
    struct pack2 
    {
        int b;
        struct pack3 *next;
    };
    struct pack1 
    {
        int c;
        struct pack2 *next;
    };

    struct pack1 data1, *data_ptr;
    struct pack2 data2;
    struct pack3 data3;

    data1.c = 30;
    data2.b = 20;
    data3.a = 10;
    data_ptr = &data1;
    data1.next = &data2;
    data2.next = &data3;


    cout<<"1) "<<data1.c<<endl;
    cout<<"2) "<<data_ptr->c<<endl;
    //cout<<"3) "<<data_ptr.c<<endl; Error
    cout<<"4) "<<data1.next->b<<endl; 
    cout<<"5) "<<data_ptr->next->b<<endl;
    //cout<<"6) "<<data_ptr.next.b<<endl; Error
    //cout<<"7) "<<data_ptr->next.b<<endl; Error
    cout<<"8) "<<(*(data_ptr->next)).b<<endl;
    cout<<"9) "<<data1.next->next->a<<endl;
    //cout<<"10) "<<data1.next->next.a<<endl; Error
    cout<<"11) "<<data_ptr->next->next->a<<endl;
    //cout<<"12) "<<data_ptr->next->a<<endl; Error
    //cout<<"13) "<<data1.next->next->b<<endl; Error


    data1.next->b;
    data_ptr->next->b;
    cout<<data1.next<<endl;
    cout<<&b<<endl;
    (*(data_ptr->next)).b;
    cout<<data1.next->next->a<<endl;

}