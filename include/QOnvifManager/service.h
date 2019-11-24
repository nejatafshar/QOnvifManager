#ifndef ONVIF_SERVICE_H
#define ONVIF_SERVICE_H

#include "message.h"
#include "messageparser.h"
#include "qonvifdevice.hpp"
#include <QNetworkAccessManager>

template <typename T>
T*
toPtr(QVariant v) {
    return static_cast<T*>(v.value<void*>());
    //        QObject *object = qvariant_cast<QObject*>(v);
    //        return qobject_cast<T*>(object);
}

template <typename T>
QVariant
toQVariant(T* ptr) {
    return qVariantFromValue(static_cast<void*>(ptr));
}

namespace ONVIF {

class Service : public QObject
{
    Q_OBJECT

public:
    explicit Service(
        const QString& wsdlUrl,
        const QString& username,
        const QString& password);

    ~Service();
    void sendMessage(
        Message&            message,
        device::MessageType messageType,
        const QString&      namespaceKey = "");
    void sendMessage(
        Message*            message,
        device::MessageType messageType,
        const QString&      namespaceKey = "");
    void setUserPass(const QString& user, const QString& pass);

signals:

    void messageParserReceived(MessageParser*, device::MessageType messageType);

protected:
    virtual QHash<QString, QString> namespaces(const QString& key) = 0;
    Message* createMessage(QHash<QString, QString>& namespaces);
    QString  mUsername, mPassword;

private:
    QNetworkAccessManager networkManager;
    QString               mUrl;
};
} // namespace ONVIF


#endif // ONVIF_SERVICE_H
