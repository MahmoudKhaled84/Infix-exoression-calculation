#include <iostream>
#include "stack.h"
#include <string.h>
#include <string>
#include <iomanip>
using namespace std;
int main(int argc , char* argv[])
{   Stack<double> values; Stack<int> chars; double value1,value2,result,m=0;bool flag; int p,k,x,e=0,z,y,j, b1=0,item,item1,item2,h=1,a=0,t=0;
    if(argc==1) {cout<<fixed<<setprecision(2)<<m; return 0;}
    if(argc!=2) {cout<<"Invalid Expression"; return 0;}
    string s=argv[1];
    k=s.size();
    for(int i=0;i<k;i++)
    {
        x=argv[1][i];
        if(x>=48&&x<=57)
            e=1;
        if(x==40)
            {
                p=argv[1][i-1];
                z=argv[1][i+1];
                if(!((z>=48&&z<=57)||z==45||z==40)){cout<<"Invalid Expression"; return 0;}
                if(p==41){cout<<"Invalid Expression"; return 0;}
                b1++;
            }
        if(x==41)
            {   z=argv[1][i-1];
                if(!((z>=48&&z<=57)||z==41)){cout<<"Invalid Expression"; return 0;}
                b1--;
            }
            if(x==120)
            {   z=argv[1][i+1];
                if(z==120||z==47||z==43||z==0){cout<<"Invalid Expression"; return 0;}
            }
            if(x==47)
            {   z=argv[1][i+1];
                if(z==120||z==47||z==43||z==0){cout<<"Invalid Expression"; return 0;}
            }
            if(x==43)
            {   z=argv[1][i+1];
                if(z==120||z==47||z==43||z==0){cout<<"Invalid Expression"; return 0;}
            }
            if(x==45)
            {   z=argv[1][i+1];
                if(e==0)
                {
                    if(z==120||z==47||z==43||z==45||z==0){cout<<"Invalid Expression"; return 0;}
                }
                if(z==0) {cout<<"Invalid Expression"; return 0;}
            }
    }
    if(b1!=0) {cout<<"Invalid Expression"; return 0;}
    for(int i=0;i<=k;i++)
    {   x=argv[1][i];
        if(x==40)
            flag=chars.push(x);
        else if((x==43||x==45||x==120||x==47)&&h==0)
        {
            flag=chars.top(item);
            if((x==45&&item==120)||(x==43&&item==120)||(x==47&&item==120)||(x==120&&item==120))
            {
                flag=chars.pop(item);
                flag=values.pop(value2);
                flag=values.pop(value1);
                result=value1*value2;
                flag=values.push(result);
            }
            if((x==45&&item==47)||(x==43&&item==47)||(x==120&&item==47)||(x==47&&item==47))
            {
                flag=chars.pop(item);
                flag=values.pop(value2); if(value2==0) {cout<<"Invalid Expression"; return 0;}
                flag=values.pop(value1);
                result=value1/value2;
                flag=values.push(result);
            }
            if((x==45&&item==43)||(x==43&&item==43))
            {
                flag=chars.pop(item);
                flag=values.pop(value2);
                flag=values.pop(value1);
                result=value1+value2;
                flag=values.push(result);
            }
            if((x==45&&item==45)||(x==43&&item==45))
            {
                flag=chars.pop(item);
                flag=values.pop(value2);
                flag=values.pop(value1);
                result=value1-value2;
                flag=values.push(result);

            }
            flag=chars.push(x);
            h=1;
            t++;
        }
        else if((x>=48&&x<=57)||x==45)
        {   if(x==45) a=1;
            if(x>=48&&x<=57)
            {
                item1=x-48;
                j=i+1;
                y=argv[1][j];
                while(y>=48&&y<=57)
                {
                    item2=y-48;
                    item1=item2+10*item1;
                    j++;
                    y=argv[1][j];
                    i=j-1;
                }
                if(a==0)
                flag=values.push(item1);
                if(a==1)
                flag=values.push(-item1);
                h=0;
                a=0;
            }

        }
        else if(x==41)
        {
            flag=chars.pop(item);
            while(item!=40)
            {
                flag=values.pop(value2);
                flag=values.pop(value1);
                if(item==43)
                    {
                        result=value1+value2;
                        flag=values.push(result);
                    }
                    if(item==45)
                    {
                        result=value1-value2;
                        flag=values.push(result);
                    }
                    if(item==120)
                    {
                        result=value1*value2;
                        flag=values.push(result);
                    }
                    if(item==47)
                    {
                        if(value2==0) {cout<<"Invalid Expression"; return 0;}
                        result=value1/value2;
                        flag=values.push(result);
                    }
                    flag=chars.pop(item);
            }

        }
        else if(x==0)
        {
            if(chars.isEmpty())
                {
                    flag=values.pop(result);
                    cout<<fixed<<setprecision(2)<<result;
                }
            else
            {
                while(!chars.isEmpty())
                {
                    flag=chars.pop(item);
                    flag=values.pop(value2);
                    flag=values.pop(value1);
                    if(item==43)
                        {
                            result=value1+value2;
                            flag=values.push(result);
                        }
                        if(item==45)
                        {
                            result=value1-value2;
                            flag=values.push(result);
                        }
                        if(item==120)
                        {
                            result=value1*value2;
                            flag=values.push(result);
                        }
                        if(item==47)
                        {
                            if(value2==0) {cout<<"Invalid Expression"; return 0;}
                            result=value1/value2;
                            flag=values.push(result);
                        }
                }
                flag=values.pop(result);
                cout<<fixed<<setprecision(2)<<result;
            }
        }
        else {cout<<"Invalid Expression"; return 0;}
    }
    return 0;
}
