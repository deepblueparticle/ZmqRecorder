
#include "zmq_player/NetworkSender.h"

#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>

#include <sstream>
#include <string>

NetworkSender::NetworkSender(const std::string& zmqAddress) :
    zmqContext_(new zmq::context_t(1)),
    zmqSender_(new zmq::socket_t(*zmqContext_, ZMQ_PUB))
{
    zmqSender_->bind(zmqAddress.c_str());
}

NetworkSender::~NetworkSender()
{}

void NetworkSender::send(std::string& data)
{
    zmqSender_->send(data.c_str(), data.size());
}