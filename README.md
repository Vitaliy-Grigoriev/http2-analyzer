# Protocol Analyzer
<h1>Fuzz testing framework for network protocols.</h1>

--------------

[![license](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/Vitaliy-Grigoriev/Protocol-Analyzer/blob/master/LICENSE)
[![Coverity Scan](https://img.shields.io/coverity/scan/10369.svg)](https://scan.coverity.com/projects/vitaliy-grigoriev-protocol-analyzer)
[![Build Status](https://travis-ci.org/Vitaliy-Grigoriev/Protocol-Analyzer.svg?branch=master)](/Vitaliy-Grigoriev/Protocol-Analyzer)

<h3><b>The framework under the deep development.</b> Version 0.0.8.</h3>

--------------

<h2><b>Current goals</b></h2>

* Development of the basis of network interaction for the needs of the framework;
  * Epoll Socket State Pool interface for all Sockets under the observation;
  * Managed Socket Pool for unique interface to take and control sockets;
  * UDP Socket interface.
  * RAW Socket interface.
  * Netlink interface for interact with Linux Kernel.

* Development of a unique interface for describing the Network Protocol;
  * Implement libJSON as submodule of framework for parsing input configs.

* Development of a unique interface for create Tasks and manage them;
* Development of a unique interface for store Global information and Settings in runtime.

--------------

<h2><b>Requirements for building</b></h2>

<h4>The following package is required to build the Protocol Analyzer:</h4>

* OpenSSL >= 1.0.2h (libssl-dev)

* CMake >= 3.8.0 (for C++17 standard support)

* Compiler that support C++17 ('clang-5.0.0' for example).

