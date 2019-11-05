#ifndef NETWORKDEFAULTGATEWAY_H
#define NETWORKDEFAULTGATEWAY_H
#include <QDomElement>
#include <QObject>

namespace ONVIF {

class NetworkDefaultGateway : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ipv4Address READ ipv4Address WRITE setIpv4Address)
    Q_PROPERTY(QString ipv6Address READ ipv6Address WRITE setIpv6Address)
public:
    NetworkDefaultGateway();
    QDomElement toxml();
    QString     ipv4Address() const {
        return m_ipv4Address;
    }
    void setIpv4Address(const QString& ipv4Address) {
        m_ipv4Address = ipv4Address;
    }
    QString ipv6Address() const {
        return m_ipv6Address;
    }
    void setIpv6Address(const QString& ipv6Address) {
        m_ipv6Address = ipv6Address;
    }

    bool result() const {
        return m_result;
    }
    void setResult(bool result) {
        m_result = result;
    }

private:
    QString m_ipv4Address;
    QString m_ipv6Address;
    bool    m_result;
};
} // namespace ONVIF
#endif // NETWORKDEFAULTGATEWAY_H
