#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/helper/bats-helper.h"
#include "ns3/model/bats-header.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("BatsExample");

int main(int argc, char *argv[])
{
    CommandLine cmd;
    cmd.Parse(argc, argv);

    // Create nodes
    NodeContainer nodes;
    nodes.Create(2);

    // Add internet stack
    InternetStackHelper stack;
    stack.Install(nodes);

    // Assign IP addresses
    Ipv4AddressHelper address;
    address.SetBase("10.1.1.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces = address.Assign(nodes.Get(0)->GetDevice(0));

    // Create BATS helper
    BatsHelper batsHelper;
    batsHelper.InstallApplication(nodes, 8080, DataRate("1Mbps"), 16, 256);

    // Run simulation
    Simulator::Stop(Seconds(10.0));
    Simulator::Run();
    Simulator::Destroy();

    return 0;
}
