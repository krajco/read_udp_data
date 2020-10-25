//2001:0db8:85a3:08d3:1319:8a2e:0370:7334
// Created by patrik on 26.9.2018.
//

#ifndef UNTITLED_GLOBAL_H
#define UNTITLED_GLOBAL_H

#endif //UNTITLED_GLOBAL_H

#include <iostream>
#include <netinet/in.h>

using namespace std;

typedef struct Arg{
    uint16_t tag ;
    uint8_t metric;
    uint8_t mask;
    string interface;
    in6_addr address;
    in6_addr next_hop;
}t_Arg;


#define RETURN_SUCCESS 1
#define RETURN_FAIL 0

#define ERR_ARGUMENTS       1
#define ERR_PACKET_INIT     2
#define ERR_CONNECTION      3

#define MTU_SIZE 1500
#define PROMISC_MODE 1  // True inidicate primisc mode
#define NO_TIMER     0  // 0 indticate withou timer


#define  AUTH 20
#define  NO_AUTH 0

#define MD5_AUTH 1
#define MD5_NO   0

/* Headers len */
#define ETHER_HEADER_LEN 14
#define IPV6_HEADER_LEN 40
#define UDP_HEADER_LEN 8


typedef struct{
    // Version (4 bits) and header length (4 bits)
    uint8_t ip_vhl;
    // Type of Service
    uint8_t ip_tos;
    // Total length
    uint16_t ip_length;
    // Identification
    uint16_t ip_id;
    // Flags and Fragment offset
    uint16_t ip_offset;
    // Time to Live
    uint8_t ip_ttl;
    // Next level protocol
    uint8_t ip_protocol;
    // Header checksum
    uint16_t ip_checksum;
    // Source and destination address
    struct in_addr ip_src, ip_dst;
} t_IPv4_header;

typedef struct{
    uint32_t V_TC_FL;
    uint16_t payload_len;
    uint8_t  next_header;
    uint8_t  hop_limit;
    struct in6_addr src_addr;
    struct in6_addr dest_addr;
}t_IPv6_header;

typedef struct {
    // Source port
    uint16_t udp_src;
    // Destination port
    uint16_t udp_dest;
    // Total length
    uint16_t udp_length;
    // Checksum
    uint16_t udp_sum;
} t_UDP_header;

typedef struct{
    uint8_t data;
}t_data;
