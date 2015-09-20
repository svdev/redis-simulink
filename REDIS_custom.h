#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simstruc.h"
#include "hiredis/hiredis.h"
#include "REDIS_bus.h"

extern redisContext * REDIS_connectRedis(const char *host, int port);
extern void REDIS_redis_disconnect(redisContext *c);
extern redisReply * REDIS_send_command(redisContext *c, const char *cmd);
extern void REDIS_Outputs_parse_response(SimStruct *S, redisContext *c, redisReply *reply, uint8_T *data, int32_T *status, uint8_T *replyType, uint32_T *numElements, uint32_T data_width, int_T tid);
extern bool REDIS_finished(SimStruct *S, int_T tid);
extern bool REDIS_received(SimStruct *S, int_T tid);
extern bool REDIS_started(SimStruct *S, int_T tid);