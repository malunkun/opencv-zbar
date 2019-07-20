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
