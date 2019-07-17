// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

// ============================================================================
// Copyright (c) 2017-2019, by Vitaly Grigoriev, <Vit.link420@gmail.com>.
// This file is part of ProtocolAnalyzer open source project under MIT License.
// ============================================================================

#include <map>
#include <iostream>

#include "FrameworkApi.hpp"

using namespace analyzer::framework;
using net::SocketSSL;


int32_t main (int32_t size, char** data)
{
    log::Logger::Instance().SwitchLoggingEngine();
    log::Logger::Instance().SetLogLevel(log::LEVEL::TRACE);

    /*auto sockets = analyzer::framework::system::allocMemoryForArrayOfObjects<SocketSSL>(3, SSL_METHOD_TLS12);
    if (sockets == nullptr) {
        std::cerr << "[error] Alloc memory fail..." << std::endl;
        return EXIT_FAILURE;
    }*/

    auto request = [] (SocketSSL* sock, const std::string& domain) noexcept -> bool
    {
        if (sock->Connect(domain.c_str()) == false) {
            std::cerr << "[error] Connection fail..." << std::endl;
            return false;
        }

        const std::string buffer = "GET / HTTP/1.1\r\nHost: " + domain + "\r\nConnection: keep-alive\r\nAccept: */*\r\nDNT: 1\r\n\r\n";
        int32_t result = sock->Send(buffer.c_str(), buffer.size());
        if (result == -1) {
            std::cerr << "[error] Send fail..." << std::endl;
            return false;
        }

        char buff_receive[DEFAULT_BUFFER_SIZE] = { };
        result = sock->Recv(buff_receive, DEFAULT_BUFFER_SIZE, true);
        if (result == -1) {
            std::cerr << "[error] Receive fail..." << std::endl;
            return false;
        }
        std::cerr << '[' << domain << "] Received data length: " << result << std::endl;
        return true;
    };

    //std::cerr << request(sockets[0].get(), "tproger.ru") << std::endl;
    //std::cerr << request(sockets[1].get(), "habrahabr.ru") << std::endl;


    std::cerr << SocketSSL::context.AllowSessionResumption(SSL_METHOD_TLS13) << std::endl;
    auto socket1 = system::allocMemoryForObject<SocketSSL>(SSL_METHOD_TLS13);
    std::cerr << request(socket1.get(), "habrahabr.ru") << std::endl;
    socket1->Shutdown();
    auto socket2 = system::allocMemoryForObject<SocketSSL>(socket1->GetSessionSSL(), SSL_METHOD_TLS13);
    socket2->SetOnlySecureCiphers();
    std::cerr << request(socket2.get(), "habrahabr.ru") << std::endl;
    std::cerr << SSL_get_version(socket2->GetSSL()) << std::endl;

    return EXIT_SUCCESS;
}
