#include <math.h>
#include "REDIS_custom.h"

/*
 * Output functions
 *
 */
void REDIS_Outputs_wrapper(void *SS,
                          redisContext *c,
                          const uint8_T *input,
                          uint8_T *data ,                           
                          int32_T *status,
                          uint8_T *replyType,
                          uint32_T *numElements,
                          uint32_T data_width,
                          int_T tid)                                                    
{
    SimStruct *S = (SimStruct *) SS;
    
    // Set REDIS_ERR by default 
    *status = -1;    
    
    // Set reply type as REDIS_REPLY_ERROR by default
    *replyType = 6;    
    
    // Set num elements to zero by default.
    *numElements = 0;
       
    redisReply *reply = REDIS_send_command(c,(char *)input);      
           
    // Parse response.
    REDIS_Outputs_parse_response(S, c, reply, data, status, replyType, numElements, data_width, tid);
                   
}


void REDIS_Outputs_parse_response(SimStruct *S, redisContext *c, redisReply *reply, uint8_T *data, int32_T *status, uint8_T *replyType, uint32_T *numElements, uint32_T data_width, int_T tid){
      
                  
    if(reply == NULL || c->err){                   
        return;
    }            
    
    *replyType = reply->type;                    
    *status = c->err;   
    // Empty data output port
    memset(data, 0, data_width);          
    
    REDIS_started(S,tid);
    int len = 0;
     // PARSE RESPONSE        
    switch(reply->type){        
        case REDIS_REPLY_ERROR:            
            //printf("RESPONSE TYPE: REDIS_REPLY_ERROR\n");             
            *numElements = 0;            
            break;           
        case REDIS_REPLY_ARRAY:
            //printf("RESPONSE TYPE: REDIS_REPLY_ARRAY\n"); 
            *numElements = reply->elements;
            for (int j = 0; j < reply->elements; j++) {
                len = strlen(reply->element[j]->str);
                //printf("%u) (data_width: %d): %s\n",j, len,reply->element[j]->str); 
                
                // Copy redis element to data output port.
                if(len < data_width){
                    memcpy(data, reply->element[j]->str, len);
                    REDIS_received(S,tid);  
                    memset(data, 0, len);
                }                                
            }            
            
            break;
        case REDIS_REPLY_INTEGER:
            //printf("RESPONSE TYPE: REDIS_REPLY_INTEGER\n");
            //printf("0): %d\n",reply->integer); 
                        
            // Convert integer to string (max 30 bytes)                        
            char num_str[30];
            sprintf(num_str, "%lu", reply->integer);
            memcpy(data, &num_str, strlen(num_str));              
            *numElements = 1;
            
            REDIS_received(S,tid);
            memset(data, 0, strlen(num_str));                                  
            
            break;
        case REDIS_REPLY_STRING:
            //printf("RESPONSE TYPE: REDIS_REPLY_STRING\n");
            //printf("0): %s\n",reply->str);  
            len = strlen(reply->str);
            if(len < data_width){
                memcpy(data, reply->str, len);                
                *numElements = 1;
                REDIS_received(S,tid);
                memset(data, 0, len); 
            }else{
               printf("ERROR 0): %s . Not enough memory to copy element\n",reply->str);  
            }            
            break;
        case REDIS_REPLY_STATUS:
            //printf("RESPONSE TYPE: REDIS_REPLY_STATUS\n");
            //printf("0): %s\n",reply->str);    
            len = strlen(reply->str);
            if(len < data_width){
                 memcpy(data, reply->str, len);    
                *numElements = 1;
                REDIS_received(S,tid);
                memset(data, 0, len); 
            }else{
                 printf("ERROR 0): %s . Not enough memory to copy element\n",reply->str);  
            }
            
            break;
        case REDIS_REPLY_NIL:
            //printf("RESPONSE TYPE: REDIS_REPLY_NIL\n");
            //printf("0): NULL\n");          
            *numElements = 1;
            REDIS_received(S,tid);
            
            break;                            
    }  
    
    // FINISHED
    REDIS_finished(S,tid);      
    memset(data, 0, len);
    
}

bool REDIS_received(SimStruct *S, int_T tid){
        
    // RECEIVED
    if (!ssCallSystemWithTid(S,0,tid)) {
        /* Error occurred, which will be reported by */
        /*the Simulink engine*/
        return false;
    }
    return true;
}

bool REDIS_finished(SimStruct *S, int_T tid){
        
    // FINISHED
    if (!ssCallSystemWithTid(S,1,tid)) {
        /* Error occurred, which will be reported by */
        /*the Simulink engine*/
        return false;
    }
    
    return true;
}

bool REDIS_started(SimStruct *S, int_T tid){
        
    // FINISHED
    if (!ssCallSystemWithTid(S,2,tid)) {
        /* Error occurred, which will be reported by */
        /*the Simulink engine*/
        return false;
    }
    
    return true;
}


