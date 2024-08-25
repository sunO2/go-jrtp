package main

/*
#cgo LDFLAGS: -L../lib -ljrtp -ljthread -ljrtplib_core
#cgo CFLAGS: -I../src
#include "jrtplib_warpper.h"
*/
import "C"
import (
	"fmt"
	"unsafe"
)

type RTPSession struct {
	CRTPSession *C.GORTPSession
}

func NewRTPSession(ip string, port int) *RTPSession {
	cip := C.CString(ip)
	defer C.free(unsafe.Pointer(cip))
	return &RTPSession{
		CRTPSession: C.rtp_session_create(cip, C.int(port)),
	}
}

func (s *RTPSession) Destroy() {
	C.rtp_session_destroy(s.CRTPSession)
	s.CRTPSession = nil
}

func (s *RTPSession) Send(data []byte, pt uint8, mark bool, timestampinc uint32) {
	C.rtp_session_send(s.CRTPSession, (*C.char)(unsafe.Pointer(&data[0])), C.int(len(data)), C.uint8_t(pt), C.bool(mark), C.uint32_t(timestampinc))
}

func main() {
	fmt.Println("开始了 开始了")
	session := NewRTPSession("172.17.0.5", 5000)
	session.Send([]byte("哈哈哈哈"), 96, true, 10)

	session.Destroy()
}
