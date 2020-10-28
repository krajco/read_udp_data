#include <iostream>
#include <getopt.h>
#include <pcap/pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap-namedb.h>
#include <cstring>
#include <vector>
#include <cstring>
#include "global.h"

using namespace std;

// callback function
void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char **argv) {

    /* Local variable declaration for interface */
    string interface,port_range;
    pcap_t *handle ;

    /* Get option from cmd */
    int c;
    while((c = getopt(argc,argv,"i:p:")) != -1){
        switch(c){
            case 'i':
                interface = optarg;
                break;
            case 'p':
                port_range = optarg;
                break;
            default:
                cerr << "Incorrect arguments" << endl;
                exit(1);
        }
    }

    if(port_range.size() < 1) {
      cerr << "Port range is not selected, user format: number-number (example: 9898-9898)" << endl;
      exit(1);
    }

    string  filter_exp = "portrange " + port_range;  // The filter expression
    bpf_u_int32 net_address; // IP address as integer

    struct bpf_program fp;  // The compiled filter expression
    char errbuf[PCAP_ERRBUF_SIZE]; // Size defined in pcap.h
    string type = interface.substr(interface.find('.',0),interface.length());


    if((handle = pcap_open_offline(interface.data(),errbuf)) == NULL){
        cout << "Chyba, pcap offline open" << endl;
        exit(1);
    }

    // Before appling filter, it must be compiled
    if(pcap_compile(handle, &fp, filter_exp.data(), 0, net_address) < 0){
        cerr << "Chyba,pcap compile" << endl;
        exit(1);
    }

    // Apply filter
    if(pcap_setfilter(handle,&fp) < 0 ){
        cerr << "Error, pcap set filter" << endl;
        exit(1);
    }

    pcap_loop(handle, 0, got_packet, NULL);
    pcap_close(handle);
    return 0;
}

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet){
    t_IPv4_header *ip_header = (t_IPv4_header *) (packet + ETHER_HEADER_LEN);

    int startingPosition = ETHER_HEADER_LEN + ((ip_header->ip_vhl & 0xF) * 4) + UDP_HEADER_LEN;

    int length = ntohs(((t_UDP_header*)(packet + ETHER_HEADER_LEN + ((ip_header->ip_vhl & 0xF) * 4)))->udp_length) + startingPosition - UDP_HEADER_LEN;

    string str;
    for(int i = startingPosition; i < length; i++) {
      str += packet[i];
    }

    char src[INET_ADDRSTRLEN];
    char dst[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &(ip_header->ip_src), src, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_header->ip_dst), dst, INET_ADDRSTRLEN);

    cout << "src:" << src  << " dst:" << dst;
    cout << "\t" << str << endl;
}
