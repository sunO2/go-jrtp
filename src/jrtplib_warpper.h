#ifndef JRTPLIB_WRAPPER_H
#define JRTPLIB_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h> 
#include <stdbool.h>
#include <stdlib.h>

// 结构体定义
typedef struct GORTPSession GORTPSession;

// 函数声明
GORTPSession* rtp_session_create(const char* ip, int port);
void rtp_session_destroy(GORTPSession* session);
void rtp_session_send(GORTPSession* session, const char* data, int length, uint8_t pt, bool mark, uint32_t timestampinc);

#ifdef __cplusplus
}
#endif

#endif // JRTPLIB_WRAPPER_H