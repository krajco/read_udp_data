
#define MTU_SIZE 1500
#define ETHER_HEADER_LEN 14
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
}t_IPv4_header;

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
