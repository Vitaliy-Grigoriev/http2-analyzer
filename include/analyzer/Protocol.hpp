#pragma once
#ifndef HTTP2_ANALYZER_PROTOCOL_HPP
#define HTTP2_ANALYZER_PROTOCOL_HPP


namespace analyzer::net::protocols
{
    /**
     * @class URLInfo Protocol.hpp "include/analyzer/Protocol.hpp"
     * @brief Parsing Uniform Resource Locators (URL).
     *
     * @see RFC 1738.
     */
    /*class URLInfo
    {
    private:
        bool isIPv4 = false;
        bool isIPv6 = false;
        bool isPortNumber = false;
        bool isAuthCredentials = false;

    };*/

    /**
     * @class ParseURI Protocol.hpp "include/analyzer/Protocol.hpp"
     * @brief Parsing Uniform Resource Identifier (URI).
     *
     * @see RFC 3986, RFC 2732.
     * @note scheme:[//[user:password@]host[:port]][/]path[?query][#fragment]
     */
    class ParseURI
    {
    private:
        bool isErrorOccur = false;
        bool isAbsoluteLink = false;
        uint16_t port;
        std::string scheme;
        std::string url, urn;
        std::string path;
        std::string query;
        std::string fragment;
        //URLInfo domain;


    public:
        ParseURI (const char * /*link*/, const std::size_t /*size*/);
        explicit ParseURI (const std::string & /*link*/);

        inline bool IsError(void)  const { return isErrorOccur; }
        inline bool IsAbsoluteLink(void)  const { return isAbsoluteLink; }

        inline std::string Scheme(void)   const { return scheme; }
        inline std::string URL(void)      const { return url; }
        inline uint16_t Port(void)        const { return port; }
        //const URLInfo & GetURLInfo() const { return domain; }
        inline std::string URN(void)      const { return urn; }
        inline std::string Path(void)     const { return path; }
        inline std::string Query(void)    const { return query; }
        inline std::string Fragment(void) const { return fragment; }

        ~ParseURI(void) = default;
    };


    /**
     * @interface ProtocolLayer ProtocolLayer.hpp "include/analyzer/ProtocolLayer"
     * @brief Interface of application layer protocol.
     */
    class Protocol {
    protected:
        Protocol (Protocol &&) = delete;
        Protocol (const Protocol &) = delete;
        Protocol & operator= (Protocol &&) = delete;
        Protocol & operator= (const Protocol &) = delete;

    public:
        Protocol(void) = default;

        virtual Protocol & SetSettings (void * /*settings*/) = 0;

        virtual bool IsVerification(void) = 0;

        virtual void ParseHeader(void) = 0;

        virtual ~Protocol(void);
    };

}  // namespace protocols.


#endif  // HTTP2_ANALYZER_PROTOCOL_HPP
