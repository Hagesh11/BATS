#ifndef BATS_HELPER_H
#define BATS_HELPER_H

#include "ns3/application-container.h"
#include "ns3/node-container.h"
#include "ns3/net-device-container.h"
#include "ns3/string.h"
#include "ns3/data-rate.h"
#include "ns3/uinteger.h"
#include "ns3/inet-socket-address.h"
#include "ns3/ipv4-address.h"
#include "ns3/ipv4-address-helper.h"
#include "ns3/pointer.h"
#include "ns3/random-variable-stream.h"
#include "ns3/simulator.h"
#include "ns3/packet.h"
#include "ns3/callback.h"
#include "ns3/bats-header.h"
#include "ns3/bats-helper.h"
#include "ns3/bats-application.h"

namespace ns3 {

class BatsHelper {
public:
    static BatsHelper* GetInstance();
    void InstallApplication(NodeContainer c, uint16_t port, DataRate rate, uint32_t batch_size, uint32_t field_size);

private:
    static BatsHelper* m_instance;

    BatsHelper();
    ~BatsHelper();

    static void ScheduleNextTx(Ptr<BatsApplication> app);
    static void HandleTxComplete(Ptr<BatsApplication> app, uint32_t packet_id);

    uint32_t m_batch_size;
    uint32_t m_field_size;
};

} // namespace ns3

#endif // BATS_HELPER_H
