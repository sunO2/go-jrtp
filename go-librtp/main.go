package main

import (
	"fmt"
	"go-librtp/rtp"
)

func main() {
	fmt.Println("开始了 开始了")
	session := rtp.NewRTPSession("172.17.0.5", 5000)
	data := []byte("哈哈哈哈")
	session.SendPacket(data, len(data), 96, true, 10)

	session.Destroy()
}
