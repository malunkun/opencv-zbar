/*************************************************************************
    > File Name: testmain.c
    > Author: malunkun
    > Mail: malunkun<209446860@qq.com>
    > Created Time: 2019年07月20日 星期六 15时17分13秒
 ************************************************************************/

#include<stdio.h>
#include"decoder.h"

int main()
{
	struct code_msg msg;
	decoder(1,&msg);
	printf("type:%s\n",msg.get_type_name);
	printf("data:%s\n",msg.get_data);
	return 0;
}
