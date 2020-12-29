#include <stdio.h>
#define N 256

//移动对齐数组
void move(int arr[], int k, int length)
{

   for (int i = length - 1; i >= 0; i--)
   {
      arr[i + k] = arr[i];
      arr[i] = 0;
   }
}

int main(int argc, char const *argv[])
{
   int a[N] = {0};   //加数
   int b[N] = {0};   //被加数
   int k = 0;        //进位
   int a_length = 1; //不用第一位用作进位
   int b_length = 1;

   char t = 0;
   //输入a
   while (1)
   {
      t = getchar();
      if (t == '+')
      {
         break;
      }
      if (t >= '0' && t <= '9')
      {
         a[a_length] = t - 48;
         a_length++;
      }
      else if (t >= 'A' && t <= 'F')
      {
         a[a_length] = t - 55;
         a_length++;
      }else if (t>='a'&&t<='f')
      {
         a[a_length]=t-87;
         a_length++;
      }
   }
   //输入b
   while (1)
   {
      t = getchar();
      if (t == '=')
      {
         break;
      }
      if (t >= '0' && t <= '9')
      {
         b[b_length] = t - 48;
         b_length++;
      }
      else if (t >= 'A' && t <= 'F')
      {
         b[b_length] = t - 55;
         b_length++;
      }else if (t>='a'&&t<='f')
      {
         b[b_length]=t-87;
         b_length++;
      }
   }

   //对齐
   if (a_length > b_length)
   {
      move(b, a_length - b_length, b_length);
      b_length = a_length;
   }
   else if (b_length > a_length)
   {
      move(a, b_length - a_length, a_length);
      a_length = b_length;
   }

   //加
   for (int i = a_length - 1; i >= 0; i--)
   {
      a[i] = a[i] + b[i] + k;
      k = 0;
      if (a[i] > 15)
      {
         k = a[i] / 16;
         a[i] = a[i] % 16;
      }
   }

   //输出
   int flag = 1;
   printf("0X");   
   for (int i = 0; i < a_length; i++)
   {
      if (flag)
      {
         if (a[i] != 0)
         {
            flag = 0;
            if (a[i] >= 0 && a[i] <= 9)
            {
               printf("%d", a[i]);
            }
            else
            {
               printf("%c", a[i] + 55);
            }
         }
      }
      else
      {
         if (a[i] >= 0 && a[i] <= 9)
         {
            printf("%d", a[i]);
         }
         else
         {
            printf("%c", a[i] + 55);
         }
      }
   }
   if (flag)
   {
      printf("0");
   }
   return 0;
}