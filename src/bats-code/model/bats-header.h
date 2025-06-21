#ifndef BATS_HEADER_H
#define BATS_HEADER_H

#include "ns3/header.h"
#include "ns3/bats-code.h"

namespace ns3 {

class BatsHeader : public Header {
public:
    static TypeId GetTypeId(void);
    TypeId GetInstanceTypeId(void) const;
    void Serialize(Buffer::Iterator start) const;
    uint32_t Deserialize(Buffer::Iterator start);
    uint32_t GetSerializedSize(void) const;
    void Print(std::ostream &os) const;

    void SetBatchId(uint32_t batch_id);
    uint32_t GetBatchId(void) const;

    void SetPacketId(uint32_t packet_id);
    uint32_t GetPacketId(void) const;

private:
    uint32_t m_batch_id;
    uint32_t m_packet_id;
};

} // namespace ns3

#endif // BATS_HEADER_H
