/* Program to print pattern
1
22
333
4444
55555 */


#include<iostream.h>
#include<conio.h>
void main()
{
 int i,j;
 for(i=0;i<=5;i++)
 {
   for(j=i;j>=1;j--)
   {
   cout<<i;
   }
   cout<<"\n";
   getch();
 }


}