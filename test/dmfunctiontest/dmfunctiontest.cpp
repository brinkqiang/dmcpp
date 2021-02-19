
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <type_traits>
#include <unordered_map>
#include <map>
#include "dmlog.h"
#include "gtest.h"

class HttpRouter {
public:
    typedef std::function<void(std::string&& req, std::string&& res)> INVOKER_FUNCTION;
    typedef std::map<std::string, INVOKER_FUNCTION> MAP_INVOKERS;
    typedef std::unordered_map<std::string, INVOKER_FUNCTION> UNORDERED_MAP_INVOKERS; //for url/*
public:
	template<typename Function>
	std::enable_if_t<!std::is_member_function_pointer_v<Function>> register_handler(const std::string& name, Function&& f)
    {
        m_mapINVOKERS[name] = f;
	}

    HttpRouter::INVOKER_FUNCTION call(const std::string& name)
    {
        return m_mapINVOKERS[name];
    }
private:
    UNORDERED_MAP_INVOKERS m_mapINVOKERS;
};

class HttpServer
{
public:
    template<typename Function>
    void set_http_handler(const std::string& name, Function&& f)
    {
        m_oRouter.register_handler(name, f);
    }

    HttpRouter::INVOKER_FUNCTION call(const std::string& name)
    {
        return m_oRouter.call(name);
    }
private:
    HttpRouter m_oRouter;
};

TEST(dmfunctiontest, dmfunctiontest)
{
    HttpServer server;

    server.set_http_handler("OnConnect", [](std::string&& req, std::string&& res) {
        LOG_DEBUG("{} -> {}", req, res);
    }
    );

    server.set_http_handler("OnDisConnect", [](std::string&& req, std::string&& res) {
        LOG_DEBUG("{} -> {}", req, res);
    }
    );

    server.set_http_handler("OnMsg", [](std::string&& req, std::string&& res) {
        LOG_DEBUG("{} -> {}", req, res);
    }
    );

    server.call("OnConnect")("OnConnect", "OnConnect");
    server.call("OnDisConnect")("OnDisConnect", "OnDisConnect");
    server.call("OnMsg")("OnMsg", "OnMsg");
}