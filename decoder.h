#ifndef _DECODER_H_
#define _DECODER_H_

struct code_msg{
	char get_type_name[10];
	char get_data[200];
};

#ifdef __cplusplus
extern "C"{
#endif

int decoder(int carame_num,struct code_msg* code_msg);

#ifdef __cplusplus
}
#endif

#endif
