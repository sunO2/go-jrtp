#include "jrtplib_warpper.h"
#include <iostream>
#include <jrtplib3/rtpsessionparams.h>
#include <jrtplib3/rtpudpv4transmitter.h>
#include <jrtplib3/rtpsession.h>
#include <jrtplib3/rtppacket.h>

using namespace jrtplib;

struct GORTPSession {
    RTPSession session;
};

GORTPSession* rtp_session_create(const char* ip, int port) {
    printf("哈哈哈哈哈阿");
    GORTPSession* gosession = new GORTPSession();

    RTPSessionParams sessionParams;
    sessionParams.SetOwnTimestampUnit(1.0/8000.0);
    sessionParams.SetAcceptOwnPackets(false);

    RTPUDPv4TransmissionParams transparams;
    transparams.SetPortbase(5002);
    int status = gosession->session.Create(sessionParams, &transparams);
    if (status < 0)
    {
        std::cerr << RTPGetErrorString(status) << std::endl;
    }else{
        printf("session 创建成功");
    }

    RTPIPv4Address addr(ntohl(inet_addr(ip)), port);
    status = gosession->session.AddDestination(addr);
    if (status < 0)
    {
        std::cerr << RTPGetErrorString(status) << std::endl;
    }

    return gosession;
}

void rtp_session_destroy(GORTPSession* session) {
     RTPTime delay = RTPTime(2.0);
    session->session.BYEDestroy(delay, "stop rtp videoSession", strlen("stop rtp videoSession"));
    delete session;
}

void rtp_session_send(GORTPSession* session, const char* data, int length, uint8_t pt, bool mark, uint32_t timestampinc) {
    session->session.SendPacket(reinterpret_cast<const uint8_t*>(data), length, pt, mark, timestampinc);
}