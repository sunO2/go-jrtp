#include <stdio.h>
#include <iostream>
#include <jrtplib3/rtpsessionparams.h>
#include <jrtplib3/rtpudpv4transmitter.h>
#include <jrtplib3/rtpsession.h>
#include <jrtplib3/rtppacket.h>


using namespace jrtplib;

int main(void){
    printf("哈哈哈哈哈阿");

    RTPSession session;
    RTPSessionParams sessionParams;
    sessionParams.SetOwnTimestampUnit(1.0/8000.0);
    sessionParams.SetAcceptOwnPackets(false);

    RTPUDPv4TransmissionParams transparams;
    transparams.SetPortbase(5002);

   int status = session.Create(sessionParams, &transparams);
    if (status < 0)
    {
        std::cerr << RTPGetErrorString(status) << std::endl;
    }else{
        printf("创建成功");
    }

    char destIp [16] = "192.168.0.115";
    int destPort = 5002;
    RTPIPv4Address addr(ntohl(inet_addr(destIp)), destPort);
    status = session.AddDestination(addr);
    if (status < 0)
    {
        std::cerr << RTPGetErrorString(status) << std::endl;
    }

    status = session.SendPacket((void *) "1234567890", 10, 0, false, 10);
    if (status < 0)
    {
        std::cerr << RTPGetErrorString(status) << std::endl;
    }
    // std::string RtpError = RTPGetErrorString(iErrNum);
    // if (iErrNum < 0){
    //     printf( "Create RTP Session error! Reason: %s!\r\n", RtpError.c_str() );
    //     return -1;
    // }
    
}