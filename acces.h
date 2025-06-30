#define ETHER_ADDR_LEN 6
#define ETHER_HDR_LEN 14
struct ether_hdr {
unsigned char ether_dest_addr[ETHER_ADDR_LEN]; // Destination MAC address
unsigned char ether_src_addr[ETHER_ADDR_LEN]; // Source MAC address
unsigned short ether_type; // Type of Ethernet packet
};
struct ip_hdr {
    unsigned char ip_version_and_header_length; // Version and header length
    unsigned char ip_tos; // Type of service
    unsigned short ip_len; // Total length
    unsigned short ip_id; // Identification number
    unsigned short ip_flag_offset; // Fragment offset and flags
    unsigned char ip_ttl; // Time to live
    unsigned char ip_type; // Protocol type
    unsigned short ip_checksum; // Checksum
    unsigned int ip_src_addr; // Source IP address
    unsigned int ip_dest_addr; // Destination IP address
    };

void fatal(char *message) {
    char error_message[100];
    strcpy(error_message, "[!!] Fatal Error ");
    strncat(error_message, message, 83);
    perror(error_message);
    exit(-1);
    }
    // An error-checked malloc() wrapper function
    void *ec_malloc(unsigned int size) {
    void *ptr;
    ptr = malloc(size);
    if(ptr == NULL)
    fatal("in ec_malloc() on memory allocation");
    return ptr;
    }
    void dump(const unsigned char *data_buffer, const unsigned int length) {
        unsigned char byte;
        unsigned int i, j;
        for(i=0; i < length; i++) {
        byte = data_buffer[i];
        printf("%02x ", data_buffer[i]); // Display byte in hex.
        if(((i%16)==15) || (i==length-1)) {
        for(j=0; j < 15-(i%16); j++)
        printf(" ");
        printf("| ");
        for(j=(i-(i%16)); j <= i; j++) { // Display printable bytes from line.
        byte = data_buffer[j];
        if((byte > 31) && (byte < 127)) // Outside printable char range
        printf("%c", byte);
        else
        printf(".");
        }
        printf("\n"); // End of the dump line (each line is 16 bytes)
        } // End if
        }
    }