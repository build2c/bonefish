#ifndef BONEFISH_BROKER_WAMP_BROKER_SUBSCRIPTION_HPP
#define BONEFISH_BROKER_WAMP_BROKER_SUBSCRIPTION_HPP

#include <bonefish/identifiers/wamp_subscription_id.hpp>
#include <bonefish/wamp_session.hpp>
#include <unordered_set>

namespace bonefish {

class wamp_broker_subscription
{
public:
    wamp_broker_subscription();
    wamp_broker_subscription(const wamp_subscription_id& subscription_id);
    ~wamp_broker_subscription();

    bool add_session(const std::shared_ptr<wamp_session>& session);
    bool remove_session(const std::shared_ptr<wamp_session>& session);
    const wamp_subscription_id& get_subscription_id() const;
    const std::unordered_set<std::shared_ptr<wamp_session>>& get_sessions() const;

private:
    const wamp_subscription_id m_subscription_id;
    std::unordered_set<std::shared_ptr<wamp_session>> m_sessions;
};

inline wamp_broker_subscription::wamp_broker_subscription()
    : m_subscription_id()
    , m_sessions()
{
}

inline wamp_broker_subscription::wamp_broker_subscription(const wamp_subscription_id& subscription_id)
    : m_subscription_id(subscription_id)
    , m_sessions()
{
}

inline wamp_broker_subscription::~wamp_broker_subscription()
{
}

inline bool wamp_broker_subscription::add_session(const std::shared_ptr<wamp_session>& session)
{
    auto result = m_sessions.insert(session);
    return result.second;
}

inline bool wamp_broker_subscription::remove_session(const std::shared_ptr<wamp_session>& session)
{
    return m_sessions.erase(session) != 0;
}

inline const wamp_subscription_id& wamp_broker_subscription::get_subscription_id() const
{
    return m_subscription_id;
}

inline const std::unordered_set<std::shared_ptr<wamp_session>>& wamp_broker_subscription::get_sessions() const
{
    return m_sessions;
}

} // namespace bonefish

#endif // BONEFISH_BROKER_WAMP_BROKER_SUBSCRIPTION_HPP