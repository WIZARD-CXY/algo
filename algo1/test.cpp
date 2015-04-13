/*************************************************************************
	> File Name: test.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Sun 15 Jun 2014 10:40:13 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
//借助strtok实现split
#include <string.h>
#include <stdio.h>

int main()
{
        char s[] = "Golden Global      View,disk * desk";
        const char *d = " ,*";
        char *p;
        p = strtok(s,d);
        while(p)
        {
                printf("%s\n",p);
                p=strtok(NULL,d);
        }

        return 0;
}
